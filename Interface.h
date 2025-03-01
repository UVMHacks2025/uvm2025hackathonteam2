#ifndef HACK_INTERFACE_H
#define HACK_INTERFACE_H
#include <iostream>
#include "Question.h"
using namespace std;

class Interface {
private:
	Question question;
	long timelimit;
	bool isGoodAnswer(string s) {
		char c = (char)s[0];
		return true;	
	}
public:
	Interface() {
		question = Question();
	}

	void askQuestion(){
		//prompt
		cout << question.getPrompt() << endl;
		bool isMultipleChoice = question.getIsMcq();
		if(isMultipleChoice){
			string ans = "";
			int num = question.getNumAnswers();
			cout << "select answer:" << endl;
			cin >> ans;	

			while(ans.size() !=1 ) {
				cout << "wrong" << endl;
				cin >> ans;
			} 

		}

	}
	void askQuestion(long time) {
		askQuestion();	
	}

	Question getQuestion() {
		return question;
	}
	void setQuestion(Question q) {
		question = q;
	}
};
#endif
