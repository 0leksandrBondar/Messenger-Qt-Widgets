#pragma once

#include <QWidget>

class QSplitter;

class Client;
class ChatListWidget;
class ChatViewWidget;

class ClientWidget final : public QWidget
{
    Q_OBJECT
public:
    explicit ClientWidget(QWidget* parent = nullptr);

private:
    void setupUi();
    void setupConnections();

    void setupSplitter() const;

private:
    Client* _client{ nullptr };
    QSplitter* _splitter{ nullptr };
    ChatListWidget* _chatListWidget{ nullptr };
    ChatViewWidget* _chatViewWidget{ nullptr };
};
