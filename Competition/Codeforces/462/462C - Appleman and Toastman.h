#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int N;
long long runningSum; 

vector<long long> group; 


int main(){
	cin >> N;
	group.push_back(0);
	for(int i = 0; i < N; i++){
		long long n;
		cin >> n;
		group.push_back(n);
	}
	
	sort(group.begin(), group.end()); 
	
	for(int i = 1; i <= N - 1; i++){
	    runningSum += (i + 1)*group[i];
	}
	
	runningSum += N*group[N];
	cout << runningSum << endl; 
}