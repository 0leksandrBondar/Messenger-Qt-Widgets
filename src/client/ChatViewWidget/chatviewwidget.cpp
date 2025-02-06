#include "chatviewwidget.h"

#include "InputWidget/inputmessagewidget.h"
#include "MessageListWidget/messagelistwidget.h"

#include <QBoxLayout>

ChatViewWidget::ChatViewWidget(QWidget* parent)
    : QWidget(parent),
      _messageListWidget{ new MessageListWidget() },
      _inputMessageWidget{ new InputMessageWidget() }
{
    setupUi();
    setupConnections();
}

void ChatViewWidget::onSendMessage(const QString& message, const QString& filePath) const
{
    _messageListWidget->addMessage(message, filePath);
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
}
