#include <iostream>
#include <algorithm>

using namespace std; 

int N;
int A [3001];

int main(){
	cin >> N;
	
	int cost = 0; 
	
	for(int i = 1; i <= N; i ++){
		int a;
		cin >> a; 
		A[a] ++; 
	}
	
	int index = 1; 
	
	while(index <= N){
		if(A[index] > 1){
			A[index + 1] += A[index] - 1; 
			cost += A[index] - 1;
		}
		index ++; 
	}
	
	cout << cost << endl;
}