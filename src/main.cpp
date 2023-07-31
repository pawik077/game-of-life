// #include "mainwindow.h"
// #include <QApplication>
#include <iostream>
#include <vector>
#include "Grid.hh"
#include "gol.hh"

int main(int argc, char* argv[]) {
    // QApplication a(argc, argv);
    // MainWindow w;
    // w.show();

    // return a.exec();
    Grid grid = Grid(10, 10);

    grid(4, 5, true);
    grid(5, 5, true);
    grid(6, 5, true);
    std::cout << grid << "\n";
    for (uint8_t i = 0; i < 5; i++) {
        gol_step(grid);
        std::cout << grid << "\n";
    }
    return 0;
}