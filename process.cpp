#include "process.h"

process::process()
{
	ID = 0;
	arrivalTime = 0; //
	burstTime = 0; //may end up not being used, is equivalent to "timeTillCompletion"
	timeBegan = -1; //
	timeFinished = -1; //
	turnAroundTime = 0; //
	timeTillCompletion = 0;
}

