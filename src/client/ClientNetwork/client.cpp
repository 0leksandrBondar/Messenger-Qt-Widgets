#include "client.h"

#include "package/jsonpackage.h"

#include <QTcpSocket>

Client::Client(QObject* parent) : QObject(parent), _socket{ new QTcpSocket } { setupConnections(); }

void Client::connectToServer(const QString& ip, const quint16 port) const
{
    _socket->connectToHost(ip, port);
}

void Client::sendMessage(const QString& message, const QString& filePath) const
{
    if (_socket->state() != QAbstractSocket::ConnectedState)
    {
        qDebug() << "Not connected to server!";
        return;
    }

    const PackageData packageData(message, _userName, _receiver);
    const QByteArray data = JsonPackage::packageDataToByteArray(packageData);

    _socket->write(data);
    _socket->flush();
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
