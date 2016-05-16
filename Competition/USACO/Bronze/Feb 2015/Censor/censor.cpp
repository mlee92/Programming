/*
BRUTE FORCE: 10 AC 5 TLE (8, 9, 10, 14, 15)
HASHING 
KNUTH MORRIS PRATT
*/

#include <fstream>
#include <iostream> 

using namespace std; 

ifstream fin ("censor.in");
ofstream fout ("censor.out");

void myReplace(std::string& str, const std::string& oldStr, const std::string& newStr){
  size_t pos = 0;
    while((pos = str.find(oldStr, pos)) != std::string::npos){
     str.replace(pos, oldStr.length(), newStr);
	 pos = 0;
  }
}

int main(){
	string str, oldStr, newStr;
	
	getline(fin, str);
	getline(fin, oldStr);
	newStr = ""; 
	
	myReplace(str, oldStr, newStr);
	fout << str; 
}
