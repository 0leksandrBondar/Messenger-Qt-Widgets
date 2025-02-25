#include "Client.h"

#include <iostream>

Client::Client() : _ioContext(), _socket(_ioContext), _resolver(_ioContext) {}

void Client::startReceivingDataFromServer() { std::thread(receiveDataFromServer).detach(); }

bool Client::connectToServer(const std::string& ip, int port)
{
    try
    {
        boost::asio::connect(_socket, _resolver.resolve(ip, std::to_string(port)));
        std::cout << "Connection to server is successful!" << std::endl;
        startReceivingDataFromServer();
        return true;
    }
    catch (const boost::system::system_error& e)
    {
        std::cerr << "Connection to server is failed: " << e.what() << std::endl;
        return false;
    }
}

void Client::sendDataToServer(const std::string& data)
{
    boost::asio::write(_socket, boost::asio::buffer(data, data.size()));
}

void Client::receiveDataFromServer()
{
    while (true)
    {
        // boost::asio::streambuf buffer;
        // boost::asio::read_until(socket, buffer, "\n");
        // std::istream is(&buffer);
        // std::string message;
        // std::getline(is, message);
        // std::cout << "Server: " << message << "\n";
    }
}
