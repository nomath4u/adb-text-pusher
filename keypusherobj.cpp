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
    launch_sms("15417882922");
}
