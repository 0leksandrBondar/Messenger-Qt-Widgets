#include "jsonpackage.h"

#include <QJsonDocument>
#include <QJsonObject>

JsonPackage::JsonPackage(const PackageData& data) {}

QByteArray JsonPackage::packageDataToByteArray(const PackageData& data)
{
    QJsonObject json;

    json["text"] = data.text;
    json["sender"] = data.sender;
    json["receiver"] = data.receiver;

    return QJsonDocument(json).toJson();
}

PackageData JsonPackage::byteArrayToPackageData(const QByteArray& data)
{
    return {};
}