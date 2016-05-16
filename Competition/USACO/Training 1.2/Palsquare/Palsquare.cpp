/*
ID: michael223
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

string reverseDigit(string str){
	string ret;
	for(int i = 0; i < str.size(); i++){
		ret += str[str.size() - 1 - i];
	}
	return ret; 
}

bool isPalindrome(string pal){
	string rev = reverseDigit(pal);
	if(rev.compare(pal) == 0){
		return true;
	} else { return false; } 
}

char toDigit(int n){
	switch(n){
		case 0: return '0';
		case 1: return '1';
		case 2: return '2';
		case 3: return '3';
		case 4: return '4';
		case 5: return '5';
		case 6: return '6';
		case 7: return '7';
		case 8: return '8';
		case 9: return '9';
		case 10: return 'A';
		case 11: return 'B';
		case 12: return 'C';
		case 13: return 'D';
		case 14: return 'E';
		case 15: return 'F';
		case 16: return 'G';
		case 17: return 'H';
		case 18: return 'I';
		case 19: return 'J';
		case 20: return 'K';
	}
}

string changeBase(int n, int b){
	int rem = n;
	string num;
	while(rem != 0){
		int c = rem % b;
		rem = rem / b;
		num = toDigit(c) + num; 	
	}
	return num;
}

void printValid(int b){
	ofstream fout ("palsquare.out");
	for(int n = 1; n < 301; n ++){
		string change = changeBase(n*n , b);
		if(isPalindrome(change)) { fout << changeBase(n, b) << ' ' << change << endl; } 
	}
}

int main(){
	ifstream fin ("palsquare.in");
	int b;
	fin >> b; 
	
	printValid(b);
}
