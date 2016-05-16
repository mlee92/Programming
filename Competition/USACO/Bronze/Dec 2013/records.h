/*
	8/24/2015: 10 out of 10 
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>

using namespace std; 

int N;
map<string, int> CowID;
map<string, int> Entrances;

ifstream fin ("records.in");
ofstream fout ("records.out");

int Frequency [1001]; 

int cowNum = 1; 

void insertCow(string cow){
	if(CowID[cow] == 0){
		CowID[cow] = cowNum;
		cowNum ++; 
	}
}
int entryNum = 1;

void insertEntry(string entry){
	if(Entrances[entry] == 0){
		Entrances[entry] = entryNum;
		entryNum ++;
	}
}

int main(){
	fin >> N;
	
	for(int i = 0; i < N; i++){
		int combo [3] = {0, 0, 0};
		for(int j = 0; j < 3; j++){
			string cow; 
			fin >> cow; 
			insertCow(cow);
			combo[j] = CowID[cow]; 
		}
		sort(combo, combo + 3);
		string entry = "   ";
		for(int j = 0; j < 3; j++){
			entry[j] = combo[j];
		} 
		insertEntry(entry);
		Frequency[Entrances[entry]] ++; 
	}
	
	sort(Frequency, Frequency + 1001);
	fout << Frequency[1000] << endl;
}