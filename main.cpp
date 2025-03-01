#include <iostream>

#include "Game.h"
#include "Interface.h"

using namespace std;

int main() {
	Game game = Game();

	return 0;
}

int old() {
	Question q = Question();
	q.setPrompt("Q1");
	q.setIsMcq(true);
	q.addAnswer("a",true);
	q.addAnswer("b",false);
	Interface test = Interface();

	
	test.ask(q,1);
	Player p = Player();
	Enemy e = Enemy(100,1,0,0);
	Level l(p,0);
	test.fight(p,e,l);

	cout << "Running" << endl;
	return 0;
}
