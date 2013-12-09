#include "mainwindow.h"
#include <QApplication>
#include <QtGui>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QCheckBox>
#include "../keypusherobj.h"

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
     QCheckBox* autoSendBox = new QCheckBox("&Send Message on Text Send");



     QLineEdit* textInput = new QLineEdit("Enter text here");
     KeyPusherObj* pusher = new KeyPusherObj(textInput);
     QObject::connect(sendButton, SIGNAL(clicked()), pusher,SLOT(sendString()));

     /*Define the layouts*/
     QVBoxLayout *layout = new QVBoxLayout;
     layout->addWidget(textInput);
     layout->addWidget(autoSendBox);
     QHBoxLayout *buttons = new QHBoxLayout();
     buttons->addWidget(quitButton);
     buttons->addWidget(sendButton);
     layout->addLayout(buttons);

     window->setLayout(layout);

     return window;

}
