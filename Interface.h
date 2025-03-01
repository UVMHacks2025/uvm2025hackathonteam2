#ifndef HACK_INTERFACE_H
#define HACK_INTERFACE_H
#include <iostream>
#include "Question.h"
#include "Player.h"
#include "Enemy.h"
using namespace std;

class Interface {
private:
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
	int fight(Player p, Enemy e) {
		return 0;	
	}

	bool ask(Question question){
		//prompt
		cout << question.getPrompt() << endl;
		bool isMultipleChoice = question.getIsMcq();
		if(isMultipleChoice){
			string ans = "";
			int num = question.getNumAnswers();
			cout << "select answer (a-"<< (char)(num+96) << "):" << endl;
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
	bool ask(Question question, long time) {
		return ask(question);	
	}

};
#endif
