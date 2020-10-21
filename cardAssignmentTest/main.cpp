#include <iostream>

bool specialPoint = true;
bool strengthBoost = false;
int actionPoint = 3;

int drawCards(bool hasBeenPulled[18], bool townTurn) {
	int lowestCardValue;
	int location;
	int drawnCard;
	
	location = rand() % 3;
	lowestCardValue = 6 * location;

	if (townTurn) {
		lowestCardValue = lowestCardValue + 3;
	}

	draw:
	drawnCard = lowestCardValue + (rand() % 3);

	if (hasBeenPulled[drawnCard] == false) {
		return drawnCard;
	}
	else {
		goto draw;
	}
}

bool SpecialActionCheck() { return specialPoint; }

void SpecialAction(std::string cardOne, std::string cardTwo, std::string cardThree)
{
	std::cout << cardOne << " " << cardTwo << " " << cardThree;
	std::string select;
	if (SpecialActionCheck)
	{
		std::cout << "\n\nWhich card will preform the special action?\nEnter 'back' to cancel the special action.\n\n";
		std::cin >> select;
		if (select == cardOne)
		{
			//check class type somehow
			//if(speedType)
			//{
				//call specialMovement();
				//(it would be the same movement function but we can pass in the character that is moveing and skip a few steps)
				//(also this function would not subtract one from action points)
				specialPoint = false;
				return;
			//}

			//check class type somehow
			//if(powerType)
			//{
				strengthBoost = true;
				//if true, stength boost will add one at the end of next roll then be set to false
				specialPoint = false;
				return;
			//}

			//check class type somehow
			//if(supportType)
			//{
				//if(cardThree'sHealth > 1)
				//{
					//cardThree'sHealth --;
				chooseHeal:
				invalid:
					//std::cout << "\n\nWhich card would you like to give health to?\nEnter back to cancel\n\n";
					//std::cin >> select;
					if (select == cardOne)
					{
						//if(cardOneHealth < MAXHEALTH)
						//{
							//cardOneHealth++;
						//}
						//else
						//{
						std::cout << "\n\nThis character is already at full health, please choose another.\n\n";
						goto chooseHeal;
						//}
					}
					else if (select == cardTwo)
					{
						//if(cardTwoHealth < MAXHEALTH)
						//{
							//cardTwoHealth++;
						//}
						//else
						//{
						std::cout << "\n\nThis character is already at full health, please choose another.\n\n";
						goto chooseHeal;
						//}
					}
					else
					{
						std::cout << "\n\nNot a valid selection, please try again.\n\n";
						goto invalid;
					}
				//}
				
				specialPoint = false;
				return;
				//}


		}
		else if (select == cardTwo)
		{

		}
		else if (select == cardThree)
		{

		}
		else if (select == "back")
		{
			return;
		}
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
	cards[3] = "DE";//detective
	cards[4] = "LO";//lover
	cards[5] = "NO";//noble
	cards[6] = "GH";//ghost
	cards[7] = "SH";//shifter
	cards[8] = "VA";//vampire
	cards[9] = "BE";//beauty
	cards[10] = "DA";//dancer
	cards[11] = "ST";//student
	cards[12] = "BA";//banshee
	cards[13] = "RE";//reaper
	cards[14] = "WI";//witch
	cards[15] = "DO";//doctor
	cards[16] = "ME";//mentor
	cards[17] = "SC";//scientist

	//card stats
	int cardstats[18][2]
	{
		{ 4, 5 }, //amalg
		{ 3, 4 },//wolf
		{ 2, 3 },//zombie
		{ 4, 5 },//detec
		{ 3, 4 },//lover
		{ 2, 3 },//noble
		{ 2, 2 },//ghost
		{ 3, 3 },//shift
		{ 4, 4 },//vamp
		{ 4, 4 },//beauty
		{ 2, 2 },//dancer
		{ 3, 3 },//stud
		{ 3, 2 },//banshee
		{ 5, 4 },//reaper
		{ 4, 3 },//witch
		{ 4, 3 },//doctor
		{ 3, 2 },//mentor
		{ 5, 4 }//scientist
	};

	bool hasBeenPulled[18] = { false };
	bool townTurn = false; //can change as needed, this is a default
	int currentHand[3];

	//draws starting hand
	for (int i = 0; i < 3; i++) {
		currentHand[i] = drawCards(hasBeenPulled, townTurn);
		hasBeenPulled[currentHand[i]] = true;
	}

	//output hand and stats
	for (int i = 0; i < 3; i++) {
		int j = i + 1;
		std::cout << "Card " << j << ": " << cards[currentHand[i]] << "\n";
		std::cout << "HP: " << cardstats[currentHand[i]][0] << " Power: " << cardstats[currentHand[i]][1];
		std::cout << "\n \n";
	}


}

