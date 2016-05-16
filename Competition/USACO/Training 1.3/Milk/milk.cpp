/*
ID: michael223
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std; 

ifstream fin ("milk.in");
ofstream fout ("milk.out");

int N; // Milk wanted per day 
int M; // Number of farmers

struct Farmer {
	int price;
	int milk;
};

vector<Farmer> farmers;

bool comparePrices(Farmer f1, Farmer f2){
	return f1.price < f2.price; 
}

int calcPayment(){
	int quota = N;
	int pay = 0;
	
	int id = 0; 
	
	while(quota > 0 && id < farmers.size()){
		int max = farmers[id].milk;
		while(quota < max){
			max--; 
		}
		quota -= max; 
		pay += max * farmers[id].price; 
	    id++;
	}
	return pay; 
}

int main(){
	fin >> N >> M;
	
	for(int m = 0; m < M; m++){
		int p, a; 
		fin >> p >> a;
		Farmer f = {p, a}; 
		farmers.push_back(f);
	}
	
	sort(farmers.begin(), farmers.end(), comparePrices);
	
	fout << calcPayment() << endl;
}