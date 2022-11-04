#ifndef WORDLADDER_H
#define WORDLADDER_H

#include <iostream>
#include <list>

using namespace std;
class WordLadder {
    private:
        list<string> dict;        //list of possible words in ladder
        int comparisons = 0;          // The number of character comparisons
        bool optimization = false;        // Sets the optimization on (true) and off (false)

    public:
        /* Passes in the name of a file that contains a dictionary of 5-letter words.
            Fills the list (dict) with the words within this file.
            If the file does not open for any reason or if any word within the file
            does not have exactly 5 characters, this function should output an
            error message and return.
        */
        WordLadder(const string&);

        /* Passes in two 5-letter words and the name of an output file.
            Outputs to this file a word ladder that starts from the first word passed in
            and ends with the second word passed in.
            If either word passed in does not exist in the dictionary (dict),
            this function should output an error message and return.
            Otherwise, this function outputs to the file the word ladder it finds or outputs
            to the file, the message, "No Word Ladder Found."
        */
        void outputLadder(const string& start, const string& end, const string& outputFile);

        void setOptimization(bool); // Set the optimization variable
        int getComparisons() const { return this->comparisons; } // Return the number of character comparisons
    private:
        bool shift(const string& curr, const string& next);
};
#endif