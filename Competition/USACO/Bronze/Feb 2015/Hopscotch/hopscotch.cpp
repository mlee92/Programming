/*
RECURSION 15 AC 
*/
#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("hopscotch.in");
ofstream fout ("hopscotch.out");
struct Matrix
{
	int length, width; 
	string buffer;
	
	bool equal (Matrix gr){
		return (buffer.compare(gr.buffer) == 0);
	}
	
	char getValue(int row, int column){
		return buffer[getPos(row, column)];
	}
	
	void setValue(int row, int column, int val){
		buffer[getPos(row, column)] = val;
	}
	
	int getColumn(int pos){
		return pos % length;
	}

	int getRow(int pos){
		return pos / width; 
	}

	int getPos(int row, int column){
		return row * length + column; 
	}
};

Matrix grid;
int length, width; 
long long count = 0; 


void nextMove(int row, int column){
	int jump;
	char state = grid.getValue(row, column);
	
	if(row == length - 1 && column == length - 1) { count ++; } // Reached the bottom and now we here

	for(int i = row + 1; i < length; i ++){
		for(int j = column + 1; j < width; j++){
			char c = grid.getValue(i, j);
			
			if(c != state) {
				nextMove(i, j);
			}
		}
	}
}


void init(){
	fin >> length >> width;
	string str = "";
	fin.ignore();
	for(int i = 0; i < length; i++){
		string line;
		getline(fin, line);
		str += line;
	}
	grid = {length, width, str};
}

int main(){
	init();
	nextMove(0, 0);
	fout << count << endl;
}
