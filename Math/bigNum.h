#include <vector>
#include <stdio.h>
#include <string>
#include <iostream>

class bigNum{
	public:
		bigNum(std::string str);
		std::string bigStr;
		std::vector<int> digits; 
		int numDigits;
};


bigNum::bigNum(std::string str){
	bigStr = str; 
	int pos = 0; 
	bool leading0 = true;
	while(pos < str.size()){
		if(str[pos] == '0' && leading0){
			// Do Nothing
		} else {
			leading0 = false; 
			digits.push_back(str[pos]);
		}
		pos++;
	}
}


char compare(bigNum x, bigNum y){
    if(x.numDigits > y.numDigits){
        return '>';
    } else if(x.numDigits < y.numDigits){
        return '<';
    } else {
        int pos = 0;
		bool equality = true;
		
		while(pos < x.numDigits && equality){
			equality &= x.digits[pos] == y.digits[pos];
			pos++;
		}
		if(equality){
			return '=';
		} else {
			if(x.digits[pos - 1] > y.digits[pos - 1]){
				return '>';
			} else {
				return '<';
			}
		}
    }
}

int main(){
	std::string strA, strB;
    std::cin >> strA >> strB;
	bigNum A = (strA);
	bigNum B = (strB);
	std::cout << compare(A, B);
	return 0; 
}