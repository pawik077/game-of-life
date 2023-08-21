#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <QtWidgets>

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow();
    ~MainWindow();
private:
    QWidget centralWidget{ this };
    QHBoxLayout* layout;

    QVBoxLayout* menuLayout;
    QWidget menuWidget{ this };
    QWidget gridWidget{ this };

    QWidget* gridEditWidget;
    QGridLayout* gridEditLayout;
    QLabel* gridWidthLabel;
    QLabel* gridHeightLabel;
    QLineEdit* gridWidthInput;
    QLineEdit* gridHeightInput;
    QPushButton* gridEditButton;
    QLabel* gridColorLabel;
    QComboBox* gridColorInput;
    QPushButton* gridColorButton;

    QWidget* controlWidget;
    QGridLayout* controlLayout;
    QPushButton* startStopButton;
    QPushButton* stepButton;
    QPushButton* resetButton;
    QLabel* generationLabel;

    void setText();
};

#endif