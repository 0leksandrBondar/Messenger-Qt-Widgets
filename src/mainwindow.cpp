#include "mainwindow.h"

MainWindow::MainWindow() : QMainWindow(), _clientWidget{ new ClientWidget(this) }
{
    resize(1300, 800);
    setCentralWidget(_clientWidget);
}
