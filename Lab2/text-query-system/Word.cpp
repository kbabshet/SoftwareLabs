// -------------------------------------------
//					Word
// -------------------------------------------

#include "Word.h"
#include <sstream>

Word::Word(const string& word)
    : _word{ word }
{
    // throws an exception (in the form of WordContainsNoLetters object)
    // indicating that the word being constructed contains no letters
    if(_word.empty())
        throw WordContainsNoLetters();

    // throws an exception (in the form of WordContainsSpace object)
    // indicating that the word being constructed has a space
    // Also counts punctuation contained in word
    unsigned int puncCounter = 0;
    for(unsigned int i = 0; i != _word.size(); i++) {
        if(isspace(_word.at(i)))
            throw WordContainsSpace();
        if(ispunct(_word.at(i)))
            puncCounter++;
    }

    // throws an exception (in the form of WordContainsNoLetters object)
    // indicating that the word being constructed consists solely of punctuation
    if(puncCounter == _word.size())
        throw WordContainsNoLetters();
}

// overloads the equivalence operator which allows to Words to be compared using ==
bool Word::operator==(const Word& rhs) const
{
    // Store both words in temp variables and convert to lowercase
    string tempRhs = rhs._word;
    string tempLhs = _word;

    //    unsigned int blah;
    for(unsigned int i = 0; i < tempRhs.size(); i++) {
        if(ispunct(tempRhs.at(i))) {
            tempRhs.erase(i--, 1);
        } else
            tempRhs.at(i) = tolower(tempRhs.at(i));
    }

    for(unsigned int i = 0; i < tempLhs.size(); i++) {
        if(ispunct(tempLhs.at(i))) {
            tempLhs.erase(i--, 1);
        } else
            tempLhs.at(i) = tolower(tempLhs.at(i));
    }

    if(tempLhs == tempRhs)
        return true;
    else
        return false;
}

bool Word::isQueryable() const
{
    if(_word.size() >= 3)
        return true;
    else
        return false;
}