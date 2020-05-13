#ifndef HANGMAN_HPP
#define HANGMAN_HPP

#include <vector>
#include <string>
class Hangman {
        public:
        //Class Member Variables
                std::string mFilename;
                std::string mWord;
                int mPlayerLives;// Our hangman game has 7 stages, so the player starts with 7 lives
                bool mRunning;
                char mKnownLetters[20] = ""; // The Word could be of different lengths, allocated some space
        //Constructors, Destructors, and Functions
                Hangman();
                Hangman(std::string);
		~Hangman();
                std::vector<std::string> GetWordList();
                std::string GenerateWord(const std::vector<std::string>&);
                void PrintLetters();
                void PrintMan();
                void PlayerLose();
                void PlayerWin();
};

#endif
