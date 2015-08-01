#include "StopWatch.h"
#include <ctime>
#include <iostream>

using namespace std;

void StopWatch::start()
{
    startTime = getProcessTime();
    running = true;
}

double StopWatch::stop()
{
    if (!running) {
        cerr << "StopWatch must be running before it can be stopped" << endl;
        return -1.;
    }

    running = false;
    return getProcessTime() - startTime;
}

// returns the amount of time in seconds that has passed since the process (i.e. your program) started executing 
double StopWatch::getProcessTime()
{
	clock_t time = clock();
	return static_cast<double>(time)/CLOCKS_PER_SEC;
}
