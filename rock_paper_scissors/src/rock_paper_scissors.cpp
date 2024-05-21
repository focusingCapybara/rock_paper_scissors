#include "../include/log.h"
#include "../include/math.h"
#include <iostream>
#include <cstdlib> // Has a function called Rand() that generates a random int
#include <ctime>

static bool isInArray(const std::string game[], const std::string userChoice) {
    const int ARR_SIZE = 3;
    for (int i = 0; i < ARR_SIZE; i++)
    {
        if (game[i] == userChoice)
        {
            return true;
        }
    }
    return false;
}

static void LogScore(int playerScore, int computerScore) {
    std::cout << "Player: " << playerScore << "\n" << "Computer: " << computerScore << "\n";
}

int main() {
    const std::string game[] = {"rock", "paper", "scissors"};
    std::string userChoice, computerChoice;
    int userScore = 0, computerScore = 0;

    srand((unsigned int)time(NULL));

    while (true) {
        computerChoice = game[rand() % 3];

        Log("Please enter either 'rock', 'paper', 'scissors' or enter 'Q' to exit:\n\n");
        Log("Player: ");
        std::cin >> userChoice;

        if (userChoice == "Q" || userChoice == "q") {
            break;
        }
        else if (!isInArray(game, userChoice)) {
            Log("Please enter the valid input.\n");
            continue;
        }

        Log("Computer: ", computerChoice, "\n");

        if (userChoice == computerChoice) {
            Log("It's a tie!\n");
        }
        else if ((userChoice == "rock" && computerChoice == "scissors") ||
            (userChoice == "paper" && computerChoice == "rock") ||
            (userChoice == "scissors" && computerChoice == "paper")) {
            userScore++;
            Log("You won!\n");
        }
        else {
            computerScore++;
            Log("You lost!\n");
        }
        LogScore(userScore, computerScore);
    }
}