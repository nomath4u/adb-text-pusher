#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QPushButton* test = new QPushButton(this);
    test->move(100,100);
    test->setText(tr("something"));
    QPlainTextEdit* textArea = new QPlainTextEdit(this);
    textArea->move(200,200);





    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
