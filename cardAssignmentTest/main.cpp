#include <iostream>
#include <ctime>
#include <conio.h>

//
//bool specialPoint = true;
//bool strengthBoost = false;
//int actionPoint = 3;
//
//
//bool SpecialActionCheck() { return specialPoint; }
//
//void SpecialAction(std::string cardOne, std::string cardTwo, std::string cardThree)
//{
//	std::cout << cardOne << " " << cardTwo << " " << cardThree;
//	std::string select;
//	if (SpecialActionCheck)
//	{
//		std::cout << "\n\nWhich card will preform the special action?\nEnter 'back' to cancel the special action.\n\n";
//		std::cin >> select;
//		if (select == cardOne)
//		{
//			//check class type somehow
//			//if(speedType)
//			//{
//				//call specialMovement();
//				//(it would be the same movement function but we can pass in the character that is moveing and skip a few steps)
//				//(also this function would not subtract one from action points)
//				specialPoint = false;
//				return;
//			//}
//
//			//check class type somehow
//			//if(powerType)
//			//{
//				strengthBoost = true;
//				//if true, stength boost will add one at the end of next roll then be set to false
//				specialPoint = false;
//				return;
//			//}
//
//			//check class type somehow
//			//if(supportType)
//			//{
//				//if(cardThree'sHealth > 1)
//				//{
//					//cardThree'sHealth --;
//				chooseHeal:
//				invalid:
//					//std::cout << "\n\nWhich card would you like to give health to?\nEnter back to cancel\n\n";
//					//std::cin >> select;
//					if (select == cardOne)
//					{
//						//if(cardOneHealth < MAXHEALTH)
//						//{
//							//cardOneHealth++;
//						//}
//						//else
//						//{
//						std::cout << "\n\nThis character is already at full health, please choose another.\n\n";
//						goto chooseHeal;
//						//}
//					}
//					else if (select == cardTwo)
//					{
//						//if(cardTwoHealth < MAXHEALTH)
//						//{
//							//cardTwoHealth++;
//						//}
//						//else
//						//{
//						std::cout << "\n\nThis character is already at full health, please choose another.\n\n";
//						goto chooseHeal;
//						//}
//					}
//					else
//					{
//						std::cout << "\n\nNot a valid selection, please try again.\n\n";
//						goto invalid;
//					}
//				//}
//				
//				specialPoint = false;
//				return;
//				//}
//
//
//		}
//		else if (select == cardTwo)
//		{
//
//		}
//		else if (select == cardThree)
//		{
//
//		}
//		else if (select == "back")
//		{
//			return;
//		}
//	}
//
//}
//


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
	int cardstats[18][2]
	{
		{ 4, 5 }, //amalg
		{ 3, 4 },//wolf
		{ 2, 3 },//zombie
		{ 2, 2 },//ghost
		{ 3, 3 },//shift
		{ 4, 4 },//vamp
		{ 3, 2 },//banshee
		{ 5, 4 },//reaper
		{ 4, 3 },//witch
		{ 4, 5 },//detec
		{ 3, 4 },//lover
		{ 2, 3 },//noble
		{ 4, 4 },//beauty
		{ 2, 2 },//dancer
		{ 3, 3 },//stud
		{ 4, 3 },//doctor
		{ 3, 2 },//mentor
		{ 5, 4 }//scientist
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
				//replace with code for special actions
				std::cout << "Your special would be selected and used here!\n";
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



