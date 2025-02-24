#pragma once

#include <QMainWindow>

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

private:
    ClientWidget* _clientWidget{ nullptr };
    WelcomeWidget* _welcomeWidget{ nullptr };
};
