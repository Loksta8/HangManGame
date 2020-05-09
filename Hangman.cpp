#include "Hangman.hpp"
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

//Constructor (Member Initialization List)
Hangman::Hangman(string aWord, int aPlayerLives, bool aRunning, int aAmountOfWords) : mWord(aWord), mPlayerLives(aPlayerLives), mRunning(aRunning), mAmountOfWords(aAmountOfWords){
}

//Destructor
Hangman::~Hangman(){
}

//Generate the word from our word list
string Hangman::GenerateWord() {
        srand(time(NULL)); // Use the system time as a random seed
        int wordID = rand() % mAmountOfWords; // Replace mAmountOfWords with the amount of words you have + 1. done in constructor
        string wordList[10] = {"pineapple", "orange", "people", "computer", "fire", "water", "cheese", "bottle", "plank", "lightbulb" };
        string word = wordList[wordID];
        return word;
}

//shows user the guessed letters if any by looping through the main word
//and checking each position based off the guess
void Hangman::PrintLetters() {
        for(int pos = 0; pos < mWord.length(); pos++) {
                if(mKnownLetters[pos] == mWord[pos]) cout << mWord[pos];
                else cout << "_";
        }
        cout << "\n";
        return;
}

// Draw out the Hangman using switch case statement based
// off of the players lives as the player gets words wrong
void Hangman::PrintMan() {
        switch(mPlayerLives) {
        case 7:
                cout << "\n\n\n\n\n";
                break;
        case 6:
                cout << "\n\n\n\n______";
                break;
        case 5:
                cout << "\n    |\n    |\n    |\n    |\n____|_";
                break;
        case 4:
                cout << " ___\n | \\|\n    |\n    |\n    |\n____|_";
                break;
        case 3:
                cout << " ___\n | \\|\n O  |\n    |\n    |\n____|_";
                break;
        case 2:
                cout << " ___\n | \\|\n O  |\n |  |\n    |\n____|_";
                break;
        case 1:
                cout << " ___\n | \\|\n O  |\n/|\\ |\n    |\n____|_";
                break;
        case 0:
                cout << " ___\n | \\|\n O  |\n/|\\ |\n/ \\ |\n____|_";
                break;
        }
        cout << "\n"; // For formatting purposes
        return;
}

//Function to let player know they Won the game
void Hangman::PlayerWin() {
        cout << "Congratulations, you guessed the word correctly!";
        cout << "Press ENTER to quit\n"; // carried over from Code::Blocks not needed in Linux
        cin.get();
        mRunning = 0;
        return;
}

//Function to let the player know they Lost the game
void Hangman::PlayerLose() {
        cout << "You lose! The word was: " << mWord << "\n";
        cout << "Press ENTER to quit\n";// same as above
        cin.get();
        mRunning = 0;
        return;
}
