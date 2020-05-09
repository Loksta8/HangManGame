#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

class HangmanGame{
        public:
        // Class Member Variables
                string mWord;
                int mPlayerLives; // Our hangman has 7 stages, so the player starts with 7 lives
                bool mRunning;
                char mKnownLetters[20] = ""; // the word could be of any length
                int mAmountOfWords; // Replace 11 with the amount of words we have in our word array
        //Constructors, Destructors, and Functions
                HangmanGame();
                HangmanGame(string, int, bool, int);
                ~HangmanGame();
                string GenerateWord();
                void PrintMan();
                void PrintLetters();
                void PlayerLose();
                void PlayerWin();
};

//Constructor
HangmanGame::HangmanGame(string aWord, int aPlayerLives, bool aRunning, int aAmountOfWords) : mWord(aWord), mPlayerLives(aPlayerLives), mRunning(aRunning), mAmountOfWords(aAmountOfWords){

}

//Destructor
HangmanGame::~HangmanGame(){
}

//Function to randomly pick a word within our wordlist that we created
string HangmanGame::GenerateWord(){
    srand(time(NULL)); // Use the system time as a seed
    int wordID = rand() % mAmountOfWords; //mAmountOfWords variable will always be +1 to whatever your wordList array size is.
    string wordList[10] = {"pineapple", "orange", "people", "computer", "fire", "water", "cheese", "bottle", "plank", "lightbulb" };
    string word = wordList[wordID];
    return word;
}

//shows user the guessed letters if any by looping through the main word
//and checking each position based off the guess
void HangmanGame::PrintLetters(){
    for(int pos = 0; pos < mWord.length(); pos++) {
        if(mKnownLetters[pos] == mWord[pos]) cout << mWord[pos];
    else cout << "_";
}
    cout << "\n";
    return;
}

//Draw the Hangman for each case
void HangmanGame::PrintMan(){

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

//Print to the user that they lost
void HangmanGame::PlayerLose(){
    cout << "You lose! The word was: " << mWord << "\n";
    cout << "Press ENTER to quit\n"; // at the time this was for Code::Blocks
    cin.get();
    mRunning = 0;
    return;
}

//Print to the user that they won
void HangmanGame::PlayerWin(){
    cout << "Congratulations, you guessed the word correctly!";
    cout << "Press ENTER to quit\n"; // at the time this was for Code::Blocks
    cin.get();
    mRunning = 0;
    return;
}

//The main program
int main() {
        HangmanGame hg("", 7, 1, 11); // Instantiate class
        hg.mWord = hg.GenerateWord(); // pick a random word from our word array
        char userGuess;

        while(hg.mRunning){
                cout << "Guess a letter: ";
                cin >> userGuess;
                bool correct = 0;

        //checker loop
        for(int pos = 0; pos < hg.mWord.length(); pos++) {
            if(userGuess == hg.mWord[pos]) {
                hg.mKnownLetters[pos] = userGuess; // If the letter is in the word, mark it as guessed
                correct = 1;
            }
        }

        if(correct == 0) hg.mPlayerLives--; // If the letter was wrong, subtract a life
        correct = 0;
        hg.PrintMan(); //displays hangman
        hg.PrintLetters();
        if(hg.mPlayerLives <= 0) hg.PlayerLose();
        if(hg.mKnownLetters == hg.mWord) hg.PlayerWin();
        }
        system("PAUSE");
        return EXIT_SUCCESS;

}
