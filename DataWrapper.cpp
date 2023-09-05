#include "DataWrapper.h"
#include <QJsonDocument>
#include <QDebug>
#include "easylogging++.h"
#include <QCryptographicHash>
#include "qaesencryption.h"

QByteArray EncryptTest();

DataWrapper::DataWrapper()
{

}

QByteArray DataWrapper::Encrypt(QByteArray input)
{
#if 1
    //QByteArray toEc = "AES,高级加密标准（英语：Advanced Encryption Standard，缩写：AES），在密码学中又称Rijndael加密法，是美国联邦政府采用的一种区块加密标准。这个标准用来替代原先的DES，已经被多方分析且广为全世界所使用。严格地说，AES和Rijndael加密法并不完全一样（虽然在实际应用中二者可以互换），因为Rijndael加密法可以支持更大范围的区块和密钥长度：AES的区块长度固定为128 比特，密钥长度则可以是128，192或256比特；而Rijndael使用的密钥和区块长度可以是32位的整数倍，以128位为下限，256比特为上限。包括AES-ECB,AES-CBC,AES-CTR,AES-OFB,AES-CFB";
    QString key("1234567890210210");        //key must be 16 byte - 128 bit
    //QString key("aaaaaaaaaaaaaaaa");        //key must be 16 byte - 128 bit
    QAESEncryption encryption(QAESEncryption::AES_128, QAESEncryption::ECB, QAESEncryption::Padding::PKCS7);
#else
    QString key("12345678901234561234567890123456");        //key must be 32 byte - 256 bit
    QAESEncryption encryption(QAESEncryption::AES_256, QAESEncryption::ECB, QAESEncryption::Padding::PKCS7);
#endif
    QByteArray hashKey = key.toUtf8();
    //QByteArray hashKey = QCryptographicHash::hash(key.toUtf8(), QCryptographicHash::Sha256);
    QByteArray encodedArray = encryption.encode(input, hashKey);
    //qDebug() << encodedArray.toBase64() << " \n\n\n\n";
    //QByteArray decodedArray = encryption.decode(encodedArray, hashKey);
    //qDebug() << decodedArray.toStdString().c_str() << " \n\n\n\n";


    //QByteArray _toEc = encryption.encode(toEc, hashKey);
    //LOG(INFO) << LogParam(_toEc.toHex().toStdString());

    return encodedArray;
}



QByteArray EncryptTest()
{
    std::string b16Input = "b16Input";
    std::string b64Input = "b64Input";
    std::string hexKey = "hexKey";

    LOG(INFO) << b16Input.c_str() << " \n" << b64Input.c_str() << " \n" << b16Input.c_str() << " \n\n\n\n";

    /*
    //unsigned char plain[] = { 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff }; //plaintext example
    //unsigned char key[] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f }; //key example
    //unsigned int plainLen = 16 * sizeof(unsigned char);  //bytes in plaintext

    //AES aes(AESKeyLength::AES_128);  ////128 - key length, can be 128, 192 or 256
    //uchar* c = aes.EncryptECB(plain, plainLen, key);


    //QString _a = "1234567890123456123";
    //QString _key = "1234567890123456";
    //unsigned char _iv[] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    //    0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    //    0xff, 0xff, 0xff, 0xff };
    //aes.EncryptCFB((uchar*)_a.data(), _a.size(), (uchar*)_key.data(), _iv);
    //QByteArray _array = QByteArray::fromRawData((char*)c, plainLen);


    //QAESEncryption encryption(QAESEncryption::AES_256, QAESEncryption::ECB);

    //QString inputStr("The Advanced Encryption Standard (AES), also known by its original name Rijndael "
    //    "is a specification for the encryption of electronic data established by the U.S. "
    //    "National Institute of Standards and Technology (NIST) in 2001");	
	//QString outputStr("VTJGc2RHVmtYMStxc3oxNld3YVlpYmV3aElsWCs0VXhid2RrM1g0U3JpRlZKZFFDRHcwanRNdWluNDlUdTN5YQpaSmd3b2ZYcVFzUkczRThsWEtnMnVKL1JzZzhTaVFKdW5xTjhacEJKbC9ZWklOZnM5TTJLbXJSbEw2OE95cC9nClI3RVVuR3JLSlBWalJhMjhJOHpDL1BBSVg5NXBmdzEvekJsT1ZSbWsvT3FaWEoxUUlPdVN1U2szLzJkQmNSemUKYzdwNGREcTd6bkpIWVRrT3kwZk5HVEtEZWxJYXB4b0R6d2JueUVxYk5OaXZkekM1bHBSZUZ5ckgrYXp4ckhPNQpIOVo5NWZuMmNXNzF4TkNyM2VvOURmUno4NDMwUFcyekdQSUhra0NuRGdSMFM4RVZQT0N3eitCczhtT2lpUFBBCmpQa0tMRzZzRzY0VUxlZGlxOEFwVHQ2QlVzTG1zVTdzQXhvZHp1dlNsTHc0TmZWQThmazlYRnBKYU1LSHRLMTEKdmJTMktUclI3c201RE5XK2RJcHZqdTBkTllWOFpZclhncFh1VTNRNWlLdz0=");
    //QString key("your-string-key");
    //QString iv("your-IV-vector");

    //QByteArray hashKey = QCryptographicHash::hash(key.toLocal8Bit(), QCryptographicHash::Sha256);
    //QByteArray hashIV = QCryptographicHash::hash(iv.toLocal8Bit(), QCryptographicHash::Md5);

    //QByteArray encodeText = encryption.encode(inputStr.toLocal8Bit(), hashKey, hashIV);
    //qDebug() << encodeText.toBase64() << " \n\n\n\n";
    //QByteArray decodeText = encryption.decode(encodeText, hashKey, hashIV);
    //qDebug() << decodeText.toStdString().c_str() << " \n\n\n\n";

    //QString decodedString = QString(encryption.removePadding(decodeText));
    */

    QString inputStr("nihao");
    //QString inputStr("The Advanced Encryption Standard (AES), also known by its original name Rijndael is a specification for the encryption of electronic data established by the U.S. National Institute of Standards and Technology(NIST) in 20012");
    
    //QString key("12345678901234561234567890123456");        //32-Sha256
    //QAESEncryption encryption(QAESEncryption::AES_256, QAESEncryption::ECB);
    
    {
        QString key("1234567890123456");        //32-Sha256
        QAESEncryption encryption(QAESEncryption::AES_128, QAESEncryption::ECB);

        QByteArray hashKey = key.toUtf8();
        //QByteArray hashKey = QCryptographicHash::hash(key.toUtf8(), QCryptographicHash::Sha256);
        LOG(INFO) << QString(inputStr).toUtf8().toStdString() << " \n\n\n\n";
        QByteArray encodedText = encryption.encode(inputStr.toUtf8(), hashKey);
        LOG(INFO) << encodedText.toBase64().toStdString() << " \n\n\n\n";
        //qDebug() << encodedText << " \n\n\n\n";
        QByteArray decodedText = encryption.decode(encodedText, hashKey);
        LOG(INFO) << decodedText.toStdString().c_str() << " \n\n\n\n";
    }
    {
        QString key("123456789012345612345678");        //32-Sha256
        QAESEncryption encryption(QAESEncryption::AES_256, QAESEncryption::CBC);

        QByteArray hashKey = key.toUtf8();
        //QByteArray hashKey = QCryptographicHash::hash(key.toUtf8(), QCryptographicHash::Sha256);
        LOG(INFO) << QString(inputStr).toUtf8().toStdString() << " \n\n\n\n";
        QByteArray encodedText = encryption.encode(inputStr.toUtf8(), hashKey);
        LOG(INFO) << encodedText.toBase64().toStdString() << " \n\n\n\n";
        //qDebug() << encodedText << " \n\n\n\n";
        QByteArray decodedText = encryption.decode(encodedText, hashKey);
        LOG(INFO) << decodedText.toStdString().c_str() << " \n\n\n\n";
    }
    {
        QString key("1234567890123456");        //32-Sha256
        QAESEncryption encryption(QAESEncryption::AES_128, QAESEncryption::CBC);
        QString iv = ("1234567890123456");
        QByteArray hashIV = QCryptographicHash::hash(iv.toLocal8Bit(), QCryptographicHash::Md5);

        QByteArray hashKey = key.toUtf8();
        //QByteArray hashKey = QCryptographicHash::hash(key.toUtf8(), QCryptographicHash::Sha256);
        LOG(INFO) << QString(inputStr).toUtf8().toStdString() << " \n\n\n\n";
        QByteArray encodedText = encryption.encode(inputStr.toUtf8(), hashKey, hashIV);
        LOG(INFO) << encodedText.toBase64().toStdString() << " \n\n\n\n";
        LOG(INFO) << QString(encodedText).toStdString() << " \n\n\n\n";
        //qDebug() << encodedText << " \n\n\n\n";
        QByteArray decodedText = encryption.decode(encodedText, hashKey, hashIV);
        LOG(INFO) << decodedText.toStdString().c_str() << " \n\n\n\n";
        LOG(INFO) << QString::fromUtf8(decodedText).toStdString().c_str() << " \n\n\n\n";
    }
    {
        QString key("123456789012345612345678");        //32-Sha256
        QAESEncryption encryption(QAESEncryption::AES_128, QAESEncryption::ECB);

        QByteArray hashKey = key.toUtf8();
        //QByteArray hashKey = QCryptographicHash::hash(key.toUtf8(), QCryptographicHash::Sha256);
        LOG(INFO) << QString(inputStr).toUtf8().toStdString() << " \n\n\n\n";
        QByteArray encodedText = encryption.encode(inputStr.toUtf8(), hashKey);
        LOG(INFO) << encodedText.toBase64().toStdString() << " \n\n\n\n";
        //qDebug() << encodedText << " \n\n\n\n";
        QByteArray decodedText = encryption.decode(encodedText, hashKey);
        LOG(INFO) << decodedText.toStdString().c_str() << " \n\n\n\n";
    }


    return NULL;
}

#include "MySqlWrapper.h"
MySqlWrapper* pSql::Ptr()
{
    static MySqlWrapper* _tmp = new MySqlWrapper();
    return _tmp;
}



