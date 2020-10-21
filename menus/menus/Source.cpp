//this part is going to display the different menus and options of Townies and Terrors
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

// declares functions for the game and info


void story()
{
	int people;
	int type;
	int persons;
	
	cout << "Would you like to see townies or terrors?" << endl;
	people = _getch();
	cout << people;
}

int main() 
{
	std::string ask;
	int hold = 1;
	cout << "Townies and Terrors" << endl << endl;

	//asks users where they would like to go
	cout << "Please enter where you would like to go" << endl;
	cout << "play" << endl << endl << "info" << endl << endl << "quit" << endl;
	cin >> ask;

	while (hold != 0)
	{
		if (ask == "play")
		{
			hold = 0;
		}
		else if (ask == "info")
		{
			story ();
			hold = 0;
		}
		else if (ask == "quit")
		{
			hold = 0;
			exit;
		}
		else
		{
			cout << "Please enter one of the options";
			cin >> ask;
		}
	}
}
