#include <iostream>
#include <time.h>
#include <cstdlib>
int rollDice();//function designed to simulate a dice roll
void battle(int& card1Health, int& card1Strength, int& card2Health, int& card2Strength);//function designed to simulate a battle between two cards
int main()
{
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

	for (int counter = 0; counter < 18; counter++)
	{
		std::cout << cards[counter] << "\n";
	}

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

	//loop for printing card stats
	for (int i = 0; i < 2; i++)
	{
		for (int x = 0; x < 18; x++)
		{
			std::cout << cardstats[x][i] << "  ";
		}
		std::cout << "\n";
	}
	int doctorHealth = 4;//test case
	int doctorStrength = 3;//test case

	int witchHealth = 4;//test case
	int witchStrength = 3;//test case

	battle(doctorHealth, doctorStrength, witchHealth, witchStrength);//function is called here
}

int rollDice()
{
    int diceFacingUp;//elaborate variable name to avoid plagiarism 
    srand(time(0) + rand());//not exactly sure what's goingg on here but it works.

    diceFacingUp = rand() % 7;//ensures that the random number is between 0 and 6
    while (diceFacingUp == 0)//if the value of diceFacingUp is 0, it will be rerolled until it is not zero
    {
        diceFacingUp = rand() % 7;
    }
    return diceFacingUp;
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
            diceRoll = rollDice();
            std::cout << "\n";
            std::cout << "Player 1's Turn\n";
            std::cout << "Number rolled: " << diceRoll << "\n";
            if (diceRoll >= card2Strength)//checks to see if the number rolled by the player is greater or equal to the opposing card's strength
            {
                card2Health -= 1;
                std::cout << "Card1 deals damage to Card2\n";
                std::cout << "Card1 health: " << card1Health << " Card1 Strength: " << card1Strength << "\n";
                std::cout << "Card2 health: " << card2Health << " Card2 Strength: " << card2Strength << "\n";
                std::cout << "\n";
            }
            else
            {
                std::cout << "No damage done\n";
                std::cout << "\n";
            }
            p1Attacking = false;
            p2Attacking = true;
        }
        else if (p2Attacking == true)
        {
            diceRoll = rollDice();
            std::cout << "\n";
            std::cout << "Player 2's Turn\n";
            std::cout << "Number rolled: " << diceRoll << "\n";
            if (diceRoll >= card1Strength)
            {
                card1Health -= 1;
                std::cout << "Card2 deals damage to Card1\n";
                std::cout << "Card1 health: " << card1Health << " Card1 Strength: " << card1Strength << "\n";
                std::cout << "Card2 health: " << card2Health << " Card2 Strength: " << card2Strength << "\n";
                std::cout << "\n";
            }
            else
            {
                std::cout << "No damage done\n";
                std::cout << "\n";
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