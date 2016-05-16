 /*
ID: michael223
PROG: sprime
LANG: C++
*/

#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <fstream>

using namespace std; 

int N;
int MAX;
vector<int> superPrimes;
ifstream fin ("sprime.in");
ofstream fout ("sprime.out");

int power(int x, int y){
	int pwr = (y >= 0);
	for(int i = 0; i < y; i++){
		pwr *= x;
	}
	return pwr;
}

bool inRange(int p){
	if(power(10, N - 1) <= p && power(10, N) >= p){
		return true;
	} else {
		return false; 
		
	}
}

bool isPrime(int number)
{
	if(number == 1) {return false;}
    for(int i = 2; i*i <= (number); ++i)
    {
        if(number % i == 0) return false;
    } 
    return true;
}


int digit1[4] = {2, 3, 5, 7}; 
int digit2[4] = {1, 3, 7, 9}; 

int nextDigit(int current, int len){
	if(len > 0){
		for(int i = 0; i < 4; i++){
			int sum = current * 10; 
			sum += digit2[i];
			if(isPrime(sum)){
				nextDigit(sum, len - 1); 
			}
		}
	} else {
		if(isPrime(current)){
			superPrimes.push_back(current); 
		}
	}
}


void generate(){
	for(int i = 0; i < 4; i++){
		int sum = digit1[i];
		nextDigit(sum, N - 1); 
	}	
}

void answer(){
	sort(superPrimes.begin(), superPrimes.end());
	
	for(int i = 0; i < superPrimes.size(); i++){
		fout << superPrimes[i] << endl;
	}
}

int main(){
	fin >> N;
	MAX = power(10, N);
	generate();
	answer();
}