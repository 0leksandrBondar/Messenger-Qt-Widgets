#pragma once

#include <QWidget>

class QLineEdit;
class QPushButton;

class WelcomeWidget final : public QWidget
{
    Q_OBJECT
public:
    explicit WelcomeWidget(QWidget* parent = nullptr);

    void onLoginButtonClicked();

    [[nodiscard]] QString getUserName() const;

signals:
    void loginButtonClicked();

private:
    void setupUi();

    void setupDarkTheme() const;
    void setupLightTheme() const;

    void setupConnections();

private:
    QPushButton* _loginButton{ nullptr };
    QLineEdit* _nameInputLine{ nullptr };
};
