#include <iostream>

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