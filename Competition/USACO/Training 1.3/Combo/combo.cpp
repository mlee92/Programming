/*
ID: michael223
PROG: combo
LANG: C++
*/

#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int validCombo [2][3];
int N;
int counter = 0;

bool valid(int a, int b){
	if((abs(a - b) >= N - 2) || (abs(a - b) <= 2)){
		return true;
	} else { return false; }
}

bool checkValid(int a, int combo, int id){
	return valid(a, validCombo[combo][id]);
}

bool checkCombo(int a, int b, int c, int combo){
	int tol = checkValid(a, combo, 0) + checkValid(b, combo, 1) + checkValid(c, combo, 2);
	return tol == 3;
}

void count(){
	for(int a = 1; a <= N; a ++){
		for(int b = 1; b <= N; b++){
			for(int c = 1; c <= N; c++){
				bool farmer = checkCombo(a, b, c, 0);
				bool master = checkCombo(a, b, c, 1);
				if(farmer && !master) { counter ++; }
				if(master && !farmer) { counter++; }
				if(farmer && master) { counter ++; } 
			}
		}
	}
}

int main(){
	ifstream fin ("combo.in");
	fin >> N;
	fin >> validCombo[0][0] >> validCombo[0][1] >> validCombo[0][2];
	fin >> validCombo[1][0] >> validCombo[1][1] >> validCombo[1][2];
	count();
	
	ofstream fout ("combo.out");
	fout << counter << endl;
}