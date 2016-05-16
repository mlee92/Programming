#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> averages;

int main() {
    
    cin >> N;
    for(int i = 0; i < N; i++){
        int n;
        cin >> n;
        averages.push_back(n);
    }
    int sum = averages[0];
    cout << averages[0] << ' ';
    for(int i = 1; i < N; i++){
        int ans = averages[i]*(i + 1);
        ans -= sum;
        cout << ans << ' ';
        sum += ans; 
    }
	// your code goes here
	return 0;
}

