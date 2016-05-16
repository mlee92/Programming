#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std; 

int N, K;
string Deck;
int Freq [26]; 
int Copy [26];

struct Card{
	int Letter;
	int Num; 
};

Card deckArr [26]; 

bool cmpCard(Card c1, Card c2){
	return c1.Num > c2.Num; 
}


int main(){
	cin >> N >> K;
	cin >> Deck; 
	
	for(int i = 0; i < N; i++){
		char n = Deck[i] - 'A';
		deckArr[n].Letter = n;
		deckArr[n].Num ++; 
	}
	
	sort(deckArr, deckArr + 26, cmpCard);
	int index = 0;
	while(K > 0){
		if(deckArr[index].Num > 0){
			Copy[deckArr[index].Letter] ++; 
			//cout << (char)(deckArr[index].Letter + 'A') << endl;
			deckArr[index].Num --;
			K --;
		} else {
			index ++;
		}
	}
	int64_t coin = 0;
	for(int i = 0; i < 26; i++){
		coin += (int64_t)Copy[i] * (int64_t)Copy[i];
	}
	cout << coin << endl;
	// cout << (char)(deckArr[0].Letter + 'A') << endl;
	/*
	for(int i = 0; i < 26; i++){
		if(deckArr[i].Num != 0){
			cout << (char)(deckArr[i].Letter + 'A') << deckArr[i].Num << endl;
		}
	}
	*/
	
	// cout << N << ' '<< K << ' ' << Deck << endl; 
	
}