#include "chatviewwidget.h"

#include "ChatInfoWidget/ChatInfoWidget.h"
#include "InputWidget/inputmessagewidget.h"
#include "MessageListWidget/messagelistwidget.h"

#include <QBoxLayout>

ChatViewWidget::ChatViewWidget(QWidget* parent)
    : QWidget(parent),
      _chatInfoWidget(new ChatInfoWidget),
      _messageListWidget{ new MessageListWidget() },
      _inputMessageWidget{ new InputMessageWidget() }
{
    setupUi();
    setupConnections();
}

void ChatViewWidget::onChatSelectionChanged(const QString& chatName)
{
    _chatInfoWidget->changeChatInfo(chatName);
}

void ChatViewWidget::onSendMessage(const QString& message, const QString& filePath) const
{
    _messageListWidget->addMessage(message, filePath);
}

void ChatViewWidget::onReceivedMessage(const QString& message) const
{
    _messageListWidget->addMessage(message, "", false);
}

void ChatViewWidget::setupUi()
{
    const auto vLayout = new QVBoxLayout();

    vLayout->addWidget(_chatInfoWidget);
    vLayout->addWidget(_messageListWidget);
    vLayout->addWidget(_inputMessageWidget);

    setLayout(vLayout);
}

void ChatViewWidget::setupConnections()
{
    connect(_inputMessageWidget, &InputMessageWidget::sendMessage, this,
            &ChatViewWidget::onSendMessage);
}
