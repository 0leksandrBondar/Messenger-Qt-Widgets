#include "client.h"

#include "package/jsonpackage.h"

#include <QJsonDocument>
#include <QJsonObject>
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

void Client::onReadyRead()
{
    qDebug() << "Client::onReadyRead()";
    const QByteArray data = _socket->readAll();
    const QJsonDocument doc = QJsonDocument::fromJson(data);
    const QJsonObject json = doc.object();

    const QString text = json["text"].toString();
    emit messageReceived(text);
    qDebug() << data;
}
