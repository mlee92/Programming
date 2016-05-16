/*
DATE: 05/18/2015

CHEATED

Solution:
start X, Y = 10 then evaluate 
if value(X) > value(Y) ; Y ++; 
it will eventually terminate
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int K; 
string strX; // RANGE [10..15000]
string strY;
int X, Y;

ifstream fin ("whatbase.in");
ofstream fout ("whatbase.out");
 
int eval(string str, int base){
	int ret = ((str[0] - '0') * base * base) + ((str[1] - '0') * base) + (str[2] - '0');
	return ret; 
}

void calc(){
	X = 10; Y = 10;
	while(X <= 15000 && Y <= 15000){
		int evX = eval(strX, X);
		int evY = eval(strY, Y);
		if(evX > evY) { Y++; } 
		if(evX < evY) { X++; }
		if(evX == evY) { fout << X << ' ' << Y << endl; break; }
	}
}

int main(){
	fin >> K; 
	for(int i = 0; i < K; i++){
		fin >> strX >> strY; 
		calc();
	}
}