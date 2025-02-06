#include "messagelistwidget.h"
#include "Messages/message.h"

#include <QBoxLayout>
#include <Qlabel>

MessageListWidget::MessageListWidget(QWidget* parent) : QListWidget(parent) { setupUi(); }

void MessageListWidget::addMessage(const QString& message, const QString& filePath,
                                   const bool isOwnMessage)
{
    const auto messageWidget = new Message(message, filePath, isOwnMessage);
    auto* item = new QListWidgetItem();
    item->setSizeHint(messageWidget->sizeHint());

    addItem(item);
    setItemWidget(item, messageWidget);
    scrollToBottom();
}

void MessageListWidget::setupUi() { setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding); }
