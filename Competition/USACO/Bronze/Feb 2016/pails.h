#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std; 

ifstream fin ("pails.in");
ofstream fout ("pails.out"); 

int X, Y, M; // X < Y < M where M [1, 1000]  

struct Milk{
	int x, y; 
	int total; 
	
	Milk(int _x, int _y){
		x = _x;
		y = _y;
		total = x*X + y*Y; 
	}
};

vector<int> totals;

int generateMilk(){
	for(int i = 0; i <= M / X; i ++){
		for(int j = 0; j <= M / Y; j++){
			Milk pail (i, j);
			totals.push_back(pail.total);
		}
	}
	
	sort(totals.begin(), totals.end());
	
	while(!totals.empty() && totals.back() > M){
		totals.pop_back();
	}
	
	return totals.back(); 
}

int main(){
	fin >> X >> Y >> M;
	fout << generateMilk() << endl; 
}