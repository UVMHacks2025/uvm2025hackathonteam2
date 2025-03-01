//
// Created by Atticus Tarleton on 3/1/25.
//

#ifndef ENEMY_H
#define ENEMY_H
#include "question.h"
#include <iostream>

class enemy {
    private:
    public:
        int health;
        bool dead;
        int x_location;
        int y_location;

        enemy(int starting_health){
          health = starting_health;
          dead = false;


        }


};


#endif //ENEMY_H


