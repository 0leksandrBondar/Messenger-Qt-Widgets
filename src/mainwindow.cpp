#include "mainwindow.h"

#include "client/ClientNetwork/client.h"
#include "client/clientwidget.h"
#include "client/welcomewidget.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      _client{ new Client(this) },
      _clientWidget{ new ClientWidget(_client) },
      _welcomeWidget{ new WelcomeWidget(_client) }
{
    setupUi();
    setupConnections();

    _client->connectToServer("127.0.0.1", 1234);
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
