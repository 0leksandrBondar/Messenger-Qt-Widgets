#include "server.h"

#include <QTcpServer>
#include <QTcpSocket>

Server::Server(QObject* parent)
    : QObject(parent), _server{ new QTcpServer }, _clientSocket{ new QTcpSocket }
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

void Server::onNewConnection()
{
    _clientSocket = _server->nextPendingConnection();
    connect(_clientSocket, &QTcpSocket::readyRead, this, &Server::onReadyRead);
    _clientSockets.push_back(_clientSocket);
    qDebug() << "New client connected!";
}

void Server::onReadyRead() const
{
    if (!_clientSocket)
        return;

    const QByteArray data = _clientSocket->readAll();
    const QString message = QString::fromUtf8(data);
    qDebug() << "Received message from client:" << message;
}