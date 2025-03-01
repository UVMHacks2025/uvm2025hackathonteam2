#ifndef HACK_LEVEL_H
#define HACK_LEVEL_H
#include <vector>
#include <random>
#include "Enemy.h"
#include "Player.h"

using namespace std;

class Level {
private:

public:

    int depth;
    int MAX_DEPTH = 5;
    int doorX;
    int doorY;
    int gridX;
    int gridY;
    int wallnumber = 5;
    vector<vector<int>> floorgrid;
    vector<Enemy> enemies;
    vector<vector<int>> enemylocs;
    struct Content {
        Enemy enemy;
        Player player;
    };

    //create a bunch of enemies with attack values based on deepness
    void fillEnemyVector(){
        for(int i = 0; i < 5; i++) {
            //using deepness for the attack mod
            Enemy newEnemy = Enemy(1, depth, rand() % gridX, rand() % gridY);
            for(int j = 0; j < enemies.size(); j++) {
                if(enemies[j].x_location == newEnemy.x_location && enemies[j].y_location == newEnemy.y_location) {
                    newEnemy.x_location = rand() % gridX;
                    newEnemy.y_location = rand() % gridY;
                    j--;
                }
            }
            enemies.push_back(newEnemy);
        }
    }

    void fillGrid() {
        for(int i = 0; i < gridX; i++) {
            for(int j = 0; j < gridY; j++) {
                floorgrid[i][j] = 0;
            }
        }
        for(int i = 0; i < wallnumber; i++) {
            floorgrid[rand() % gridX][rand() % gridY] = 1;
        }
    }

    void movePlayer() {
        //determine which way the player wants to move
        //determine their position
        //check if there's a wall/enemy in the way
        //if there's stuff in the way, print a message
        //if not, move the player
        //moving left
        if(player.x > 0 && floorgrid[player.x - 1][player.y] == 0) {
            player.x--;
        }
        //moving right
        if(player.x < gridX - 1 && floorgrid[player.x + 1][player.y] == 0) {
            player.x++;
        }
        //moving up
        if(player.y > 0 && floorgrid[player.x][player.y - 1] == 0) {
            player.y--;
        }
        //moving down
        if(player.y < gridY - 1 && floorgrid[player.x][player.y + 1] == 0) {
            player.y++;
        }

    }

    void checkForDead(){
        for(Enemy e : enemies) {
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
            player.y = gridY / 2;
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
