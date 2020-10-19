// CombatSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include <cstdlib>
int rollDice();//function designed to simulate a dice roll
void battle(int& card1Health, int& card1Strength, int& card2Health, int& card2Strength);//function designed to simulate a battle between two cards
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
