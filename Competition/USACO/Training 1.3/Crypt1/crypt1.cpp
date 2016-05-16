/*
ID: michael223
PROG: crypt1
LANG: C++
DATE: 05/18/2015
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

ifstream fin ("crypt1.in");
ofstream fout ("crypt1.out");

vector<int> digits;
int N;

string toString(int num){
	stringstream ss;
	ss << num;
	return ss.str();
}
bool contains(int i){
	int c = 0;
	bool contain = false; 
	while(!contain && c < N){
		contain |= digits[c] == i;
	    c++;
	}
	return contain;
}

bool validNumber(int number){
    bool valid = true;
    while (number && valid)
    {
        int digit = number % 10;
        number /= 10;
        valid = valid && contains(digit);
	}
	return valid;
}

void calc(){
	int count = 0;
	for(int a = 0; a < N; a++){
		for(int b = 0; b < N; b++){
			for(int c = 0; c < N; c++){
				for(int d = 0; d < N; d++){
					for(int e = 0; e < N; e++){
						int A = digits[a];
						int B = digits[b];
						int C = digits[c];
						int D = digits[d];
						int E = digits[e]; 
						int ABC = 100*A + 10*B + C;
						int DE = 10*D + E; 
						int partial1 = D*ABC; string p1 = toString(partial1);
						int partial2 = E*ABC; string p2 = toString(partial2);
						int ABCDE = ABC * DE; string abcde = toString(ABCDE);
						bool valid = validNumber(partial1) && validNumber(partial2) && validNumber(ABCDE);
						valid &= (p1.size() == 3);
						valid &= (p2.size() == 3);
						valid &= (abcde.size() == 4); 
						if(valid) { count ++; }
					}
				}	
			}
		}
	}
	fout << count << endl;
}

int main(){
	fin >> N;
	for(int i = 0; i < N; i++){
		int n;
		fin >> n;
		digits.push_back(n);
	}
	calc();
}