/*
ID: michael223
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> strDict;
vector<string> numDict;

char getDigit(char c){
	switch(c){
		case 'A':
			return '2';
		case 'B':
			return '2';
		case 'C':
			return '2';
		case 'D':
			return '3';
		case 'E':
			return '3';
		case 'F':
			return '3';
		case 'G':
			return '4';
		case 'H':
			return '4';
		case 'I':
			return '4';
		case 'J':
			return '5';
		case 'K':
			return '5';
		case 'L':
			return '5';
		case 'M':
			return '6';
		case 'N':
			return '6';
		case 'O':
			return '6';
		case 'P':
			return '7';
		case 'R':
			return '7';
		case 'S':
			return '7';
		case 'T':
			return '8';
		case 'U':
			return '8';
		case 'V':
			return '8';
		case 'W':
			return '9';
		case 'X':
			return '9';
		case 'Y':
			return '9';
	}
}

void loadDict(){
	ifstream fin ("dict.txt");
	string name;
	while(fin >> name && !name.empty()){
		strDict.push_back(name);
		//cout << name << endl;
	}
}

string transStr(string str){
    string num;
    for(int i = 0; i  < str.size(); i++){
        num += getDigit(str[i]);
    }
    return num;
}

void transDict(){
    for(int i = 0; i < strDict.size(); i++){
        string str = strDict[i];
        string num = transStr(str);
        numDict.push_back(num);
    }
}


void printValid(string cell){
    ofstream fout ("namenum.out");
	bool set = false;
    for(int i = 0; i < numDict.size(); i++){
        string test = numDict[i];
        if(test.compare(cell) == 0) {
			set = true;
            fout << strDict[i] << endl;
        }
    }
	if(set == false) { fout << "NONE" << endl; }
}

int main(){
    loadDict();
    transDict();
    string name;
    ifstream fin ("namenum.in");
    getline(fin, name);
    printValid(name);
}