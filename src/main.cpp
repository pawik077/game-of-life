#include <iostream>
#include <vector>
#include <QApplication>
#include "Grid.hh"
#include "gol.hh"
#include "MainWindow.hh"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}