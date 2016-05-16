/*
Suppose you're on a game show, and you're given the choice of three doors: Behind one door is a car; behind the others, goats. You pick a door, say No. 1, and the host, who knows what's behind the doors, opens another door, say No. 3, which has a goat. He then says to you, "Do you want to pick door No. 2?" Is it to your advantage to switch your choice?
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h> 
using namespace std; 

int SIM = 5000;


int exclude(int i, int j){
	int k = 0;
	while(k == i || k == j){
		k++;
	}
	return k;
}

/*
	3 ints represent the doors 
	a random door is chosen as winner and set = 2
	a random door is chosen and its co-int += 1 (can be winner) 
	a non-chosen non-winning door is revealed and deleted
	
	Prob(Wins:Games ~ 2/3) a switch is made
	Prob(Wins:Games ~ 1/2) a switch is made or a switch is not made
*/

int simulate(){
	vector<int> doors (3, 0); 
	
	int winner = rand() % 3; 
	doors[winner] = 2; 
	int choice1 = rand() % 3;
	doors[choice1] += 1; 
	
	int reveal = rand() % 3; 
	
	//cout << doors[0] << doors[1] << doors[2] << endl;
	
	while(doors[reveal] > 0){
		reveal = rand() % 3; 
	}
	
	doors.erase(doors.begin() + reveal);
	
	
	//cout << doors[0] << doors[1] << doors[2] << endl;
	
	int choice2 = 0; 
	
	while(doors[choice2] == 1 || doors[choice2] == 3){
		choice2 ++; 
	}
	
	if(doors[choice2] > 1){
		return 1; 
	} else {
		return 0;
	}
}

int main(){
	int WINS; 
	for(int i = 0; i < SIM; i ++){
		//cout << "Game " << i << ": " << endl; 
		WINS += simulate();
	}
	cout << WINS << " out of " << SIM << endl; 
	return 0;
}