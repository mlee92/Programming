// Naive Solution 6/11

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std; 

ifstream fin ("crowded.in");
ofstream fout ("crowded.out"); 

int N, D;

struct Cow{
	int x;
	int h;

	Cow(int X, int H){
		x = X;
		h = H; 
	}
};

vector<Cow> cows;

bool ascendingCow(Cow c1, Cow c2){
	return c1.x < c2.x; 
}

bool crowdPos(Cow c1, Cow c2){ // Should I compare these two cows?
	return abs(c1.x - c2.x) <= D; 
}

bool crowdHeight(Cow c1, Cow c2){ // is c2 at least twice as tall as c1 
	return ((c2.h >= c1.h * 2));
}

void test(){
	D = 5; 
	Cow c1 (10, 100);
	Cow c2 (11, 1000);
	cout << crowdPos(c1, c2) << crowdHeight(c2, c1);
}

bool solveRight(int i){
	Cow c_i = cows[i];
	int x_i = c_i.x;
	int h_i = c_i.h; 
	
	int j = 1; 
	
	int crowd = 0; 
	bool running = true;
	
	while((i + j) < N && (i + j) >= 0 && running){
		Cow c_j = cows[i + j];
		int x_j = c_j.x;
		int h_j = c_j.h; 
		
		running &= crowdPos(c_i, c_j);
		
		if(h_j >= h_i*2){
			crowd++;
			running = false;
		}
		j++;
	}
	
	return (crowd > 0);
}

bool solveLeft(int i){
	Cow c_i = cows[i];
	int x_i = c_i.x;
	int h_i = c_i.h; 
	
	int j = 1; 
	
	int crowd = 0; 
	bool running = true;
	
	while((i - j) < N && (i - j) >= 0 && running){
		Cow c_j = cows[i - j];
		int x_j = c_j.x;
		int h_j = c_j.h; 
		
		running &= crowdPos(c_i, c_j);
		
		if(h_j >= h_i*2){
			crowd++;
			running = false;
		}
		j++;
	}
	
	return (crowd > 0);
}

int solve(){
	int crowd = 0;
	for(int i = 0; i < N; i++){
		if(solveLeft(i) and solveRight(i))
			crowd++;
	}
	return crowd;
}

int fmain(){
	fin >> N >> D; 
	for(int i = 0; i < N; i++){
		int x, h;
		fin >> x >> h; 
		Cow c (x, h);
		cows.push_back(c);
	}
	
	sort(cows.begin(), cows.end(), ascendingCow);
	
	fout << solve() << endl;
}

int cmain(){
	cin >> N >> D; 
	for(int i = 0; i < N; i++){
		int x, h;
		cin >> x >> h; 
		Cow c (x, h);
		cows.push_back(c);
	}
	
	sort(cows.begin(), cows.end(), ascendingCow);
	
	cout << solve() << endl;
}

int main(){
	fmain();
}