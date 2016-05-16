/*
ID: michael223
PROG: skidesign
LANG: C++
DATE: 05/18/2015
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
int Cost = 1000*100 * 1000*100; // NUMBER OF (HILLS * ELEVATION)^2

vector<int> hills;


int main(){
	
	ifstream fin ("skidesign.in");
	
	fin >> N;
	
	for(int i = 0; i < N; i++){
		int h;
		fin >> h;
		hills.push_back(h);
	}
	
	for(int i = 0; i <= 83; i++){
		int price = 0;
		
		for(int j = 0; j < N; j++){
			int x = 0;
			if(hills[j] > (i + 17)) { x += hills[j] - (i + 17); }
			if(hills[j] < i) { x += i - hills[j]; }
			
			price += x*x;		
		}
		Cost = min(Cost, price);
		
	}
	
	ofstream fout ("skidesign.out");
	
	fout << Cost << endl;
}