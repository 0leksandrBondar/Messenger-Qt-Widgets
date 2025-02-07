#pragma once

#include <QObject>

class QTcpSocket;
class QTcpServer;

struct ClientData
{
    QString name;
    QTcpSocket* socket;
};

class Server final : public QObject
{
    Q_OBJECT

public:
    explicit Server(QObject* parent = nullptr);

private:
    void setupConnections();

    void sendToClient(const QString& receiver, const QByteArray& data) const;

    void onNewConnection();
    void onReadyRead();

private:
    ClientData* _client;
    QTcpServer* _server{ nullptr };
    std::vector<ClientData*> _clients;
};