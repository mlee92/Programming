/*
BRUTE FORCE: 7 AC 3 TLE (7, 9, 10)
*/

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
 
string str; 

vector<int> Cpos;
vector<int> Opos;
vector<int> Wpos; 

ifstream fin ("cow.in");
ofstream fout ("cow.out");

// SOLUTION //

/*
For every O, there is a number of Cs before it; this combo is valid;
For every W, there is a number of Cs and Os before it; this is the desired combo.

Example:

COOWWW
 i = 0; foo = 'c'; C = 1; 
 i = 1; foo = 'o'; O += C = 1; 
 i = 2; foo = 'o'; O += C = 1 + 1 = 2;
 i = 3; foo = 'w'; W += O = 2;
 i = 4; foo = 'w'; W += O = 2 + 2 = 4;
 i = 5; foo = 'w'; W += O = 2 + 2 + 2 = 6;
 
 Valid Combos = 6
*/
long long count(){
	long long C = 0, O = 0, W = 0; 
	for(int i = 0; i < str.size(); i++){
		char foo = str[i];
		if(foo == 'C'){
			C ++;
		} else if(foo == 'O'){
			O += C;
		} else if(foo == 'W'){
			W += O;
		}
	}
	return W; 
}

// BRUTE FORCE SOLUTION

void occurences(){
	for(int i = 0; i < str.size(); i ++){
		char c = str[i];
		if(c == 'C') { Cpos.push_back(i); } 
		if(c == 'O') { Opos.push_back(i); }
		if(c == 'W') { Wpos.push_back(i); } 
	}
}

int comb(){
	int num = 0;
	
	for(int i = 0; i < Cpos.size(); i ++){
		for(int j = 0; j < Opos.size(); j ++){
			for(int k = 0; k < Wpos.size(); k++){
				int c = Cpos[i];
				int o = Opos[j];
				int w = Wpos[k];
				if((c < o) && (o < w) && (c < w)){ num ++; } 
			}
		}
	}
	return num;
}
// CONSOLE MAIN 

int cmain(){
	int N;
	cin >> N;
	cin >> str;
	
	cout << count() << endl;
	
}

// FILE MAIN
int main(){
	int N;
	fin >> N;
	fin >> str;
	
	fout << count() << endl;
	// fout << comb() << endl;
}