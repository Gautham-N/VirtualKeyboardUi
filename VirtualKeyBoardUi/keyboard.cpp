#include "keyboard.h"
#include <QCoreApplication>

Keyboard* Keyboard::KeyboardSingleton =nullptr;

//----------Creating single instance-------------//
Keyboard &Keyboard::GetInstance()
{
    if(KeyboardSingleton==nullptr)
    {
           KeyboardSingleton = new Keyboard();
    }
    return *KeyboardSingleton;
}

QString Globaldata="";

//----Store data and display when enter pressed-----//
QString Keyboard::DisplayData(QString Data ,int key )
{
    try
    {
       Globaldata+=Data;
       if(key==Qt::Key_Enter || key==Qt::Key_Return)
       {
           return Globaldata;
       }
       else
       {
           return "";
       }
    }
    catch (...)
    {
       cout<<"Exception during Display"<<endl;
       return "";
    }
}

//-----------Closing the Application---------------//
void Keyboard::closeApplication()
{
    try
    {
       QCoreApplication::quit();
    }
    catch (...)
    {
        cout<<"Execption in Application closing"<<endl;
    }
}
