#pragma once

#include <QString>

struct PackageData
{
    QString text;
    QString sender;
    QString receiver;
};

class JsonPackage
{
public:
    explicit JsonPackage(const PackageData& data);

    static QByteArray packageDataToByteArray(const PackageData& data);
    static PackageData byteArrayToPackageData(const QByteArray& data);
};