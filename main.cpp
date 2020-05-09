#include "Hangman.hpp"
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

//main program
int main() {
        Hangman hm("", 7, 1, 11);// Class Instantiation and Initialization. Change 11 to the number you have inside wordList plus 1
        hm.mWord = hm.GenerateWord(); // Pick a random word
        char userGuess;
        while(hm.mRunning) {
                cout << "Guess a letter: ";
	        cin >> userGuess;

                bool correct = 0;

                //checker loop
                for(int pos = 0; pos < hm.mWord.length(); pos++) {
        	        if(userGuess == hm.mWord[pos]) {
            	                hm.mKnownLetters[pos] = userGuess; // If the letter is in the word, mark it as guessed
            	                correct = 1;
            	        }
    	        }

                if(correct == 0) hm.mPlayerLives--; // If the letter was wrong, subtract a life
    	        correct = 0;
   	        hm.PrintMan(); //displays hangman
   	        hm.PrintLetters(); // show user the letters guessed if any
   	        if(hm.mPlayerLives <= 0) hm.PlayerLose(); // player lost end game
   	        if(hm.mKnownLetters == hm.mWord) hm.PlayerWin(); // player won end game
        }
        return 0;
}
