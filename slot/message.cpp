#include "message.h"

//message::message()
//{

//}

Message::Message() :
    msg("Hello")
{}

Message::Message(const QString &msg) :
    msg(msg)
{}

Message::Message(const QString &msg, const QString &adr) :
    msg(msg),
    address(adr)
{}
