#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std; 

ifstream fin ("balancing.in");
ofstream fout ("balancing.out"); 

struct Cow{
	int X, Y; // Odd positive integers at most B
	
	Cow(int x, int y) { X = x; Y = y; } 
};

int N; // Number of Cows [1, 100]
int B; // Max Coordinate [0, 1 000 000] 

vector<Cow> Cows; 

int region(Cow c, int a, int b){ // NW 0 NE 1 SW 2 SE 3 
	int dir = 0;
    if(c.X < a) // 
        dir += 1;
    else 
        dir += 3; 
    if(c.Y > b)
        dir += 5;
    else 
        dir += 9; 
	return (dir / 2) - 3; 
}


int M(int a, int b){
	int regions [] = {0, 0, 0, 0};   
	for(int i = 0; i < N; i++){
		int r = region(Cows[i], a, b); 
		regions[r] ++; 
	}
	int MR = 0;
	
	for(int j = 0; j < 4; j++){
	    MR = max(regions[j], MR);
	}
	
	return MR;
}
/*
	Naive Solution - Test every combo (a, b)
*/
int minBalance(){
	for(int i = 0; i <= B; i++){
		for(int j = 0; j <= B; j++){
			balance.push_back(M(i, j));
	vector<int> balance; 
		}
	}
	sort(balance.begin(), balance.end());
	return balance.front();
}

int main(){
	fin >> N >> B; 
	for(int i = 0; i < N; i++){
	    int x, y;
	    fin >> x >> y;
		Cow c (x, y);
		Cows.push_back(c); 
	}
	fout << minBalance() << endl; 
}