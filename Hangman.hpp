#ifndef HANGMAN_HPP
#define HANGMAN_HPP

#include <string>
class Hangman {
        public:
        //Class Member Variables
                std::string mWord;
                int mPlayerLives;// Our hangman game has 7 stages, so the player starts with 7 lives
                bool mRunning;
                char mKnownLetters[20] = ""; // The Word could be of different length so allocated some space
                int mAmountOfWords; // Replace 11 with the amount of words you have in your array
        //Constructors, Destructors, and Functions
                Hangman();
                Hangman(std::string, int, bool, int);
		~Hangman();
                std::string GenerateWord();
                void PrintLetters();
                void PrintMan();
                void PlayerLose();
                void PlayerWin();
};

#endif
