#pragma once

#include <QObject>

class QTcpSocket;

class Client final : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject* parent = nullptr);

    void connectToServer(const QString& ip, const quint16 port) const;

    void sendMessage(const QString& message, const QString& filePath) const;

signals:
    void messageReceived(const QString& message);

private:
    void setupConnections();

    void onReadyRead() const;

private:
    QTcpSocket* _socket{ nullptr };
};