#include <iostream>

using namespace std;

long long triangle = 1;
int addend = 2;

void generateNextTriangle(){
	triangle += addend;
	addend ++;
}

int getDivisors(){
	int div = 0;
	for(long long i = 1; i <= triangle; i++){
		if(triangle % i == 0) { div ++; }
	}
	return div;
}

int main(){

	for(int i = 0; i < 150000; i++){
        generateNextTriangle();
	}
    cout << triangle << endl;
    cout << getDivisors() << endl;
}
