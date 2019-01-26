#include <iostream>
#include <string>
using namespace std;

class P1{
	public:
	string name; 
	int turn_total;
	int sum = 201;
	
	int get_score();
	int total_score(int turn_score,int compiled);
	void checkout(int score);
};

// CHECK SUM FUNCTION 

int main(){
	P1 player1;
	P1 player2;
	int choice, compiled;
	string raw_score;

	cout << "player 1 enter name: ";
	cin >> player1.name;
	cout << "player 2 enter name: ";
	cin >> player2.name;
	
	cout << "hello " << player1.name << " and " << player2.name << ", who will go first?" << endl;
	cout << "1. " << player1.name << endl;
	cout << "2. " << player2.name << endl;
	
	cin >> choice; 
	
	switch(choice){
		
		case 1 :
		while(player1.sum > 0 && player2.sum > 0){
			cout << "enter " << player1.name << "'s scores" << endl;
			
			 player1.turn_total = player1.get_score();
			 player1.sum = player1.total_score(player1.turn_total,player1.sum);
			 
			cout << "enter " << player2.name << "'s scores" << endl;
		
			player2.turn_total = player2.get_score();
			 player2.sum = player2.total_score(player2.turn_total, player2.sum);
			 
			 cout << "Scores: " << endl;
			 cout << player1.name << ": " <<player1.sum << endl;
			 player1.checkout(player1.sum);
			 cout << player2.name << ": " <<player2.sum << endl;
			 player2.checkout(player2.sum);
		}
			 
		case 2 :
		while(player1.sum < 201 && player2.sum < 201){
			cout << "enter " << player2.name << "'s scores" << endl;
		
			player2.turn_total = player2.get_score();
			player2.sum = player2.total_score(player2.turn_total, player2.sum);
			 
			cout << "enter " << player1.name << "'s scores" << endl;
			
			player1.turn_total = player1.get_score();
			player1.sum = player1.total_score(player1.turn_total,player1.sum);
			
			 cout << "Scores: " << endl;
			 cout << player2.name << ": " <<player2.sum << endl;
			 cout << player1.name << ": " <<player1.sum << endl;
		
		}
			 
	}
	
	
}

int P1::get_score(){
		int score;
		int first_try,second_try,third_try;
		string first_raw,second_raw,third_raw;
		
		getline(cin,first_raw,',');
		first_try = stoi(first_raw);
		
		getline(cin,second_raw,',');
		second_try = stoi(second_raw);
		
		getline(cin,third_raw);
		third_try = stoi(third_raw);
		
		score = first_try + second_try +third_try;
		return score;
}

int P1::total_score(int turn_score, int compiled){
	
	 compiled = compiled - turn_score; 
	return compiled;
}

void P1::checkout(int score){
	if(score < 100 && (score%2) ==0){
		cout << (score)/2 << " to checkout" << endl; 
	}
}


















