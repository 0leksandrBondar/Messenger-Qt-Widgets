#pragma once

#include <QObject>

class QTcpSocket;
class QTcpServer;

class Server final : public QObject
{
    Q_OBJECT

public:
    explicit Server(QObject* parent = nullptr);

private:
    void setupConnections();

    void onNewConnection();
    void onReadyRead() const;

private:
    QTcpServer* _server{ nullptr };
    QTcpSocket* _clientSocket{ nullptr };
    std::vector<QTcpSocket*> _clientSockets;
};