//this part is going to display the different menus and options of Townies and Terrors
#include <iostream>
#include <string>
using namespace std;

// declares functions for the game and info


void story()
{
	/*
	else if (peoples == 50)
	{
		std::cout << "\n\nWhich type of Townie would you like to learn about?\n1: Power\n2: Speed\n3: Support\n\n";
		peoples = _getch();
		if (peoples == 49)
		{
			std::cout << "\n\nWhich Townie would you like to learn about?\n1: Detective\n2: Lover\n3: Noble\n\n";
			peoples = _getch();
			if (peoples == 49)
			{
				std::cout << "\n\nA woman trying to solve a string of mysterious murders, leading to even more mysterious beings.\n\nAbility: Lawful Crash\nHP: 4\nStrength: 5\n\n";
			}
			else if (peoples == 50)
			{
				std::cout << "\n\nShe is willing to do anythnig for her love. Even if it means fighting monsters of the night.\n\nAbility: Crash of Love\nHP: 3\nStrength : 4\n\n";
			}
			else if (peoples == 51)
			{
				std::cout << "\n\nThe nobleman who looks after the town. After a string of murders, he is forced to face the possibility of something sinister lurking\n\nAbility: Noble's Mighty Crash\nHP: 2\nStrength: 3\n\n";
			}
		}
		else if (peoples == 50)
		{
			std::cout << "\n\nWhich Townie would you like to learn about?\n1: Beauty\n2: Dancer\n3: Student\n\n";
			peoples = _getch();
			if (peoples == 49)
			{
				std::cout << "\n\nThe most beautiful woman in town. She stuns everyone with her charm. Even the monsters who wish to feast on her blood\n\nAbility: Stunning Dash\nHP: 4\nStrength: 4\n\n";
			}
			else if (peoples == 50)
			{
				std::cout << "\n\nA young woman who dances at night for the pleasure of many. Her nightly outings have brought her to the attention of the other creatures of the night.\n\nAbility: Dashing Charm\nHP: 2\nStrength: 2\n\n";
			}
			else if (peoples == 51)
			{
				std::cout << "\n\nA young boy just looking to learn. Now, monsters are after him and he must run.\n\nAbility: Youthful Dash\nHP: 3\nStrength: 3\n\n";
			}
		}
		else if (peoples == 51)
		{
			std::cout << "\n\nWhich Townie would you like to learn about?\n1: Scientist\n2: Mentor\n3: Doctor\n\n";
			peoples = _getch();
			if (peoples == 49)
			{
				std::cout << "\n\nA man who has spent his whole life trying to solve the mysteries of the world. He knows the danger that is coming. Coming for him.\n\nAbility: Stash of Knowledge\nHP: 5\nStrength: 4\n\n";
			}
			else if (peoples == 50)
			{
				std::cout << "\n\nA older man who teaches the young. He is just an unlucky bystander to the monster's night attack\n\nAbility: Wiseman's Stash\nHP: 3\nStrength: 2\n\n";
			}
			else if (peoples == 51)
			{
				std::cout << "\n\nAn old man who has seen a night like this before. He just wishes to lessen the number of casualties and survive the night.\n\nAbility: Blood Stash\nHP: 4\nStrength: 3\n\n";
			}
		}
	}
	else
	{
	}
	*/
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
