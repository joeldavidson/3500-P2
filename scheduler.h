#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <string>
#include <vector>
#include "process.h"
using namespace std::string_literals;

class scheduler
	//The scheduler is responsible for executing and printing the state of a process
	// to the console. It will hold a PCB-like data structure that will be populated
	//by the appropriate scheduling algorithm.
{
private:
	int systemTime;
	int totalWaitTime;
	int unusedCycles;
	bool isFinished;
	std::string schedulingAlgorithm;
	std::vector<process> processSchedule;
	std::vector<process> ready;
	
	std::vector<process> sortIncoming(std::vector<process> processes);
	void addFCFS();
	void addRR();
	void addSRTF();
	void addElem();
	void wait();

public:
	void run();
	scheduler(std::string schedulingAlgorithm, std::vector<process> processList);
	~scheduler();
};

#endif
