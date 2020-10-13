#include <iostream>
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
}