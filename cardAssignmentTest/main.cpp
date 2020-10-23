#include <iostream>
#include <ctime>
#include <conio.h>





// declares functions for the game and info


void story()
{
	int peoples;
	int type;
	int persons;
restartone:
	std::cout << "Which would you like to see? \n \n 1: townies \n \n 2: terrors \n \n 3: return to menu \n";

	peoples = _getch();

	if (peoples == 50)
	{
	restarttwo:
		std::cout << "\n\nWhich type of Terror would you like to learn about?\n1: Power\n2: Speed\n3: Support\n\n";
		type = _getch();

		if (type == 49)
		{
		restartthree:
			std::cout << "\n\nWhich Terror would you like to learn about?\n1: Amalgam\n2: Wolfman\n3: Zombie\n\n";
			persons = _getch(); //lets see

			if (persons == 49)
			{
				std::cout << "\n\nA creature made from the body parts of various corpses brought to life. He now seeks vengeance on the man that created him and the humans that hate him.\n\nAbility: Crash of Hatred\nHP: 4\nStrength: 5\n\n";
				goto restartone;
			}
			else if (persons == 50)
			{
				std::cout << "\n\nA being cursed to take the form of the wolf. He lacks control and can only feel the bloodlust pumping through his veins.\n\nAbility: Wolf Crash\nHP: 3\nStrength : 4\n\n";
				goto restartone;
			}
			else if (persons == 51)
			{
				std::cout << "\n\nA mindless corpse, brought back to life by the magic of the night. It only wishes to feed on the flesh of the living.\n\nAbility: Mindless Crash\nHP: 2\nStrength: 3\n\n";
				goto restartone;
			}
			else
			{
				std::cout << "That was not a correct choice.\n\n";
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
				goto restartone;
			}
			else if (persons == 50)
			{
				std::cout << "\n\nA vengeful student looking to kill as many humans as he can, even if he has to rely on the power of others to do so.\n\nAbility: Spiritual Dash\nHP: 2\nStrength: 2\n\n";
				goto restartone;
			}
			else if (persons == 51)
			{
				std::cout << "\n\nA doctor who used his knowledge to allow himself to change shape. Tonight, he is looking to have some fun.\n\nAbility: Changing Dash\nHP: 3\nStrength: 3\n\n";
				goto restartone;
			}
			else
			{
				std::cout << "That was not a correct choice.\n\n";
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
				goto restartone;
			}
			else if (persons == 50)
			{
				std::cout << "\n\nA long dead woman who comes to wail outside the window of those soon to be deceased. Tonight, she has started to wail all around town.\n\nAbility: Wail of Stash\nHP: 3\nStrength: 2\n\n";
				goto restartone;
			}
			else if (persons == 51)
			{
				std::cout << "\n\nAn outcast who is using her magic to help the wicked monsters.\n\nAbility: Magic Stash\nHP: 4\nStrength: 3\n\n";
				goto restartone;
			}
			else
			{
				std::cout << "That was not a correct choice.\n\n";
				goto restartfive;
			}
		}
		else
		{
			std::cout << "That was not a correct choice.\n\n";
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
				goto restartone;
			}
			else if (persons == 50)
			{
				std::cout << "\n\nShe is willing to do anythnig for her love. Even if it means fighting monsters of the night.\n\nAbility: Crash of Love.\nHP: 3\nStrength : 4\n\n";
				goto restartone;
			}
			else if (persons == 51)
			{
				std::cout << "\n\nThe nobleman who looks after the town. After a string of murders, he is forced to face the possibility of something sinister lurking.\n\nAbility: Noble's Mighty Crash\nHP: 2\nStrength: 3\n\n";
				goto restartone;
			}
			else
			{
				std::cout << "That was not a correct choice.\n\n";
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
				goto restartone;
			}
			else if (persons == 50)
			{
				std::cout << "\n\nA young woman who dances at night for the pleasure of many. Her nightly outings have brought her to the attention of the other creatures of the night.\n\nAbility: Dashing Charm\nHP: 2\nStrength: 2\n\n"; 
				goto restartone;
			}
			else if (persons == 51)
			{
				std::cout << "\n\nA young boy just looking to learn. Now, monsters are after him and he must run.\n\nAbility: Youthful Dash\nHP: 3\nStrength: 3\n\n";
				goto restartone;
			}
			else
			{
				std::cout << "That was not a correct choice.\n\n";
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
				goto restartone;
			}
			else if (persons == 50)
			{
				std::cout << "\n\nA older man who teaches the young. He is just an unlucky bystander to the monster's night attack.\n\nAbility: Wiseman's Stash\nHP: 3\nStrength: 2\n\n";
				goto restartone;
			}
			else if (persons == 51)
			{
				std::cout << "\n\nAn old man who has seen a night like this before. He just wishes to lessen the number of casualties and survive the night.\n\nAbility: Blood Stash\nHP: 4\nStrength: 3\n\n";
				goto restartone;
			}
			else
			{
				std::cout << "That was not a correct choice.\n\n";
				goto restartnine;
			}
		}
		else
		{
			std::cout << "That was not a correct choice.\n\n";
			goto restartsix;
		}
	}
	else if (peoples == 51)
	{ 

	exit;
	}
	else
	{
		std::cout << "That was not a correct choice.\n\n";
		goto restartone;
	}
} 

void menu()
{
	int ask;
	int hold = 1;
	std::cout << "Townies and Terrors \n \n";
beginning:
	//asks users where they would like to go
	std::cout << "Please enter where you would like to go \n";
	std::cout << "1: play \n \n 2: info  \n \n 3: quit \n";
	ask = _getch();

	while (hold != 0)
	{
		if (ask == 49)
		{
			
			exit;
		}
		else if (ask == 50)
		{
			
			story();
			goto beginning;
		}
		else if (ask == 51)
		{
			
			exit(1);
		}
		else
		{
			std::cout << "Please enter one of the options";
			ask = _getch();
		}
	}
}
//hehehehee sneaky comment










int SpecialActionSelect(int hand[3], bool townTurn)
{
	std::cout << "\n\nWhich card will preform the special action?\nEnter 'back' to cancel the special action.\n\n";
	int select;
	std::cin >> select;
	int card = hand[select];
	return card;
}

bool PowerMove(int cardReference, bool hasBoosted)
{
	if (!hasBoosted)
	{
		hasBoosted = true;
	}
	//if true, stength boost will add one at the end of next roll then be set to false
	return hasBoosted;
}

//speed special action function goes here

int ChoosePatient(int cardstats[18][3], int hand[3], int cardReference, std::string cards[18])
{
	bool canBeHealed[3]{false};
	if (cardstats[cardReference][0] == 1)
	{
		std::cout << "This card has no health to give.\n\n";
		return -1;
	}
	reheal:
	std::cout << "Which card would you like to heal?\n\n";
	for(int count = 0; count < 3; count++)
	{
		if (hand[count] != cardReference)
		{
			if (cardstats[hand[count]][0] < cardstats[hand[count]][2])
			{
				std::cout << count + 1 << ": " << cards[hand[count]] << "\n";
				canBeHealed[count] = true;
			}
			else
			{
				std::cout << count + 1 << ": This card is already at full health"  << "\n";
			}
		}
		else
		{
			std::cout << count + 1 << ": This card is performing the special action and cannot be selected" << "\n";
		}
	}
	int select;
	std::cin >> select;
	if (!canBeHealed[select])
	{
		std::cout << "\nThis action cannot be preformed on this card, please select another.\n";
		goto reheal;
	}
	else 
	{
		return hand[select];
	}


	
}

void SupportMove(int& supportCard, int& patient)
{
	supportCard--;
	patient++;
}






//this function checks to see if the specified position (NOT the values around it) is unavaillable
//it returns false if it is availlable and true if it is not
bool checkSingleDirection(int pos[2], int board[7][13], bool townTurn) {
	
	if (!townTurn) {
		if (board[pos[0]][pos[1]] > 8 && board[pos[0]][pos[1]] < 19) {
			return false;
		}
		else {
			std::cout << "You cannot move in that direction. Please enter a different one.\n";
			return true;
		}
	}
	else {
		if (board[pos[0]][pos[1]] < 9 || board[pos[0]][pos[1]] == 18) {
			return false;
		}
		else {
			std::cout << "You cannot move in that direction. Please enter a different one.\n";
			return true;
		}
	}
}

//this function gets the direction in which the player wishes to move
//it makes sure the character can move in the selected direction before returning the direction
int getMoveDirection(int pos[2], int board[7][13], bool townTurn) {
	int input;
	bool invalid = true;
	std::cout << "Enter a direction: \n";
	std::cout << "1: UP\n";
	std::cout << "2: LEFT\n";
	std::cout << "3: RIGHT\n";
	std::cout << "4: DOWN\n";
	
	
	while (invalid) {
		input = _getch();
		input = input - 48;
		
		switch (input) {
		case 1:
			pos[0] -= 1;
			invalid = checkSingleDirection(pos, board, townTurn);
			pos[0] += 1;

			break;

		case 2:
			pos[1] -= 1;
			invalid = checkSingleDirection(pos, board, townTurn);
			pos[1] += 1;

			break;

		case 3:
			pos[1] += 1;
			invalid = checkSingleDirection(pos, board, townTurn);
			pos[1] -= 1;

			break;

		case 4:
			pos[0] += 1;
			invalid = checkSingleDirection(pos, board, townTurn);
			pos[0] -= 1;

			break;

		default:
			std::cout << "Invalid input. Please select a valid direction\n";
		}
	}

	return input;

}

//this function checks to see if a certain character is unable to move
//it checks the spaces above, below, and beside the position occupied by the character
//if any of these positions are availlable, the function will return false
bool checkIfTrapped(int board[7][13], int pos[2], bool townTurn) {
	int min = -1;
	int max = 9;

	if (!townTurn) {
		max = 19;
	}

	if (townTurn) {
		if (board[pos[0] - 1][pos[1]] < 9 || board[pos[0] - 1][pos[1]] == 18) {
			return false;
		}
		else if (board[pos[0]][pos[1] - 1] < 9 || board[pos[0]][pos[1] - 1] == 18) {
			return false;
		}
		else if (board[pos[0]][pos[1] + 1] < 9 || board[pos[0]][pos[1] + 1] == 18) {
			return false;
		}
		else if (board[pos[0] + 1][pos[1]] < 9 || board[pos[0] + 1][pos[1]] == 18) {
			return false;
		}else {
			return true;
		}
	}
	else {
		if (board[pos[0] - 1][pos[1]] > 8 && board[pos[0] - 1][pos[1]] < 19) {
			return false;
		}
		else if (board[pos[0]][pos[1] - 1] > 8 && board[pos[0]][pos[1] - 1] < 19) {
			return false;
		}
		else if (board[pos[0]][pos[1] + 1] > 8 && board[pos[0]][pos[1] + 1] < 19) {
			return false;
		}
		else if (board[pos[0] + 1][pos[1]] > 8 && board[pos[0] + 1][pos[1]] < 19) {
			return false;
		}
		else {
			return true;
		}
	}
}

//this funtion returns the value of the card the player wishes to move
//this card must be in the player's hand and be able to move in at least one direction on the board
//this function WILL need modification later someone please remind me
int selectCardToMove(int hand[3], int board[7][13], std::string cards[18], bool townTurn) {
	int count = 1;
	int input;
	bool invalidEntry = true;
	int pos[2];
	int cardVal = -1;
	
	std::cout << ("Which troop will you move?\n");

	for (int i = 0; i < 3; i++) {
		if (hand[i] != -1) {
			std::cout << count << ": " << cards[hand[i]] << "\n";
			count++;
		}
	}

	while (invalidEntry) {
	getInput:

		input = _getch();
		input = input - 49;

		if (input < 0 || input > count - 1) {
			goto getInput;
		}

		cardVal = hand[input];

		//locates selected card on board and stores its position
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 13; j++) {
				if (board[i][j] == cardVal) {
					pos[0] = i;
					pos[1] = j;
				}
			}
		}

		//checks to see if that character is UNABLE to move
		invalidEntry = checkIfTrapped(board, pos, townTurn);
	}

	return cardVal;
}

//this procedure is what is says on the box
//symbols 0-17 are characters
//the remaining symbols are used to indicate spaces that can or cannot be occupied
void printBoard(int board[7][13]) {
	std::string symbols[22];
	symbols[0] = "AM";//amalgam
	symbols[1] = "WO";//wolfman
	symbols[2] = "ZO";//zombie
	symbols[3] = "GH";//ghost
	symbols[4] = "SH";//shifter
	symbols[5] = "VA";//vampire
	symbols[6] = "BA";//banshee
	symbols[7] = "RE";//reaper
	symbols[8] = "WI";//witch	

	symbols[9] = "DE";//detective
	symbols[10] = "LO";//lover
	symbols[11] = "NO";//noble
	symbols[12] = "BE";//beauty
	symbols[13] = "DA";//dancer
	symbols[14] = "ST";//student
	symbols[15] = "DO";//doctor
	symbols[16] = "ME";//mentor
	symbols[17] = "SC";//scientist
	symbols[18] = "__";//unoccupied space
	symbols[19] = "||";//wall placed by user
	symbols[20] = "  ";//outside edge
	symbols[21] = "__";//looks the same as unoccupied space but functions as a barrier

	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 13; j++) {
			if (board[i][j] == 20 || board[i][j] == 21) {
				std::cout << " ";
				std::cout << symbols[board[i][j]];
				std::cout << " ";
			}
			else {
				std::cout << "[";
				std::cout << symbols[board[i][j]];
				std::cout << "]";
			}
		}
		std::cout << "\n";
	}

}

//will randomly draw a card of the specified faction
//if boolean is true, a townie card value will be drawn
//if boolean is false, a terror card will be drawn
//the value (0-17) of the card drawn is returned
int drawCards(bool hasBeenPulled[18], bool townTurn) {
	int lowestCardValue = 0;
	int drawnCard;

	if (townTurn) {
		lowestCardValue += 9;
	}

	draw:
	srand((unsigned)time(0));
	drawnCard = lowestCardValue + (rand() % 9);

	if (hasBeenPulled[drawnCard] == false) {
		return drawnCard;
	}
	else {
		goto draw;
	}
}

int main()
{

	menu();
	//variables

	//lists for character cards and their stats
	std::string cards[18];

	//setting the card reference locations
	cards[0] = "AM";//amalgam
	cards[1] = "WO";//wolfman
	cards[2] = "ZO";//zombie
	cards[3] = "GH";//ghost
	cards[4] = "SH";//shifter
	cards[5] = "VA";//vampire
	cards[6] = "BA";//banshee
	cards[7] = "RE";//reaper
	cards[8] = "WI";//witch	
	
	cards[9] = "DE";//detective
	cards[10] = "LO";//lover
	cards[11] = "NO";//noble
	cards[12] = "BE";//beauty
	cards[13] = "DA";//dancer
	cards[14] = "ST";//student
	cards[15] = "DO";//doctor
	cards[16] = "ME";//mentor
	cards[17] = "SC";//scientist

	//card stats
	int cardstats[18][3]
	{
		{ 4, 5, 4 }, //amalg
		{ 3, 4, 3 },//wolf
		{ 2, 3, 2 },//zombie
		{ 2, 2, 2 },//ghost
		{ 3, 3, 3 },//shift
		{ 4, 4, 4 },//vamp
		{ 3, 2, 3 },//banshee
		{ 5, 4, 5 },//reaper
		{ 4, 3, 4 },//witch
		{ 4, 5, 4 },//detec
		{ 3, 4, 3 },//lover
		{ 2, 3, 2 },//noble
		{ 4, 4, 4 },//beauty
		{ 2, 2, 2 },//dancer
		{ 3, 3, 3 },//stud
		{ 4, 3, 4 },//doctor
		{ 3, 2, 3 },//mentor
		{ 5, 4, 5 }//scientist
	};
	
	int board[7][13]{
		{20, 20, 20, 21, 21, 21, 21, 21, 21, 21, 20, 20, 20 },
		{20, 20, 21, 18, 18, 18, 18, 18, 18, 18, 21, 20, 20 },
		{20, 21, 18, 18, 18, 18, 18, 18, 18, 18, 18, 21, 20 },
		{20, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 20 },
		{20, 20, 18, 18, 18, 18, 18, 18, 18, 18, 18, 20, 20 },
		{20, 20, 20, 18, 18, 18, 18, 18, 18, 18, 20, 20, 20 },
		{20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20 }
	};
	
	bool hasBeenPulled[18] = { false };
	int pos[2];
	int direction = 0;
	int cardToMove;
	bool townTurn = true; //can change as needed, this is a default
	int townHand[3];
	int terrHand[3];
	int movesRemaining = 3;
	bool hasUsedSpecial = false;//default, feel free to modify/replace
	bool actionsOver = false;
	bool townBoost = false;
	bool terrBoost = false;


	//setup game
	//draws starting hands
	for (int i = 0; i < 3; i++) {
		townHand[i] = drawCards(hasBeenPulled, true);
		hasBeenPulled[townHand[i]] = true;
		terrHand[i] = drawCards(hasBeenPulled, false);
		hasBeenPulled[terrHand[i]] = true;
	}

	//puts starting hand on the board
	for (int i = 0; i < 3; i++) {
		board[i + 2][2] = townHand[i];
		board[i + 2][10] = terrHand[i];
	}
	//i hope this procedure doesn't require an explanation
	printBoard(board);
	


	//action function
	//relocate this inside whatever menu thing you've got going
	while (!actionsOver) {
		std::cout << "Press 1 to move one of your troops\n";
		std::cout << "Press 2 to use a Special Action\n";
		if (movesRemaining == 0) {
			std::cout << "Press 3 to end your turn\n";
		}

		int actionInput = _getch();
		actionInput -= 48;

		switch (actionInput) {
		case 1:
			if (movesRemaining > 0) {
				if (townTurn) {
					cardToMove = selectCardToMove(townHand, board, cards, true);
				}
				else {
					cardToMove = selectCardToMove(terrHand, board, cards, false);
				}

				std::cout << cardToMove << "\n";


				for (int i = 0; i < 7; i++) {
					for (int j = 0; j < 13; j++) {
						if (board[i][j] == cardToMove) {

							pos[0] = i;
							pos[1] = j;
						}
					}
				}

				direction = getMoveDirection(pos, board, townTurn);

				board[pos[0]][pos[1]] = 18;
				switch (direction) {
				case 1:
					pos[0] = pos[0] - 1;
					break;

				case 2:
					pos[1] = pos[1] - 1;
					break;

				case 3:
					pos[1] = pos[1] + 1;
					break;

				default:
					pos[0] = pos[0] + 1;
					break;
				}

				if (board[pos[0]][pos[1]] != 18) {
					//placeholder text
					std::cout << "An epic battle between " << cards[cardToMove] << " and " << cards[board[pos[0]][pos[1]]] << " occurs here! \n";
				}
				board[pos[0]][pos[1]] = cardToMove;

				printBoard(board);

				movesRemaining--;
			}
			else {
				std::cout << "You have already used all of your availlable movement oppourtunities!\n";
			}
			break;

		case 2:
			if (!hasUsedSpecial) {
				int specialCard;
				selectSpecial:
				if (townTurn)
				{
					specialCard = SpecialActionSelect(townHand, townTurn);
				}
				else
				{
					specialCard = SpecialActionSelect(terrHand, townTurn);
				}
				std::cout << "\n" << specialCard << "\n";
				int cardReference = specialCard;
				if (townTurn) { specialCard -= 9; }
				if (specialCard < 3)
				{
					if (townTurn)
					{
						townBoost =  PowerMove(cardReference, townBoost);
					}
					else
					{
						terrBoost = PowerMove(cardReference, terrBoost);
					}
				}
				else if (specialCard < 6)
				{
					//speed function call
				}
				else
				{
					
					if (townTurn)
					{
						int patient = ChoosePatient(cardstats, townHand, cardReference, cards);
						if (patient == -1)
						{
							goto selectSpecial;
						}
						SupportMove(cardstats[cardReference][0], cardstats[patient][0]);
					}
					else
					{
						int patient = ChoosePatient(cardstats, terrHand, cardReference, cards);
						if (patient == -1)
						{
							goto selectSpecial;
						}
						SupportMove(cardstats[cardReference][0], cardstats[patient][0]);
					}
				}
				hasUsedSpecial = true;
			}
			else {
				std::cout << "You have already used your special action on this turn!\n";
			}
			break;

		case 3:
			if (movesRemaining == 0) {
				std::cout << "Your turn is now over.\n";
				actionsOver = true;
			}
			else {
				std::cout << "You must move " << movesRemaining << " more time/s\n";
			}
			break;

		default:
			std::cout << "Invalid input. Please try again. \n";
		}
	}

}






/*// CombatSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <windows.h>
int rollDice();//function designed to simulate a dice roll
void battle(int& card1Health, int& card1Strength, int& card2Health, int& card2Strength);//function designed to simulate a battle between two cards
void SetColor(int);
int main()
{
	int doctorHealth = 4;//test case
	int doctorStrength = 3;//test case

	int witchHealth = 4;//test case
	int witchStrength = 3;//test case

	battle(doctorHealth, doctorStrength, witchHealth, witchStrength);//function is called here

}
int rollDice()
{
	int diceFacingUp;//elaborate variable name to avoid plagiarism
	srand(time(0)+rand());//not exactly sure what's goingg on here but it works.

	diceFacingUp = rand() % 7;//ensures that the random number is between 0 and 6
	while (diceFacingUp == 0)//if the value of diceFacingUp is 0, it will be rerolled until it is not zero
	{
		diceFacingUp = rand() % 7;
	}
	return diceFacingUp;
}

void SetColor(int value)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
}

void battle(int& card1Health, int& card1Strength, int& card2Health, int& card2Strength)
{
	//card1 represents the cards of the player who initiated the battle
	//card2 represents the cards of the player who is being attacked
	//the stats of the player who initiated the battle should always be written in the first 2 parameters(CONTINUED)
	//while the stats of the player being attacked should be written in the last 2 parameters
	bool p1Attacking = true;//used to decide which player is rolling the dice.
	bool p2Attacking = false;//used to decide which player is rolling the dice.
	bool battleEnd = false;
	int diceRoll;
	while (battleEnd == false)
	{
		if (p1Attacking == true)
		{
			SetColor(11);
			diceRoll = rollDice();
			std::cout << "Player 1's Turn\n";
			std::cout << "Number rolled: " << diceRoll << "\n";
			if (diceRoll >= card2Strength)//checks to see if the number rolled by the player is greater or equal to the opposing card's strength
			{
				card2Health -= 1;
				std::cout << "Card1 deals damage to Card2\n";
				std::cout << "Card1 health: " << card1Health << " Card1 Strength: " << card1Strength << "\n";
				std::cout << "Card2 health: " << card2Health << " Card2 Strength: " << card2Strength << "\n";
			}
			else
			{
				std::cout << "No damage done\n";
			}
			p1Attacking = false;
			p2Attacking = true;
		}
		else if (p2Attacking == true)
		{
			SetColor(5);
			diceRoll = rollDice();
			std::cout << "Player 2's Turn\n";
			std::cout << "Number rolled: " << diceRoll << "\n";
			if (diceRoll >= card1Strength)
			{
				card1Health -= 1;
				std::cout << "Card2 deals damage to Card1\n";
				std::cout << "Card1 health: " << card1Health << " Card1 Strength: " << card1Strength << "\n";
				std::cout << "Card2 health: " << card2Health << " Card2 Strength: " << card2Strength << "\n";
			}
			else
			{
				std::cout << "No damage done\n";
			}
			p1Attacking = true;
			p2Attacking = false;
		}
		if (card1Health <= 0)
		{
			std::cout << "Player2 wins\n";
			battleEnd = true;
		}
		if (card2Health <= 0)
		{
			std::cout << "Player1 wins\n";
			battleEnd = true;
		}
	}
}
*/

