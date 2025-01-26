#include "Hangman.hpp"
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <vector>
#include <ctype.h>
#include <csignal>
#include <stdexcept>

volatile std::sig_atomic_t gSignalStatus;

Hangman* hmPtr = nullptr;

void signalHandler(int signum) {
    gSignalStatus = signum;
    if (hmPtr != nullptr) {
        hmPtr->mRunning = 0;
        std::cout << "\nCaught signal " << signum << ". Exiting the game cleanly...\n";
    }
    exit(signum);
}

// Main program
int main() {
    try {
        // Register signal SIGINT and signal handler
        std::signal(SIGINT, signalHandler);

        std::string playAgain;

        do {
            std::string wordlist_path = "./wordlist_dictionary.txt"; // Relative path to word list file
            Hangman hm(wordlist_path); // Class Instantiation and Initialization.
            hmPtr = &hm;
            std::vector<std::string> allWords = hm.GetWordList(); // Get the word list

            if (allWords.empty()) {
                throw std::runtime_error("Error: The word list is empty or could not be loaded. Exiting program.");
            }

            std::string guessed; // Used to store players' guessed words
            hm.mWord = hm.GenerateWord(allWords); // Pick a random word

            if (hm.mWord.empty()) {
                throw std::runtime_error("Error: Failed to generate a word. Exiting program.");
            }

            char userGuess; // Store player's guesses
            hm.Welcome(); // Print Welcome to Hangman

            while (hm.mRunning) { // Begin game
                std::cout << std::endl;
                std::cout << "Guess a SINGLE letter: "; // Be careful: no error checking if entering more than one letter at a time, I apologize!
                std::cout << std::endl;
                std::cin.get(userGuess); // Only getting the first character
                std::cin.ignore(256, '\n'); // Try and ignore everything typed afterward and up to ENTER
                std::cin.clear(); // Clear the cin buffer stream

                if (isalpha(userGuess)) { // Try and help out the player if they enter something other than a letter
                    guessed.push_back(userGuess); // Store only if guess is alpha-numeric
                    bool correct = 0; // Keep track of player's correct guesses

                    // Checker loop
                    for (unsigned int pos = 0; pos < hm.mWord.length(); pos++) {
                        if (userGuess == hm.mWord[pos]) {
                            hm.mKnownLetters[pos] = userGuess; // If the letter is in the word, mark it as guessed
                            correct = 1; // Player guessed correctly
                        }
                    }

                    if (correct == 0) hm.mPlayerLives--; // Player guessed wrong, subtract a life
                    correct = 0;
                    hm.PrintMan(); // Displays hangman
                    hm.PrintLetters(); // Show user the correct letters guessed if any
                    std::cout << std::endl; // Formatting
                    hm.PrintGuessedLetters(guessed); // Show the player's guessed words so far

                    if (hm.mPlayerLives <= 0) hm.PlayerLose(); // Player lost, end game
                    if (hm.mKnownLetters == hm.mWord) hm.PlayerWin(); // Player won, end game
                }
                else {
                    std::cout << "Try entering a single letter. " << std::endl;
                    std::cin.clear(); // Clear cin buffer stream
                }

                // Check for signal status and exit if interrupted
                if (gSignalStatus) break;
            } // End game

            std::cout << "Do you want to play again? (yes/no): ";
            std::getline(std::cin, playAgain);

        } while (playAgain == "yes" && !gSignalStatus);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0; // End program
}
