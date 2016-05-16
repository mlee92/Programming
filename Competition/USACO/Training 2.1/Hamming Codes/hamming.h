/*
NAME: michael223
PROG: hamming
LANG: C++
*/

#include <iostream>
#include <fstream>


using namespace std; 

int N; 
int B;
int D; 

ifstream fin ("hamming.in");
ofstream fout ("hamming.out");

int codes [64];

int power(int i, int j){
	int pwr = 1;
	for(int s = 1; s < j; s++){
		pwr *= i;
	}
	return pwr; 
}

int hammingDistance(string a, string b){
	int dist = 0;
	for(int i = 0; i < a.size(); i++){
		if(a[i] != b[i]){
			dist ++; 
		}
	}
	return dist; 
}

string binIntStr(int i){
	int bin = i;
	int pos = B;
	string ret = "";
	while(pos > 0){
		int d = power(2, pos);
		if(bin >= d){
			ret += '1';
			bin -= d; 
		} else {
			ret += '0';
		}
		pos --;
	}
	return ret; 
}

int code_size;

bool checkSolution(int sol){
	bool check = true;
	string binStr = binIntStr(sol);

	for(int i = 0; i < code_size; i++){
		int dist = hammingDistance(binIntStr(codes[i]), binStr);
		check &= dist >= D; 
	}
	return check;
}

void addSolution(){
	bool added = false;
	int run = codes[code_size - 1] + 1;
	
	while(!added){
		if(checkSolution(run)){
			codes[code_size] = run;
			code_size ++;
			added = true; 
		} else {
			run ++;
		}
	}
}

void answer(){
	code_size = 1; 
	codes[0] = 0; 
	while(code_size != N){
		addSolution(); 
	}
	
	for(int i = 0; i < N - 1; i++){
		cout << codes[i];
		if((i + 1) % 10 == 0){
			cout << endl;
		} else {
			cout << ' ';
		}
	}
	cout << codes[N - 1] << endl;
}



int main(){
	cin >> N >> B >> D; 
	answer();
}
