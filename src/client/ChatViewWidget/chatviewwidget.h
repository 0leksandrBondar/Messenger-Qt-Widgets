#pragma once

#include <QWidget>

class Client;
class MessageListWidget;
class InputMessageWidget;

class ChatViewWidget final : public QWidget
{
    Q_OBJECT
public:
    explicit ChatViewWidget(Client* client, QWidget* parent = nullptr);

    void onSendMessage(const QString& message, const QString& filePath) const;

private:
    void setupUi();
    void setupConnections();

private:
    Client* _client{ nullptr };
    MessageListWidget* _messageListWidget{ nullptr };
    InputMessageWidget* _inputMessageWidget{ nullptr };
};
