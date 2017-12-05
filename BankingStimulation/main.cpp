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
	float generateRandNum;
	float probibilty = float(rand()) / float(RAND_MAX);
	int showTime;
	Teller Test;
	ArrayQueue<int> Test2;
	int Customers, total_waitTime = 0;
	int time = 0;
	cout << "Enter the time customer to arrive" << endl;
	cin >> showTime;
	cout << "Please enter the intial amount of customers!" << endl;
	cin >> Customers;
	cout << Customers << " customer(s) have entered at time: " << time << endl;
	time++;
	for (int i = 1; i <= Customers; i++)
	{
		cout << "Customer #: " << i << " has entered the queue!" << endl;
		Test2.enqueue(i);
	}
	for (int i = 0; i <15; i++)
	{
		generateRandNum = float(rand()) / float(RAND_MAX);
		if (time % showTime == 0)
		{
			if (generateRandNum >= probibilty)
				Customers++;
			cout << "Customer has arrived at " << time << endl;
		}
		if (Test.free == true && Customers>0)
		{
			cout << "At time: "<<time<< " Customer #: " << Test2.peekFront() << " Has arrived to the teller"  << endl;
			Test2.dequeue();
			Customers--;
			Test.free = false;
			Test.arrival_Time = time;
			Test.wait_Time = rand() % 10 + 1;
			total_waitTime += Test.wait_Time;
			time++;
		}
		else if (Test.free == false && Test.wait_Time == 0)
		{
			Test.departed_Time = time;
			cout << "Customer has departed at time: " << Test.departed_Time << endl;
			Test.free = true;
			time++;
		}
		else
		{
			if (Customers > 0)
			{
				cout << "At time: " << time << ": " << Customers << " customers are waiting. Wait Time: " << Test.wait_Time << endl;
				time++;
				Test.wait_Time--;
			}
			else
			{
				cout << "At time: " << time << " There are no customers at this time" << endl;
				time++;
			}
		}


	}
	cout << endl;
	cout <<"Average wait time:"<< total_waitTime << endl;

	system("pause");
	return 0;
}


