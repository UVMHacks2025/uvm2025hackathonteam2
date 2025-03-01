#include <iostream>

#include "Game.h"
#include "Interface.h"

using namespace std;

int main() {
	cout << "\033[H\033[J";
	Game game = Game();

	while(game.getPlayer().getHealth()>0){
		Level* l = game.getCurrentLevel();
		cout << "\033[H";
		l->printLevel();
		l->checkForDead();
		l->moveEnemies();
		int d = game.getInterface().promptMoveLoop();
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
		if(d==-1){
			cout << "you quit the game"<< endl;
			break;
		}
		Player* p = game.getPlayer();
		cout <<p->getX() << ", "<<p->getY()<<endl;
		l->movePlayer(dir);
		cout <<p->getX() << ", "<<p->getY()<<endl;

		
	}
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
