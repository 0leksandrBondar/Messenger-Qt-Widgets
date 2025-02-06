#pragma once

#include <QListWidget>

class MessageListWidget final : public QListWidget
{
public:
    explicit MessageListWidget(QWidget* parent = nullptr);

    void addMessage(const QString& message, const QString& filePath, bool isOwnMessage = true);

private:
    void setupUi();
};
