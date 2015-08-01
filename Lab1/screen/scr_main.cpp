// Exercising the Screen class
#include "screen.h"
#include <iostream>

using namespace std;

int main()
{
    Screen myScreen{6,6};

    myScreen.set(' ');
    myScreen.forward();
    myScreen.set('*');
    myScreen.forward();
    myScreen.set('*');
    myScreen.forward();
    myScreen.set('*');
    myScreen.forward();
    myScreen.set('*');
    myScreen.forward();
    myScreen.set('*');
    myScreen.move(2,1);
    myScreen.set('*');
    myScreen.forward();
    myScreen.set(' ');
    myScreen.forward();
    myScreen.set(' ');
    myScreen.forward();
    myScreen.set(' ');
    myScreen.forward();
    myScreen.set(' ');
    myScreen.forward();
    myScreen.set(' ');
    myScreen.move(3,1);
    myScreen.set('*');
    myScreen.forward();
    myScreen.set(' ');
    myScreen.forward();
    myScreen.set(' ');
    myScreen.forward();
    myScreen.set(' ');
    myScreen.forward();
    myScreen.set(' ');
    myScreen.forward();
    myScreen.set(' ');
    myScreen.move(4,1);
    myScreen.set('*');
    myScreen.forward();
    myScreen.set(' ');
    myScreen.forward();
    myScreen.set(' ');
    myScreen.forward();
    myScreen.set(' ');
    myScreen.forward();
    myScreen.set(' ');
    myScreen.forward();
    myScreen.set(' ');
    myScreen.move(5,1);
    myScreen.set('*');
    myScreen.forward();
    myScreen.set(' ');
    myScreen.forward();
    myScreen.set(' ');
    myScreen.forward();
    myScreen.set(' ');
    myScreen.forward();
    myScreen.set(' ');
    myScreen.forward();
    myScreen.set(' ');
    myScreen.move(6,1);
    myScreen.set(' ');
    myScreen.forward();
    myScreen.set('*');
    myScreen.forward();
    myScreen.set('*');
    myScreen.forward();
    myScreen.set('*');
    myScreen.forward();
    myScreen.set('*');
    myScreen.move(Direction::Forward);
    myScreen.set('*');
    myScreen.move(6,4);
    myScreen.down();
    myScreen.set('%');
    myScreen.move(1,2);
    myScreen.up();
    myScreen.set('@');


    myScreen.display();
    cout << endl << endl << endl;

    cout << "Testing drawSquare" << endl;
    myScreen.reSize(16,16);
    myScreen.drawSquare(8,4,5);
    myScreen.display();

    return 0;
}
