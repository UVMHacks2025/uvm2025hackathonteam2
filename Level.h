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
    int wallnumber;
    int enemynumber;
    vector<vector<string>> floorgrid;
    vector<Enemy> enemies;
    vector<vector<int>> enemylocs;
    struct Content {
        Enemy enemy;
        Player player;
    };

    Level() {
        depth = 0;
        gridX = 5;
        gridY = 5;
        wallnumber = 5;
        enemynumber = 5;
        doorY = gridY / 2;
        doorX = gridX - 1;
    }

    Level(int dep, int gx, int gy, int wallnum, int enemynum) {
        depth = dep;
        gridX = gx;
        gridY = gy;
        wallnumber = wallnum;
        enemynumber = enemynum;
    }

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

    //main issues: if an enemy spawns on top of a wall, the wall gets deleted
    void fillGrid() {
        for(int i = 0; i < gridX; i++) {
            for(int j = 0; j < gridY; j++) {
                floorgrid[i][j] = "*";
            }
        }
        for(int i = 0; i < wallnumber; i++) {
            floorgrid[rand() % gridX][rand() % gridY] = "#";
        }
        for(Enemy e : enemies) {
            floorgrid[e.x_location][e.y_location] = "e";
        }
        floorgrid[doorX][doorY] = ">";
    }

    //pass in the input as an argument
    void movePlayer(string input) {
        //determine which way the player wants to move
        //determine their position
        //check if there's a wall/enemy in the way
        //if there's stuff in the way, print a message
        //if not, move the player
        //moving left
        int pX = player.x;
        int pY = player.y;
        if(input == "left" && px > 0 && floorgrid[px - 1][pY] == "*") {
            //pX--;
            player.move({-1, 0})
        }
        //moving right
        else if(input == "right" && pX < gridX - 1 && floorgrid[pX + 1][pY] == "*") {
            //pX++;
            player.move({1, 0})
        }
        //moving up
        else if(input == "up" && pY > 0 && floorgrid[pX][pY - 1] == "*") {
            //pY--;
            player.move({0, -1})
        }
        //moving down
        else if(input == "down" && pY < gridY - 1 && floorgrid[pX][pY + 1] == "*") {
            //pY++;
            player.move({0, 1})
        }
        else {
            cout << "You ran into a wall!";
        }
        floorgrid[pX][pY] = "*";
        floorgrid[player.x][player.y] = "@";

    }

    void moveEnemies() {
        int playerX = player.x;
        int playerY = player.y;
        for(Enemy enemy : enemies) {
            int enemX = enemy.x_location;
            int enemY = enemy.y_location;
            if(enemX > 0 && enemX > playerX && floorgrid[enemX - 1][enemY] == "*") {
                enemy.move({-1, 0});
            }
            else if(enemX < gridX && enemX < playerX && floorgrid[enemX + 1][enemY] == "*") {
                enemy.move({1, 0});
            }
            else if(enemY > 0 && enemY > playerY && floorgrid[enemY][enemY - 1] == "*") {
                enemy.move({0, -1});
            }
            else if(enemY < gridY && enemY < playerY && floorgrid[enemX][enemY + 1] == "*") {
                enemy.move({0, 1});
            }
            floorgrid[enemX][enemY] = "*";
            floorgrid[enemy.x_location][enemy.y_location] = "e";
        }
    }

    void printLevel(){
        for(int i = 0; i < gridY; i++) {
            for(int j = 0; j < gridX; j++) {
                cout << floorgrid[j][i];
            }
            cout << "\n";
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
        //whatever the player's number is
        if(floorgrid[doorX][doorY] == "@") {
            //next level function
            enterNextLevel();
        }
    }


};

#endif //HACK_LEVEL_H
