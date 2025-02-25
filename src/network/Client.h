#pragma once

#include "boost/asio.hpp"

class Client
{
public:
    Client();

    static void startReceivingDataFromServer();
    bool connectToServer(const std::string& ip, int port);

    void sendDataToServer(const std::string& data);

private:
    static void receiveDataFromServer();

private:
    boost::asio::io_context _ioContext;
    boost::asio::ip::tcp::socket _socket;
    boost::asio::ip::tcp::resolver _resolver;
};