#include "keypusherobj.h"
#include "keypusher.cpp"
#include <QLineEdit>
#include <QCheckBox>


KeyPusherObj::KeyPusherObj(QLineEdit* boxy,QCheckBox* check)
{
    this->box = boxy;
    this->checky = check;

}


void KeyPusherObj::sendString(){
    send_string(parse_string(this->box->text().toStdString()));
}

void KeyPusherObj::setAutoSendState(){
    set_TextMode(this->checky->isChecked());
}

