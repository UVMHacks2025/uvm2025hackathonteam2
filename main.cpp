#include "Interface.h"
#include <iostream>

using namespace std;

int main() {
	Question q = Question();
	q.setPrompt("Q1");
	q.setIsMcq(true);
	q.addAnswer("a",true);
	q.addAnswer("b",false);
	Interface test = Interface();
	test.setQuestion(q);

	test.ask();
	cout << "Running" << endl;	
	return 0;
}
