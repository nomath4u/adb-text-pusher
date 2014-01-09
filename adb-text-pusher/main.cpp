#include "mainwindow.h"
#include <QApplication>
#include <QtGui>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QCheckBox>
#include "../keypusherobj.h"

const int dkey = 20;

const int lkey = 21;
const int rkey = 22;
const int ukey = 19;


QWidget* setUpGUI();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    /*QPushButton* quitButton = new QPushButton("&Quit");
    QObject::connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(quitButton);
    //w.setLayout(layout);

    QWidget window;
    window.setLayout(layout);*/
    QWidget* window = setUpGUI();
    window->show();

    return a.exec();
}

/*Setup GUI*/
QWidget* setUpGUI(){
    QWidget* window = new QWidget();


     /*Create Widgets*/
     QPushButton* quitButton = new QPushButton("&Quit");
     QObject::connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
     QPushButton* sendButton = new QPushButton("&Send");
     QCheckBox* autoSendBox = new QCheckBox("Send &Message on Text Send");
     QPushButton* cameraButton = new QPushButton("&Camera");
     QPushButton* scriptButton = new QPushButton("&Push Script");
     QPushButton* smsButton = new QPushButton("Launch SMS");
     QPushButton* upButton = new QPushButton("Up");
     upButton->setFixedSize(upButton->sizeHint());
     QPushButton* leftButton = new QPushButton("Left");
     QPushButton* rightButton = new QPushButton("Right");
     QPushButton* downButton = new QPushButton("Down");
     downButton->setFixedSize(upButton->sizeHint());
     QPushButton* enterButton = new QPushButton("Enter");
     QPushButton* backButton = new QPushButton("Back");
     //QSpacerItem *item = new QSpacerItem(1,1)


     QLineEdit* textInput = new QLineEdit("Enter text here");
     KeyPusherObj* pusher = new KeyPusherObj(textInput,autoSendBox);
     QObject::connect(sendButton, SIGNAL(clicked()), pusher,SLOT(sendString()));
     QObject::connect(autoSendBox, SIGNAL(stateChanged(int)),pusher,SLOT(setAutoSendState()));
     QObject::connect(textInput,SIGNAL(returnPressed()),pusher,SLOT(sendString()));
     QObject::connect(cameraButton,SIGNAL(clicked()),pusher,SLOT(takePicture()));
     QObject::connect(scriptButton,SIGNAL(clicked()),pusher,SLOT(pushScript()));
     QObject::connect(smsButton,SIGNAL(clicked()),pusher,SLOT(launchSms()));
     QObject::connect(upButton,SIGNAL(clicked()),pusher,SLOT(sendUKey()));
     QObject::connect(leftButton,SIGNAL(clicked()),pusher,SLOT(sendLKey()));
     QObject::connect(rightButton,SIGNAL(clicked()),pusher,SLOT(sendRKey()));
     QObject::connect(downButton,SIGNAL(clicked()),pusher,SLOT(sendDKey()));
     QObject::connect(enterButton,SIGNAL(clicked()),pusher,SLOT(sendEKey()));
     QObject::connect(backButton,SIGNAL(clicked()),pusher,SLOT(sendBackKey()));



     /*Define the layouts*/
     QVBoxLayout *layout = new QVBoxLayout;
     QHBoxLayout *firstLine = new QHBoxLayout();
     QHBoxLayout *secondLine = new QHBoxLayout();
     QHBoxLayout *thirdLine = new QHBoxLayout();
     QHBoxLayout *fourthLine = new QHBoxLayout();
     firstLine->setAlignment(Qt::AlignLeft);
     //firstLine->insertSpacerItem(item);
     firstLine->insertSpacing(0,upButton->width()/2);
     thirdLine->insertSpacing(0,upButton->width()/2);
     secondLine->addWidget(leftButton);
     secondLine->addWidget(rightButton);
     firstLine->addWidget(upButton);

     thirdLine->addWidget(downButton);
     fourthLine->addWidget(enterButton);
     fourthLine->addWidget(backButton);
     fourthLine->addWidget(sendButton);
     fourthLine->addWidget(cameraButton);
     fourthLine->addWidget(quitButton);
     fourthLine->addWidget(scriptButton);
     fourthLine->addWidget(smsButton);


     secondLine->addWidget(textInput);
     thirdLine->addWidget(autoSendBox);
     layout->addLayout(firstLine);
     layout->addLayout(secondLine);
     layout->addLayout(thirdLine);
     layout->addLayout(fourthLine);

     window->setLayout(layout);

     return window;

}
