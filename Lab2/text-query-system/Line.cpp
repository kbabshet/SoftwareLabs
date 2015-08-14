// -------------------------------------------
//					Line
// -------------------------------------------

#include "Line.h"
#include <sstream>

Line::Line(const string& line)
{
	// Hint: some of string's member functions might come in handy here
	// for extracting words.
    std::istringstream iss(line);
    
    string substring;
    while (iss >> substring) {
        words.push_back(substring);
    }
}

bool Line::contains(const Word& search_word) const
{
	for (auto word : words) {
        if (word == search_word) {
            return true;
        }
    }
    
    return false;
}
