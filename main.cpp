#include "Hangman.hpp"
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>
#include <iostream>
#include <ctype.h>

//main program
int main() {
        std::string wordlist_path = "./wordlist_dictionary.txt"; // Relative path to word list file
        Hangman hm(wordlist_path);// Class Instantiation and Initialization.
        std::vector<std::string> allWords = hm.GetWordList(); // Get the word list
        std::string guessed;
        hm.mWord = hm.GenerateWord(allWords); // Pick a random word

        char userGuess; // Store Player's guesses
        hm.Welcome(); // Print Welcome to Hangman
        while(hm.mRunning) { //Begin game
                std::cout << std::endl;
                std::cout << "Guess a SINGLE letter: "; //BE CAREFUL NO ERROR CHECKING IF ENTERING MORE THAN ONE LETTER AT A TIME, I APOLOGIZE!
                std::cin >> userGuess;
                guessed.push_back(userGuess); //
                if(isalpha(userGuess)){// Try and help out the player if they enter something other than a letter
                        bool correct = 0;// Keep track of player's correct guesses
                        //checker loop
                        for(unsigned int pos = 0; pos < hm.mWord.length(); pos++) {
        	                if(userGuess == hm.mWord[pos]) {
            	                        hm.mKnownLetters[pos] = userGuess; // If the letter is in the word, mark it as guessed
            	                        correct = 1; // Player guessed correctly
            	                }
    	                }

                        if(correct == 0) hm.mPlayerLives--; // Player guessed wrong, subtract a life
    	                correct = 0;
   	                hm.PrintMan(); //Displays hangman
                        hm.PrintLetters(); // show user the correct letters guessed if any
                        std::cout << std::endl; // Formatting
                        hm.PrintGuessedLetters(guessed); // Show the player's guessed words so far
   	                if(hm.mPlayerLives <= 0) hm.PlayerLose(); // Player lost end game
   	                if(hm.mKnownLetters == hm.mWord) hm.PlayerWin(); // Player won end game
                        }
                else{
                        std::cout << "Try entering a single letter. " << std::endl;
                }
        }// End Game
        return 0;//End Program
}
