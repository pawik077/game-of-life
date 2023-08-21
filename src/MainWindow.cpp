#include "MainWindow.hh"

MainWindow::MainWindow() {
    setWindowTitle("Game of Life");
    setMinimumSize(1920, 1080);

    layout = new QHBoxLayout(&centralWidget);

    menuLayout = new QVBoxLayout(&menuWidget);

    gridEditWidget = new QWidget(&menuWidget);
    gridEditLayout = new QGridLayout(gridEditWidget);
    gridWidthLabel = new QLabel("Width:", gridEditWidget);
    gridHeightLabel = new QLabel("Height:", gridEditWidget);
    gridWidthInput = new QLineEdit("10", gridEditWidget);
    gridHeightInput = new QLineEdit("10", gridEditWidget);
    gridEditButton = new QPushButton("Resize Grid", gridEditWidget);
    gridColorLabel = new QLabel("Grid Color:", gridEditWidget);
    gridColorInput = new QComboBox(gridEditWidget);
    gridColorButton = new QPushButton("Change Color", gridEditWidget);

    gridColorInput->addItem("Black");
    gridColorInput->addItem("Red");
    gridColorInput->addItem("Green");
    gridColorInput->addItem("Blue");

    gridEditLayout->addWidget(gridWidthLabel, 0, 0);
    gridEditLayout->addWidget(gridWidthInput, 1, 0);
    gridEditLayout->addWidget(gridHeightLabel, 0, 1);
    gridEditLayout->addWidget(gridHeightInput, 1, 1);
    gridEditLayout->addWidget(gridEditButton, 2, 0, 1, 2);
    gridEditLayout->addWidget(gridColorLabel, 3, 0);
    gridEditLayout->addWidget(gridColorInput, 3, 1);
    gridEditLayout->addWidget(gridColorButton, 4, 0, 1, 2);
    gridEditLayout->setAlignment(Qt::AlignTop);
    gridEditWidget->setLayout(gridEditLayout);

    menuLayout->addWidget(gridEditWidget);

    controlWidget = new QWidget(&menuWidget);
    controlLayout = new QGridLayout(controlWidget);
    startStopButton = new QPushButton("Start/Stop", controlWidget);
    stepButton = new QPushButton("Step", controlWidget);
    resetButton = new QPushButton("Reset", controlWidget);
    generationLabel = new QLabel("Generation: 0", controlWidget);

    controlLayout->addWidget(startStopButton, 0, 0);
    controlLayout->addWidget(stepButton, 0, 1);
    controlLayout->addWidget(resetButton, 0, 2);
    controlLayout->addWidget(generationLabel, 1, 0, 1, 3);
    controlLayout->setAlignment(Qt::AlignBottom);
    controlWidget->setLayout(controlLayout);

    menuLayout->addWidget(controlWidget);
    
    menuWidget.setLayout(menuLayout);

    centralWidget.setLayout(layout);
    setCentralWidget(&centralWidget);

    layout->addWidget(&menuWidget);
    layout->addWidget(&gridWidget);

    QSizePolicy spLeft(QSizePolicy::Preferred, QSizePolicy::Preferred);
    spLeft.setHorizontalStretch(1);
    QSizePolicy spRight(QSizePolicy::Preferred, QSizePolicy::Preferred);
    spRight.setHorizontalStretch(3);

    menuWidget.setSizePolicy(spLeft);
    gridWidget.setSizePolicy(spRight);

}

MainWindow::~MainWindow() {
    // delete grid;
    // delete control;
}
