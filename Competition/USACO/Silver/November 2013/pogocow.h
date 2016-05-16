#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int POS [1000];
int POINTS [1000];

int N;
vector<int> SCORES; 

bool sortPoints(int i, int j){
	return POS[i] < POS[j];
}

int getDistance(int x, int y){
	return POS[y] - POS[x]; 
}

bool valid(int i){
	return i >= 0 && i < N; 
}

void walk(int from, int to, int dist, int pts){
	if(!(valid(from) && valid(to))){
	} else {
		if(getDistance(from, to) >= dist){
			pts += POINTS[to];
			dist = getDistance(from, to); 
			SCORES.push_back(pts);
		}
		for(int i = to + 1; i < N; i++){
			walk(to, i, dist, pts);
		}
	}
}

int main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> POS[i] >> POINTS[i];
	}
	sort(POINTS, POINTS + 1000, sortPoints);
	sort(POS, POS + 1000);
	walk(0, 0, 0, 0);
	sort(SCORES.begin(), SCORES.end());
	cout << SCORES.back() << endl; 
}