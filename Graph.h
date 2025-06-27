//ImaduddinAnsari_22I-2446 WaleedAbdullah_22I-2714
//All functionality defined in the project report attached.
#pragma once
#include <iostream>
#include <Windows.h>
#include "Queue.h"
#include "Heap.h"
#include "Linked List.h"
#include <fstream>
#include <queue>
using namespace std;

struct Node {      								//USed to show and represnt a cell in the map
	char location;
	Node* left;
	int weightl;
	Node* right;
	int weightr;
	Node* down;
	int weightd;
	Node* up;
	int weightu;
	int Distance;
	bool traversed;
	int x;
	int y;
	Node* prev;
};

class Graph {
private:
	int difficulty;
	string Name;
	int Score;
	int NumOfObs;
	Queue Q1;
	LinkedList L1;
	Node Map[7][7];
	Node* PlayerPosition;
	Node* FinishPosition;
public:
	Graph(char diff, int x1,int y1,int x2,int y2)     						//Used to create a grid based on the difficulty leevl and also set the starting postion of the player
	{
		difficulty = 0;
		if (diff == 'E')
		{
			difficulty = 3;
		}
		if (diff == 'M')

		{
			difficulty = 4;
		}
		if (diff == 'H')
		{
			difficulty = 5;
		}
		Score = 0;
		srand(time(0));
		int x, y;
		for (int i = 0; i < 4; i++)
		{
			x = rand() % 5 + 1;
			y = rand() % 5 + 1;
			while ((x == x1 && y == y1) || (x == x2 && y == y2))
			{
				x = rand() % 5 + 1;
				y = rand() % 5 + 1;
			}
			Map[x][y].location = '|';
		}
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (i == 0 || i == 6 || j == 0 || j == 6)
				{
					Map[i][j].location = '#';
				}
				else
				{
					if (Map[i][j].location == '|')
					{

					}
					else
					{
						Map[i][j].location = ' ';
					}
				}
			}
		}
		FinishPosition = &Map[x2][y2];
		FinishPosition->location = 'F';
		PlayerPosition = &Map[x1][y1];
		PlayerPosition->location = 'P';
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (i > 0)
				{
					Map[i][j].up = &Map[i - 1][j];
				}
				if (i < 6)
				{
					Map[i][j].down = &Map[i + 1][j];
				}
				if (j > 0)
				{
					Map[i][j].left = &Map[i][j - 1];
				}
				if (j < 6)
				{
					Map[i][j].right = &Map[i][j + 1];
				}
				Map[i][j].x = i;
				Map[i][j].y = j;
			}
		}
		NumOfObs = 0;
		for (int i = 0; i < 3; i++)
		{
			x = rand() % 4;
			if (x == 1)
			{
				Q1.enqueue('$');
			}
			if (x == 2)
			{
				Q1.enqueue('T');
			}
			if (x == 3)
			{
				Q1.enqueue('B');
			}
			if (x == 0)
			{
				Q1.enqueue('X');
			}
		}
		for (int i = 0; i < difficulty; i++)
		{
			AddObstacle();
		}
	}
	Graph(char diff)    						//Used to create a grid based on the difficulty leevl and also set the starting postion of the player randonmly
	{
		difficulty = 0;
		if (diff == 'E')
		{
			difficulty = 3;
		}
		if (diff == 'M')

		{
			difficulty = 4;
		}
		if (diff == 'H')
		{
			difficulty = 5;
		}
		Score = 0;
		srand(time(0));
		int x, y;
		for (int i = 0; i < 4; i++)
		{
			x = rand() % 5 + 1;
			y = rand() % 5 + 1;
			if (Map[1][2].location == '|')
			{
				if (x == 2 && y == 1)
				{
					x = rand() % 5 + 1;
					y = rand() % 5 + 1;
				}
			}
			if (Map[2][1].location == '|')
			{
				if (x == 1 && y == 2)
				{
					x = rand() % 5 + 1;
					y = rand() % 5 + 1;
				}
			}
			if (Map[5][4].location == '|')
			{
				if (x == 4 && y == 5)
				{
					x = rand() % 5 + 1;
					y = rand() % 5 + 1;
				}
			}
			if (Map[4][5].location == '|')
			{
				if (x == 5 && y == 4)
				{
					x = rand() % 5 + 1;
					y = rand() % 5 + 1;
				}
			}
			Map[x][y].location = '|';
		}
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (i == 0 || i == 6 || j == 0 || j == 6)
				{
					Map[i][j].location = '#';
				}
				else
				{
					if (Map[i][j].location == '|')
					{

					}
					else
					{
						Map[i][j].location = ' ';
					}
				}
			}
		}
		FinishPosition = &Map[5][5];
		FinishPosition->location = 'F';
		PlayerPosition = &Map[1][1];
		PlayerPosition->location = 'P';
		int randomweight;
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (i > 0)
				{
					randomweight = rand() % 10 + 1;
					Map[i][j].weightu = randomweight;
					Map[i][j].up = &Map[i - 1][j];
				}
				if (i < 6)
				{
					randomweight = rand() % 10 + 1;
					Map[i][j].weightd = randomweight;
					Map[i][j].down = &Map[i + 1][j];
				}
				if (j > 0)
				{
					randomweight = rand() % 10 + 1;
					Map[i][j].weightl = randomweight;
					Map[i][j].left = &Map[i][j - 1];
				}
				if (j < 6)
				{
					randomweight = rand() % 10 + 1;
					Map[i][j].weightr = randomweight;
					Map[i][j].right = &Map[i][j + 1];
				}
			}
		}
		NumOfObs = 0;
		for (int i = 0; i < 3; i++)
		{
			x = rand() % 4;
			if (x == 1)
			{
				Q1.enqueue('$');
			}
			if (x == 2)
			{
				Q1.enqueue('T');
			}
			if (x == 3)
			{
				Q1.enqueue('B');
			}
			if (x == 0)
			{
				Q1.enqueue('X');
			}
		}
	}
	void SetName(string n)                    //function to set the name of the player
	{
		Name = n;
	}
	void DisplayMap()                    //function to display the whole grid on hwich the game is to be played
	{
		system("cls");
		for (int i = 0; i < 25; i++)
		{
			cout << "-";
		}
		cout << endl;
		cout << "|\t\t\t|" << endl;
		cout << "| PS: " << PreviousScore() << " Pts\t|" << endl;
		if (difficulty == 3)
		{
			cout << "| Difficulty: Easy" << "\t|" << endl;
		}
		if (difficulty == 4)
		{
			cout << "| Difficulty: Medium" << "\t|" << endl;
		}
		if (difficulty == 5)
		{
			cout << "| Difficulty: Hard" << "\t|" << endl;
		}
		cout << "| Number of Coins: " << L1.NumofCoins() << "\t|" << endl;
		cout << "| Number of Trophies: " << L1.NumofTrophies() << "\t|" << endl;
		cout << "|\t\t\t|" << endl;
		for (int i = 0; i < 7; i++)
		{
			cout << "|     ";
			for (int j = 0; j < 7; j++)
			{
				cout <<Map[i][j].location << " ";
			}
			cout << "\t|" << endl;
		}
		cout << "|\t\t\t|" << endl;
		cout << "|\tScore: " <<Score<<"\t|" << endl;
		cout << "|\t\t\t|" << endl;
		cout << "| Every Move is +10 Pts" << "\t|" << endl;
		cout << "| $ = -20 Pts" << "\t\t|" << endl;
		cout << "| T = -30 Pts" << "\t\t|" << endl;
		cout << "| B = +10 Pts" << "\t\t|" << endl;
		cout << "| X = +20 Pts" << "\t\t|" << endl;
		cout << "|\t\t\t|" << endl;
		for (int i = 0; i < 25; i++)
		{
			cout << "-";
		}
	}
	void MovePlayer(char d)                    //function to move the player up, down, left and right, based on key clicks.
	{
		if (d == 'W' || d == 'w')
		{
			if (PlayerPosition->up->location != '#' && PlayerPosition->up->location != '|')
			{
				if (PlayerPosition->up->location == '$')
				{
					Score = Score - 20;
					L1.insert('$');
					NumOfObs--;
				}
				else if (PlayerPosition->up->location == 'T')
				{
					Score = Score - 30;
					L1.insert('T');
					NumOfObs--;
				}
				else if (PlayerPosition->up->location == 'B')
				{
					Score = Score + 10;
					NumOfObs--;
				}
				else if (PlayerPosition->up->location == 'X')
				{
					Score = Score + 20;
					NumOfObs--;
				}
				Score = Score + 10;
				Node* temp = PlayerPosition->up;
				PlayerPosition->location = ' ';
				PlayerPosition = temp;
				PlayerPosition->location = 'P';
			}
			else
			{
				cout << "Cannot Move There , Try Again" << endl;
				Sleep(500);
			}
		}
		else if (d == 'S' || d == 's')
		{
			if (PlayerPosition->down->location != '#' && PlayerPosition->down->location != '|')
			{
				if (PlayerPosition->down->location == '$')
				{
					Score = Score - 20;
					L1.insert('$');
					NumOfObs--;
				}
				else if (PlayerPosition->down->location == 'T')
				{
					Score = Score - 30;
					L1.insert('T');
					NumOfObs--;
				}
				else if (PlayerPosition->down->location == 'B')
				{
					Score = Score + 10;
					NumOfObs--;
				}
				else if (PlayerPosition->down->location == 'X')
				{
					Score = Score + 20;
					NumOfObs--;
				}
				Score = Score + 10;
				Node* temp = PlayerPosition->down;
				PlayerPosition->location = ' ';
				PlayerPosition = temp;
				PlayerPosition->location = 'P';
			}
			else
			{
				cout << "Cannot Move There , Try Again" << endl;
				Sleep(500);
			}
		}
		else if (d == 'A' || d == 'a')
		{
			if (PlayerPosition->left->location != '#' && PlayerPosition->left->location != '|')
			{
				if (PlayerPosition->left->location == '$')
				{
					Score = Score - 20;
					L1.insert('$');
					NumOfObs--;
				}
				else if (PlayerPosition->left->location == 'T')
				{
					Score = Score - 30;
					L1.insert('T');
					NumOfObs--;
				}
				else if (PlayerPosition->left->location == 'B')
				{
					Score = Score + 10;
					NumOfObs--;
				}
				else if (PlayerPosition->left->location == 'X')
				{
					Score = Score + 20;
					NumOfObs--;
				}
				Score = Score + 10;
				Node* temp = PlayerPosition->left;
				PlayerPosition->location = ' ';
				PlayerPosition = temp;
				PlayerPosition->location = 'P';
			}
			else
			{
				cout << "Cannot Move There , Try Again" << endl;
				Sleep(500);
			}
		}
		else if (d == 'D' || d == 'd')
		{
			if (PlayerPosition->right->location != '#' && PlayerPosition->right->location != '|')
			{
				if (PlayerPosition->right->location == '$')
				{
					Score = Score - 20;
					L1.insert('$');
					NumOfObs--;
				}
				else if (PlayerPosition->right->location == 'T')
				{
					Score = Score - 30;
					L1.insert('T');
					NumOfObs--;
				}
				else if (PlayerPosition->right->location == 'B')
				{
					Score = Score + 10;
					NumOfObs--;
				}
				else if (PlayerPosition->right->location == 'X')
				{
					Score = Score + 20;
					NumOfObs--;
				}
				Score = Score + 10;
				Node* temp = PlayerPosition->right;
				PlayerPosition->location = ' ';
				PlayerPosition = temp;
				PlayerPosition->location = 'P';
			}
			else
			{
				cout << "Cannot Move There , Try Again" << endl;
				Sleep(500);
			}
		}
		else
		{
			cout << "Enter Only WASD Please!" << endl;
			Sleep(500);
		}
	}
	bool CheckIfLost()                    //function to check oif the player has already lost the game by checking the score
	{
		if (Score >=150)
		{
			cout << "You lost the game (Reached pts more than 150)" << endl;
			return true;
		}
		else
		{
			return false;
		}
	}
	bool CheckIfWon()                   //function to check if the player has won the game by reaching the finish line
	{
		if (PlayerPosition==FinishPosition)
		{
			DisplayMap();
			cout << endl;
			cout << "Congratulations, You Have Finished The Race!!" << endl;
			return true;
		}
		else
		{
			return false;
		}
	}
	void AddObstacle()                //function to add an obstacle into the grid
	{
		srand(time(0));
		int x;
		if (Q1.isEmpty() == true)
		{
			for (int i = 0; i < difficulty; i++)
			{
				x = rand() % 4;
				if (x == 1)
				{
					Q1.enqueue('$');
				}
				if (x == 2)
				{
					Q1.enqueue('T');
				}
				if (x == 3)
				{
					Q1.enqueue('B');
				}
				if (x == 0)
				{
					Q1.enqueue('X');
				}
			}
		}
		if (NumOfObs == difficulty)
		{

		}
		else
		{
			x = rand() % 5 + 1;
			int y = rand() % 5 + 1;
			while (Map[x][y].location == 'P' || Map[x][y].location == 'F' || Map[x][y].location == '|' || Map[x][y].location == '$' || Map[x][y].location == 'T' || Map[x][y].location == 'B' || Map[x][y].location == 'X')
			{
				x = rand() % 5 + 1;
				y = rand() % 5 + 1;
			}
			Map[x][y].location = Q1.showFront();
			Q1.dequeue();
			NumOfObs++;
		}
	}
	void DisplayLeaderBoard()                //function to shwo the already existing leaderboard from the file input
	{
		Heap H1(10);
		string name = "";
		fstream F;
		F.open("Leaderboard.txt", ios::in);
		string x;
		int check = 0;
		int count = 0;
		string num = "";
		while (getline(F, x))
		{
			for (int i = 0; i < x.length(); i++)
			{
				if (x[i] == ':')
				{
					check = 2;
				}
				if (x[i] == '*')
				{
					check == 3;
				}
				if (check == 3)
				{

				}
				if (check == 1)
				{
					name = name + x[i];
				}
				if (check == 2)
				{
					if (x[i] == ':')
					{

					}
					else
					{
						num = num + x[i];
					}
				}
				if (x[i] == '.')
				{
					check = 1;
				}
			}
			if (check == 0)
			{

			}
			else
			{
				H1.Insert(name, stoi(num));
			}
			count++;
			check = 0;
			num = "";
			name = "";
		}
		H1.Insert(Name, Score);
		F.close();
		for (int i = 0; i < 25; i++)
		{
			cout << "-";
		}
		cout << endl;
		cout << "|\t\t\t|" << endl;
		cout << "|\tLEADERBOARD\t|" << endl;
		cout << "|\t\t\t|" << endl;
		int same=-1;
		string sname;
		for (int i = 0;H1.IsEmpty()!=true; i++)
		{
			if (H1.LowestScore().score == 0)
			{
				i--;
				if (H1.LowestScore().score == same&&H1.LowestScore().name==sname)
				{

				}
				else
				{
					sname = H1.LowestScore().name;
					same = H1.LowestScore().score;
					H1.Remove();
				}
			}
			else
			{
				if (H1.LowestScore().score == same && H1.LowestScore().name == sname)
				{

				}
				else
				{
					if (H1.LowestScore().name.length() == 2)
					{
						cout << "|\t" << i + 1 << "." << H1.LowestScore().name << ":" << H1.LowestScore().score << "\t\t|" << endl;
					}
					else
					{
						cout << "|\t" << i + 1 << "." << H1.LowestScore().name << ":" << H1.LowestScore().score << "\t|" << endl;
					}
				}
				same = H1.LowestScore().score;
				sname = H1.LowestScore().name;
				H1.Remove();
			}
		}
		cout << "|\t\t\t|" << endl;
		for (int i = 0; i < 25; i++)
		{
			cout << "-";
		}
	}
	int getX(Node* temp)
	{
		return temp->x;
	}
	int getY(Node* temp)
	{
		return temp->y;
	}
	void UpdateLeaderBoard()                //function to update th eleaderboard woth the new score of the player
	{
		Heap H1(10);
		string name = "";
		fstream F;
		F.open("Leaderboard.txt", ios::in);
		string x;
		int check = 0;
		int count = 0;
		string num="";
		while (getline(F, x))
		{
			for (int i = 0; i < x.length(); i++)
			{
				if (x[i] == ':')
				{
					check = 2;
				}
				if (x[i] == '*')
				{
					check == 3;
				}
				if (check == 3)
				{

				}
				if (check == 1)
				{
					name = name + x[i];
				}
				if (check == 2)
				{
					if (x[i] == ':')
					{

					}
					else
					{
						num = num + x[i];
					}
				}
				if (x[i] == '.')
				{
					check = 1;
				}
			}
			if (check == 0)
			{

			}
			else
			{
				H1.Insert(name, stoi(num));
			}
			count++;
			check = 0;
			num = "";
			name = "";
		}
		H1.Insert(Name, Score);
		F.close();
		F.open("Leaderboard.txt", ios::out);
		for (int i = 0; H1.IsEmpty()!=true; i++)
		{
			if (H1.LowestScore().score == 0)
			{
				i--;
				H1.Remove();
			}
			else
			{
				F << i + 1 << "." << H1.LowestScore().name << ":" << H1.LowestScore().score << endl;
				H1.Remove();
			}
		}
		F << "*" <<Name <<" "<<Score<< endl;
		H1.Remove();
		F.close();
	}
	void AutomaticShortestPath(int x1,int y1,int x2,int y2)                 //function to check the shortest path from a point to the finish line and then run the game automatically.
	{
		int randomweight;
		srand(time(0));
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				randomweight = (rand() % 20)+1;
				Map[i][j].weightu = ++randomweight;
				randomweight = (rand() % 20) + 1;
				Map[i][j].weightd = ++randomweight;
				randomweight = (rand() % 20) + 1;
				Map[i][j].weightl = ++randomweight;
				randomweight = (rand() % 20) + 1;
				Map[i][j].weightr = ++randomweight;
				Map[i][j].Distance = INT_MAX;
				Map[i][j].traversed = false;
			}
		}
		PlayerPosition->Distance = 0;
		PlayerPosition->traversed = true;
		Heap Priority(4);
		Node* curr = &Map[getX(PlayerPosition)][getY(PlayerPosition)];
		if (x1 > x2 && y1 >= y2)
		{
			while (true)
			{
				if (curr->down != NULL)
				{
					if (curr->down->location == 'F')
					{
						break;
					}
				}
				if (curr->up != NULL)
				{
					if (curr->up->location == 'F')
					{
						break;
					}
				}
				if (curr->left != NULL)
				{
					if (curr->left->location == 'F')
					{
						break;
					}
				}
				if (curr->right != NULL)
				{
					if (curr->right->location == 'F')
					{
						break;
					}
				}
				if (getX(curr) != getX(FinishPosition))
				{
					if (curr->up != NULL && (!curr->up->traversed) && ((curr->up->location != '#') && (curr->up->location != '|')))
					{
						Priority.Insert("u", curr->weightu);
					}
				}
				if (getY(curr) != getY(FinishPosition))
				{
					if (curr->left != NULL && (!curr->left->traversed) && ((curr->left->location != '#') && (curr->left->location != '|')))
					{
						Priority.Insert("l", curr->weightl);
					}
				}
				NodeH temp = Priority.LowestScore();
				if (temp.name == "u")
				{
					PlayerPosition->Distance = PlayerPosition->Distance + temp.score;
					curr = curr->up;
				}
				if (temp.name == "l")
				{
					PlayerPosition->Distance = PlayerPosition->Distance + temp.score;
					curr = curr->left;
				}
				if (temp.name == "r")
				{
					PlayerPosition->Distance = PlayerPosition->Distance + temp.score;
					curr = curr->right;
				}
				while (!Priority.IsEmpty())
				{
					Priority.Remove();
				}
				curr->traversed = true;
				if (curr->location)
					curr->location = '*';
				if (curr->left->location == '|' && curr->up->location == '|')
				{
					break;
				}
			}
		}
		if (x1 > x2 && y1 < y2)
		{
			while (true)
			{
				if (curr->down != NULL)
				{
					if (curr->down->location == 'F')
					{
						break;
					}
				}
				if (curr->up != NULL)
				{
					if (curr->up->location == 'F')
					{
						break;
					}
				}
				if (curr->left != NULL)
				{
					if (curr->left->location == 'F')
					{
						break;
					}
				}
				if (curr->right != NULL)
				{
					if (curr->right->location == 'F')
					{
						break;
					}
				}
				if (getX(curr) != getX(FinishPosition))
				{
					if (curr->up != NULL && (!curr->up->traversed) && ((curr->up->location != '#') && (curr->up->location != '|')))
					{
						Priority.Insert("u", curr->weightu);
					}
				}
				if (getY(curr) != getY(FinishPosition))
				{
					if (curr->right != NULL && (!curr->right->traversed) && ((curr->right->location != '#') && (curr->right->location != '|')))
					{
						Priority.Insert("r", curr->weightr);
					}
				}
				NodeH temp = Priority.LowestScore();
				if (temp.name == "u")
				{
					PlayerPosition->Distance = PlayerPosition->Distance + temp.score;
					curr = curr->up;
				}
				if (temp.name == "l")
				{
					PlayerPosition->Distance = PlayerPosition->Distance + temp.score;
					curr = curr->left;
				}
				if (temp.name == "r")
				{
					PlayerPosition->Distance = PlayerPosition->Distance + temp.score;
					curr = curr->right;
				}
				while (!Priority.IsEmpty())
				{
					Priority.Remove();
				}
				curr->traversed = true;
				if (curr->location)
					curr->location = '*';
				if (curr->right->location == '|' && curr->up->location == '|')
				{
					break;
				}
			}
		}
		if (x1 < x2 && y1 >= y2)
		{
			while (true)
			{
				if (curr->down != NULL)
				{
					if (curr->down->location == 'F')
					{
						break;
					}
				}
				if (curr->up != NULL)
				{
					if (curr->up->location == 'F')
					{
						break;
					}
				}
				if (curr->left != NULL)
				{
					if (curr->left->location == 'F')
					{
						break;
					}
				}
				if (curr->right != NULL)
				{
					if (curr->right->location == 'F')
					{
						break;
					}
				}
				if (getX(curr) != getX(FinishPosition))
				{
					if (curr->down != NULL && (!curr->down->traversed) && ((curr->down->location != '#') && (curr->down->location != '|')))
					{
						Priority.Insert("d", curr->weightd);
					}
				}
				if (getY(curr) != getY(FinishPosition))
				{
					if (curr->left != NULL && (!curr->left->traversed) && ((curr->left->location != '#') && (curr->left->location != '|')))
					{
						Priority.Insert("l", curr->weightl);
					}
				}
				NodeH temp = Priority.LowestScore();
				if (temp.name == "d")
				{
					PlayerPosition->Distance = PlayerPosition->Distance + temp.score;
					curr = curr->down;
				}
				if (temp.name == "u")
				{
					PlayerPosition->Distance = PlayerPosition->Distance + temp.score;
					curr = curr->up;
				}
				if (temp.name == "l")
				{
					PlayerPosition->Distance = PlayerPosition->Distance + temp.score;
					curr = curr->left;
				}
				if (temp.name == "r")
				{
					PlayerPosition->Distance = PlayerPosition->Distance + temp.score;
					curr = curr->right;
				}
				while (!Priority.IsEmpty())
				{
					Priority.Remove();
				}
				curr->traversed = true;
				curr->location = '*';
				if (curr->left->location == '|' && curr->down->location == '|')
				{
					break;
				}
			}
		}
		if (x1 < x2 && y1 < y2)
		{
			while (true)
			{
				if (curr->down != NULL)
				{
					if (curr->down->location == 'F')
					{
						break;
					}
				}
				if (curr->up != NULL)
				{
					if (curr->up->location == 'F')
					{
						break;
					}
				}
				if (curr->left != NULL)
				{
					if (curr->left->location == 'F')
					{
						break;
					}
				}
				if (curr->right != NULL)
				{
					if (curr->right->location == 'F')
					{
						break;
					}
				}
				if (getX(curr) != getX(FinishPosition))
				{
					if (curr->down != NULL && (!curr->down->traversed) && ((curr->down->location != '#') && (curr->down->location != '|')))
					{
						Priority.Insert("d", curr->weightd);
					}
				}
				if (getY(curr) != getY(FinishPosition))
				{
					if (curr->right != NULL && (!curr->right->traversed) && ((curr->right->location != '#') && (curr->right->location != '|')))
					{
						Priority.Insert("r", curr->weightr);
					}
				}
				NodeH temp = Priority.LowestScore();
				if (temp.name == "d")
				{
					PlayerPosition->Distance = PlayerPosition->Distance + temp.score;
					curr = curr->down;
				}
				if (temp.name == "u")
				{
					PlayerPosition->Distance = PlayerPosition->Distance + temp.score;
					curr = curr->up;
				}
				if (temp.name == "l")
				{
					PlayerPosition->Distance = PlayerPosition->Distance + temp.score;
					curr = curr->left;
				}
				if (temp.name == "r")
				{
					PlayerPosition->Distance = PlayerPosition->Distance + temp.score;
					curr = curr->right;
				}
				while (!Priority.IsEmpty())
				{
					Priority.Remove();
				}
				curr->traversed = true;
				curr->location = '*';
				if (curr->right->location == '|' && curr->up->location == '|')
				{
					break;
				}
			}
		}
	}

	string PreviousScore()             //Fucntion to chweck the previous score saved in the leaderboard for a specific person.
	{
		fstream F;
		string x;
		string prevscore;
		int check = 0;
		F.open("Leaderboard.txt", ios::in);
		while (getline(F, x))
		{
			for (int i = 0; i < x.length(); i++)
			{
				if (x[i] == '*')
				{
					check = 1;
				}
				if (check == 1)
				{
					if (x[i] == '*')
					{

					}
					else
					{
						prevscore = prevscore + x[i];
					}
				}
			}
			if (check == 1)
			{
				break;
			}
		}
		return prevscore;
	}
};