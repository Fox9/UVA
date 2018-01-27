//
//  main.cpp
//  Beggar My Neighbour
//
//  Created by Ellan Esenaliev on 10.11.2017.
//  Copyright © 2017 Ellan Esenaliev. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

int cardWeight(string symbol);
void showVector(vector<string> vec);
void takeCards(vector<string> &taker, vector<string> &table);
void putCards(vector<string> &deck, vector<string> &table, int amount);
void playGame(vector<string> &dealerCards, vector<string> &playerCards);

int main(){
	string s;
	bool is_continue = true;
	while(true){
		vector<string> dealerCards;
		vector<string> playerCards;

		bool giveToPlayer = true;
		for (int i = 0; i < 4; ++i){
			for (int i = 0; i < 13; ++i){
				string card;
				cin >> card;
				if(card == "#") {
					is_continue = false;
					break;
				}
				if(giveToPlayer){
					playerCards.push_back(card);
					giveToPlayer = false;
				}else{
					dealerCards.push_back(card);
					giveToPlayer = true;
				}
			}
			if(!is_continue) break;
		}
		if(!is_continue) break;
		playGame(dealerCards, playerCards);
	}
	return 0;
}

void playGame(vector<string> &dealerCards, vector<string> &playerCards){

	bool playerMove = true;
	vector<string> tableCards;
	string activeCard = "";

	int amountOfCardsToPut = 1;
	while(true){
		try{
			if(playerMove){
				putCards(playerCards, tableCards, amountOfCardsToPut);
			}else{
				putCards(dealerCards, tableCards, amountOfCardsToPut);
			}
		}catch(int message){
			if(message == 1337){
				if(playerMove){
					cout << 1 << setw(3) << dealerCards.size() << endl;
				}else{
					cout << 2 << setw(3) << playerCards.size() << endl;
				}
			}
			break;
		}

		playerMove = !playerMove;
		amountOfCardsToPut = cardWeight(tableCards.back());
		if(amountOfCardsToPut == 0) amountOfCardsToPut = 1;
		

		if(cardWeight(tableCards.back()) > 0){
			activeCard = tableCards.back();
			amountOfCardsToPut = cardWeight(tableCards.back());
			if(amountOfCardsToPut == 0) amountOfCardsToPut = 1;	
		}else{
			if(cardWeight(activeCard) > 0){
				if(!playerMove){
					takeCards(dealerCards, tableCards);
				}else{
					takeCards(playerCards, tableCards);
				}
				activeCard = "";
			}
		}
	}
}

void putCards(vector<string> &deck, vector<string> &table, int amount){	
	string putCard;
	
	if(deck.size() < amount){
		bool hasFace = false;
		for(string el : deck){
			if(cardWeight(el) > 0) hasFace = true;
		}
		if(!hasFace){
			throw 1337;
		}
	}
	
	for(int i = 0; i < amount; i++){
		putCard = deck.back();
		table.push_back(putCard);
		deck.pop_back();

		if(cardWeight(putCard) > 0)
			break;
	}
}

void takeCards(vector<string> &taker, vector<string> &table){
	vector<string> temp;
	reverse(table.begin(), table.end());
	temp.insert(temp.end(), table.begin(), table.end());
	temp.insert(temp.end(), taker.begin(), taker.end());

	taker.clear();
	table.clear();
	
	taker = temp;
}

void showVector(vector<string> vec){
	for(string el : vec){
		cout << el << ' ';
	}
	cout << endl;
}


int cardWeight(string card){
	if(card.size() == 0) return 0;
	switch (char(card[1])) {
		case 'A':
			return 4;
		case 'K':
			return 3;
		case 'Q':
			return 2;
		case 'J':
			return 1;
		default:
			return 0;
	}
}
