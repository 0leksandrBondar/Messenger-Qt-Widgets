#include "server.h"

#include "../src/client/ClientNetwork/client.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QTcpServer>
#include <QTcpSocket>

Server::Server(QObject* parent) : QObject(parent), _server{ new QTcpServer }
{
    setupConnections();
    if (_server->listen(QHostAddress::Any, 1234))
        qDebug() << "Server started on port 1234";
    else
        qDebug() << "Failed to start server: " << _server->errorString();
}

void Server::setupConnections()
{
    connect(_server, &QTcpServer::newConnection, this, &Server::onNewConnection);
}

void Server::sendToClient(const QString& receiver, const QByteArray& data) const
{
    for (const auto& client : _clients)
    {
        if (client->name == receiver)
        {
            qDebug() << "sending to client: " << client->name;
            client->socket->write(data);
            client->socket->flush();
        }
        else
        {
            qDebug() << "failed sending to client: " << client->name;
        }
    }
}

void Server::onNewConnection()
{
    auto client = new ClientData;
    client->socket = _server->nextPendingConnection();
    connect(client->socket, &QTcpSocket::readyRead, this, &Server::onReadyRead);
    _clients.push_back(client);
    _client = client;

    qDebug() << "New client connected!";
}

void Server::onReadyRead()
{
    const QByteArray data = _client->socket->readAll();
    const QJsonDocument doc = QJsonDocument::fromJson(data);
    const QJsonObject json = doc.object();

    const QString text = json["text"].toString();
    const QString sender = json["sender"].toString();
    const QString receiver = json["receiver"].toString();

    if (_client->name.isEmpty() && !sender.isEmpty())
        _client->name = sender;

    if (!text.isEmpty() && !receiver.isEmpty())
        sendToClient(receiver, data);

    qDebug() << "Message from:" << _client->name << "to:" << receiver;
    qDebug() << "Text:" << text;
}