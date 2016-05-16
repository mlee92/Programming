/*
	8/24/2015: 10 out of 10 
*/

#include <iostream>
#include <fstream>
#include <algorithm> 

using namespace std;

int N; 

int cowPos [1001];

int valid = 0;

ifstream fin ("baseball.in");
ofstream fout ("baseball.out");

void Count(){
	for(int x = 0; x < N; x++){
		for(int y = x + 1; y < N; y++){
			int XY = cowPos[y] - cowPos[x]; 
			for(int z = y + 1; z < N; z++){
				int YZ = cowPos[z] - cowPos[y];
				if((XY <= YZ) && (YZ <= 2*XY)){
					valid ++; 
				}
			}
		}
	}
}

int main(){
	fin >> N;
	for(int i = 0; i < N; i++){
		fin >> cowPos[i];  
	}
	sort(cowPos, cowPos + N);
	Count();
	fout << valid << endl;
}