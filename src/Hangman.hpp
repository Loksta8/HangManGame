#ifndef HANGMAN_HPP
#define HANGMAN_HPP
/*
  @Author: Logan Herrera
  @Date: 1/29/2025
  @Version: C++ 11
  @Description: This program is the game of Hangman in the command line. It takes in a file and reads
  every word then chooses at random one of those words from the word list. The player has 7 lives
  and it will display back to the user the letters that have been guessed correctly. It will also draw out
  the hangman onto the console if the player guesses wrong. The Wordlist that currently works with 
  this program does not have any words bigger than 20. A python tool that comes with this repo can be 
  used to search for words with a certain length and tailor the wordlist to their liking. 
  @Purpose: All for the love of games! For Fun! Enjoy!
*/
#include <vector>
#include <string>
class Hangman {
        private:
        //Class Member Variables
                std::string mFilename;
                std::string mWord;
                int mPlayerLives;// Our hangman game has 7 stages, so the player starts with 7 lives
                bool mRunning;
                bool mIsCorrect;
                std::string mKnownLetters; // Switched to string instead of char
        //Constructors, Destructors, and Functions
        public:
                Hangman();
                Hangman(std::string);
		        ~Hangman();
                std::vector<std::string> GetWordList() const;
                std::string GenerateWord(const std::vector<std::string>&) const;
                void PrintLetters() const;
                void PrintMan() const;
                void PrintGuessedLetters(std::string&) const;
                void PlayerLose();
                void PlayerWin();
                void Welcome() const;

                //setters
                void SetFileName(std::string&);
                void SetWord(const std::string&);
                void MinusLife();
                void SetIsRunning(bool);
                void SetKnownLetters(char aLetter, bool aBool);
                void SetIsCorrect(bool);

                //getters
                std::string GetFileName() const;
                std::string GetWord() const;
                int GetLives() const;
                bool IsRunning() const;
                std::string GetKnownLetters() const;
                bool GetIsCorrect() const;
};

#endif
