#ifndef HACK_LEVEL_H
#define HACK_LEVEL_H
#include <vector>
#include "Enemy.h"

using namespace std;

class Level {
private:

public:
    vector<vector<int>> floorgrid;
    int depth;
    int MAX_DEPTH = 5;
    int doorX;
    int doorY;
    vector<Enemy> enemies;
    struct Content {
        Enemy enemy;
        Player player;
    };

    //create a bunch of enemies with attack values based on deepness
    void fillEnemyVector(){
        for(int i = 0; i < 5; i++) {
            //using deepness for the attack mod
            enemies.push_back(Enemy(1, depth));
        }
    }

    void checkForDead(){
        for(Enemy e :enemies) {
            if(e.health == 0) {
                e.dead = true;
            }
        }
    }

    void enterNextLevel() {
        depth++;
        if(depth >= MAX_DEPTH) {
            //you win
        }
        else{
            player.x = 0;
            player.x = 0;
        }
    }

    void checkDoor() {
        if(doorX == player.X and doorY == player.Y) {
            //next level function
            enterNextLevel();
        }
    }


};

#endif //HACK_LEVEL_H
