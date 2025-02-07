#pragma once

#include <QWidget>

class MessageListWidget;
class InputMessageWidget;

class ChatViewWidget final : public QWidget
{
    Q_OBJECT
public:
    explicit ChatViewWidget(QWidget* parent = nullptr);

    void onSendMessage(const QString& message, const QString& filePath) const;

signals:
    void sendMessage(const QString& message, const QString& filePath) const;

private:
    void setupUi();
    void setupConnections();

private:
    MessageListWidget* _messageListWidget{ nullptr };
    InputMessageWidget* _inputMessageWidget{ nullptr };
};
