/*
DATE: 05/18/2015
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int A, B, N;

ifstream fin ("cowroute.in");
ofstream fout ("cowroute.out");

struct Route{
	int cost;
	int size; 
	vector<int> stops;

	bool contains(int id){
		bool found = false; 
		int pos = 0;
		while(!found && pos < size){
			found |= stops[pos] == id; 
			pos++;
		}
		return found; 
	}
	
	int stopNumber(int id){
		int stop = 0;
		bool found = false; 
		int pos = 0;
		while(!found && pos < size){
			found |= stops[pos] == id; 
			pos++;
		}
		if(!found) { pos = -1; } 
		return pos;
	}
};

vector<Route> routes;
vector<Route> valid; 

void filter(){
	for(int i = 0; i < routes.size(); i ++){
		Route r = routes[i];
		if(r.contains(A) && r.contains(B)) { 
			if(r.stopNumber(A) < r.stopNumber(B)) {
				valid.push_back(r);
			}
		}
	}
}

bool compareRoutes(Route r1, Route r2){
	return r1.cost < r2.cost;
}

int getMinCost(){
	sort(valid.begin(), valid.end(), compareRoutes);
	return valid[0].cost;
}

int main(){
	cin >> A >> B >> N;
	
	for(int n = 0; n < N; n ++){
		int cost, size; 
		cin >> cost >> size; 
		vector<int> stops; 
				
		for(int i = 0; i < size; i ++){
			int stop;
			cin >> stop;
			stops.push_back(stop);
		}
		Route route = {cost, size, stops};
		routes.push_back(route);
	}
	filter();
	cout << getMinCost() << endl;

}