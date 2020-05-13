#include "Hangman.hpp"
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <random>
#include <boost/algorithm/string.hpp>

//Constructor (Member Initialization List)
Hangman::Hangman(std::string aFilename) : mFilename(aFilename), mWord(""), mPlayerLives(7), mRunning(1){
}

//Destructor
Hangman::~Hangman(){
}

// Function to fetch words from the text file
std::vector<std::string> Hangman::GetWordList(){
        std::ifstream file (mFilename);
        std::vector<std::string> dataWordList;
        if(file.is_open()){//Check if file is open
                std::string line = "";
                // Read the next line from file until it reaches the end.
                while(getline(file, line)){
                // Store line in vector as long as it is not empty
                        if(line.size() > 0){
                                boost::trim(line);// Get rid of white space
                                dataWordList.push_back(line);// Store words
                        }
                }
                file.close(); // close when finished reading
        }
        else{//Print Error if we cannot open the file
                std::cout << "Error Opening file!";
        }
        return dataWordList;
}

//Function that uses random uniform distribution to Generate the word from our word list
std::string Hangman::GenerateWord(const std::vector<std::string>& aWordList){
        std::random_device dev;//Random device
    	std::mt19937 rng(dev());//A Mersenne Twister pseudo-random generator of 32-bit numbers using the Random device
    	std::uniform_int_distribution<std::mt19937::result_type> dist6(0,aWordList.size()); // uniform distribution in range [0, 10000]
        unsigned int wordID = dist6(rng); // our key to unlock 1 word
        std::string word = aWordList[wordID]; // store the word randomly picked
        return word;
}

//shows user the guessed letters if any by looping through the main word
//and checking each position based off the guess
void Hangman::PrintLetters() {
        for(unsigned int pos = 0; pos < mWord.length(); pos++) {
                if(mKnownLetters[pos] == mWord[pos]) std::cout << mWord[pos];
                else std::cout << "_";
        }
        std::cout << "\n";
        return;
}

// Draw out the Hangman using switch case statement based
// off of the players lives as the player gets words wrong
void Hangman::PrintMan() {
        switch(mPlayerLives) {
        case 7:
                std::cout << "\n\n\n\n\n";
                break;
        case 6:
                std::cout << "\n\n\n\n______";
                break;
        case 5:
                std::cout << "\n    |\n    |\n    |\n    |\n____|_";
                break;
        case 4:
                std::cout << " ___\n | \\|\n    |\n    |\n    |\n____|_";
                break;
        case 3:
                std::cout << " ___\n | \\|\n O  |\n    |\n    |\n____|_";
                break;
        case 2:
                std::cout << " ___\n | \\|\n O  |\n |  |\n    |\n____|_";
                break;
        case 1:
                std::cout << " ___\n | \\|\n O  |\n/|\\ |\n    |\n____|_";
                break;
        case 0:
                std::cout << " ___\n | \\|\n O  |\n/|\\ |\n/ \\ |\n____|_";
                break;
        }
        std::cout << "\n"; // For formatting purposes
        return;
}

//Function to let player know they Won the game
void Hangman::PlayerWin() {
        std::cout << "Congratulations, you guessed the word correctly!" << std::endl;
        mRunning = 0;// End Game
        return;
}

//Function to let the player know they Lost the game
void Hangman::PlayerLose() {
        std::cout << "You lose! The word was: " << mWord << std::endl;
        mRunning = 0;// End Game
        return;
}
