/*
ID: michael223
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

ifstream fin ("barn1.in");
ofstream fout ("barn1.out");

int M; // Max number of boards 
int S; // Total # stalls 
int C; // Occupied stalls
vector<int> stalls; 

int minLength;

int getLength(int a, int b){
	return abs(stalls[b] - stalls[a]) + 1;
}


void next(int c, int m, int len){
	if(c == C) { 
		minLength = min(len, minLength);
	} else if (m < M && c < C){
		for(int i = c; i < C; i++){
			int length = len + getLength(c, i);
			int start = i + 1;
			int board = m + 1;
			// cout << c << ' ' << m << ' ' << len << endl;
			next(start, board, length);
		}
	}
}


int main(){
	fin >> M >> S >> C; 
	
	for(int i = 0; i < C; i ++){
		int c;
		fin >> c;
		stalls.push_back(c);
	}
	sort(stalls.begin(), stalls.end());
	minLength = S;
	if(M >= C) { minLength = C; } else {
		next(0, 0, 0);
	}
	fout << minLength << endl;

}
