# HANGMAN GAME

Welcome to my first Hangman Game that I created back in 2011. When I first created this program it was to teach me how to use
C++ to solve the problem of programming Hangman in the C++ Language. I did not know how Object Oriented Style Programming
worked until later on in the years, so my first attempt was written all in the main function. Eventually I gained more
understanding and converted the code to the more elegant ways of Object Oriented Programming. None of the variables are private
even though they probably should be now that I think about it. At first it was written with the class and the main function
inside of the same .cpp file. Later I separated it even further into the most truest form of OOP.
It has a .hpp for the class definition file, the .cpp for the implementation file, and finally a main.cpp for the main program
to run. Hopefully this helps some people who are learning how to code so that they can see the steps necessary to incorporate
converting their code into OOP style. I know when I first was learning to program this way it confused me. There were not many
examples online that made sense because books and online examples mainly teach how to put everything in one file instead
of separating them out into their unique definitions and implementations. I recently converted the code to read words from a
word list. I also added a Boost library call that trims the white space as I read the file in. If you need help with Boost
follow these helpful instructions https://www.boost.org/doc/libs/1_61_0/more/getting_started/unix-variants.html .
Thank you and have fun using the program! Feel free to change it any way you like, or if you have any feedback I'm all ears
for that too! Take care!

***
My Instructions for compiling this program in Linux:
compiler used: g++ .
compiler version: gcc version 6.3.0 20170516 (Raspbian 6.3.0-18+rpi1+deb9u1) .
***

**1. Have _Hangman.hpp_, _Hangman.cpp_, and _main.cpp_ in the same working
directory.**

**2. Navigate to the directory that has these three files and use the command below to compile and create your object file for linking with the executable:**

`g++ -std=c++11 Hangman.cpp main.cpp -o HangmanClass`

**3. Where "HangmanClass" will be the name of the Linux executable that you are creating as your outfile.**

**4. To run and play the game Run the command:**

`./HangmanClass`

**1. The same can be done with the individual files _hangmangameClass.cpp_ and _hangmaninmain.cpp_.**

**2. The commands for each respectively would be like this:**

`g++ -std=c++11 hangmangameClass.cpp -o HangmanClass`

or

`g++ -std=c++11 hangmaninmain.cpp -o HangmanClass`

**3. Do number 4 up above.**

**4. Remember if you made any changes don't forget to recompile.**

Hopefully this was helpful!
