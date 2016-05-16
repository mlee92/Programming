#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

class Module{
	public:
		Module(int key, int x, int y);
		int X;
		int Y; 
		int id; 
		bool North;
		bool South;
		bool West;
		bool East; 
		int pathID = -1;
};

int M, N; // Dimensions of Map

Module::Module(int key, int x, int y){
	X = x;
	Y = y; 
	bitset<4> walls (key); 
	North = walls[0];
	South = walls[1];
	West = walls[2];
	East = walls[3];
}

vector<Module> Castle; 
map<int, int> Paths;

struct Node{
	int id;
	Node South;
	Node East; 
	
	Node(int _id){
		id = _id;
		South = id + N;
		East = id + 1; 
	}
};

int getID(int X, int Y){
	return ((X- 1) * N) + Y; 
}

int main(){
	cin >> M >> N;
	int id = 1; 
	for(int m = 1; m <= M; m++){
		for(int n = 1; n <= N; n++){
			int key; 
			cin >> key; 
			Module mod (key, m, n); 
			mod.id = id; 
			id++;
			Castle.push_back(mod);
		}		
	}
	return 0;
}