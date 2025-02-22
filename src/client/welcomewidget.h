#pragma once

#include <QWidget>

class Client;
class QLineEdit;
class QPushButton;

class WelcomeWidget final : public QWidget
{
    Q_OBJECT
public:
    explicit WelcomeWidget(Client* client, QWidget* parent = nullptr);

    void onLoginButtonClicked();

signals:
    void loginButtonClicked();

private:
    void setupUi();

    void setupDarkTheme() const;
    void setupLightTheme() const;

    void setupConnections();

private:
    Client* _client{ nullptr };
    QPushButton* _loginButton{ nullptr };
    QLineEdit* _nameInputLine{ nullptr };
};
