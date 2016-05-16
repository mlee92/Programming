/*
NAME: michael223
PROB: numtri
LANG: C++
*/

#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <map>
#include <fstream>

using namespace std;

int R;
int numbers [1000][1000]; 
int dp [1000][1000]; 
int maxDist = 0;
ifstream fin ("numtri.in");
ofstream fout ("numtri.out");


void traverse(){
	int r = R;
	while(r != 0){
		for(int i = 0; i <= r - 1; i++){
			dp[r - 1][i] = dp[r - 1][i] + max(dp[r][i], dp[r][i + 1]); 
		}
		r--;
	}
}

int main(){
	fin >> R;
	for(int r = 0; r < R; r++){
		for(int c = 0; c <= r; c++){
			fin >> numbers[r][c];
			dp[r][c] = numbers[r][c];
		}
	}
	traverse();
	fout << dp[0][0] << endl;
}