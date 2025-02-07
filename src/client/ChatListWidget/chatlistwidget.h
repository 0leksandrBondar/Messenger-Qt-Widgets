#pragma once

#include <QWidget>

class QLineEdit;
class QListWidget;
class QPushButton;

class Client;

class ChatListWidget final : public QWidget
{
    Q_OBJECT
public:
    explicit ChatListWidget(Client* client, QWidget* parent = nullptr);

    void onChatSelectionChanged() const;
    void onAddChatButtonClicked() const;
    void onSplitterResized(int pos, int index) const;

private:
    void setupUi();
    void setupConnections();

    void createChat(const QString& chatName) const;

private:
    Client* _client{ nullptr };
    QLineEdit* _searchLine{ nullptr };
    QPushButton* _addChatButton{ nullptr };
    QListWidget* _chatListWidget{ nullptr };
};
