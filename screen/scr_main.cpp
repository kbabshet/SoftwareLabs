// Exercising the Screen class
#include "screen.h"
#include <iostream>

using namespace std;

int main()
{
	Screen myScreen{6,6};

	myScreen.forward();
	myScreen.set('*');
	myScreen.down();
	myScreen.set('*');
	myScreen.move(3,3);
	myScreen.set("---");
        myScreen.drawSquare(1,1,4);

	myScreen.display();
	cout << endl;

	myScreen.reSize(16,16);
	myScreen.display();
	myScreen.clear(' ');

	myScreen.move(7,7);
	myScreen.set("BIG");
	myScreen.move(8,5);
	myScreen.set("SCREEN");
	myScreen.display();

        //myScreen.drawSquare(1,2,16);
        //myScreen.display();

	return 0;
}

