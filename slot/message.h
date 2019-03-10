#ifndef MESSAGE_H
#define MESSAGE_H
#include <QString>

class Message
{
public:
    Message();
    Message(const QString &msg);
    Message(const QString &msg, const QString &adr);

    QString body()
    {
        return msg;
    }

    QString getAddress()
    {
        return address;
    }

private:
    QString address;
    QString msg;
};

#endif // MESSAGE_H
