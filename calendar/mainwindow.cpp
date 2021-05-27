#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QVBoxLayout *a = new QVBoxLayout;
    ui->groupBox->setLayout(a);
    day = ui->calendarWidget->selectedDate().day();
    month = ui->calendarWidget->selectedDate().month();
    year = ui->calendarWidget->selectedDate().year() - 2000;
    weatherRequest();
    loadNotesFromFile();
    on_calendarWidget_selectionChanged();
}

MainWindow::~MainWindow()
{
    saveNotesToFile();
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString text = ui->lineEdit->text();
    if (calendarNotes[day][month][year].size() > 5)
    {
        QMessageBox::warning(0, "Ошибка добавления заметки", "Невозможно добавить более 6 заметок");
        return;
    }
    calendarNotes[day][month][year].push_back({text, 0});

    on_calendarWidget_selectionChanged();
}

void MainWindow::on_calendarWidget_selectionChanged()
{
    // weather change info
    getWeather();
   // qDebug() << QPixmap(":/weather/resources/" + weatherMap[ui->calendarWidget->selectedDate()].icon);
    qDebug() << weatherMap[ui->calendarWidget->selectedDate()].icon;

    // save previous day and set new day
    prevDay = day; prevMonth = month; prevYear = year;
    day = ui->calendarWidget->selectedDate().day();
    month = ui->calendarWidget->selectedDate().month();
    year = ui->calendarWidget->selectedDate().year() - 2000;

    // save previous states of checkboxes
    auto checkBoxList = ui->groupBox->findChildren<QCheckBox*>();
    int index = 0;
    for (auto&& box : checkBoxList)
    {
        calendarNotes[prevDay][prevMonth][prevYear][index].state = box->isChecked();
        index++;
    }

    // delete old widgets from layout
    QLayoutItem *wItem;
    while ((wItem = ui->groupBox->layout()->takeAt(0)) != nullptr)
    {
        if (wItem->widget())
        {
            wItem->widget()->setParent(nullptr);
            delete wItem;
        }
    }

    // draw new checkboxes
    mapper = new QSignalMapper(this);
    qDebug() << calendarNotes[day][month][year].size();
    for (int i = 0; i < (int)calendarNotes[day][month][year].size(); i++)
    {
        checkBox[i] = new QCheckBox(calendarNotes[day][month][year][i].note);
        qDebug() << calendarNotes[day][month][year][i].note;
        if (calendarNotes[day][month][year][i].state)
        {
            checkBox[i]->setChecked(true);
        }
        on_clickedCheckBox(i);
        ui->groupBox->layout()->addWidget(checkBox[i]);
        mapper->setMapping(checkBox[i], i);
        connect(checkBox[i], SIGNAL(toggled(bool)), mapper, SLOT(map()));
    }
    connect(mapper, SIGNAL(mappedInt(int)), this, SLOT(on_clickedCheckBox(int)));
}

void MainWindow::on_clickedCheckBox(int index)
{
    QFont font = checkBox[index]->font();
    if (checkBox[index]->checkState() == 2)
    {
         font.setStrikeOut(true);
         font.setBold(true);
         checkBox[index]->setFont(font);
    }
    else
    {
        font.setStrikeOut(false);
        font.setBold(false);
        checkBox[index]->setFont(font);
    }
}


void MainWindow::getWeather()
{
    if (weatherMap[ui->calendarWidget->selectedDate()].icon != "")
    {
        ui->weatherIcon->show();
        ui->weatherLow->show();
     //   return QString::number(weatherMap[date].temp);
        QString weather = QString::number(weatherMap[ui->calendarWidget->selectedDate()].temp);
        QString lowTemp = QString::number(weatherMap[ui->calendarWidget->selectedDate()].lowTemp);
        if (weather[0] != '-') weather.prepend("+");
        weather += "°C";
        weather += "\n";
        weather += weatherMap[ui->calendarWidget->selectedDate()].descriprion;
        weather += "\n";
        weather += "Вероятность осадков: ";
        weather += QString::number(weatherMap[ui->calendarWidget->selectedDate()].precipation);
        weather += "%";
        if (lowTemp[0] != '-') lowTemp.prepend("+");
        lowTemp += "°C";
        ui->weather->setText(weather);
        ui->weatherIcon->setPixmap(QPixmap(":/weather/resources/" + weatherMap[ui->calendarWidget->selectedDate()].icon));
        ui->weatherLow->setText(lowTemp);
    }
    else
    {
        ui->weather->setText("Не удалось загрузить данные\nо погоде");
        ui->weatherIcon->hide();
        ui->weatherLow->hide();
    }
}

void MainWindow::weatherRequest()
{
    QUrl url ("http://api.weatherbit.io/v2.0/forecast/daily?city=Minsk,Belarus&lang=ru&key=535d6ae9531743b5a6654ee288c0bb84");
    QNetworkAccessManager *manager = new QNetworkAccessManager;
    QNetworkRequest request;
    request.setUrl(url);
    manager->get(request);



    QObject::connect(manager, &QNetworkAccessManager::finished,
            this, [=](QNetworkReply *reply)
    {
                if (reply->error())
                {
                    qDebug() << reply->errorString();
                }

                QString str = reply->readAll();
               // qDebug() << str;
                QJsonParseError jsonError;
                QJsonDocument response = QJsonDocument::fromJson(str.toUtf8(), &jsonError);
                if (jsonError.error != QJsonParseError::NoError)
                {
                    qDebug() << jsonError.errorString();
                  //  return;
                }
                QFile file("D:/study/qt/calendar/resources/weatherinfo/weather.json");
                file.open(QIODevice::ReadWrite | QIODevice::Text);
                if (reply->error() == QNetworkReply::NoError)
                {
                    file.write(response.toJson());
                    file.close();
                    qDebug() << response.toJson();
                }
                else
                {
                    if (file.size() == 0)
                    {
                        qDebug() << "Weather info file is Empty. Fail to get weather info";
                        return;
                    }
                    else response = QJsonDocument::fromJson(QByteArray(file.readAll()));
                }
                file.write(response.toJson());
                QJsonObject obj = response.object();
                QJsonArray array = obj["data"].toArray();
              //  qDebug() << array;
                for (QJsonValue i: array)
                {
                    QJsonObject j = i.toObject();
                   // qDebug() << j["max_temp"];
                    QDate date = QDate::fromString(j["valid_date"].toString(), "yyyy-MM-dd");
                    Weather w;
                    w.temp = j["high_temp"].toDouble();
                    w.lowTemp = j["low_temp"].toDouble();

                    QJsonObject k = j["weather"].toObject();
                    w.icon = k["icon"].toString() + ".png";
                   // qDebug() << w.icon;

                    w.descriprion = k["description"].toString();
                   // qDebug() << w.descriprion;
                    w.precipation = j["pop"].toDouble();
                    weatherMap[date] = w;
                }

                getWeather();
             //   qDebug() << response.toVariant();

            /*    QMap <QString, QVariant> map = response.toVariant().toMap();
                QVariant data = map["data"];
                qDebug() << data;
                QMap <QString, QVariant> map2 = data.toMap();
                qDebug() << map2;
                qDebug() << response["valid_date"].toString();
                QJsonArray jsonArray = response.array();
                for (QJsonValue a : jsonArray)
                {
                    QMessageBox::information(nullptr, "ok", "info get");
                    QJsonObject obj = a.toObject();
                    qDebug() << obj["valid_date"].toString();
                }*/

    }
    );

    //QMessageBox::information(nullptr, "ok", "info got")
}

/*void MainWindow::eggs()
{
    al_init();
    ALLEGRO_SAMPLE *mus = al_load_sample("D:\\study\\qt\\calendar\\resources\\music.calendar.mp3");
    ALLEGRO_SAMPLE_INSTANCE *mus2 = al_create_sample_instance(mus);
    al_play_sample_instance(mus2);
}*/

void MainWindow::saveNotesToFile()
{
    auto checkBoxList = ui->groupBox->findChildren<QCheckBox*>();
    int index = 0;
    for (auto&& box : checkBoxList)
    {
        calendarNotes[prevDay][prevMonth][prevYear][index].state = box->isChecked();
        index++;
    }

    QFile file ("D:/study/qt/calendar/resources/weatherinfo/notes.txt");
    if (!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "SAVE NOTES ERROR. unable to open file";
        return;
    }
    QString text;
    for (int i = 1; i <= 31; i++)
    {
        for (int j = 1; j <= 12; j++)
        {
            for (int k = 1; k <= 105; k++)
            {
                if (calendarNotes[i][j][k].empty()) continue;
                text+=QString::number(i);
                text+='-';
                text+=QString::number(j);
                text+='-';
                text+=QString::number(k);
                text+=';';
                text+=QString::number(calendarNotes[i][j][k].size());
                text+=';';

                for (Note note : calendarNotes[i][j][k])
                {
                    text+= note.note;
                    text+='-';
                    text+=QString::number(note.state);
                    text+=';';
                }
                text += '\n';
            }
        }
    }
    file.write(QByteArray::fromStdString(text.toStdString()));
    file.close();
}

void MainWindow::loadNotesFromFile()
{
    QFile file ("D:/study/qt/calendar/resources/weatherinfo/notes.txt");
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "LOAD NOTES ERROR. unable to open file";
        return;
    }

    while (!file.atEnd())
    {
        QString line = file.readLine();
        if (line.size() < 5) continue;
        qDebug() << line;

        int index = 0;
        QString temp;
        while (line[index] != '-')
        {
            temp += line[index];
            index++;
        }

        int day = temp.toInt();
        temp.clear();
        index++;

        while (line[index] != '-')
        {
            temp += line[index];
            index++;
        }

        int month = temp.toInt();
        temp.clear();
        index++;


        while (line[index] != ';')
        {
            temp += line[index];
            index++;
        }

        int year = temp.toInt();
        temp.clear();
        index++;

        while (line[index] != ';')
        {
            temp += line[index];
            index++;
        }

       // qDebug() << day << month << year;
        int notesNumber = temp.toInt();
        temp.clear();
        index++;

        for (int i = 0; i < notesNumber; i++)
        {
            while (line[index] != '-')
            {
                temp += line[index];
                index++;
            }

            index++;
            if (line[index] == '0') calendarNotes[day][month][year].push_back({temp, false});
            else calendarNotes[day][month][year].push_back({temp, true});

            qDebug() << temp;

            temp.clear();
            index+=2;
        }

        qDebug() << calendarNotes[day][month][year].size();
    }
    file.close();
}
