#include "StopWatch.h"
#include <iostream>

using namespace std;

int main()
{
    StopWatch sw;

    cout << "Starting..." << endl;
    sw.start();
    for (int i = 0; i < 99000000; i++)
    {
        double a, b = 2323.23;
        double c = (a*b*b*a*a*a*b);
        a = c;
    }
    double seconds = sw.stop();

    cout << "Code took " << seconds << " seconds to run" << endl;
}
