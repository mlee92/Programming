/*
ID: michael223
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream fin ("ride.in");
ofstream fout ("ride.out");

int getCharValue(char c){
    return (int)c;
}

int getStringValue(string str){
    long long total = 1;
    for(int i = 0; i < str.size(); i++){
        total *= getCharValue(str[i]);
    }
    return total % 47;
}

int main() {
    string str1, str2;
    fin >> str1 >> str2;
    if((getStringValue(str1) == 27) && (getStringValue(str2) == 27)){
        fout << "GO" << endl;
    } else {
        fout  << "STAY" << endl;
    }
	// your code goes here
	return 0;
}

