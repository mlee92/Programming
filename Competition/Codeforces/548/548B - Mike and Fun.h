#include <iostream>

using namespace std;
 
int N, M, Q;  
bool Grid [501][501];
int scores [501];

int count(){
	int MAX = 0; 
	for(int i = 1; i <= N; i++){
		int score = 0; 
		bool consecutive; 
		for(int j = 1; j <= M; j++){
			consecutive = Grid[i][j] == true;
			if(consecutive){
				score ++; 
			} else {
				MAX = max(MAX, score);
				score = 0; 
			}
		}
		MAX = max(MAX, score);
		scores[i] = MAX;
		MAX = 0;
	}	
}

int scoreBoard(){
	int board = 0;	
	for(int k = 1; k <= N; k++){
		board = max(board, scores[k]);
	}
	return board;
}

void scoreRow(int i){
	int MAX = 0;
	int score = 0; 
		bool consecutive; 
		for(int j = 1; j <= M; j++){
			consecutive = Grid[i][j] == true;
			if(consecutive){
				score ++; 
			} else {
				MAX = max(MAX, score);
				score = 0; 
			}
		}
		MAX = max(MAX, score);
		scores[i] = MAX;
}

int main(){
	cin >> N >> M >> Q;	
	for(int i = 1; i <= N;i++){
		for(int j = 1; j <= M; j++){
			bool val;
			cin >> val; 
			Grid[i][j] = val; 
		}
	}
	count(); 
	
	for(int q = 0; q < Q; q++){
		int x, y;
		cin >> x >> y;
		if(Grid[x][y] == 0) { Grid[x][y] = 1; }
		else { Grid[x][y] = 0; } 
		scoreRow(x);
		cout << scoreBoard() << endl; 
	}
}