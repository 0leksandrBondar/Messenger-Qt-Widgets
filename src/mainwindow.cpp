#include "mainwindow.h"

#include "client/clientwidget.h"
#include "client/welcomewidget.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      _clientWidget{ new ClientWidget() },
      _welcomeWidget{ new WelcomeWidget() }
{
    setupUi();
    setupConnections();

}

void MainWindow::onLoginButtonClicked() { setCentralWidget(_clientWidget); }

void MainWindow::setupUi()
{
    resize(1300, 800);
    setCentralWidget(_welcomeWidget);
}

void MainWindow::setupConnections()
{
    connect(_welcomeWidget, &WelcomeWidget::loginButtonClicked, this,
            &MainWindow::onLoginButtonClicked);
}
