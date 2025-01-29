# HANGMAN GAME

![HangMan Game](https://github.com/Loksta8/HangManGame/blob/master/hangmanpic.gif?raw=true)

Welcome to my first Hangman Game that I created back in 2011. When I first created this program it was to teach me how to use
C++ to solve the problem of programming Hangman in the C++ Language. I did not know how Object Oriented Style Programming
worked until later on in the years, so my first attempt was written all in the main function. Eventually I gained more
understanding and converted the code to the more elegant ways of Object Oriented Programming. At first it was written with the class and the main function
inside of the same .cpp file. Later I separated it even further into the most truest form of OOP.
It has a .hpp for the class definition file, the .cpp for the implementation file, and finally a main.cpp for the main program
to run. Hopefully this helps some people who are learning how to code so that they can see the steps necessary to incorporate
converting their code into OOP style. I know when I first was learning to program this way it confused me at first. There were not many
examples online that made sense because books and online examples mainly teach how to put everything in one file instead
of separating them out into their unique definitions and implementations. I recently updated the code to read words from a word
list. You will need this word list or you could create your own. If you create your own just change the filepath location in
the main.cpp file or name the file wordlist_dictionary.txt . The name of the word list file is called wordlist_dictionary.txt. I found it floating around somewhere online, so sorry if there are words in there that don't make sense. I created a mini python command-line tool to help with tailoring the word list to only include word lengths that you specify via command line args. If people want to add more words they can either change the wordlist how they want themselves by adding more words, or they can use the python tool to tailor the words to a certain letter count. Thank you and have fun using the program! Feel free to change it any way you like, or if you have any feedback I'm all ears for that too! Take care and Enjoy guessing words!

***
> Instructions for running Python Command-Line tool:
> Python version: 3.5.3
***

**1. Have _word_tool.py_ and _wordlist_dictionary.txt_ in the same working
directory.**

**2. Run the program with something similar to these commands. The args are an integer for word length, input file, output file
name.txt parameter In this case *3* *wordlist_dictionary.txt* *newwords.txt* :**

`python3 word_tool.py 3 wordlist_dictionary.txt newwords.txt`

**3. Next the program will find all words with a length of 3 or less so it can
create a new file with words that are bigger than a length of 3. It will then
proceed to ask the user if they want the words displayed. Enter one of the
following to accept. Or anything else to not show the words and only get the
total words if any were found.**

`Y` `y` `YES` `Yes` `yes`

**4. The _newwords.txt_ file is now created in the working directory you ran the python
script in. You can now use this new file to compile with for Hangman. Just
remember before you compile to change the filename in the _main.cpp_.**

***
> My Instructions for compiling using CMAKE:
> CMAKE version: 3.10
***

**1. Open CMAKE and use CMakeLists.txt to build the project. If in windows navigate to the root directory where CMakeLists.txt is located. For Where to build the binaries create a 'build' folder inside the HangManGame source directory and build the binaries there. Generate the solution, open the solution, set Hangman project as the startup project build and compile. If building in Linux make a 'build' directory and change directories into the build directory. Run CMAKE inside the build directory.**

`cmake ../CMakeLists.txt`

**2. After cmake generates the make file in the build directory run the make command.**

`make`

**3. To run and play the game make sure wordlist_dictionary.txt is in the same directory as your Hangman executable and Run the command:**

`./Hangman`


Hopefully this was helpful!
