// -------------------------------------------
//					Paragraph
// -------------------------------------------

#include "Paragraph.h"
#include <iostream>

void Paragraph::addLine(const Line& line)
{
    _lines.push_back(line);
}

bool Paragraph::contains(const Word& search_word, vector<int>& line_numbers) const
{
    bool found = false;
    
    line_numbers.clear();
	for (auto i = 0; i < _lines.size(); ++i) {
        if (_lines[i].contains(search_word)) {
            // vector indices are zero-based but line numbers start at one
            line_numbers.push_back(i + 1);
            cout << i << endl;
            found = true;
        }
    }
    
    return found;
}