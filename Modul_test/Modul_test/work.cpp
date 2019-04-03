#include <iostream>
#include <fstream>
#include <string>
#include "stack.h"
#include "work.h"
using namespace std;

void analysis(string filename){
	ifstream the_file(filename);
	if (!the_file.is_open()){
		cout << "can't oppen the sile\n";
		return;
	}
	string the_bars = bars(filename);
	char buff;
	stack mystack;
	ofstream result("result.txt", ios::trunc);

	while (!the_file.eof()){
		buff = the_file.get();
		if ((the_bars.find_first_of(buff) != string::npos) && (the_bars.find_first_of(buff) % 2 == 0)){
			if ((the_bars.find(buff) + 1) == the_bars.rfind(buff)){
				if (mystack.top != NULL){
					if (mystack.top->symbol == buff)
						pop(mystack, buff);
					else
						push(mystack, buff);
				}
			}
			else{
				push(mystack, buff);
			}
		}
		else if ((the_bars.find_first_of(buff) != string::npos) && (the_bars.find_first_of(buff) % 2 == 1)){
			if ((the_bars.find(mystack.top->symbol) + 1) == the_bars.rfind(buff)){
				pop(mystack, buff);
			}
			else if (mystack.top == NULL){
				cout << "No Balance\n";
				result << "Bars Are Not Balanced\n";
				result.close();
				the_file.close();
				return;
			}
		}
	}
	if (!empty_or_not(mystack)){
		cout << "No Balance\n";
		result << "Bars Are Not Balanced\n";
		result.close();
		the_file.close();
		return;
	}
	cout << "bars are ballenced\n";
	result << "The Bars Are Ballanced!!";
	result.close();
	the_file.close();
}

string bars(string filename){
	ifstream the_file(filename);
	string buff;
	while (!the_file.eof()){
		getline(the_file, buff);
	}
	the_file.close();
	return buff;
}
