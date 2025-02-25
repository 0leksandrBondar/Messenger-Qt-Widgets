#pragma once

#include <QWidget>

class ChatInfoWidget;
class MessageListWidget;
class InputMessageWidget;

class ChatViewWidget final : public QWidget
{
    Q_OBJECT
public:
    explicit ChatViewWidget(QWidget* parent = nullptr);

    void onChatSelectionChanged(const QString& chatName);
    void onReceivedMessage(const QString& message) const;
    void onSendMessage(const QString& message, const QString& filePath) const;

private:
    void setupUi();
    void setupConnections();

private:
    ChatInfoWidget* _chatInfoWidget{ nullptr };
    MessageListWidget* _messageListWidget{ nullptr };
    InputMessageWidget* _inputMessageWidget{ nullptr };
};
