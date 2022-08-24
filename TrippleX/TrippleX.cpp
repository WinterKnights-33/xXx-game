

#include <iostream>
#include <ctime>

//run in term with g++ -o tripplex tripplex.cpp && ./tripplex

void PrintIntroduction(int Difficulty)
{
        //print welcome messages to the term

    std::cout << "\n\nASU has stolen your money by refusing to pay for an event you had worked for them.  \nThis has cause a great deal of stress.  \nWith the new semester coming to a start and ASU still refusing to pay... \nIt's time to take action...\n\n";
    std::cout << "Let's break into the main office and get their attention to this matter and have them finally pay what they owe!\n\n";
    std::cout << "You need to enter the correct codes to win... \nBut ASU wont make it easy... \nYou have to pass a few floors to get to the end... \nEach new floor means it'll get harder \n\nThe first floor is only a level "<< Difficulty;
    std::cout << " so should be easy but you'll go through more difficult levels to get to the main office: \n";
    std::cout << "Kira Gatewood.  It's time to pay.\n\n";
}


bool PlayGame(int Difficulty)
{

    PrintIntroduction(Difficulty);

    //the declared 3 number code

    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

//    CodeA = 7;  added const so this var change doesnt work anymore

    int CodeSum = CodeA+CodeB+CodeC;
    int CodeProduct = CodeA*CodeB*CodeC;

    //prints the CodeSum and the product to the term


    std::cout << "+ There are 3 numbers in the code\n";
    std::cout << "\n+ The codes add-up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;


    //storing the players guess

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct =  GuessA * GuessB * GuessC;

    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n *** Goodjob now keep going.  You are almost there... ***";
        return true;
    }
    else
    {
        std::cout << "\n *** Watch out... you were almost caught... try the again but slowdown and think... ***";
        return false;
    }

}


int main()
{
    srand(time(NULL)); //create new random sequence based on time of day

    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    //loops the game until all levels are completed
    while (LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //clears any errors
        std::cin.ignore(); //discards buffer

        if (bLevelComplete)
        {
            ++ LevelDifficulty;
        }
        
    }
    std::cout << "\nYou did it!  \nIt's over and you got your money!  \n\nNow get out of there!";

    return 0;
}