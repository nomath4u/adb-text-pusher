#include "keypusherobj.h"
#include "keypusher.h"

#include <QLineEdit>
#include <QCheckBox>


KeyPusherObj::KeyPusherObj(QLineEdit* boxy,QCheckBox* check)
{
    this->box = boxy;
    this->checky = check;

}


void KeyPusherObj::sendString(){
    send_string(parse_string(this->box->text().toStdString()));
    this->box->setText("");
}

void KeyPusherObj::setAutoSendState(){
    set_TextMode(this->checky->isChecked());
}

void KeyPusherObj::takePicture(){
    take_photo();
}

void KeyPusherObj::pushScript(){
    push_Script();
}

void KeyPusherObj::launchSms(){
    launch_sms();
}

void KeyPusherObj::sendUKey(){
    send_key(19);
}

void KeyPusherObj::sendDKey(){
    send_key(20);
}

void KeyPusherObj::sendLKey(){
    send_key(21);
}

void KeyPusherObj::sendRKey(){
    send_key(22);
}

void KeyPusherObj::sendEKey(){
    send_key(66);
}

void KeyPusherObj::sendBackKey(){
    send_key(4);
}
