#include <iostream>

using namespace std; 

int N, M;

int main(){
	cin >> N >> M;
	
	int D = 0; 
	
	while(N > 0){
	    D++; 
		N --;
		if(D % M == 0){
			N ++;
		}
	}
	cout << D ;
}