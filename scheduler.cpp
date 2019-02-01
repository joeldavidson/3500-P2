#include "scheduler.h"
#include <iostream>
using namespace std;

scheduler::scheduler(std::string algorithm, std::vector<process> processes)
{
	systemTime = 0;
	totalWaitTime = 0;
	unusedCycles = 0;
	isFinished = false;
	schedulingAlgorithm = algorithm;
	processSchedule = sortIncoming(processes);

}

void scheduler::run() //is destructive at the moment
{
	if (processSchedule.empty())
	{
		cout << "There are no processes to run." << endl;
		return;
	}

	addElem(); //attempts to add an element at t = 0, perhaps not necessary

	process* running;
	while (!ready.empty() || !processSchedule.empty())
	{
		if (!ready.empty()) //if there are programs to be processed in ready
		{
			running = &ready.front();
			if ((*running).timeTillCompletion > 0)
			{
				if ((*running).timeBegan == -1)
					(*running).timeBegan = systemTime;

				cout << "<sytem time " << systemTime << "> process " << (ready.front()).ID << " is running." << endl;
				(*running).timeTillCompletion--;
				//add stats
				systemTime++;
			}
			else
			{
				cout << "<sytem time " << systemTime << "> process " << (ready.front()).ID << " is finished....." << endl;
				//add time finished

				ready.erase(ready.begin());
			}
			
			addElem(); //checks if a new process is added to the readyQ
		}
		else //if there is nothing on the readyQ
			wait();
	}
}


std::vector<process> scheduler::sortIncoming(std::vector<process> processList)
{
	int size = processList.size();
	int lowestTimeIndex = processList[0].arrivalTime;
	std::vector<process>* orderedProcesses = new std::vector<process>;
	for (int i = 0; i < size; i++)
	{
		int elemIndex = 0;
		for (process elem : processList)
		{
			if (elem.arrivalTime < processList[lowestTimeIndex].arrivalTime)
				lowestTimeIndex = elemIndex;

			elemIndex++;
		}
		(*orderedProcesses).emplace_back(processList[lowestTimeIndex]);
		processList.erase(processList.begin() + lowestTimeIndex);
	}
	return (*orderedProcesses);
}

void scheduler::addElem()
{
	if (processSchedule.empty())
		return;
	process curr = processSchedule.front();
	if (curr.arrivalTime == systemTime)
	{
		if (schedulingAlgorithm == "FCFS")
			addFCFS();
		else if (schedulingAlgorithm == "SRTF")
			addSRTF();
		else
			addRR();
	}
}

void scheduler::addRR()
{
	addFCFS(); //placeholder
}

void scheduler::addSRTF()
{
	addFCFS(); //placeholder
}

void scheduler::addFCFS()
{
	while (!processSchedule.empty() && (processSchedule.front().arrivalTime == systemTime))
	{
		process newProcess = processSchedule.front();
		ready.push_back(newProcess);
		processSchedule.erase(processSchedule.begin());
	}
}
void scheduler::wait()
{
	while (ready.empty())
	{
		if ((processSchedule.front()).arrivalTime == systemTime)
			addElem();
		else
		{
			unusedCycles++;
			systemTime++;
		}

	}
}
scheduler::~scheduler()
{

}
