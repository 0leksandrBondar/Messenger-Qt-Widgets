#include "mainwindow.h"

#include "client/clientwidget.h"
#include "client/welcomewidget.h"
#include "network/Client.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      _clientSocket{ new Client() },
      _clientWidget{ new ClientWidget() },
      _welcomeWidget{ new WelcomeWidget() }
{
    setupUi();
    setupConnections();
}

void MainWindow::onLoginButtonClicked()
{
    if (connectToServer())
    {
        setCentralWidget(_clientWidget);
    }
}

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

bool MainWindow::connectToServer()
{
    const std::string username = _welcomeWidget->getUserName().toStdString();
    const bool isConnectedToServer = _clientSocket->connectToServer("127.0.0.1", 8080);

    if (isConnectedToServer && !username.empty())
    {
        _clientSocket->sendDataToServer("USER:" + username);
        return true;
    }

    return false;
}
