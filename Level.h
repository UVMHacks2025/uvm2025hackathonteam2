#ifndef HACK_LEVEL_H
#define HACK_LEVEL_H
#include <vector>
#include "Enemy.h"

using namespace std;

class Level {
private:
	vector<Enemy> enemies;
    struct Content {
        Enemy enemy;
        Player player;
    };
public:



};

#endif //HACK_LEVEL_H
