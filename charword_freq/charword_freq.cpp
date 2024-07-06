/************************************************************************************************************************
Name: Aaron P. Mills			Z#: Z-23547104
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: 07/14/2021			Total Points: 10
Assignment #: Assignment#7		Program Name: charword_freq.cpp

Description: This program counts the number of words in a file & the number occurrences of only each
letter in that file.

*************************************************************************************************************************/
//Include libraries
#include <iostream>				//input/ouput
#include <string>				//strings
#include <fstream>				//file input/output
#include <iomanip>				//input/output manipulation
using namespace std;			//allows ommition of "std::", because it is now implied. 

/*******************************************************************************************************************/
//function prototypes
void input(const string filename, string& str);
void wordCount(const string str);
void letCount(string str);

/*******************************************************************************************************************/
//Name:  input
//Precondition: Before this function executes,  string variable is declared & ready to accept input.
//Postcondition: After this function executes, the string variable will hold the data from the file. 
//Description: This function reads info from a file to store it in a string. It opens & closes file.
void input(const string filename, string& str) {
	ifstream in;
	in.open(filename);

	if (in.fail())
		cout << "Input file did not open correctly" << endl;
	else
	{
		getline(in, str);
		cout << str << endl;
	}
}

/*******************************************************************************************************************/
//Name: wordCount
//Precondition: Before the string variable holds the data from the file.
//Postcondition: After this function executes, the word count of the string is recorded & displayed. 
//Description: This function counts the number of words in a string & displays it to screen.
void wordCount(const string str) {
	int wrd_counter=0;
	for (int x = 0; x < str.length(); x++) {
		//if this index IS a letter & the next is NOT a letter
		if (str[x] >= 'A' && str[x] <= 'z' && !(str[x + 1] >= 'A' && str[x + 1] <= 'z'))
		{//then we have a word
			wrd_counter += 1;
		}
	}
	
	cout << wrd_counter << " words" << endl;
}

/*******************************************************************************************************************/
//Name:  charCount
//Precondition: Before function executes, the word count has been found, and the string holds file data.
//Postcondition: After this function executes, each letter is counted & displayed if it ever
//shows up in the string. 
//Description: This function counts the number of each letter in the string.
void letCount(string str) {
	//TEMPORARILY make the string lowercase for easier counting 
	for (int x = 0; x <= str.length(); x++) {
		str[x] = static_cast<char>(tolower(str[x]));
	}

	int let_counter;
	//Go through each letter of the alphabet
	for (char letter = 'a'; letter <= 'z'; letter++) {
		let_counter = 0;
	//Go through each character of the string	
		for (int y = 0; y <= str.length(); y++) {
	//compare current character with the current letter
			if (str[y] == letter) {
				let_counter += 1;
			}
		}
	//once finish counting current letter, display to screen ONLY if letter is in string
		if (let_counter > 0) {
			cout << let_counter << "\t" << letter << endl;
		}
	//continue until the last letter (z) is counted

	}
}

/*******************************************************************************************************************/
int main() {

	string str, filename = "word_data.txt";
	input(filename, str);	//read from file
	wordCount(str);			//count words
	letCount(str);			//count letters 

	return 0;
}