//ImaduddinAnsari_22I-2446 WaleedAbdullah_22I-2714
//All functionality defined in the project report attached.
#pragma once
#include <iostream>
#include <string>
using namespace std;

class NodeH {           // to keep track of scores of the player
public:
	int score;
	string name;
};

class Heap {		
private:
	NodeH* heap;
	int capacity;
	int size;
public:
	Heap(int cap)
	{
		capacity = cap;
		heap = new NodeH[capacity];
		size = 0;
	}
	void Insert(string n, int s)				//Used to add a new score for the player playign the game
	{
		if (size < capacity)
		{
			NodeH temp;
			temp.name = n;
			temp.score = s;
			heap[size] = temp;
			int x = size;
			while (x > 0 && heap[x].score < heap[(x - 1) / 2].score)
			{
				NodeH temp = heap[x];
				heap[x] = heap[(x - 1) / 2];
				heap[(x - 1) / 2] = temp;
				x = (x - 1) / 2;
			}
			size++;
		}
		else
		{

		}
	}
	NodeH LowestScore()				//Used to return the lowest score entcountered until now in the game.
	{
		if (size > 0)
		{
			return heap[0];
		}
		else
		{

		}
	}
	void RecursiveRemove(int x)  				//Used to recursively remove a desired elem,ent from the heap
	{
		int smallest = x;
		if ((2 * x + 1) < size && heap[2 * x + 1].score < heap[x].score)
		{
			smallest = 2 * x + 1;
		}
		if ((2 * x + 2) < size && heap[2 * x + 2].score < heap[x].score&&heap[2*x+2].score<heap[smallest].score)
		{
			smallest = 2 * x + 2;
		}
		if (smallest != x)
		{
			NodeH temp = heap[x];
			heap[x] = heap[smallest];
			heap[smallest] = temp;
			RecursiveRemove(smallest);
		}
	}
	void Remove()				 					//Used to delete an elemnt from th eheap and reduce its size.
	{
		if (size > 0)
		{
			heap[0] = heap[size - 1];
			RecursiveRemove(0);
			size--;
		}
		else
		{

		}
	}
	bool IsEmpty()                                // to check if the heap is emptry or not
	{
		if (size == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};