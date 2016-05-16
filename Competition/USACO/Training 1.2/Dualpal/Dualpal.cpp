/*
ID: michael223
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std; 

char toDigit(int n){ // Given value returns alphanumeric representation
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

string convertToBase(int n, int b){ // Returns base b representation of decimal n
	int rem = n;
	string str;
	while(rem != 0){
		int c = rem % b; 
		rem /= b;
		str = toDigit(c) + str; 
	}
	return str;
}

string reverseStr(string str1){
	string str;
	for(int i = 0; i < str1.size(); i++){
		str += str1[str1.size() - 1 - i];
	}
	return str;
}

bool isPalindrome(string num){
	return num.compare(reverseStr(num)) == 0;
}

bool checkDual(int n){
	int b = 2; 
	int pal = 0;
	
	while(pal < 2 && b <= 10){
		string conv = convertToBase(n, b);
		if(isPalindrome(conv)) {
			pal ++;
		}
		b++;
	}
	
	return (pal >= 2); 
}

void answer(int n, int s){
	int val = s + 1;
	int count;
	
	ofstream fout ("dualpal.out");
	while(count < n){
		if(checkDual(val) == true) { fout << val << endl; count ++; }
		val++;
	}
}

int main(){
	ifstream fin ("dualpal.in");
	int N, S; 
	fin >> N >> S;
	answer(N, S);
}