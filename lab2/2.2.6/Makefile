main: main.c
	gcc main.c -std=c89 -Wall -lm -pedantic -o main
test: main.c main_test.c
	gcc main.c main_test.c -lm -std=c89 -Wall -pedantic -Dmain=_main -o test
