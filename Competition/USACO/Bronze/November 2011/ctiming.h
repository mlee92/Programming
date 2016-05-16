#include <iostream>
#include <fstream>

using namespace std;

int D, H, M;

int N = 11; 

ifstream fin ("ctiming.in");
ofstream fout ("ctiming.out");

int calcMinutes(int d, int h, int m){
	if(m < 0){
		m += 60;
		h --;
	}
	if(h < 0){
		h += 24; 
		d --;  
	h += d * 24; 
	int minutes = m;
	minutes += h * 60; 
	return minutes;
}

int main(){
	fin >> D >> H >> M;
	
	int Time [3];
	Time[0] = D - 11; 
	Time[1] = H - 11;
	Time[2] = M - 11; 
	fout << calcMinutes(Time[0], Time[1], Time[2]) << endl;
}