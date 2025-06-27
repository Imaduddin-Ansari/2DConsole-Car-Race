//ImaduddinAnsari_22I-2446 WaleedAbdullah_22I-2714
//All functionality defined in the project report attached.
#include <iostream>
#include "Graph.h"
#include "Heap.h"
using namespace std;

//Main used to test all functionality
int main()
{
	int choice = 0;
	string next;
	char diff = 'E';
	int playerpos[2];
	int finishpos[2];
	Graph* G1=new Graph(diff);
	string Name;
	while (choice != 5)
	{
		system("cls");
		for (int i = 0; i < 25; i++)
		{
			cout << "-";
		}
		cout << endl;
		cout << "|\t\t\t|" << endl;                             //All options displayed along with a menu to choose from
		cout << "|\tRace Game\t|" << endl;
		cout << "|\t\t\t|" << endl;
		cout << "|\t1.Automatic\t|" << endl;
		cout << "|\t2.Manual\t|" << endl;
		cout << "|\t3.Leaderboard\t|" << endl;
		cout << "|\t4.Difficulty\t|" << endl;
		cout << "|\t5.Exit\t\t|" << endl;
		cout << "|\t\t\t|" << endl;
		for (int i = 0; i < 25; i++)
		{
			cout << "-";
		}
		cout << endl;
		cout << "Enter(1-5): ";
		cin >> choice;
		while (choice < 1 || choice > 5)                           //loop to handle any error inputs by the user
		{
			cout << "Enter Again" << endl;
			cin >> choice;
		}
		switch (choice)       										//switch used to give options to the user
		{
		case 1:
				system("cls");
			    cout << "Enter Position of Player (X)" << endl;
				cin >> playerpos[0];
				while (playerpos[0] >= 6 || playerpos[0] <= 0)
				{
					cout << "Enter from 1-5 Only" << endl;
					cin >> playerpos[0];
				}
				cout << "Enter Position of Player (Y)" << endl;
				cin >> playerpos[1];
				while (playerpos[1] >= 6 || playerpos[1] <= 0)
				{
					cout << "Enter from 1-5 Only" << endl;
					cin >> playerpos[1];
				}
				cout << "Enter Position of Finish Line (X)" << endl;
				cin >> finishpos[0];
				while (finishpos[0] >= 6 || playerpos[0] <= 0)
				{
					cout << "Enter from 1-5 Only" << endl;
					cin >> playerpos[0];
				}
				cout << "Enter Position of Finish Line (Y)" << endl;
				cin >> finishpos[1];
				while (finishpos[1] >= 6 || playerpos[1] <= 0)
				{
					cout << "Enter from 1-5 Only" << endl;
					cin >> playerpos[0];
				}
				system("cls");
				for (int i = 0; i < 33; i++)
				{
					cout << "-";
				}
				cout << endl;
				cout << "|\t\t\t\t|" << endl;
				cout << "|\tP is you character\t|" << endl;
				cout << "|\tF is finish line\t|" << endl;
				G1 = new Graph(diff);
				cout << "|\t\t\t\t|" << endl;
				for (int i = 0; i < 33; i++)
				{
					cout << "-";
				}
				cout << endl;
				cout << "Enter Your Name: ";
				cin >> Name;
			G1 = new Graph('E', playerpos[0], playerpos[1], finishpos[0], finishpos[1]);
			G1->SetName(Name);
			G1->AutomaticShortestPath(playerpos[0], playerpos[1], finishpos[0], finishpos[1]);
			while (!G1->CheckIfWon() && !G1->CheckIfLost())
			{
				G1->DisplayMap();
				char x;
				cout << endl;
				cout << "Shortest Path Displayed By *" << endl;
				cout << "INPUT WASD FOR MOVING OR E FOR RESTARTING" << endl;
				cin >> x;
				if (x == 'E')
				{
					G1 = new Graph('E', playerpos[0], playerpos[1], finishpos[0], finishpos[1]);
					G1->SetName(Name);
					G1->AutomaticShortestPath(playerpos[0], playerpos[1], finishpos[0], finishpos[1]);
				}
				G1->MovePlayer(x);
				G1->AddObstacle();
			}
			if (G1->CheckIfWon() == true)
			{
				G1->UpdateLeaderBoard();
			}
			if (G1->CheckIfLost() == true)
			{

			}
			Sleep(2000);
			break;
		case 2:
			system("cls");
			for (int i = 0; i < 33; i++)
			{
				cout << "-";
			}
			cout << endl;
			cout << "|\t\t\t\t|" << endl;
			cout << "|\tP is you character\t|" << endl;
			cout << "|\tF is finish line\t|" << endl;
			G1 = new Graph(diff);
			cout << "|\t\t\t\t|" << endl;
			for (int i = 0; i < 33; i++)
			{
				cout << "-";
			}
			cout << endl;
			cout << "Enter Your Name: ";
			cin >> Name;
			G1->SetName(Name);
			while (!G1->CheckIfWon()&&!G1->CheckIfLost())
			{
				G1->DisplayMap();
				char x;
				cout << endl;
				cout << "INPUT WASD FOR MOVING: ";
				cin >> x;
				G1->MovePlayer(x);
				G1->AddObstacle();
			}
			if (G1->CheckIfWon() == true)
			{
				G1->UpdateLeaderBoard();
			}
			if (G1->CheckIfLost() == true)
			{

			}
			Sleep(2000);
			break;
		case 3:
			system("cls");
			G1->DisplayLeaderBoard();
			cout << endl;
			cout << "Enter Anything to go Back: ";
			cin >> next;
			break;
		case 4:
			system("cls");
			cout << "Easy , Medium , Hard" << endl;
			cout << " (E)     (M)     (H)" << endl;
			cin >> diff;
			while (diff != 'E' && diff != 'M' && diff != 'H')
			{
				cout << "Enter Only E , M or H" << endl;
				cin >> diff;
			}
			if (diff == 'E')
			{
				cout << "Difficulty set to Easy" << endl;
			}
			if (diff == 'M')
			{
				cout << "Difficulty set to Medium" << endl;
			}
			if (diff == 'H')
			{
				cout << "Difficulty set to Hard" << endl;
			}
			system("cls");
			Sleep(1000);
			break;
		case 5:
			break;
		case 6:
			break;
		}
		if (choice == 5)
		{
			break;
		}
	}
}