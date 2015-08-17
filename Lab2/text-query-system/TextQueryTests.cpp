#include "Word.h"
#include "Line.h"
#include "Paragraph.h"
#include "FileReader.h"
#include <gtest/gtest.h>

const string PUNCTUATION = "~`!@#$%^&*()-_+={}[]\\|:;'<>?,./\"";
const string UPPERCASE = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string LOWERCASE = "abcdefghijklmnopqrstuvwxyz";
const int MIN_SIZE_FOR_QUERY = 3;

// ----------------------------------------------------

// Test the null case first - cannot have an empty word
// EXPECT_THROW is described in the googletest advanced guide:
// https://code.google.com/p/googletest/wiki/V1_6_AdvancedGuide#Exception_Assertions
TEST(Word, throwsAnExceptionIfEmpty) {
	EXPECT_THROW({Word testword("");}, WordContainsNoLetters);
}

TEST(Word, canIdentifyIdenticalWords) {
	Word word1("that");
	Word word2("that");
	EXPECT_TRUE(word1 == word2);
}

TEST(Word, canIdentifyNonIdenticalWords) {
	Word word1("this");
	Word word2("that");
	EXPECT_FALSE(word1 == word2);
}

TEST(Word, ignoresCaseWhenComparedWithAnotherWord) {
	Word uppercase_word(UPPERCASE);
	Word lowercase_word(LOWERCASE);
	EXPECT_TRUE(lowercase_word == uppercase_word);
}

TEST(Word, ignoresPunctuationWhenComparedWithAnotherWord) {
	Word word_with_punct(PUNCTUATION + "hel" + PUNCTUATION + "lo" + PUNCTUATION);
	Word word_without_punct("hello");
	EXPECT_TRUE(word_without_punct == word_with_punct);
}

TEST(Word, throwsAnExceptionIfItConsistsSolelyOfPunctuation) {
	EXPECT_THROW({Word testword("!@#$%");}, WordContainsNoLetters);
}

TEST(Word, throwsAnExceptionIfItContainsASpace) {
	EXPECT_THROW({Word testword("hello there");}, WordContainsSpace);
}

TEST(Word, isQueryableIfGreaterThanOrEqualToASpecifiedSize) {
	string test_string;
	test_string.resize(MIN_SIZE_FOR_QUERY, 'a');
	Word test_word(test_string);
	EXPECT_TRUE(test_word.isQueryable());
}

TEST(Word, isNotQueryableIfLessThanASpecifiedSize) {
    string test_string;
    test_string = "ab"; //String length = 2 (therefore < 3)
    Word test_word(test_string);
    EXPECT_FALSE(test_word.isQueryable());
}

//// Test null case first - here, an empty line
TEST(Line, cannotFindWordInEmptyLine) {
   Line testline("");
   Word searchword("hello");
   EXPECT_FALSE(testline.contains(searchword));
}
//
TEST(Line, canFindTheOnlyWordInLineWithOneWord) {
    Line testline("Stop");
	Word searchword("Stop");
	EXPECT_TRUE(testline.contains(searchword));
}
//
//// It is always good to write tests which test boundary conditions
TEST(Line, canFindFirstAndLastWords) {
	Line testline("Walking on water and developing software from a specification are easy if both are frozen.");
	Word first_word_in_line("Walking");
	EXPECT_TRUE(testline.contains(first_word_in_line));
	Word second_word_in_line("frozen");
	EXPECT_TRUE(testline.contains(second_word_in_line));
}
//
//// Test not only success scenarios but also failure scenarios.
TEST(Line, cannotFindWordNotInLine) {
	Line testline("I have always wished for my computer to be as easy to use as my telephone; my wish has come true because I can no longer figure out how to use my telephone.");
	Word word_not_in_line("cellphone");
	EXPECT_FALSE(testline.contains(word_not_in_line));
}
//
TEST(Line, canFindWordsIrrespectiveOfCase) {
	Line testline("You can stand on the shoulders of giants or a BIG enough pile of dwarfs, works either way.");
	Word lower_case("big");
	EXPECT_TRUE(testline.contains(lower_case));
	Word uppercase("STAND");
	EXPECT_TRUE(testline.contains(uppercase));
}

TEST(Line, canFindWordsIrrespectiveOfPunctuation) {
	Line testline("How can you tell if a person is a programmer? They use nested parentheses in normal writing (at least I do (sometimes)).");
	Word punctuation_word_1("programmer");
	EXPECT_TRUE(testline.contains(punctuation_word_1));
	Word punctuation_word_2("sometimes");
	EXPECT_TRUE(testline.contains(punctuation_word_2));
}

TEST(Line, cannotFindWordWhichIsNotQueryable) {
   Line testline("Any fool can write code that a computer can understand. Good programmers write code that humans can understand.");
   Word too_small_to_query("a");
   EXPECT_FALSE(testline.contains(too_small_to_query));
}

// ----------------------------------------------------

TEST(Paragraph, cannotFindWordInEmptyParagraph) {
    Paragraph par;
    Word word("Hello");
    vector<int> lines;
    EXPECT_FALSE(par.contains(word, lines));
    EXPECT_TRUE(lines.empty());
}
//
TEST(Paragraph, cannotFindWordNotInParagraph) {
    Paragraph par;
    Line line("There are some words here, but not the one you're looking for.");
    par.addLine(line);
    Word word("Hello");
    vector<int> lines;
    EXPECT_FALSE(par.contains(word, lines));
    EXPECT_TRUE(lines.empty());
}
//
TEST(Paragraph, canFindWordAppearingOnceAndReturnLineNumber) {
    Paragraph par;
    Line line("There are some words here.");
    par.addLine(line);
    Word word("some");
    vector<int> lines;
    EXPECT_TRUE(par.contains(word, lines));
    EXPECT_FALSE(lines.empty());
    EXPECT_TRUE(lines.at(0) == 1);
}
//
TEST(Paragraph, canFindSameWordAppearingOnDifferentLinesAndReturnLineNumbers) {
    Paragraph par;
    Line line1("There are some words here.");
    Line line2("And some more here.");
    par.addLine(line1);
    par.addLine(line2);
    Word word("some");
    vector<int> lines;
    EXPECT_TRUE(par.contains(word, lines));
    EXPECT_FALSE(lines.empty());
    EXPECT_TRUE(lines.size() == 2);
    EXPECT_TRUE(lines.at(0) == 1);
    EXPECT_TRUE(lines.at(1) == 2);
}
//
TEST(Paragraph, correctlyReturnsLineNumbersWhichAccountForAnEmptyLine) {
    // If the first line of the paragraph is empty, and the word being searched for
    // is on the second line, the vector returned should be: [2]
    Paragraph par;
    Line line1("");
    Line line2("There are some words here.");
    par.addLine(line1);
    par.addLine(line2);
    Word word("some");
    vector<int> lines;
    EXPECT_TRUE(par.contains(word, lines));
    EXPECT_FALSE(lines.empty());
    EXPECT_TRUE(lines.at(0) == 2);
}
//
//// ----------------------------------------------------
//
// Integration test - both Paragraph and File Reader are tested together
TEST(Paragraph, usingFileReaderCanFindWordAppearingMultipleTimesInParagraph) {
	// make sure that alice.txt is in the right location for this to work!
	// in Visual C++ and Code::Blocks, that location is the root directory of the project --
	// not the directory which contains the executable
    //
    // CodeLite requires alice.txt to be in the Debug folder
	FileReader filereader("alice.txt");
	Paragraph paragraph;
	filereader.readFileInto(paragraph);
	Word search_word("Daddy");
	vector<int> line_numbers;
	EXPECT_TRUE(paragraph.contains(search_word, line_numbers));
	vector<int> expected_line_numbers;
	expected_line_numbers.push_back(1);
	expected_line_numbers.push_back(4);
	expected_line_numbers.push_back(6);
	EXPECT_TRUE(expected_line_numbers == line_numbers);
}