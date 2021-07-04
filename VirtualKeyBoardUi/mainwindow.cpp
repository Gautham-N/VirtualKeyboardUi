#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "string"
#include<QKeyEvent>
#include<QString>
#include<QEvent>
#include<iostream>
#include<keyboard.h>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->installEventFilter(this);
}

QSet<int> PressedKeys;
static Keyboard &KeyBrdObj= Keyboard::GetInstance();

//--------Event generated and respective action taken on key press------//
bool MainWindow::eventFilter(QObject * obj, QEvent * event)
{
    if(event->type()==QEvent::KeyPress)
    {
        PressedKeys += ((QKeyEvent*)event)->key();
        string str=((QKeyEvent*)event)->text().toStdString();
        ui->label_Data->setText(KeyBrdObj.DisplayData(QString::fromStdString(str),((QKeyEvent*)event)->key()));
        if( PressedKeys.contains(Qt::Key_Q) && PressedKeys.contains(Qt::Key_Control) )
        {
            KeyBrdObj.closeApplication();
        }
    }
    else if(event->type()==QEvent::KeyRelease)
    {
        PressedKeys -= ((QKeyEvent*)event)->key();
    }
    return false;
}


MainWindow::~MainWindow()
{
    delete ui;
}

