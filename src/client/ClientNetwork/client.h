#pragma once

#include <QObject>

class QTcpSocket;

class Client final : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject* parent = nullptr);

    void connectToServer(const QString& ip, const quint16 port) const;

    void sendMessage(const QByteArray& data) const;
    void sendMessage(const QString& message, const QString& filePath) const;

    void setUserName(const QString& userName) { _userName = userName; }
    void setReceiverName(const QString& receiver) { _receiver = receiver; }

signals:
    void messageReceived(const QString& message);

private:
    void setupConnections();

    void onReadyRead() const;

private:
    QString _userName;
    QString _receiver;
    QTcpSocket* _socket{ nullptr };
};