#ifndef KEYPUSHEROBJ_H
#define KEYPUSHEROBJ_H
#include <QObject>
#include <QLineEdit>

class KeyPusherObj : public QObject
{
    Q_OBJECT
public:
    KeyPusherObj(QLineEdit*);


public slots:
    void sendString();

private:
    QLineEdit* box;
    
};
#endif // KEYPUSHEROBJ_H
