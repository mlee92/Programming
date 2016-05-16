/*
ID: michael223
PROG: wormhole
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

const int SIZE = 12;

typedef  int MATRIX [SIZE][SIZE]; 
int N; 

MATRIX move_right;
MATRIX same_row;
MATRIX solution;

ifstream fin ("wormhole.in");
ofstream fout ("wormhole.out");

void initMatrix(MATRIX &A){
	for(int i = 0; i < SIZE; i ++){
		for(int j = 0; j < SIZE; j++){
			A[i][j] = 0;
		}
	}
}

void multimat(MATRIX A, MATRIX B, MATRIX &product){
	initMatrix(product);
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j< SIZE; j++){
			for(int k = 0; k < SIZE; k++){
			    product[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}

void printMatrix(MATRIX A){
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			cout << A[i][j] << ' ';
		}
		cout << endl; 
	}
}

vector<int> holeX;
vector<int> holeY; 

int adj_row(int i, int j){
	if(holeY[i] == holeY[j] && i != j) { return 1; }
	else { return 0; }
}

int adj_col(int i, int j){
	if(holeX[i] > holeX[j] && i != j) { return 1; }
	else { return 0; }
}

void initInput(){
	initMatrix(move_right); initMatrix(same_row);
	for(int i = 0; i < SIZE && i < N; i++){
		for(int j =0; j < SIZE && j < N; j++){
			move_right[i][j] = adj_col(i, j);
			same_row[i][j] = adj_row(i, j);
		}
	}
}

void readInput(){
	fin >> N;
	for(int i = 0; i < N; i++){
		int x, y;
		fin >> x >> y;
		holeX.push_back(x);
		holeY.push_back(y);
	}
}

void initSol(){
	readInput();
	initInput();
	MATRIX product;
	multimat(move_right, same_row, product);
	int sum = 0;
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			if(product[i][j] == 1) { sum++; }
		}
	}
	if(sum % 2 == 1) { sum += 1; } 
	fout << sum / 2 << endl; 
}

int main(){
	initSol();
}