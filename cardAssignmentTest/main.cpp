#include <iostream>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <cstdlib>

void menu();

void clear(int y) {
	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO IpCursor;
	IpCursor.bVisible = false;
	IpCursor.dwSize = 1;
	SetConsoleCursorInfo(hconsole, &IpCursor);

	std::cout.flush();
	COORD coord = { (SHORT)0, (SHORT)y };
	SetConsoleCursorPosition(hconsole, coord);
}

void wipeText() {
	clear(7);
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 35; j++) {
			std::cout << ("   ");
		}
		std::cout << '\n';
	}
	clear(7);
}


void wipeScreen() {
	clear(0);
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 40; j++) {
			std::cout << ("   ");
		}
		std::cout << '\n';
	}
	clear(0);

}

int rollDice()
{
	int diceFacingUp;//elaborate variable name to avoid plagiarism
	srand(time(0) + rand());

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

void battle(int& card1Health, int card1Strength, int& card2Health, int card2Strength, bool townTurn, bool& card1boost, bool& card2boost)
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
			if (townTurn) {
				SetColor(11);
			}
			else {
				SetColor(5);
			}
			
			diceRoll = rollDice();
			
			if (card1boost)
			{
				if (diceRoll != 6)
				{
					diceRoll += 1;
					card1boost = false;
				}
			}
				
			
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
			if (townTurn) {
				SetColor(5);
			}
			else {
				SetColor(11);
			}

			diceRoll = rollDice();
				if (card2boost)
				{
					if (diceRoll != 6)
					{
						diceRoll += 1;
						card2boost = false;
					}
				}
				
			
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

		std::cout << "Press any key to continue\n";
		int input = _getch();
		wipeText();
	}
}

// declares functions for the game and info
void story()
{
	int peoples;
	int type;
	int persons;
restartone:
	std::cout << "Which would you like to see? \n \n1: Townies \n \n2: Terrors \n \n3: Return to Menu \n";

	peoples = _getch();

	if (peoples == 50)
	{
	restarttwo:
		std::cout << "\n\nWhich type of Terror would you like to learn about?\n \n1: Power\n \n2: Speed\n \n3: Support\n\n";
		type = _getch();

		if (type == 49)
		{
		restartthree:
			std::cout << "\n\nWhich Terror would you like to learn about?\n \n1: Amalgam\n \n2: Wolfman\n \n3: Zombie\n\n";
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
			std::cout << "\n\nWhich terror would you like to learn about?\n \n1: Vampire\n \n2: Ghost\n \n3: Shifter\n\n";
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
			std::cout << "\n\nWhich Terror would you like to learn about?\n \n1: Reaper\n\n2: Banshee\n\n3: Witch\n\n";
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
		std::cout << "\n\nWhich type of Townie would you like to learn about?\n\n1: Power\n\n2: Speed\n\n3: Support\n\n";
		type = _getch();

		if (type == 49)
		{
		restartseven:
			std::cout << "\n\nWhich Townie would you like to learn about?\n\n1: Detective\n\n2: Lover\n\n3: Noble\n\n";
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
			std::cout << "\n\nWhich Townie would you like to learn about?\n\n1: Beauty\n\n2: Dancer\n\n3: Student\n\n";
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
			std::cout << "\n\nWhich Townie would you like to learn about?\n\n1: Scientist\n\n2: Mentor\n\n3: Doctor\n\n";
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

void title()
{
	
	int start;
	int loop = 0;

	
	std::cout << " \n\n\n\n\n\n\n\n            ___  _, _  _ _, _ _ __,  _,          _, _, _ __,         ___ __, __, __,  _, __,  _, \n" <<
		"             |  / \\ |  | |\\ | | |_  (_          /_\\ |\\ | | \\          |  |_  |_) |_) / \\ |_) (_ \n" <<
		"             |  \\ / |/\\| | \\| | |   , )         | | | \\| |_/          |  |   | \\ | \\ \\ / | \\ , ) \n" <<
		"             ~   ~  ~  ~ ~  ~ ~ ~~~  ~          ~ ~ ~  ~ ~            ~  ~~~ ~ ~ ~ ~  ~  ~ ~  ~ \n \n";

	std::cout << "\n\n\n\n\n\n\n\n\n                                           Press Any Button \n\n\n\n\n\n\n";
	
	start = _getch();
	while (start == ' \n') {
		start = _getch();
	}
	wipeScreen();
	menu();
}
void menu()
{
	int ask;
	int hold = 1;
	

beginning:
	//asks users where they would like to go
	std::cout << "Please enter where you would like to go \n\n";
	std::cout << "1: play \n \n2: info  \n \n3: quit \n\n";
	ask = _getch();

	while (hold != 0)
	{
		if (ask == 49)
		{
			
			hold = 0;
		}
		else if (ask == 50)
		{
			
			story();
			goto beginning;
		}
		else if (ask == 51)
		{
			std::cout << "\n\nThank you for playing Townies and Terrors.\n\n";
			exit(1);
		}
		else
		{
			std::cout << "Please enter one of the options. \n\n";
			ask = _getch();
		}
	}
}
//hehehehee sneaky comment


int SpecialActionSelect(int hand[3], std::string cards[18], bool townTurn)
{
	bool canDoSpecialAction[3]{ false };
	int card;
	int select;

enterChoice:
	std::cout << "Which card will perform the special action?\n";
	for (int i = 0; i < 3; i++) {
		if (hand[i] > -1) {
			std::cout << i + 1 << ": " << cards[hand[i]] << "\n";
			canDoSpecialAction[i] = true;
		}
		else {
			std::cout << "[Empty Slot, cannot select]\n";
		}
	}
	std::cout << "Press 4 to go back";
	
	select = _getch();

	select -= 49;

	if (select == 3) {
		card = -1;
	}
	else if (select < 3 && select > -1) {
		if (canDoSpecialAction[select]) {
			card = hand[select];
		}
		else {
			goto enterChoice;
		}
	}
	else {
		goto enterChoice;
	}
	
	return card;
}

bool PowerMove(int cardReference, bool hasBoosted)
{
	if (!hasBoosted)
	{
		std::cout << "You will get a +1 bonus on your next attack roll!\n";
		hasBoosted = true;
	}
	else {
		std::cout << "You have already used this ability! You can use it again after a fight.\n";
	}

	std::cout << "Press any key to continue\n";
	int input = _getch();
	//if true, stength boost will add one at the end of next roll then be set to false
	return hasBoosted;
}



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

	std::cout << "Press 4 to go back\n";

	int select;
	select = _getch();
	select -= 49;

	if (select < 0 || select > 3) {
		goto reheal;
	}
	
	if (select == 3) {
		return -1;
	}

	if (!canBeHealed[select])
	{
		std::cout << "This action cannot be performed on this card, please select another.\n";
		goto reheal;
	}
	else 
	{
		std::cout << "Healing " << cards[hand[select]] << "\n";
		return hand[select];
	}


	
}

void SupportMove(int& supportCard, int& patient)
{
	supportCard--;
	patient++;

	std::cout << "Patient has been healed! Press any key to continue";
	int input;
	input = _getch();

}


bool checkIfEmpty(int hand[3]) {
	if (hand[0] == -1) {
		if (hand[1] == -1) {
			if (hand[2] == -1) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

//this function checks to see if the specified position (NOT the values around it) is unavaillable
//it returns false if it is availlable and true if it is not
bool checkSingleDirection(int pos[2], int board[7][13], bool townTurn) {
	
	if (!townTurn) {
		if (board[pos[0]][pos[1]] > 8 && board[pos[0]][pos[1]] < 19 && pos[1]!= 1 && pos[1]!= 12) {
			return false;
		}
		else {
			std::cout << "You cannot move in that direction. Please enter a different one.\n";
			return true;
		}
	}
	else {
		if ((board[pos[0]][pos[1]] < 9 || board[pos[0]][pos[1]] == 18) && pos[1] != 1 && pos[1] != 12) {
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
void getMoveDirection(int& y, int& x, int board[7][13], bool townTurn) {
	int input;
	bool invalid = true;
	int pos[2]{ y, x }; 
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
			
			if (!invalid) {
				y -= 1;
			}
			pos[0] += 1;

			break;

		case 2:
			pos[1] -= 1;
			invalid = checkSingleDirection(pos, board, townTurn);
			
			if (!invalid) {
				x -= 1;
			}
			pos[1] += 1;

			break;

		case 3:
			pos[1] += 1;
			invalid = checkSingleDirection(pos, board, townTurn);
			
			if (!invalid) {
				x += 1;
			}
			pos[1] -= 1;

			break;

		case 4:
			pos[0] += 1;
			invalid = checkSingleDirection(pos, board, townTurn);
			
			if (!invalid) {
				y += 1;
			}
			pos[0] -= 1;

			break;

		default:
			std::cout << "Invalid input. Please select a valid direction\n";
		}
	}
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
		else if ((board[pos[0]][pos[1] - 1] < 9 || board[pos[0]][pos[1] - 1] == 18) && pos[1]!= 2) {
			return false;
		}
		else if ((board[pos[0]][pos[1] + 1] < 9 || board[pos[0]][pos[1] + 1] == 18) && pos[1]!= 11) {
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
		else if (board[pos[0]][pos[1] - 1] > 8 && board[pos[0]][pos[1] - 1] < 19 && pos[1] > 3) {
			return false;
		}
		else if (board[pos[0]][pos[1] + 1] > 8 && board[pos[0]][pos[1] + 1] < 19 && pos[1] < 10) {
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

//this method determines where to place a new character
//it tries to place the character as close as possible to the player's side of the board
//kinda gross but if you have a prettier way of doing this i'm all ears
void getSpawnLoc(int& y, int& x, int board[7][13], bool townTurn) {
	if(townTurn){
		if (board[3][1] == 18) {
			y = 3;
			x = 1;
		}
		else if (board[3][2] == 18) {
			y = 3;
			x = 2;
		}
		else if (board[2][2] == 18) {
			y = 2;
			x = 2;
		}
		else if (board[4][2] == 18) {
			y = 4; 
			x = 2;
		}
		else if (board[3][3] == 18) {//at this point, you are doing a horrible job at the game
			y = 3;
			x = 3;
		}
		else if (board[2][3] == 18) {
			y = 2;
			x = 3;
		}
		else {
			y = 4;
			x = 3;
		}
	}
	else {
		if (board[3][12] == 18) {
			y = 3;
			x = 12;
		}
		else if (board[3][11] == 18) {
			y = 3;
			x = 11;
		}
		else if (board[2][11] == 18) {
			y = 2;
			x = 11;
		}
		else if (board[4][11] == 18) {
			y = 4;
			x = 11;
		}
		else if (board[3][10] == 18) {//at this point, you are doing a horrible job at the game
			y = 3;
			x = 10;
		}
		else if (board[2][10] == 18) {
			y = 2;
			x = 10;
		}
		else {
			y = 4;
			x = 10;
		}
	}
	
}

//this funtion returns the value of the card the player wishes to move
//this card must be in the player's hand and be able to move in at least one direction on the board
int selectCardToMove(int hand[3], int board[7][13], std::string cards[18], bool townTurn) {
	bool canSelect[3]{ false };
	int input;
	bool invalidEntry = true;
	int pos[2];
	int cardVal = -1;
	
	std::cout << ("Which troop will you move?\n");

	for (int i = 0; i < 3; i++) {
		if (hand[i] != -1) {
			std::cout << i+1 << ": " << cards[hand[i]] << "\n";
			canSelect[i] = true;
		}
		else {
			std::cout << "[Empty Slot, cannot select]\n";
		}
	}

	while (invalidEntry) {
	getInput:

		input = _getch();
		input = input - 49;
		wipeText();

		if (input < 0 || input > 2|| canSelect[input] == false) {
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
void printBoard(int board[7][13], bool townTurn) {
	SetColor(15);
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
	if (townTurn)
	{
		SetColor(11);
	}
	else
	{
		SetColor(5);
	}

}

void placeWalls(int& sq1, int& sq2, int& sq3, int& sq4, int& sq5, int& sq6, int& sq7, int& sq8, int& sq9, int& sq10, int board[7][13], bool townTurn) {
	int input;

	if (townTurn) {
		std::cout << "Townie player, ";
	}
	else {
		std::cout << "Terror player, ";
	}

	for (int i = 0; i < 3; i++) {
	selectSquare:
		
		std::cout << "enter the number of the square you wish to place a wall on:\n";
		std::cout << " [1][2]\n";
		std::cout << " [3][4]\n";
		std::cout << " [5][6]\n";
		std::cout << " [7][8]\n";
		std::cout << " [9][0]\n";

		input = _getch();
		input -= 48;
		wipeText();
		if (input < 10 && input > -1) {
			switch (input) {
			case 1:
				if (sq1 == 18) {
					sq1 = 19;
					std::cout << "Wall " << i + 1 << " of 3 placed!\n";
				}
				else {
					std::cout << "There is already a wall there!\n";
					goto selectSquare;
				}
				break;

			case 2:
				if (sq2 == 18) {
					sq2 = 19;
					std::cout << "Wall " << i + 1 << " of 3 placed!\n";
				}
				else {
					std::cout << "There is already a wall there!\n";
					goto selectSquare;
				}
				break;

			case 3:
				if (sq3 == 18) {
					sq3 = 19;
					std::cout << "Wall " << i + 1 << " of 3 placed!\n";
				}
				else {
					std::cout << "There is already a wall there!\n";
					goto selectSquare;
				}
				break;

			case 4:
				if (sq4 == 18) {
					sq4 = 19;
					std::cout << "Wall " << i + 1 << " of 3 placed!\n";
				}
				else {
					std::cout << "There is already a wall there!\n";
					goto selectSquare;
				}
				break;

			case 5:
				if (sq5 == 18) {
					sq5 = 19;
					std::cout << "Wall " << i + 1 << " of 3 placed!\n";
				}
				else {
					std::cout << "There is already a wall there!\n";
					goto selectSquare;
				}
				break;

			case 6:
				if (sq6 == 18) {
					sq6 = 19;
					std::cout << "Wall " << i + 1 << " of 3 placed!\n";
				}
				else {
					std::cout << "There is already a wall there!\n";
					goto selectSquare;
				}
				break;

			case 7:
				if (sq7 == 18) {
					sq7 = 19;
					std::cout << "Wall " << i + 1 << " of 3 placed!\n";
				}
				else {
					std::cout << "There is already a wall there!\n";
					goto selectSquare;
				}
				break;

			case 8:
				if (sq8 == 18) {
					sq8 = 19;
					std::cout << "Wall " << i + 1 << " of 3 placed!\n";
				}
				else {
					std::cout << "There is already a wall there!\n";
					goto selectSquare;
				}
				break;

			case 9:
				if (sq9 == 18) {
					sq9 = 19;
					std::cout << "Wall " << i + 1 << " of 3 placed!\n";
				}
				else {
					std::cout << "There is already a wall there!\n";
					goto selectSquare;
				}
				break;

			default:
				if (sq10 == 18) {
					sq10 = 19;
					std::cout << "Wall " << i + 1 << " of 3 placed!\n";
				}
				else {
					std::cout << "There is already a wall there!\n";
					goto selectSquare;
				}
			}

		}
		else {
			std::cout << "Invalid Entry. Try again";
			goto selectSquare;
		}
		
		wipeScreen();
		printBoard(board, townTurn);
	}

}


//will randomly draw a card of the specified faction
//if boolean is true, a townie card value will be drawn
//if boolean is false, a terror card will be drawn
//the value (0-17) of the card drawn is returned
int drawCards(bool hasBeenPulled[18], bool townTurn) {
	int lowestCardValue = 0;
	int highest = 9;
	int drawnCard;
	bool allCardsDrawn = true;

	if (townTurn) {
		lowestCardValue += 9;
		highest += 9;
	}

	for (int i = lowestCardValue; i < highest; i++) {
		if (hasBeenPulled[i] == false) {
			allCardsDrawn = false;
		}
	}

	if (!allCardsDrawn) {
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
	else {
		return -1;
	}
	
}

int main()
{

	title();

	wipeScreen();

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
	bool townTurn = true;
	int townHand[3];
	int terrHand[3];
	int movesRemaining = 3;
	bool hasUsedSpecial = false;
	bool actionsOver = false;
	bool townBoost = false;
	bool terrBoost = false;
	bool townHandEmpty = false;
	bool terrHandEmpty = false;


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
	printBoard(board, townTurn);
	std::cout << "\n\nThe Townies move first (they start on the left side of the board)\n\n";
	SetColor(11);

	//has both players place three walls
	placeWalls(board[1][4], board[1][5], board[2][4], board[2][5], board[3][4], board[3][5], board[4][4], board[4][5], board[5][4], board[5][5], board, true);
	SetColor(5);
	placeWalls(board[1][7], board[1][8], board[2][7], board[2][8], board[3][7], board[3][8], board[4][7], board[4][8], board[5][7], board[5][8], board, false);
	SetColor(11);


	//main gameplay loop! hooray!

	while (!terrHandEmpty && !townHandEmpty) {
		
		if (townTurn) {
			std::cout << "\Townie's Turn\n";
		}
		else {
			std::cout << "\Terror's Turn\n";
		}

		while (!actionsOver) {
			turnOptions:
			std::cout << "Press 1 to move one of your troops\n";
			std::cout << "Press 2 to use a Special Action\n";
			if (movesRemaining == 0) {
				std::cout << "Press 3 to end your turn\n";
			}

			int actionInput = _getch();
			wipeText();
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

					wipeText();

					for (int i = 0; i < 7; i++) {
						for (int j = 0; j < 13; j++) {
							if (board[i][j] == cardToMove) {

								pos[0] = i;
								pos[1] = j;
							}
						}
					}

					board[pos[0]][pos[1]] = 18;
					getMoveDirection(pos[0], pos[1], board, townTurn);

					wipeText();

					if (board[pos[0]][pos[1]] != 18) {
						if (townTurn) {
							battle(cardstats[cardToMove][0], cardstats[cardToMove][1], cardstats[board[pos[0]][pos[1]]][0], cardstats[board[pos[0]][pos[1]]][0], townTurn, townBoost, terrBoost);
						}
						else {
							battle(cardstats[cardToMove][0], cardstats[cardToMove][1], cardstats[board[pos[0]][pos[1]]][0], cardstats[board[pos[0]][pos[1]]][0], townTurn, terrBoost, townBoost);
						}

						if (cardstats[cardToMove][0] > 0) {
						
							if (townTurn) {
								for (int i = 0; i < 3; i++) {
									if (terrHand[i] == board[pos[0]][pos[1]]) {
										terrHand[i] = drawCards(hasBeenPulled, false);

										if (terrHand[i] != -1) {
											hasBeenPulled[terrHand[i]] = true;
											int spawnLoc[2]{ 0 };
											getSpawnLoc(spawnLoc[0], spawnLoc[1], board, false);
											board[spawnLoc[0]][spawnLoc[1]] = terrHand[i];
										}
									}
								
								}
							}
							else {
								for (int i = 0; i < 3; i++) {
									if (townHand[i] == board[pos[0]][pos[1]]) {
										townHand[i] = drawCards(hasBeenPulled, true);

										if (townHand[i] != -1) {
											hasBeenPulled[townHand[i]] = true;
											int spawnLoc[2]{ 0 };
											getSpawnLoc(spawnLoc[0], spawnLoc[1], board, true);
											board[spawnLoc[0]][spawnLoc[1]] = townHand[i];
										}
									}

								}

							}
						
							board[pos[0]][pos[1]] = cardToMove;
							wipeScreen();
							printBoard(board, townTurn);
						}
						else {
							if (townTurn) {
								for (int i = 0; i < 3; i++) {
									if (townHand[i] == cardToMove) {
										townHand[i] = drawCards(hasBeenPulled, true);

										if (townHand[i] != -1) {
											hasBeenPulled[townHand[i]] = true;
											int spawnLoc[2]{ 0 };
											getSpawnLoc(spawnLoc[0], spawnLoc[1], board, true);
											board[spawnLoc[0]][spawnLoc[1]] = townHand[i];
										}
									}

								}
							}
							else {
								for (int i = 0; i < 3; i++) {
									if (terrHand[i] == cardToMove) {
										terrHand[i] = drawCards(hasBeenPulled, false);

										if (terrHand[i] != -1) {
											hasBeenPulled[terrHand[i]] = true;
											int spawnLoc[2]{ 0 };
											getSpawnLoc(spawnLoc[0], spawnLoc[1], board, false);
											board[spawnLoc[0]][spawnLoc[1]] = terrHand[i];
										}
									}

								}

							}

							wipeScreen();
							printBoard(board, townTurn);
						}
					}
					else {
						board[pos[0]][pos[1]] = cardToMove;
						wipeScreen();
						printBoard(board, townTurn);
					}
				

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
						specialCard = SpecialActionSelect(townHand, cards, townTurn);
					}
					else
					{
						specialCard = SpecialActionSelect(terrHand, cards, townTurn);
					}
					
					wipeText();
					
					if (specialCard == -1) {
						
						goto turnOptions;
					}

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
						wipeText();
					}
					else if (specialCard < 6)
					{
						bool trapped;
						for (int i = 0; i < 7; i++) {
							for (int j = 0; j < 13; j++) {
								if (board[i][j] == cardReference) {

									pos[0] = i;
									pos[1] = j;
								}
							}
						}

						trapped = checkIfTrapped(board, pos, townTurn);

						if (!trapped) {
							board[pos[0]][pos[1]] = 18;
							getMoveDirection(pos[0], pos[1], board, townTurn);

							if (board[pos[0]][pos[1]] != 18) {

								if (townTurn) {
									battle(cardstats[cardReference][0], cardstats[cardReference][1], cardstats[board[pos[0]][pos[1]]][0], cardstats[board[pos[0]][pos[1]]][0], townTurn, townBoost, terrBoost);
								}
								else {
									battle(cardstats[cardReference][0], cardstats[cardReference][1], cardstats[board[pos[0]][pos[1]]][0], cardstats[board[pos[0]][pos[1]]][0], townTurn, terrBoost, townBoost);
								}

								if (cardstats[cardReference][0] > 0) {

									if (townTurn) {
										for (int i = 0; i < 3; i++) {
											if (terrHand[i] == board[pos[0]][pos[1]]) {
												terrHand[i] = drawCards(hasBeenPulled, false);

												if (terrHand[i] != -1) {
													hasBeenPulled[terrHand[i]] = true;
													int spawnLoc[2]{ 0 };
													getSpawnLoc(spawnLoc[0], spawnLoc[1], board, false);
													board[spawnLoc[0]][spawnLoc[1]] = terrHand[i];
												}
											}

										}
									}
									else {
										for (int i = 0; i < 3; i++) {
											if (townHand[i] == board[pos[0]][pos[1]]) {
												townHand[i] = drawCards(hasBeenPulled, true);

												if (townHand[i] != -1) {
													hasBeenPulled[townHand[i]] = true;
													int spawnLoc[2]{ 0 };
													getSpawnLoc(spawnLoc[0], spawnLoc[1], board, true);
													board[spawnLoc[0]][spawnLoc[1]] = townHand[i];
												}
											}

										}

									}

									board[pos[0]][pos[1]] = cardReference;
									wipeScreen();
									printBoard(board, townTurn);
								}
								else {
									if (townTurn) {
										for (int i = 0; i < 3; i++) {
											if (townHand[i] == cardReference) {
												townHand[i] = drawCards(hasBeenPulled, true);

												if (townHand[i] != -1) {
													hasBeenPulled[townHand[i]] = true;
													int spawnLoc[2]{ 0 };
													getSpawnLoc(spawnLoc[0], spawnLoc[1], board, true);
													board[spawnLoc[0]][spawnLoc[1]] = townHand[i];
												}
											}

										}
									}
									else {
										for (int i = 0; i < 3; i++) {
											if (terrHand[i] == cardReference) {
												terrHand[i] = drawCards(hasBeenPulled, false);

												if (terrHand[i] != -1) {
													hasBeenPulled[terrHand[i]] = true;
													int spawnLoc[2]{ 0 };
													getSpawnLoc(spawnLoc[0], spawnLoc[1], board, false);
													board[spawnLoc[0]][spawnLoc[1]] = terrHand[i];
												}
											}

										}

									}
									wipeScreen();
									printBoard(board, townTurn);
								}
							}
							else {
								board[pos[0]][pos[1]] = cardReference;
								wipeScreen();
								printBoard(board, townTurn);
							}

						}
						else {
							std::cout << "This card cannot currently be moved. Press any key to go back\n";
							int input;
							input = _getch();
							wipeText();
							goto selectSpecial;
						}
					}
					else
					{
					
						if (townTurn)
						{
							int patient = ChoosePatient(cardstats, townHand, cardReference, cards);
							wipeText();
							if (patient == -1)
							{
								goto selectSpecial;
							}
							SupportMove(cardstats[cardReference][0], cardstats[patient][0]);
						}
						else
						{
							int patient = ChoosePatient(cardstats, terrHand, cardReference, cards);
							wipeText();
							if (patient == -1)
							{
								goto turnOptions;
							}
							SupportMove(cardstats[cardReference][0], cardstats[patient][0]);
						}

						wipeText();
					}
					hasUsedSpecial = true;
				}
				else {
					std::cout << "You have already used your special action on this turn!\n";
				}
				break;

			case 3:
				if (movesRemaining == 0) {
					std::cout << "Your turn is now over. Press any key to continue\n";
					int input = _getch();
					actionsOver = true;
					wipeText();
				}
				else {
					std::cout << "You must move " << movesRemaining << " more time(s)\n";
				}
				break;

			default:
				std::cout << "Invalid input. Please try again. \n";
			}

			if(townTurn){
				townHandEmpty = checkIfEmpty(townHand);
				if (townHandEmpty) {
					actionsOver = true;
				}
			}
			else {
				terrHandEmpty = checkIfEmpty(terrHand);
				if (townHandEmpty) {
					actionsOver = true;
				}
			}
		}

		actionsOver = false;
		movesRemaining = 3;
		hasUsedSpecial = false;

		townHandEmpty = checkIfEmpty(townHand);
		if (!townHandEmpty) {
			terrHandEmpty = checkIfEmpty(terrHand);
			if (terrHandEmpty) {
				wipeScreen();
				std::cout << "\n\n\n\n     ___ _,_ __,   ___  _, _  _ _, _ _ __,  _,   _,_  _, _,_ __,   ___ __, _ _,_ _, _ __, _,_ __, __,  \n" <<
					"      |  |_| |_     |  / \\ |  | |\\ | | |_  (_    |_| /_\\ | / |_     |  |_) | | | |\\/| |_) |_| |_  | \\  \n" <<
					"      |  | | |      |  \\ / |/\\| | \\| | |   , )   | | | | |/  |      |  | \\ | | | |  | |   | | |   |_/  \n" <<
					"      ~  ~ ~ ~~~    ~   ~  ~  ~ ~  ~ ~ ~~~  ~    ~ ~ ~ ~ ~   ~~~    ~  ~ ~ ~ `~' ~  ~ ~   ~ ~ ~~~ ~    \n\n\n" <<
					"                 _, _,_ __, __,   ___ _,_ __,   ___ __, __, __,  _, __,  _, ,                       \n" <<
					"                / \\ | / |_  |_)    |  |_| |_     |  |_  |_) |_) / \\ |_) (_  |                       \n" <<
					"                \\ / |/  |   | \\    |  | | |      |  |   | \\ | \\ \\ / | \\ , ) |                       \n" <<
					"                 ~  ~   ~~~ ~ ~    ~  ~ ~ ~~~    ~  ~~~ ~ ~ ~ ~  ~  ~ ~  ~  .                       ";
			}
		}
		else {
			std::cout << "\n\n\n\n     ___ _,_ __,   ___ __, __, __,  _, __,  _,   _,_  _, _,_ __,   ___ __, _ _,_ _, _ __, _,_ __, __,  \n" <<
				"      |  |_| |_     |  |_  |_) |_) / \\ |_) (_    |_| /_\\ | / |_     |  |_) | | | |\\/| |_) |_| |_  | \\  \n" <<
				"      |  | | |      |  |   | \\ | \\ \\ / | \\ , )   | | | | |/  |      |  | \\ | | | |  | |   | | |   |_/  \n" <<
				"      ~  ~ ~ ~~~    ~  ~~~ ~ ~ ~ ~  ~  ~ ~  ~    ~ ~ ~ ~ ~   ~~~    ~  ~ ~ ~ `~' ~  ~ ~   ~ ~ ~~~ ~    \n\n\n" <<
				"                  _, _,_ __, __,   ___ _,_ __,   ___  _, _  _ _, _ _ __,  _, ,                       \n" <<
				"                 / \\ | / |_  |_)    |  |_| |_     |  / \\ |  | |\\ | | |_  (_  |                       \n" <<
				"                 \\ / |/  |   | \\    |  | | |      |  \\ / |/\\| | \\| | |   , ) |                       \n" <<
				"                  ~  ~   ~~~ ~ ~    ~  ~ ~ ~~~    ~   ~  ~  ~ ~  ~ ~ ~~~  ~  .                       ";
		}


		if (townTurn) {
			townTurn = false;
			SetColor(5);
		}
		else {
			townTurn = true;
			SetColor(11);
		}
	}


}
//sneaky end comment