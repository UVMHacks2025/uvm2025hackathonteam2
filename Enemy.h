//
// Created by Atticus Tarleton on 3/1/25.
//

#ifndef ENEMY_H
#define ENEMY_H
#include "question.h"
#include <iostream>
#include "player.h"

class Enemy {
    private:
    public:
        int health;
        bool dead;
        int x_location;
        int y_location;

        Enemy(int starting_health){
          health = starting_health;
          dead = false;
        }
        int attack(){
          player.damage();
        }




};


#endif //ENEMY_H


