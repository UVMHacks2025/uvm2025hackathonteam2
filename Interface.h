#ifndef HACK_INTERFACE_H
#define HACK_INTERFACE_H
#include <iostream>
#include "Question.h"
#include "Player.h"
#include "Enemy.h"
#include "Level.h"
#include <thread>
using namespace std;
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
class Interface {
private:
	 vector<Question> questions;
	int qn;
	long timelimit;
	 bool isGoodAnswer(string s,int n) {
		int c = (int)s[0];
		c |= 32;
		c -= 96;
		
		return c<=n && c>0 ;	
	}
public:
	Interface(vector<Question> qs) : qn(0) {
		questions = qs;
	}
	int promptMoveLoop(){
		string ans = "";
		int dir = -1;
		cout << "which way do you want to move (w,a,s,d keys): ";
		cin >> ans;
		while(ans.size()!=1 || !(ans=="w" || ans=="a" || ans=="s" || ans=="d" || ans=="q")) {
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
		if(ans == "q"){
			dir == -1;
		}
		return dir;	
			
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
	int fight(Player &p, Enemy &e, Level &l) {
		vector<string> abilities = p.getAbilities();
		int rounds = 0;
		while(p.getHealth()>=0 && !e.is_dead()) {
		cout << e.get_type() << ": "<<e.health<<"/"<<e.get_max_health()<<endl;
		cout << "Player: "<<p.getHealth() << "/"<<p.getMaxHealth()<<endl;
		int n = abilities.size();
		for(int i = 0; i < abilities.size(); ++i){
			cout << abilities[i] << "("<<(char)(i+97)<<"), ";
		}
		string ans = "";
		cin >> ans;
		while(ans.size() !=1 || !isGoodAnswer(ans,n)) {
				cout << "Invalid input, try again: ";
				cin >> ans;
		}
		Question q = questions[qn];
		if(ask(q)){
		switch((int)ans[0]){
			case 'a':{
				l.printLevel();
				int d = promptMovement();
				string dir = "up";
				if(d==SOUTH){
					dir = "down";
				}
				if(d==EAST){
					dir = "right";
				}
				if(d==WEST){
					dir = "left";
				}
				l.movePlayer(dir);
				return rounds;
			}
			case 'b':{
				p.shield();
			}
			case 'c':{
				int d = p.attack(&e);
				cout << "you attack for" << d <<endl;
			}
		}
		}
			cout << e.get_type()<<" attacks you "<<endl;
			int d = e.randomize_attack();
			cout << "you take "<< d << endl;
			p.damage(d);
			++rounds;
		}
		if(p.getHealth()<0){
			cout << "you DEAD"<< endl;	
		}
		else if(e.is_dead()){
			p.addExperience(e.experience);
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
			cout << "select answer (a-"<< (char)(num+97) << "):" << endl;
			for(int i = 0; i < num; ++i) {
				cout << "("<<(char)(i+97)<<") " << question.getAnswer(i) << endl;
			}
			cin >> ans;	

			while(ans.size() !=1 || !isGoodAnswer(ans,num)) {
				cout << "Invalid input, try again: ";
				cin >> ans;
			} 
			cout << ((int)(ans[0]&(~96))) << endl;
			return question.isCorrect((int)(ans[0]&(~96))-1);

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
