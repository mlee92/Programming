/*
5 / 10
6 - 10 Timeout
*/

#include <fstream>
#include <sstream>
#include <vector>

using namespace std; 

int64_t X, Y;

ifstream fin ("odometer.in"); 
ofstream fout ("odometer.out");

bool interesting(int num){
	bool val = false;
	stringstream ss ("");
	ss << num; 
	string str = ss.str();
	int digits [10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
	for(int i = 0; i < str.size(); i++){
		digits[str[i] - '0'] ++;  
	}
	
	vector<int> interest; 
	
	for(int j = 0; j < 10; j++){
		if(digits[j] > 0) { interest.push_back(digits[j]);}
	}
	
	if(interest.size() == 2){
		val = (interest[0] == 1 || interest[1] == 1);
	}
	
	return val;
}
 
int main(){
	fin >> X >> Y;
	int64_t count = 0;
	for(int x = X; x <= Y; x++){
		if(interesting(x)){
			count ++;
		}
	}
	
	fout << count << endl;
}