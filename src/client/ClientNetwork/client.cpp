#include "client.h"

#include <QTcpSocket>

Client::Client(QObject* parent) : QObject(parent), _socket{ new QTcpSocket } { setupConnections(); }

void Client::connectToServer(const QString& ip, const quint16 port) const
{
    _socket->connectToHost(ip, port);
}

void Client::sendMessage(const QString& message, const QString& filePath) const
{
    if (_socket->state() == QAbstractSocket::ConnectedState)
    {
        _socket->write(message.toUtf8());
        _socket->flush();
    }
    else
    {
        qDebug() << "Not connected to server!";
    }
}

void Client::setupConnections()
{
    connect(_socket, &QTcpSocket::readyRead, this, &Client::onReadyRead);
}

void Client::onReadyRead() const
{
    const QByteArray data = _socket->readAll();
    qDebug() << data;
}
