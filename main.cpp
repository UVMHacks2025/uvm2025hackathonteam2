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

	
	test.ask(q,1);
	Player p = Player();
	Enemy e = Enemy(100,1,0,0);
	test.fight(p,e);

	cout << "Running" << endl;	
	return 0;
}
