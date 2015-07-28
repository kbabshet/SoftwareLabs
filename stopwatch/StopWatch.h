#ifndef STOPWATCH_H
#define STOPWATCH_H

/*
 * A simple stopwatch that can be used to time how long a section of code takes
 * to run.
 * The stopwatch should be started by calling StopWatch::start just before the
 * section of code to be timed. StopWatch::stop returns the time taken in
 * seconds and should be called immediately after the section of code. 
 * StopWatch::stop can only be called once after StopWatch::start
 */

class StopWatch
{
public:
    void start();
    double stop();

private:
    double startTime;
    bool running = false;
    // returns the amount of time in seconds that has passed since the process (i.e. your program) started executing 
    double getProcessTime();
};

#endif
