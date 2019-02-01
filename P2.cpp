#include "process.h"
#include "scheduler.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;
//Main will take input from the argument array and parse it into commands. Those commands will then be passed to a scheduler, along with the
//type of scheduling algorithm to be implemented.

void argChecker(int argc, char* argV[], string &fileName, string& type, int& quantum);
vector<process> fileParser(string fileName);

int main(int argc, char *argV[])
{
	string fileName = "input1.txt";
	string type = "FCFS"; 
	int quantum;
	//argChecker(argc, argV, fileName, type, quantum);
	vector<process> processes = fileParser(fileName);

	scheduler* sched = new scheduler(type, processes); //not compatible with RR
	(*sched).run();//this looks weird


}

void argChecker(int argc, char *argV[], string &fileName, string& type, int& quantum)
{
	if (argc == 4)
		quantum = atoi(argV[3]);
	else if (argc == 3 || argc == 4)
	{
		fileName = argV[1];
		type = argV[2];
	}
	else
	{
		cout << "Error: Improper number of arguments given" << endl;
		exit(1);
	}
	
}

vector<process> fileParser(string fileName)
//reads files and returns vector of processes where each int[] holds the [pid, arrivalTime, burstTime] for the scheduler
{
	ifstream infile(fileName);
	int pid, arrivalTime, runTime;
	vector<process> holder;
	int i = 0;
	while (infile >> pid >> arrivalTime >> runTime)
	{
		process* in = new process();
		in->ID = pid;
		in->arrivalTime = arrivalTime;
		in->burstTime = runTime;
		in->timeTillCompletion = runTime;
		holder.push_back(*in);
		delete in;
	}
	cout << holder.size();
	infile.close();
	return holder;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

