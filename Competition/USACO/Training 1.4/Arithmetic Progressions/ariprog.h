/*
NAME: michael223
PROB: ariprog
LANG: C++
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <bitset>
#include <fstream>
using namespace std; 

int N, M; // N - Length of Progressions M - Upper bound 
vector<int> bisquares;
bitset<125001> valid; 
ifstream fin ("ariprog.in");
ofstream fout ("ariprog.out");
int MAX; 

void calcBisquares(){
	for(int p = 0; p <= M; p++){
		for(int q = p; q <= M; q++){
			valid[p*p + q*q] = 1; 
			bisquares.push_back(p*p + q*q);
		}
	}
	sort(bisquares.begin(), bisquares.end());
	bisquares.erase(unique(bisquares.begin(), bisquares.end()), bisquares.end());
	MAX = bisquares[bisquares.size() - 1];
}

struct bsqDiff{
	int start;
	int diff;
};

vector<bsqDiff> pairs; 

void calc(int index){
	int difference = ceil((MAX - bisquares[index]) / (N- 1)) ;
	int adj = bisquares[index + 1] - bisquares[index];
	for(int i = adj; i <= difference; i++){
		bool yes = true; int j = 1;
		while(yes && j < N){
		   int value = bisquares[index] + j*i; 
           yes &= valid[value];
		   j++;
		}
	    if(yes) { 
			bsqDiff d = {bisquares[index], i};  
			pairs.push_back(d); 
		}
	}
}

bool cmpBsqDiff(bsqDiff b1, bsqDiff b2){
	if(b1.diff == b2.diff){
		return b1.start < b2.start;
	} else {
		return b1.diff < b2.diff; 
	}
}


int main(){
	fin >> N >> M;
	calcBisquares();
	// for(int i = 0; i < bisquares.size(); i++) { cout << bisquares[i] << " ";  }
	// cout << endl;
    for(int i = 0; i < bisquares.size() - 1; i++) { calc(i);}
	sort(pairs.begin(), pairs.end(), cmpBsqDiff);
	if(pairs.size() == 0) { fout << "NONE" << endl; } else {
	for(int i = 0; i < pairs.size(); i++){
		fout << pairs[i].start << " " << pairs[i].diff << endl;
	}
	}
	// cout << pairs.size();
}