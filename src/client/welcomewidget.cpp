#include "welcomewidget.h"

#include "ClientNetwork/client.h"

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

    emit loginButtonClicked();
}

void WelcomeWidget::setupUi()
{
    _nameInputLine->setPlaceholderText(QStringLiteral("Enter username..."));

    _nameInputLine->setFixedWidth(500);
    _loginButton->setFixedWidth(500);

    const auto layout = new QVBoxLayout();

    layout->setAlignment(Qt::AlignCenter);
    layout->setSpacing(20);

    layout->addWidget(_nameInputLine);
    layout->addWidget(_loginButton);

    setLayout(layout);
}

void WelcomeWidget::setupConnections()
{
    connect(_loginButton, &QPushButton::clicked, this, &WelcomeWidget::onLoginButtonClicked);
}