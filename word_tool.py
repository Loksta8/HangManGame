import sys, getopt
import io
import string

'''
@Author: Logan Herrera
@Date: 5/14/2020
@Version: Python 3.5.3
@Description: A tool in its infancy that will help count the number of letters
in a given word from a word list. It assumes the list is given one word at a time
one line at a time. The program take a number value as a command-line argument
and it will check the list and find any words greater than or equal to that amount.
@Purpose: A quick letter counter tool to look through a word file structured as
one word on each new line. It will return a list of culprits found that meet the
criteria. Works with wordlist_dictionary.txt. Eventually I will build this tool
into something better, such as: Giving the choice to delete the words found
based off of the criteria, create a new file with the found words removed.
'''

#Function to Read the word file and return
#the filtered words meeting the criteria
def ReadAndCreateNew(aFilename, aNewFile, aNumLetters, aWordsFound):
    with io.open(aNewFile, 'w') as outfile:
        with io.open(aFilename, 'rt') as readfile:
            for line in readfile:
                line = line.rstrip() # strip white space
                if(len(line) <= aNumLetters):
                    aWordsFound.append(line) # Words have been found greater than or equal to the argument given
                elif(len(line) > aNumLetters):
                    outfile.write(line + "\n")
                if not aWordsFound:
                    print ("No Words matched length criteria of: ", aNumLetters, "\n")
            return aWordsFound

#Function to Print the Words Found
def PrintFound(aWordsFound):
    for words in aWordsFound:
        print ("Word Found: ", words)
        print ("Length: ", len(words), " \n")

def Choice(aAnswer, aWordsFound):
    if(aAnswer == 'Y' or aAnswer == 'y' or aAnswer == 'yes' or aAnswer == 'Yes' or aAnswer == 'YES'):
        PrintFound(aWordsFound) # Display the found words that meet the criteria
        print("\n")
        print("Total words found: " , len(aWordsFound))
    else:
        print("\n")
        print("Total words found: " , len(aWordsFound))

#Main function
def main(argv):
    wordsFound = []
    filename = argv[2]
    newfile = argv[3]
    numLetters = int(argv[1]) # The number up to this amount of letters we will filter for
    ReadAndCreateNew(filename, newfile, numLetters, wordsFound) # Read the file
    print("Would you like to see the words got removed? " , "\n")
    answer = input("Enter 'Y' for Yes or anything else for No. ")
    Choice(answer, wordsFound)
    print("The file ", newfile , " is now ready with the words removed from it.")

if __name__=="__main__":
    main(sys.argv)
