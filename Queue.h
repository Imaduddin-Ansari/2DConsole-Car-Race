//ImaduddinAnsari_22I-2446 WaleedAbdullah_22I-2714
//All functionality defined in the project report attached.
#pragma once
#include <iostream>
#include<string>
using namespace std;

class NodeQ {            // to keep track of obstacles in the grid
public:
	char obstacle;
	NodeQ* next;
};

class Queue {
private:
	NodeQ* front;
	NodeQ* rear;
public:
	Queue()
	{
		front = NULL;
		rear = NULL;
	}
	void enqueue(char x)                          // to add an obstacle into the queue
	{
		NodeQ* temp = new NodeQ;
		temp->obstacle = x;
		temp->next = NULL;
		if (front == NULL && rear == NULL)
		{
			front = temp;
			rear = front;
		}
		else
		{
				rear->next = temp;
				rear = rear->next;
		}
	}
	void dequeue()                          // to remove an obstacle from the queue
	{
		if (front == NULL && rear == NULL)
		{
			cout << "Queue is Empty" << endl;
		}
		else
		{
			NodeQ* temp = front;
			if (front->next == NULL)
			{
				front = NULL;
				rear = NULL;
			}
			else
			{
				front = front->next;
				delete temp;
			}
		}
	}
	char showFront()                           // to show thte last obsatcle that is present in the queue
	{
		return front->obstacle;
	}
	bool isEmpty()                                // to check if the queue is emptry or not
	{
		if (front == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};