#include "Hangman.hpp"
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>
#include <fstream>
#include <random>
#include <algorithm>
#include <cctype>

// Helper function to trim white space from a string
void trim(std::string& str) {
    str.erase(std::remove_if(str.begin(), str.end(), ::isspace), str.end());
}

Hangman::Hangman() : mPlayerLives(7), mRunning(true), mIsCorrect(false)
{
}

// Constructor (Member Initialization List)
Hangman::Hangman(std::string aFilename) : mFilename(aFilename), mWord(""), mPlayerLives(7), mRunning(true), mIsCorrect(false) {
}

// Destructor
Hangman::~Hangman() {
}

// Function to fetch words from the text file
std::vector<std::string> Hangman::GetWordList() const {
    std::ifstream file(mFilename);
    std::vector<std::string> dataWordList;
    if (file.is_open()) { // Check if file is open
        std::string line = "";
        // Read the next line from file until it reaches the end.
        while (getline(file, line)) {
            // Store line in vector as long as it is not empty
            if (line.size() > 0) {
                trim(line); // Get rid of white space
                dataWordList.push_back(line); // Store words
            }
        }
        file.close(); // close when finished reading
    }
    else { // Print Error if we cannot open the file
        std::cout << "Error Opening file!";
    }
    return dataWordList;
}

// Function that uses random uniform distribution to generate the word from our word list
std::string Hangman::GenerateWord(const std::vector<std::string>& aWordList) const {
    std::random_device dev; // Random device
    std::mt19937 rng(dev()); // A Mersenne Twister pseudo-random generator of 32-bit numbers using the Random device
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, aWordList.size()); // uniform distribution in range [0, 10000]
    unsigned int wordID = dist6(rng); // our key to unlock 1 word
    std::string word = aWordList[wordID]; // store the word randomly picked
    return word;
}

// Shows user the guessed letters if any by looping through the main word and checking each position based off the guess
void Hangman::PrintLetters() const{
    for (unsigned int pos = 0; pos < mWord.length(); pos++) {
        if (mKnownLetters[pos] == mWord[pos]) std::cout << mWord[pos];
        else std::cout << "_";
    }
    std::cout << "\n";
    return;
}

// Draw out the Hangman using switch case statement based off of the players lives as the player gets words wrong
void Hangman::PrintMan() const{
    switch (mPlayerLives) {
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

// Function to show player the guessed letters so far
void Hangman::PrintGuessedLetters(std::string& aGuessed) const {
    std::cout << "Guessed Letters:    " << aGuessed << std::endl;
}

// Function to let player know they won the game
void Hangman::PlayerWin() {
    std::cout << R"(
 _____                             _        __   __            _    _             _ 
/  __ \                           | |       \ \ / /           | |  | |           | |
| /  \/ ___  _ __   __ _ _ __ __ _| |_ ___   \ V /___  _   _  | |  | | ___  _ __ | |
| |    / _ \| '_ \ / _` | '__/ _` | __/ __|   \ // _ \| | | | | |/\| |/ _ \| '_ \| |
| \__/\ (_) | | | | (_| | | | (_| | |_\__ \   | | (_) | |_| | \  /\  / (_) | | | |_|
 \____/\___/|_| |_|\__, |_|  \__,_|\__|___/   \_/\___/ \__,_|  \/  \/ \___/|_| |_(_)
                    __/ |                                                           
                   |___/                                                          
)" << '\n';
    std::cout << "Congratulations! You guessed the word: " << mWord << std::endl;
    std::cout << "Press Enter to continue." << std::endl;
    std::cin.get();
    mRunning = false;
    return;
}

// Function to let the player know they lost the game
void Hangman::PlayerLose() {
    std::cout << R"(
 ____                                      __    __                  __                       __    __
/\  _`\                                   /\ \  /\ \                /\ \                     /\ \__/\ \
\ \,\L\_\    ___   _ __   _ __   __  __   \ `\`\\/'/ ___   __  __   \ \ \        ___     ____\ \ ,_\ \ \
 \/_\__ \   / __`\/\`'__\/\`'__\/\ \/\ \   `\ `\ /' / __`\/\ \/\ \   \ \ \  __  / __`\  /',__\\ \ \/\ \ \
   /\ \L\ \/\ \L\ \ \ \/ \ \ \/ \ \ \_\ \    `\ \ \/\ \L\ \ \ \_\ \   \ \ \L\ \/\ \L\ \/\__, `\\ \ \_\ \_\
   \ `\____\ \____/\ \_\  \ \_\  \/`____ \     \ \_\ \____/\ \____/    \ \____/\ \____/\/\____/ \ \__\\/\_\
    \/_____/\/___/  \/_/   \/_/   `/___/> \     \/_/\/___/  \/___/      \/___/  \/___/  \/___/   \/__/ \/_/
                                     /\___/
                                     \/__/
)" << '\n';
    std::cout << "You lose! The word was: " << mWord << std::endl;
    std::cout << "Press Enter to continue.";
    std::cin.get();
    mRunning = false;
    return;
}

// Welcome the player to hangman
void Hangman::Welcome() const {
    std::cout << "Coded by Logan! Thanks for playing and GOOD LUCK! " << std::endl;
    std::cout << std::endl;
    std::cout << R"(
 __          __  _                            _______      _    _                                         
 \ \        / / | |                          |__   __|    | |  | |                                        
  \ \  /\  / /__| | ___ ___  _ __ ___   ___     | | ___   | |__| | __ _ _ __   __ _ _ __ ___   __ _ _ __  
   \ \/  \/ / _ \ |/ __/ _ \| '_ ` _ \ / _ \    | |/ _ \  |  __  |/ _` | '_ \ / _` | '_ ` _ \ / _` | '_ \ 
    \  /\  /  __/ | (_| (_) | | | | | |  __/    | | (_) | | |  | | (_| | | | | (_| | | | | | | (_| | | | |
     \/  \/ \___|_|\___\___/|_| |_| |_|\___|    |_|\___/  |_|  |_|\__,_|_| |_|\__, |_| |_| |_|\__,_|_| |_|
                                                                               __/ |                      
                                                                              |___/                
)" << '\n';
}

void Hangman::SetFileName(std::string& aFileName) {
    mFilename = aFileName;
}

void Hangman::SetWord(const std::string& aWord) {
    mWord = aWord;
    mKnownLetters = std::string(mWord.size(), '_'); // Initialize with underscores
}

void Hangman::MinusLife() {
    mPlayerLives--;
}

void Hangman::SetIsRunning(bool aBool) {
    mRunning = aBool;
}

void Hangman::SetKnownLetters(char aLetter, bool aBool) {
    if (mWord.find(aLetter) != std::string::npos) {
        mIsCorrect = true;
        for (unsigned int pos = 0; pos < mWord.length(); pos++) {
            if (aLetter == mWord[pos]) {
                mKnownLetters[pos] = aLetter;
            }
        }
    }
}

void Hangman::SetIsCorrect(bool aBool) {
    mIsCorrect = aBool;
}


std::string Hangman::GetFileName() const {
    return mFilename;
}

std::string Hangman::GetWord() const {
    return mWord;
}

int Hangman::GetLives() const {
    return mPlayerLives;
}

bool Hangman::IsRunning() const {
    return mRunning;
}

std::string Hangman::GetKnownLetters() const {
    return mKnownLetters;
}

bool Hangman::GetIsCorrect() const {
    return mIsCorrect;
}
