#ifndef HACK_INTERFACE_H
#define HACK_INTERFACE_H
#include <iostream>
#include "Question.h"
using namespace std;

class Interface {
private:
	Question question;
	long timelimit;
	bool isGoodAnswer(string s,int n) {
		int c = (int)s[0];
		c |= 32;
		c -= 96;
		
		return c<=n && c>0 ;	
	}
public:
	Interface() {
		question = Question();
	}

	bool ask(){
		//prompt
		cout << question.getPrompt() << endl;
		bool isMultipleChoice = question.getIsMcq();
		if(isMultipleChoice){
			string ans = "";
			int num = question.getNumAnswers();
			cout << "select answer (a-"<< (char)(num+96) << "):" << endl;
			cin >> ans;	

			while(ans.size() !=1 || !isGoodAnswer(ans,num)) {
				cin >> ans;
			} 
			return question.isCorrect((int)(num&(~96)));

		}

		return false;

	}
	bool ask(long time) {
		return ask();	
	}

	Question getQuestion() {
		return question;
	}
	void setQuestion(Question q) {
		question = q;
	}
};
#endif
