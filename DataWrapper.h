#ifndef DataWrapper_H
#define DataWrapper_H

#include <QByteArray>
#include <QJsonObject>

class DataWrapper
{
public:
    DataWrapper();

    static QByteArray Encrypt(QByteArray input);
    
private:
};


class MySqlWrapper;
class pSql
{
public:
    static MySqlWrapper* Ptr();
private:
    pSql(){}
    MySqlWrapper* m_MysqlWrapper = NULL;
};


#endif // DataWrapper_H
