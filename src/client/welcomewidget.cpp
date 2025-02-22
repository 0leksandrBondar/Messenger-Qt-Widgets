#include "welcomewidget.h"

#include "ClientNetwork/client.h"
#include "Style/Style.h"

#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

WelcomeWidget::WelcomeWidget(Client* client, QWidget* parent)
    : QWidget(parent),
      _client{ client },
      _loginButton{ new QPushButton(QStringLiteral("Login")) },
      _nameInputLine{ new QLineEdit() }
{
    setupUi();
    setupConnections();
}

void WelcomeWidget::onLoginButtonClicked()
{
    if (_nameInputLine->text().isEmpty())
        return;

    _client->setUserName(_nameInputLine->text());
    _client->sendMessage();

    emit loginButtonClicked();
}

void WelcomeWidget::setupUi()
{
    _nameInputLine->setMinimumHeight(50);
    _nameInputLine->setMaximumWidth(500);
    _nameInputLine->setMinimumWidth(200);
    _nameInputLine->setFocusPolicy(Qt::ClickFocus);
    _nameInputLine->setPlaceholderText(QStringLiteral("Enter username..."));

    _loginButton->setFixedWidth(500);

    if (Style::isDarkSystemTheme())
        setupDarkTheme();
    else
        setupLightTheme();

    const auto layout = new QVBoxLayout();
    layout->setAlignment(Qt::AlignCenter);
    layout->setSpacing(20);

    layout->addWidget(_nameInputLine);
    layout->addWidget(_loginButton);

    setLayout(layout);
}

void WelcomeWidget::setupDarkTheme() const
{
    _loginButton->setStyleSheet(Style::getStyle("Style/WelcomePage/Dark/QPushButtonStyle.qss"));
    _nameInputLine->setStyleSheet(Style::getStyle("Style/WelcomePage/Dark/QLineEditStyle.qss"));
}

void WelcomeWidget::setupLightTheme() const
{
    _loginButton->setStyleSheet(Style::getStyle("Style/WelcomePage/Light/QPushButtonStyle.qss"));
    _nameInputLine->setStyleSheet(Style::getStyle("Style/WelcomePage/Light/QLineEditStyle.qss"));
}

void WelcomeWidget::setupConnections()
{
    connect(_loginButton, &QPushButton::clicked, this, &WelcomeWidget::onLoginButtonClicked);
    connect(_nameInputLine, &QLineEdit::returnPressed, this, &WelcomeWidget::onLoginButtonClicked);
}
