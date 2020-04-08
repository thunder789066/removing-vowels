// Christina Gerstner
// clgdtf@mail.umkc.edu
// 12/03/2019
// CS201L Lab 15

//#include "Lab15.h"
#include <iostream>
#include <fstream>
#include <list>
#include <iterator>
#include <string>
using namespace std;

void fillList(list<char>& l, string str) {	// "ABC" -> ["A"], ["B"], ["C"]
	string::iterator it;
	for (it = str.begin(); it != str.end(); ++it) {
		l.push_back(*it);
	}
}

//void removeChar(list<char> &l, char c) {
//	l.remove(c);
//}

void removeChar(list<char>& l, char c) {
	list<char>::iterator it;
	for (it = l.begin(); it != l.end();) {
		if (*it == c) {
			it = l.erase(it);
			continue;
		}
		it++;
	}
}

void printList(list<char>& l, ostream& fout) {
	list<char>::iterator it;
	for (it = l.begin(); it != l.end(); ++it) {
		fout << "[" << *it << "] -> ";
	}
	fout << 0 << endl << endl;
}

int main() {
	list<char> word;	// word -> sub/temp list
	string str;
	char c;

	ifstream fin("input.txt");
	ofstream fout("output.txt");

	// Throw error if can't open input file
	if (!fin) {
		cerr << "Error opening input file!";
		system("pause");
		return 1;
	}

	while (fin.good()) {
		getline(fin, str);
		if (str == "END") {
			break;
		}
		else {
			fillList(word, str);
			removeChar(word, 'a');
			removeChar(word, 'A');
			removeChar(word, 'e');
			removeChar(word, 'E');
			removeChar(word, 'i');
			removeChar(word, 'I');
			removeChar(word, 'o');
			removeChar(word, 'O');
			removeChar(word, 'u');
			removeChar(word, 'U');
			printList(word, fout);
			word.clear();
		}
	}
	fin.close();

	return 0;
}