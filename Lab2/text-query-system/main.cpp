#include <iostream>
#include <vector>
#include "FileReader.h"
#include "Paragraph.h"
#include "Word.h"

int main(int argc, char** argv)
{
    string filename;
    cout << "Enter a filename: ";
    cin >> filename;

    FileReader filereader{ filename };

    string search_word;

    while(search_word != ".") {
        cout << "Enter a word to search for, or '.' to quit: ";
        cin >> search_word;

        if(search_word == ".") {
            break;
        }

        Paragraph paragraph;
        filereader.readFileInto(paragraph);
        Word word{ search_word };
        vector<int> line_numbers;

        if(paragraph.contains(word, line_numbers)) {
            cout << "Word found:" << endl;
            for(const auto& line : line_numbers) {
                cout << "\tline " << line << endl;
            }
        } else {
            cout << "Word not found... pizza" << endl;
        }
    }

    return 0;
}
