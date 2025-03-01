#ifndef HACK_INTERFACE_H
#define HACK_INTERFACE_H
#include "Question.h"

class Interface {
private:
	Question question;
	long timelimit;
public:
	Interface() {
		question = Question();
	}

	void askQuestion(){
		//prompt
		cout << question.getPrompt() << endl;
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
