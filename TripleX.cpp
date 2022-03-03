#include <iostream>
#include <ctime>

// Introduction to print at the start of every level
void PrintIntroduction(int Difficulty)
{
  // Story for the game
    std::cout << "\n--- You're a bank robber currently at the door of a level " << Difficulty;
    std::cout << "/10 vault. ---\n--- You must find the code that opens the vault door in order to get your money... ---\n";
    std::cout << "--- You will have 3 attempts at each level. ---\n--- If you fail on your third attempt, the police will catch up and you will fail the mission. ---\n\n";
}

// Main function to play the actual game
bool PlayGame(int Difficulty) 
{
    
    // Prints the intro at the start of every level
    PrintIntroduction(Difficulty);

    // Declare the 3 number code
    int CodeA = rand() % Difficulty + 1;
    int CodeB = rand() % Difficulty + 1;
    int CodeC = rand() % Difficulty + 1;

    // To prevent each digit from going bigger than 9
    if (CodeA >= 10) {
        CodeA = rand() % 9 + 1;
    }
    if (CodeB >= 10) {
        CodeB = rand() % 9 + 1;
    }
    if (CodeC >= 10) {
        CodeC = rand() % 9 + 1;
    }

    // To determaine the values for the hints
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;
       
    // UNCOMMENT THIS LINE TO REVEAL ANSWERS FOR TESTING
    // std::cout << CodeA << CodeB << CodeC << std::endl;
    
    // Print the sum and product to the terminal
    std::cout << "There are 3 numbers in the code\n";
    std::cout << "The codes add up to: " << CodeSum;
    std::cout << "\nThe codes multiply to give: " << CodeProduct << std::endl;

    // Store player guess
    int GuessA, GuessB, GuessC;
    std::cout << "\nFirst Number of the Code: ";
    std::cin >> GuessA; 
    std::cout << "Second Number of the Code: ";
    std::cin >> GuessB; 
    std::cout << "Third Number of the Code: ";
    std::cin >> GuessC;
    std::cout << "\n\nYou entered: " << GuessA << GuessB << GuessC << std::endl;

    // Calculate the guess into one sum and product
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Return TRUE or FALSE depending on whether player guess was correct or incorrect
    return GuessSum == CodeSum && GuessProduct == CodeProduct;

}

// Main function
int main()
{
    
    // To help randomize the codes
    srand(time(NULL));
    
    // Current level difficulty and max level
    int LevelDifficulty = 1;
    int const MaxDifficulty = 10;
    int CurrentLevel = 1;
    
    // Variables used in main() function
    int Attempts = 3;

    // Loop game until all levels are completed.
    while (LevelDifficulty <= MaxDifficulty) 
    {
        // Calling of PlayGame() function and some debug stuff
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();
        
        // What happens when the user enters the correct answer
        if (bLevelComplete) {
            Attempts = 3;
            std::cout << "\n--- Correct! Move on to the next vault for even MORE money! ---\n";
            ++LevelDifficulty;
            ++CurrentLevel;
        }
        // What happens when the user enters the wrong answer
        else {
            Attempts = Attempts - 1;
            std::cout << "\n--- Oh no! Wrong code, try again but be careful. You only have 3 total attempts! ---\n";
            std::cout << "--- Attempts Left: " << Attempts << " ---" << std::endl;
        }

        // What happens when attempts reaches 0
        if (Attempts == 0) {
            LevelDifficulty = 15;
        }
    }
    
    // What happens when user completes all 10 levels
    if (LevelDifficulty == 11)
    {
        std::cout << "\n--- Congrats! You emptied out the bank and are driving away in your runaway care to live a life of luxury on a private island! ---\n\n";
        return 0;
    }
    // What happens when user uses up all 3 attempts and fails a level
    else 
    {
        std::cout << "\n--- You failed your third attempt and were caught by the police! Oh no! Better luck next time! :) ---\n";
        std::cout << "--- You were on level: " << CurrentLevel << ". ---\n\n";
        return 0;
    }
    
    
}