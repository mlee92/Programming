/*
ID: michael223
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std; 

ifstream fin ("transform.in");
ofstream fout ("transform.out");

struct Grid
{
	int length, width; 
	string buffer;
	
	bool equal (Grid gr){
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
} plane, transform;

int N;
string emptyStr;

string binHash(string c){
	string str; 
	for(int i = 0; i < c.size(); i++){
		if(c[i] == '@') { str += '1'; } 
		else if (c[i] == '-') { str += '0';} else { str += c[i]; }
	}
	return str;
}

void initPlane(){
	fin >> N;
	fin.ignore();
	string original = "";
	
	for(int i = 0; i < N; i++){
		string line;
		getline(fin, line);
		original += binHash(line);
	}
	
	plane.length = N;
	plane.width = N;
	plane.buffer = original;
}

void initTransform(){
	string str = "";
	
	for(int i = 0; i < N; i++){
		string line;
		getline(fin, line);
		str += binHash(line);
	}
	
	transform.length = N;
	transform.width = N;
	transform.buffer =str;
}

Grid rotate90(Grid gr){
	Grid ret = {N, N, emptyStr};
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			ret.setValue(i, j, gr.getValue(N - j - 1, i));
		}
	}
	return ret;
}

Grid reflectLat(Grid gr){
	Grid ret = {N, N, emptyStr};
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			ret.setValue(i, j, gr.getValue(i, N - j - 1));
		}
	}
	return ret; 
}
/*
1 - rot 90 
2 - rot 180
3 - rot 270
4 - reflect 
5 - combo
6 - no change
7 - impossible
*/

bool combo(Grid refl){
	int i = 0;
	bool found = false;
	Grid temp = refl;
	while(i < 4 && !found){
		temp = rotate90(temp);
		found = temp.equal(transform);
		i++;
	}
	return found; 
}

int getAnswer(){
	int id = 0;
	Grid temp = plane;
	
	Grid rot90 = rotate90(temp); if(id == 0&& transform.equal(rot90)) {  id = 1; }
	Grid rot180 = rotate90(rot90); if(id == 0 && transform.equal(rot180)) { id = 2; }
	Grid rot270 = rotate90(rot180); if(id == 0 && transform.equal(rot270)) { id = 3; }
	
	Grid refl = reflectLat(temp); if(id == 0 && transform.equal(refl)) { id = 4; }
	if(combo(refl) && id == 0) { id = 5; }
	if(temp.equal(transform) && id == 0) { id = 6; } 
	if(id == 0) { id = 7; }
	return id;
}

int main(){
	initPlane();
	initTransform();
	
    emptyStr.resize(N*N, ' ');
	
	fout << getAnswer() << endl;
}