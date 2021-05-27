#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <QString>
#include <map>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QSignalMapper>
#include <QDate>
#include <QMap>

#include <QtNetwork/QNetworkAccessManager>
#include <QJsonArray>
#include <QJsonDocument>
#include <QtNetwork/QNetworkReply>
#include <QJsonValue>
#include <QJsonObject>
#include <QDebug>
#include <QMessageBox>
#include <QUrl>
#include <QtNetwork>
#include <QList>
#include <windows.h>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    struct Note
    {
        QString note;
        bool state;
    };

    vector <Note> calendarNotes[32][13][106];

    struct Weather
    {
        double temp;
        double lowTemp;
        QString icon;
        QString descriprion;
        double precipation;

    };

    QMap <QDate, Weather> weatherMap;

    void getWeather();

    void weatherRequest();

    void eggs();

    void loadNotesFromFile();

    void saveNotesToFile();


private slots:
    void on_pushButton_clicked();

    void on_calendarWidget_selectionChanged();

    void on_clickedCheckBox(int index);

private:
    Ui::MainWindow *ui;
    int day, month, year;
    int prevDay, prevMonth, prevYear;
    QCheckBox* checkBox[6];
    QSignalMapper *mapper;
};
#endif // MAINWINDOW_H
