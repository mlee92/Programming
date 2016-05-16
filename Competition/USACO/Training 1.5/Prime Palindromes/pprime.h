/*
ID: michael223
PROG: pprime
LANG: C++
*/

#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <fstream>

using namespace std; 

int MAX = 100000000;

int LOW, HIGH;
bitset<100000001> primes;
vector<int> palindromes;

ifstream fin ("pprime.in");
ofstream fout ("pprime.out");

int power(int x, int y){
	int pwr = (y >= 0);
	for(int i = 0; i < y; i++){
		pwr *= x;
	}
	return pwr;
}

bool inRange(int pal){
	if((pal >= LOW) && (pal <= HIGH)){
		return true;
	} else {
		return false;
	}
}

void gen1(){
	for(int i = 1; i <= 9; i+= 2){
		if(inRange(i)){
			palindromes.push_back(i);
		}
	}
}

void gen2(){
	for(int i = 1; i <= 9; i+= 2){
		int sum = 11 * i;
		if(inRange(sum)){
			palindromes.push_back(sum);
		}
	}
}

void gen3(){
	for(int i = 1; i <= 9; i+= 2){
		for(int j = 0; j <= 9; j++){
			int sum = 101 * i + 10*j;
			if(inRange(sum)){
				palindromes.push_back(sum);
			}
		}
	}
}

void gen4(){
	for(int i = 1; i <= 9; i+= 2){
		for(int j = 0; j <= 9; j++){
			int sum = 1001 * i + 110*j;
			if(inRange(sum)){
				palindromes.push_back(sum);
			}
		}
	}
}

void gen5(){
	for(int i = 1; i <= 9; i+= 2){
		for(int j = 0; j <= 9; j++){	
			for(int k = 0; k <= 9; k++){
				int sum =10001 * i + 1010*j + 100*k; 
				if(inRange(sum)){
					palindromes.push_back(sum);
				}			}
		}
	}
}

void gen6(){
	for(int i = 1; i <= 9; i+= 2){
		for(int j = 0; j <= 9; j++){	
			for(int k = 0; k <= 9; k++){
				int sum = 100001 * i + 10010*j + 1100*k;
				if(inRange(sum)){
					palindromes.push_back(sum);
				}				}
		}
	}
}

void gen7(){
	for(int i = 1; i <= 9; i+= 2){
		for(int j = 0; j <= 9; j++){	
			for(int k = 0; k <= 9; k++){
				for(int m = 0; m <= 9; m++){
					int sum = 1000001 * i + 100010*j + 10100*k + 1000*m;
if(inRange(sum)){
					palindromes.push_back(sum);
				}						}
			}
		}
	}	
}

void gen8(){
	for(int i = 1; i <= 9; i+= 2){
		for(int j = 0; j <= 9; j++){	
			for(int k = 0; k <= 9; k++){
				for(int m = 0; m <= 9; m++){
					int sum = 10000001 * i + 1000010*j + 100100*k + 11000*m;
					if(inRange(sum)){
						palindromes.push_back(sum);
					
				}
			}
		}
	}	
}
}

void gen(){
	gen1(); gen2(); gen3(); gen4(); gen5(); gen6(); gen7(); gen8();
}

void printPal(){
	for(int i = 0; i < palindromes.size(); i++){
		cout << palindromes[i] << endl;
	}
}

void markPrime(int p){
	long long np = 2*p;
	while(np <= HIGH){
		primes[np] = true;
		np += p;
	}
}

void generatePrimes(){
	for(int p = 2; p * p <= HIGH; p++){
		if(primes[p] == false){
			markPrime(p);
		}
	}
}

void printPrimes(){
	for(int i = 0; i <= 500; i ++){
		cout << i << ' ' << primes[i] << endl;
	}
}

bool isPrime(int number)
{
    for(int i = 2; i*i <= (number); ++i)
    {
        if(number % i == 0) return false;
    }
    return true;
}


void answer(){
	// sort(palindromes.begin(), palindromes.end());
	int ind = 0;
	while(palindromes[ind] >= LOW && palindromes[ind] <= HIGH){
		if(isPrime(palindromes[ind]) == true){
			fout << palindromes[ind] << endl; 
		}
		ind ++; 
	}
}

int main(){
	fin >> LOW >> HIGH;
	gen();
	// generatePrimes();
	// printPal();
	// printPrimes();
	answer();
}