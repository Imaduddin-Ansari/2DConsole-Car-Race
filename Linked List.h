//ImaduddinAnsari_22I-2446 WaleedAbdullah_22I-2714
//All functionality defined in the project report attached.
#pragma once
#include <iostream>
#include<string>
using namespace std;

class NodeL {                                  //To keep track of the achievemnts oif the player
public:
	char Achievements;
	NodeL* next;
	NodeL()
	{
		Achievements = '/0';
		next = NULL;
	}
};

class LinkedList {
private:
	NodeL* Head;
public:
	LinkedList()
	{
		Head = nullptr;
	}
	void insert(char x)   
	{                                                   //To add a new achievemnt for the player
		NodeL* last = new NodeL();
		last->Achievements = x;
		last->next = nullptr;
		if (Head == nullptr)
		{
			Head = last;
		}
		else
		{
			NodeL* curr = new NodeL();
			curr = Head;
			while (curr->next != nullptr)
			{
				curr = curr->next;
			}
			curr->next = last;
		}
	}
	void DeleteLast()                                 //To delete the last achievemnt of the player
	{
		NodeL* temp = Head;
		while (temp->next->next != NULL)
		{
			temp = temp->next;
		}
		NodeL* temp1 = temp->next;
		temp->next = NULL;
		delete temp1;
	}
	bool isEmpty()                                // to check if the list is emptry or not
	{
		if (Head == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void display()                                    //To shwo all the achivemnts of the player controllign the game    
	{
		if (Head != nullptr)
		{
			NodeL* curr = new NodeL();
			curr = Head;
			while (curr != nullptr)
			{
				cout <<curr->Achievements<< endl;
				curr = curr->next;
			}
		}
	}
	int NumofCoins()                                 //To keep balance of the  the count of the numebr of coins collected by player
	{
		NodeL* temp = Head;
		int count = 0;
		while (temp != NULL)
		{
			if (temp->Achievements == '$')
			{
				count++;
			}
			temp = temp->next;
		}
		return count;
	}
	int NumofTrophies()   		                            //To keep balance of the  the count of the numebr of trophies collected by player
	{
		NodeL* temp = Head;
		int count = 0;
		while (temp != NULL)
		{
			if (temp->Achievements == 'T')
			{
				count++;
			}
			temp = temp->next;
		}
		return count;
	}
};