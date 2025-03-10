#pragma once

#include <QWidget>

class QLineEdit;
class QListWidget;
class QPushButton;

class ChatListWidget final : public QWidget
{
    Q_OBJECT
public:
    explicit ChatListWidget(QWidget* parent = nullptr);

    void onChatSelectionChanged();
    void onAddChatButtonClicked() const;
    void onSplitterResized(int pos, int index) const;

signals:
    void chatSelectionChanged(const QString& chatName);

private:
    void setupUi();
    void setupConnections();

    void createChat(const QString& chatName) const;

private:
    QLineEdit* _searchLine{ nullptr };
    QPushButton* _addChatButton{ nullptr };
    QListWidget* _chatListWidget{ nullptr };
};
