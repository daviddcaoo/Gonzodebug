// Project 2
// Texttool.h

#pragma once

#include <string>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <list>

using namespace std;


class TextTool {
public:
	// default constructor
	TextTool() {
		totalw=0;
		duplicate=0;
		wordlist = new list<string>();

		// TO BE COMPLETED
	
	}

	// destructor
	~TextTool() {
		// TO BE COMPLETED
	
	}

	// Load information from a text file with the given filename.
	void loadListFromTextfile(string filename) {
		ifstream ifs;
		ifs.open(filename);

		if (ifs.is_open()) {
			string aword;
			while (ifs >> aword) {
				addEntryBack(aword);
			}
			ifs.close();
		}
		else
			throw invalid_argument("Could not open file " + filename);
	}

	// return the number of words in the linked list
	int totalWords() {
		return totalw; // TO BE COMPLETED
		
	}

	// add entry at the back of the linked list
	void addEntryBack(const string& aword) {
		wordlist->push_back(aword);
		totalw++;
		// TO BE COMPLETED
		
	}

	// print all words stored in the linked list, separated by a space
	const string listToString() {
		list<string>::iterator e;
		string str = "";
		for (e = wordlist->begin(); e != wordlist->end(); ++e)
		{
			 str +=*e+" ";
		}
		// TO BE COMPLETED
		return str; 
	
	}

	// print duplicated words in the linked list
	void printDuplicates() {
		list<string>::iterator i=wordlist->begin();
		list<string>::iterator b=wordlist->begin();
		i++;
		for (;i != wordlist->end(); ++i)
		{ 
			if (*i == *b)
			{
				cout <<"duplicated word found:"<< *b <<endl;
			}
			b++;
		}
		// TO BE COMPLETED
		
	}

	// remove duplicated words in the linked
	void removeDuplicates() {
		wordlist->unique();
		duplicate=0;
		// TO BE COMPLETED
		
	}

	// determine the total number of duplicated words in the list
	int totalDuplicates() {
		list<string>::iterator i = wordlist->begin();
		list<string>::iterator b = wordlist->begin();
		i++;
		for (;i != wordlist->end(); ++i)
		{
			if (*i == *b)
			{
				duplicate++;
			}
			b++;
		}
		return duplicate;
		// TO BE COMPLETED
		
	}

	// check if the list is empty
	bool isEmpty() {
		return wordlist->empty();
		// TO BE COMPLETED
	}

	//Empty the list
	void makeEmpty() {
		while (totalw != 0)
		{
		wordlist->pop_back();
		totalw--;
	}
		// TO BE COMPLETED
	}

private:
	int duplicate;
	int totalw;
	list<string> *wordlist;
};
