// -------------------------------------------
//					Word
// -------------------------------------------

#include "Word.h"
#include <sstream>

Word::Word(const string& word): _word{word}
{
    // throws an exception (in the form of WordContainsNoLetters object)
    // indicating that the word being constructed contains no letters
    if (_word.empty()) throw WordContainsNoLetters();

    // throws an exception (in the form of WordContainsSpace object)
    // indicating that the word being constructed has a space
    // Also counts punctuation contained in word
    unsigned int puncCounter = 0;
    for (unsigned int i = 0; i != _word.size(); i++ )
    {
        if (isspace(_word.at(i))) throw WordContainsSpace();
        if (ispunct(_word.at(i))) puncCounter++;
    }

    // throws an exception (in the form of WordContainsNoLetters object)
    // indicating that the word being constructed consists solely of punctuation
    if (puncCounter == _word.size()) throw WordContainsNoLetters();

}

// overloads the equivalence operator which allows to Words to be compared using ==
bool Word::operator==(const Word& rhs) const
{
    // Store both words in temp variables and convert to lowercase  
    // temp to ensure original words aren't changed when/if accessed later
    string tempRhs = rhs._word;
    string tempLhs = _word;

    for (unsigned int i = 0; i < tempRhs.size(); i++ )
    {
        // Also ignore punctuation found in between the word
        if (ispunct(tempRhs.at(i))) {tempRhs.erase(i--,1);}
        // No punctuation found, convert to lower case
        else tempRhs.at(i) = tolower(tempRhs.at(i));
    }

    for (unsigned int i = 0; i < tempLhs.size(); i++ )
    {
        // Also ignore punctuation found in between the word
        if (ispunct(tempLhs.at(i))) {tempLhs.erase(i--,1);}
        // No punctuation found, convert to lower case
        else tempLhs.at(i) = tolower(tempLhs.at(i));
    }

    // Now compare
    if (tempLhs == tempRhs)
        return true;
    else
        return false;
}

// Check size to see if queryable
bool Word::isQueryable() const
{
    if (_word.size() >= 3) return true;
    else return false;
}
