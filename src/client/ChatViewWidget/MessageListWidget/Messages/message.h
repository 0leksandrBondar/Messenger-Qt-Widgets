#pragma once

#include <QWidget>

class QLabel;
class Message final : public QWidget
{
public:
    explicit Message(const QString& message, const QString& filePath, bool isOwnMessage = true,
                     QWidget* parent = nullptr);

private:
    void composeMessageWidget();

private:
    bool _isOwnMessage{ true };

    QPixmap _pixmap{};
    QLabel* _label{ nullptr };
    QLabel* _imageLabel{ nullptr };
};