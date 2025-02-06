#pragma once

#include <QWidget>

class QPushButton;

class InputMessageField;

class InputMessageWidget final : public QWidget
{
    Q_OBJECT
public:
    explicit InputMessageWidget(QWidget* parent = nullptr);

    void onSendButtonClicked();
    void onFileButtonClicked();

signals:
    void sendMessage(const QString& message, const QString& filePath);

private:
    void setupUi();
    void setupLayout();
    void setupConnections();

private:
    QString _filePath;
    QPushButton* _sendButton{ nullptr };
    QPushButton* _fileButton{ nullptr };
    InputMessageField* _inputMessageField{ nullptr };
};
