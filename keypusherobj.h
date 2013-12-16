#ifndef KEYPUSHEROBJ_H
#define KEYPUSHEROBJ_H
#include <QObject>
#include <QLineEdit>
#include <QCheckBox>

class KeyPusherObj : public QObject
{
    Q_OBJECT
public:
    KeyPusherObj(QLineEdit*, QCheckBox*);


public slots:
    void sendString();
    void setAutoSendState();

private:
    QLineEdit* box;
    QCheckBox* checky;
    
};
#endif // KEYPUSHEROBJ_H
