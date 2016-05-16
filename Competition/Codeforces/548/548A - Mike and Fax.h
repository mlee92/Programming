#include <iostream>

using namespace std; 

string str; 
int K;

bool checkPalindrone(string s){
	string rev = "";
	for(int i = s.size(); i >= 1; i--){
		rev += s[i - 1]; 
	}
	return (s.compare(rev) == 0); 
}

int main(){
	cin >> str >> K; 
	int len = str.size() / K;
	int pos = 0;
	
	bool ans = ((str.size() - (len * K)) == 0);
	
	//cout << checkPalindrone("aba") << endl;
	
	while(len + pos <= str.size() && ans){
		string sub = str.substr(pos, len);
		ans &= checkPalindrone(sub);
		pos += len; 
		//cout << sub << endl;
	}
	
	if(ans){
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}