#pragma once

#include <QWidget>

class QSplitter;

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
    QSplitter* _splitter{ nullptr };
    ChatListWidget* _chatListWidget{ nullptr };
    ChatViewWidget* _chatViewWidget{ nullptr };
};
