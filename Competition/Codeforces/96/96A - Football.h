#include <iostream>

using namespace std;

int main(){
	int state = -1;
	int count = 0;
	string football;
	getline(cin, football);
	string response = "NO";
	for(int i = 0; i < football.size(); i++){
		int val = football[i] - '0';
		if(state != val){
			count = 0;
			state = val; 
		} 
		
		count ++;
		if(count >= 7) {
			response = "YES";
		}
	}
	cout << response << endl;
}