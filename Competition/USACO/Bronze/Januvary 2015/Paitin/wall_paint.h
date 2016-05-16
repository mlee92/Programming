#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("paint.in");
ofstream fout("paint.out");

int paintA [101];
int paintB [101];
int paintC [101];

int a, b, c, d;


int init(){
	fin >> a >> b >> c>>d;
}
int main(){
	init();
	int wds = 0;
	for(int i = a; i < b; i++){
		 paintC[i] = 1;
	}
	for(int i = c ; i < d; i++){
		paintC[i] = 1; 
	}
	for(int i  = 0 ; i < 100; i++){
		if(paintC[i]){
			wds ++; 
		}
	}
	fout<< wds << endl;
	return 0;
}