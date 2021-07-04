#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <QWidget>
#include <QKeyEvent>
#include <iostream>
using namespace std;
class Keyboard
{

public:

    static Keyboard* KeyboardSingleton;
    static Keyboard& GetInstance();
    QString DisplayData(QString Data ,int key );
    void closeApplication();

protected:

  Keyboard() = default;

private:
//-----Delete copy/move so extra instances can't be created/moved----//
 Keyboard(const Keyboard&) = delete;
 Keyboard& operator=(const Keyboard&) = delete;
 Keyboard(Keyboard&&) = delete;
 Keyboard& operator=(Keyboard&&) = delete;
};

#endif // KEYBOARD_H
