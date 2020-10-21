//this part is going to display the different menus and options of Townies and Terrors
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

// declares functions for the game and info


void story()
{
	int peoples;
	int type;
	int persons;
	restartone:
	cout << "Which would you like to see?" << endl << endl << "1: townies" << endl << endl << "2: terrors?" << endl;

	peoples = _getch();

	if (peoples == 50)
	{	
		restarttwo:
		cout << "\n\nWhich type of Terror would you like to learn about?\n1: Power\n2: Speed\n3: Support\n\n";
		type = _getch();

		if (type == 49)
		{
			restartthree:
			cout << "\n\nWhich Terror would you like to learn about?\n1: Amalgam\n2: Wolfman\n3: Zombie\n\n";
			persons = _getch(); //lets see

			if (persons == 49)
			{
				cout << "\n\nA creature made from the body parts of various corpses brought to life. He now seeks vengeance on the man that created him and the humans that hate him.\n\nAbility: Crash of Hatred\nHP: 4\nStrength: 5\n\n";
			}
			else if (persons == 50)
			{
				cout << "\n\nA being cursed to take the form of the wolf. He lacks control and can only feel the bloodlust pumping through his veins.\n\nAbility: Wolf Crash\nHP: 3\nStrength : 4\n\n";
			}
			else if (persons == 51)
			{
				cout << "\n\nA mindless corpse, brought back to life by the magic of the night. It only wishes to feed on the flesh of the living.\n\nAbility: Mindless Crash\nHP: 2\nStrength: 3\n\n";
			}
			else
			{
				cout << "That was not a correct choice.\n\n";
				goto restartthree;
			}
		}

		else if (type == 50)
		{
			restartfour:
			std::cout << "\n\nWhich terror would you like to learn about?\n1: Vampire\n2: Ghost\n3: Shifter\n\n";
			persons = _getch();

			if (persons == 49)
			{
				std::cout << "\n\nThe original creature of the night. A thousand year old woman looking to drink the blood of anyone she can find.\n\nAbility: Bat Dash\nHP: 4\nStrength: 4\n\n";
			}
			else if (persons == 50)
			{
				std::cout << "\n\nA vengeful student looking to kill as many humans as he can, even if he has to rely on the power of others to do so.\n\nAbility: Spiritual Dash\nHP: 2\nStrength: 2\n\n";
			}
			else if (persons == 51)
			{
				std::cout << "\n\nA doctor who used his knowledge to allow himself to change shape. Tonight, he is looking to have some fun.\n\nAbility: Changing Dash\nHP: 3\nStrength: 3\n\n";
			}
			else
			{
				cout << "That was not a correct choice.\n\n";
				goto restartfour;
			}
		}

		else if (type == 51)
		{
			restartfive:
			std::cout << "\n\nWhich Terror would you like to learn about?\n1: Reaper\n2: Banshee\n3: Witch\n\n";
			persons = _getch();

			if (persons == 49)
			{
				std::cout << "\n\nThe personification of death. He has heard the wails and felt the need for vengeance. He has come to reap its aftermath.\n\nAbility: Deadly Stash\nHP: 5\nStrength: 4\n\n";
			}
			else if (persons == 50)
			{
				std::cout << "\n\nA long dead woman who comes to wail outside the window of those soon to be deceased. Tonight, she has started to wail all around town.\n\nAbility: Wail of Stash\nHP: 3\nStrength: 2\n\n";
			}
			else if (persons == 51)
			{
				std::cout << "\n\nAn outcast who is using her magic to help the wicked monsters.\n\nAbility: Magic Stash\nHP: 4\nStrength: 3\n\n";
			}
			else
			{
				cout << "That was not a correct choice.\n\n";
				goto restartfive;
			}
		}
		else
		{
			cout << "That was not a correct choice.\n\n";
			goto restarttwo;
		}
	}
	else if (peoples == 49)
	{
		restartsix:
		std::cout << "\n\nWhich type of Townie would you like to learn about?\n1: Power\n2: Speed\n3: Support\n\n";
		type = _getch();

		if (type == 49)
		{
			restartseven:
			std::cout << "\n\nWhich Townie would you like to learn about?\n1: Detective\n2: Lover\n3: Noble\n\n";
			persons = _getch();

			if (persons == 49)
			{
				std::cout << "\n\nA woman trying to solve a string of mysterious murders, leading to even more mysterious beings.\n\nAbility: Lawful Crash\nHP: 4\nStrength: 5\n\n";
			}
			else if (persons == 50)
			{
				std::cout << "\n\nShe is willing to do anythnig for her love. Even if it means fighting monsters of the night.\n\nAbility: Crash of Love.\nHP: 3\nStrength : 4\n\n";
			}
			else if (persons == 51)
			{
				std::cout << "\n\nThe nobleman who looks after the town. After a string of murders, he is forced to face the possibility of something sinister lurking.\n\nAbility: Noble's Mighty Crash\nHP: 2\nStrength: 3\n\n";
			}
			else
			{
				cout << "That was not a correct choice.\n\n";
				goto restartseven;
			}
		}
		else if (type == 50)
		{
			restarteight:
			std::cout << "\n\nWhich Townie would you like to learn about?\n1: Beauty\n2: Dancer\n3: Student\n\n";
			persons = _getch();

			if (persons == 49)
			{
				std::cout << "\n\nThe most beautiful woman in town. She stuns everyone with her charm. Even the monsters who wish to feast on her blood.\n\nAbility: Stunning Dash\nHP: 4\nStrength: 4\n\n";
			}
			else if (persons == 50)
			{
				std::cout << "\n\nA young woman who dances at night for the pleasure of many. Her nightly outings have brought her to the attention of the other creatures of the night.\n\nAbility: Dashing Charm\nHP: 2\nStrength: 2\n\n";
			}
			else if (persons == 51)
			{
				std::cout << "\n\nA young boy just looking to learn. Now, monsters are after him and he must run.\n\nAbility: Youthful Dash\nHP: 3\nStrength: 3\n\n";
			}
			else
			{
				cout << "That was not a correct choice.\n\n";
				goto restarteight;
			}
		}
		else if (type == 51)
		{
			restartnine:
			std::cout << "\n\nWhich Townie would you like to learn about?\n1: Scientist\n2: Mentor\n3: Doctor\n\n";
			persons = _getch();

			if (persons == 49)
			{
				std::cout << "\n\nA man who has spent his whole life trying to solve the mysteries of the world. He knows the danger that is coming. Coming for him.\n\nAbility: Stash of Knowledge\nHP: 5\nStrength: 4\n\n";
			}
			else if (persons == 50)
			{
				std::cout << "\n\nA older man who teaches the young. He is just an unlucky bystander to the monster's night attack.\n\nAbility: Wiseman's Stash\nHP: 3\nStrength: 2\n\n";
			}
			else if (persons == 51)
			{
				std::cout << "\n\nAn old man who has seen a night like this before. He just wishes to lessen the number of casualties and survive the night.\n\nAbility: Blood Stash\nHP: 4\nStrength: 3\n\n";
			}
			else
			{
				cout << "That was not a correct choice.\n\n";
				goto restartnine;
			}
		}
		else
		{
			cout << "That was not a correct choice.\n\n";
			goto restartsix;
		}
	}
	else
	{
	cout << "That was not a correct choice.\n\n";
	goto restartone;
	}

	persons = _getch();
	//cout << people;
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
//hehehehee sneaky comment
