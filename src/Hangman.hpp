#ifndef HANGMAN_HPP
#define HANGMAN_HPP
/*
  @Author: Logan Herrera
  @Date: 5/12/2020
  @Version: C++ 11
  @Description: This program is the game Hangman in the console. It takes in a file and reads
  every word then chooses at random one of those words from the word list. The player has 7 lives
  and it will display back to the user the letters that have been guessed correctly. It will draw out
  the hangman onto the console if the player guesses wrong. Currently it allocates for words no
  bigger than 20 but if a programmer so chooses, they can easily increase the length of words in
  the word list and adjust the mKnownLetters char array to account for the new length of the word.
  The Wordlist that currently works with this program does not have any words bigger than 20. A
  python tool that comes with this repo can be used to search for words with a certain length.
  @Purpose: All for the love of games! For Fun! Enjoy!
*/
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
                void PrintGuessedLetters(std::string&);
                void PlayerLose();
                void PlayerWin();
                void Welcome();
};

#endif
