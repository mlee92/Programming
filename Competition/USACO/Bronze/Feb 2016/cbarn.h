#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std; 

ifstream fin ("cbarn.in");
ofstream fout ("cbarn.out"); 

struct Room{
	int capacity; 
};

int N; // Number of rooms around barn [3, 1000]
int numCows; // Number of Cows 

/*
Rooms are arranged in a circle
1. Unlock the exterior door of a single room 
2. Cows walk in and go to their rooms clockwise 
3. Find the minimum total distance the cows need to travel 
	a. Distance = Number of interior doors 
*/
vector<Room> Barn; 

int nextRoom(int current){
	return (current + 1) % N;
}

bool isRoomFull(int r, int n){
	if(n >= Barn[r].capacity)
		return true;
	else 
		return false; 
}

/*
 Naive Solution -
	Unlock every exterior and compare total distance
*/

int openDoor(int start){
	
	int totalDist = 0; 
	
	int cows = numCows; 
	int current = start;
	
	while(cows > 0){
		cows -= Barn[current].capacity; 
		current = nextRoom(current);
		totalDist += cows; 
	}
	return totalDist; 
}

int minDist(){
    vector<int> dist; 
    for(int i = 0; i< N; i++){
        dist.push_back(openDoor(i));
    }
    sort(dist.begin(), dist.end());
    return dist.front();
}

int main(){
	fin >> N; 
	for(int i = 0; i < N; i++){
		Room r; 
		fin >> r.capacity;
		numCows += r.capacity; 
		Barn.push_back(r);
		// cout << Barn[i].capacity;
	}
	fout << minDist(); 
}