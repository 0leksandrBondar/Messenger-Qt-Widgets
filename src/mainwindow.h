#pragma once

#include <QMainWindow>

class Client;
class ClientWidget;
class WelcomeWidget;

class MainWindow final : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = nullptr);

    void onLoginButtonClicked();

private:
    void setupUi();
    void setupConnections();

    bool connectToServer();

private:
    Client* _clientSocket{ nullptr };
    ClientWidget* _clientWidget{ nullptr };
    WelcomeWidget* _welcomeWidget{ nullptr };
};
