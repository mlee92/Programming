#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std; 

ifstream fin ("");
ofstream fout (""); 

int N; // Number of Lines 
int K; 

void addCow(String Size, String Color, String Noisy){
	int i, j, k;
	if(Size.compare("large")){
		i = 0;
	} else { 
		i = 1; 
	}
	
	if(Color.compare("brown")){
		j = 0; 
	} else if(Color.compare("white")) {
		j = 1; 
	} else {
		j = 2; 
	}
	
	if(Noisy.compare("noisy")){
		k = 1; 
	} else {
		k = 0; 
	}
	
}

int main(){
	for(int i = 0; i < N; i++){
		String filler;
		cin >> filler >> filler >> filler >> filler;
		String next; 
		while(cin >> next && next.compare("cow") != 0){
			
		}
	}
}