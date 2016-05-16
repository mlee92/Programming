/*
ID: michael223
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <bitset>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std; 

int N;
bitset<1000000> timeline;
int START, END;
vector<int> start_times;
vector<int> end_times;

ifstream fin ("milk2.in");
ofstream fout ("milk2.out");

void loadIntervals(){
	for(int i = 0; i < N; i ++){
		int start, end;
		fin >> start >> end; 
		start_times.push_back(start);
		end_times.push_back(end);
	}
}

void getLimits(){
	vector<int> min = start_times;
	vector<int> max = end_times;
	sort(min.begin(), min.end());
	sort(max.begin(), max.end());
	START = min[0];
	END = max[N - 1];
}

void milkCow(int id){
    for(int t = start_times[id]; t < end_times[id]; t++){
        timeline.set(t, 1);
    }
}

void milkCows(){
    for(int i = 0; i <  N; i ++){
        milkCow(i);
    }
}

void printTimeline(){
    for(int i = START; i < END; i++){
        fout << timeline[i];
    }
    fout << endl;
}

vector<int> milkStreak;
vector<int> idleStreak;

void countMilk(){
    int running = -1;
    int sum = 0;
    for(int t = START; t <= END; t++){
        if(timeline[t] != running){
            if(running == 1) { milkStreak.push_back(sum); } 
            else if(running == 0) { idleStreak.push_back(sum);  }
            running = timeline[t];
            sum = 0;
        }
        ++sum;
    }
    sort(milkStreak.begin(), milkStreak.end());
    sort(idleStreak.begin(), idleStreak.end());
    
    if(milkStreak.size() > 0) { fout << milkStreak[milkStreak.size() - 1]; } else {fout << "0"; } fout << " ";
    if(idleStreak.size() > 0) { fout << idleStreak[idleStreak.size() - 1]; } else { fout << "0"; } fout << endl;
}

int main(){
    fin >> N;
    loadIntervals();
    getLimits();
    milkCows();
    countMilk(); 
}
