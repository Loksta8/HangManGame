#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

//define variables
string word = "";
int playerLives = 7;    // Our hangman has 7 stages, so the player starts with 7 lives
bool running = 1;
char knownLetters[20];  // The word could be of any length so allocate some space for it
int amountOfWords = 11; // Replace 11 with the amount of words you have + 1

//define functions
string GenerateWord();
void PrintLetters();
void PrintMan();
void PlayerLose();
void PlayerWin();

//main program
int main() {
    word = GenerateWord(); // Pick a random word
    char userGuess;
//game begins
    while(running) {

    cout << "Guess a letter: ";
    cin >> userGuess;

    bool correct = 0;

    //checker loop
    for(int pos = 0; pos < word.length(); pos++) {
            if(userGuess == word[pos]) {
            knownLetters[pos] = userGuess; // If the letter is in the word, mark it as guessed
            correct = 1;
            }
    }

    if(correct == 0) playerLives--; // If the letter was wrong, subtract a life
    correct = 0;

   PrintMan(); //displays hangman
   PrintLetters();// shows the guessed word so far
   if(playerLives <= 0) PlayerLose(); // player lost
   if(knownLetters == word) PlayerWin(); // player won

    }
/* I wrote this in code::blocks so I believe this was needed to prevent
   the console dialog from closing too fast before you see the results
   Not needed in Linux
*/
    system("PAUSE");
    return EXIT_SUCCESS;
}

//Function to randomly pick a word within our wordlist that we created
string GenerateWord() {
    srand(time(NULL)); // Use the system time as a seed
    int wordID = rand() % amountOfWords; // amountOfWords variable will always be +1 to whatever your wordList array size is.
    string wordList[10] = {"pineapple", "orange", "people", "computer", "fire", "water", "cheese", "bottle", "plank", "lightbulb" };
    string word = wordList[wordID];
    return word;
}

//shows user the guessed letters if any by looping through the main word and
//checking each position based off the guess
void PrintLetters() {
    for(int pos = 0; pos < word.length(); pos++) {
    if(knownLetters[pos] == word[pos]) cout << word[pos];
    else cout << "_";
}
    cout << "\n";

    return;
}

// prints the visual representation of the hangman being hung if you guess wrong
void PrintMan() {
    switch(playerLives) {
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
//Let player know they won
void PlayerWin() {
    cout << "Congratulations, you guessed the word correctly!";
    cout << "Press ENTER to quit\n"; //Code::Blocks would close console too fast. This prevents that.
    cin.get();
    running = 0;

    return;
}
//Let player know they lost
void PlayerLose() {
    cout << "You lose! The word was: " << word << "\n";
    cout << "Press ENTER to quit\n"; // Same as above
    cin.get();
    running = 0;

    return;
}
