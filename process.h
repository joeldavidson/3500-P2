#ifndef PROCESS_H
#define PROCESS_H

struct process
{
public:
	int ID;
	int arrivalTime; //use timeBegan - waitTime to figure out waitTime
	int burstTime; 
	int timeBegan; 
	int timeFinished;
	int waitTime;
	int turnAroundTime; //calculate through timeFinished - arrivalTime
	int timeTillCompletion;
	process();
	
};

#endif