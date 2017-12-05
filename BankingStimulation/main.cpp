#include "ArrayQueue.h"
#include <iostream>
#include <string>
#include<cstdlib>
#include<ctime>
using namespace std;
struct Teller {
	bool free = true;
	int wait_Time=0;
	int arrival_Time = 0;
	int departed_Time = 0;
 };

 

int main() {
	srand(time(0));
	float generateRandNum = float(rand())/ float(RAND_MAX);
	cout << generateRandNum << endl;
	Teller Test;
	ArrayQueue<int> Test2;
	int initCustomers;
	int time = 0;
	cout << "Please enter the intial amount of customers!" << endl;
	cin >> initCustomers;
	cout << initCustomers << " customer(s) have entered at time: " << time << endl;
	time++;
	for (int i = 1; i <= initCustomers; i++)
	{
		cout << "Customer #: " << i << " has entered the queue!" << endl;
		Test2.enqueue(i);
	}
	for (int i = 0; i < 100; i++)
	{
		if (Test.free == true)
		{
			cout << "Customer #: " << Test2.peekFront() << " Has arrived at time: " << time << endl;
			Test2.dequeue();
			Test.free = false;
			Test.arrival_Time = time;
			Test.wait_Time = rand() % 10 + 1;
			time++;
		}
		else if (Test.free == false && Test.wait_Time == 0)
		{
			Test.departed_Time = time;
			cout << "Customer has departed at time: " << Test.departed_Time << endl;
			Test.free = true;
		}
		else
		{
			cout << "At time: " << time << endl;
			cout << "Waiting for teller to be finished..." << endl;
			time++;
			Test.wait_Time--;
			cout << "Time left for Teller to be free: " << Test.wait_Time << endl;
		}


	}

	system("pause");
	return 0;
}


