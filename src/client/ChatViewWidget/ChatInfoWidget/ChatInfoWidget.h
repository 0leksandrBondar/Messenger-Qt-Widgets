#pragma once

#include <QWidget>

class QLabel;

class ChatInfoWidget final : public QWidget
{
public:
    ChatInfoWidget(QWidget* parent = nullptr);

    void changeChatInfo(const QString& clientName);

private:
    void setupUi();

private:
    QLabel* _clientName{ nullptr };
};