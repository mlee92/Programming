/*
NAME: michael223
PROG: frac1
LANG: C++
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std; 

int N;
ifstream fin ("frac1.in");
ofstream fout ("frac1.out");

int gcd(int x, int y){
	int temp;
	while(x > 0){
		temp = x;
		x = y % x;
		y = temp;
	}
	return y; 
}

struct fraction{
	int num;
	int den; 
};

vector<fraction> fv; 

bool cmp(fraction a, fraction b){
	return  b.den * a.num < b.num * a.den ; 
}

void addZero(){
	fraction zero = {0, 1};
	fv.push_back(zero);
}

void answer(){
	sort(fv.begin(), fv.end(), cmp);
	
	for(int i = 0; i < fv.size(); i++){
		fout << fv[i].num << '/' << fv[i].den << endl;
	}
}

int main(){
    fin >> N;
	addZero();
	
	for(int i = 1; i <= N; i++){
		for(int j = i; j <= N; j++){
			int num = i;
			int den = j; 
			int k = gcd(num, den); 
			// cout << num << ' ' << den << ' ' << k << endl;
			if(k == 1){
				fraction frac = {num, den};
				fv.push_back(frac);
			}
		}
	}
	
	answer();
}
