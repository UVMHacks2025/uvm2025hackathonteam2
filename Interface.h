#ifndef HACK_INTERFACE_H
#define HACK_INTERFACE_H
#include <iostream>
#include "Question.h"
#include "Player.h"
#include "Enemy.h"
//#include "Level.h"
#include <thread>
using namespace std;
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
class Interface {
private:
	 Question q;
	long timelimit;
	 bool isGoodAnswer(string s,int n) {
		int c = (int)s[0];
		c |= 32;
		c -= 96;
		
		return c<=n && c>0 ;	
	}
public:
	Interface() {
	}

	int promptMovement(){
		string ans = "";
		int dir = -1;
		cout << "which way do you want to move (w,a,s,d keys): ";
		cin >> ans;
		while(ans.size()!=1 || !(ans=="w" || ans=="a" || ans=="s" || ans=="d")) {
			cout << "Invalid Input: ";
			cin >> ans;
		}
		if(ans=="w"){
			dir = NORTH;
		}
		if(ans=="a"){
			dir = WEST;
		}
		if(ans=="d"){
			dir = EAST;
		}
		if(ans=="s"){
			dir = SOUTH;
		}
		return dir;	
			
	}
	//returns num rounds passed
	int fight(Player p, Enemy e) {
		vector<string> abilities = p.getAbilities();
		int rounds = 0;
		while(p.getHealth()>=0 && !e.is_dead()) {
		int n = abilities.size();
		for(int i = 0; i < abilities.size(); ++i){
			cout << abilities[i] << "("<<(char)(i+96)<<"), ";
		}
		string ans = "";
		cin >> ans;
		while(ans.size() !=1 || !isGoodAnswer(ans,n)) {
				cout << "Invalid input, try again: ";
				cin >> ans;
		}
		
		switch((int)ans[0]){
			case 'a':{
				//l.move();
				return rounds;
			}
			case 'b':{
				p.shield();
			}
			case 'c':{
				p.attack(e);
			}
		}
			++rounds;
		}


		return rounds;	
	}
	

	bool ask(Question question){
		//prompt
		cout << question.getPrompt() << endl;
		bool isMultipleChoice = question.getIsMcq();
		if(isMultipleChoice){
			string ans = "";
			int num = question.getNumAnswers();
			cout << "select answer (a-"<< (char)(num+96) << "):" << endl;
			for(int i = 0; i < num; ++i) {
				cout << "("<<(char)(i+96)<<") " << question.getAnswer(i) << endl;
			}
			cin >> ans;	

			while(ans.size() !=1 || !isGoodAnswer(ans,num)) {
				cout << "Invalid input, try again: ";
				cin >> ans;
			} 
			return question.isCorrect((int)(num&(~96)));

		}
		else {
		}

		return false;

	}
	bool ask(Question question, long timeSeconds) {
		if(timeSeconds < 0){
			ask(question);
		}
		auto start = chrono::steady_clock::now();

		bool out = ask(question);
		if((long)chrono::duration_cast<chrono::seconds>(chrono::steady_clock::now()-start).count() < timeSeconds ) {
			return out;
		}
		cout << "Time Limit passed"<< endl;



		return false;
	   		
	}

};
#endif
