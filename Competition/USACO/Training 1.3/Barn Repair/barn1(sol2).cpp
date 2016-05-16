/*
ID: michael223
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <deque>
#include <bitset>
#include <algorithm>

using namespace std;

ifstream fin ("barn1.in");
ofstream fout ("barn1.out"); 

int M, S, C;

deque<int> stalls;
deque<int> gaps;
int runningsum; 

bool cmp (int a, int b){
    return a > b;
}


void loadGaps(){
    sort(stalls.begin(), stalls.end());
	
	for(int i = 1; i < stalls.size(); i ++){
		int gap = stalls[i] - stalls[i - 1] - 1; 
		if(gap > 0){
		gaps.push_back(gap);
		}
	}
	sort(gaps.begin(), gaps.end(), cmp);
}

int main(){
	fin >> M >> S >> C; 
	for(int i = 0; i < C; i++){
		int c;
		fin >> c;
		stalls.push_back(c);
	}
	sort(stalls.begin(), stalls.end());
	
	loadGaps();
    runningsum = stalls[stalls.size() - 1] - stalls[0] + 1; 

	for(int m = 0; m < M - 1 && m < gaps.size(); m++){
		runningsum -= gaps[m];
	}
	fout << runningsum << endl;
}