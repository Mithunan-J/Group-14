#include <iostream>
int main()
{
	//lists for character cards and their stats
	std::string cards[18];

	//setting the card reference locations
	cards[0] = "AM";//amalgam
	cards[1] = "DE";//detective
	cards[2] = "SH";//shifter
	cards[3] = "ST";//student
	cards[4] = "GH";//ghost
	cards[5] = "DA";//dancer
	cards[6] = "VA";//vampire
	cards[7] = "BE";//beauty
	cards[8] = "WO";//wolfman
	cards[9] = "LO";//lover
	cards[10] = "BA";//banshee
	cards[11] = "ME";//mentor
	cards[12] = "WI";//witch
	cards[13] = "DO";//doctor
	cards[14] = "ZO";//zombie
	cards[15] = "NO";//noble
	cards[16] = "RE";//reaper
	cards[17] = "SC";//scientist

	for (int counter = 0; counter < 18; counter++)
	{
		std::cout << cards[counter] << "\n";
	}

	//card stats
	int cardstats[18][2]
	{
		{ 4, 5 },
		{ 4, 5 },
		{ 3, 3 },
		{ 3, 3 },
		{ 2, 2 },
		{ 2, 2 },
		{ 4, 4 },
		{ 4, 4 },
		{ 3, 4 },
		{ 3, 4 },
		{ 3, 2 },
		{ 3, 2 },
		{ 4, 3 },
		{ 4, 3 },
		{ 2, 3 },
		{ 2, 3 },
		{ 5, 4 },
		{ 5, 4 }
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