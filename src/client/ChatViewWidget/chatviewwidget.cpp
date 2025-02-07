#include "chatviewwidget.h"

#include "../ClientNetwork/client.h"
#include "InputWidget/inputmessagewidget.h"
#include "MessageListWidget/messagelistwidget.h"

#include <QBoxLayout>

ChatViewWidget::ChatViewWidget(Client* client, QWidget* parent)
    : QWidget(parent),
      _client{ client },
      _messageListWidget{ new MessageListWidget() },
      _inputMessageWidget{ new InputMessageWidget() }
{
    setupUi();
    setupConnections();
}

void ChatViewWidget::onSendMessage(const QString& message, const QString& filePath) const
{
    _messageListWidget->addMessage(message, filePath);
    _client->sendMessage(message, filePath);
}

void ChatViewWidget::onReceivedMessage(const QString& message) const
{
    _messageListWidget->addMessage(message, "", false);
}

void ChatViewWidget::setupUi()
{
    const auto vLayout = new QVBoxLayout();

    vLayout->addWidget(_messageListWidget);
    vLayout->addWidget(_inputMessageWidget);

    setLayout(vLayout);
}

void ChatViewWidget::setupConnections()
{
    connect(_inputMessageWidget, &InputMessageWidget::sendMessage, this,
            &ChatViewWidget::onSendMessage);
    connect(_client, &Client::messageReceived, this, &ChatViewWidget::onReceivedMessage);
}
