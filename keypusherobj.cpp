#include "keypusherobj.h"
#include "keypusher.cpp"
#include <QLineEdit>


KeyPusherObj::KeyPusherObj(QLineEdit* boxy)
{
    this->box = boxy;
}


void KeyPusherObj::sendString(){
    send_string(parse_string(this->box->text().toStdString()));
}

