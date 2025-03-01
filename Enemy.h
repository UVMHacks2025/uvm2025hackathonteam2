//
// Created by Atticus Tarleton on 3/1/25.
//

#ifndef ENEMY_H
#define ENEMY_H
#include "question.h"
#include <iostream>
#include "player.h"
#include <random>

class Enemy {
    private:
    public:
        int health;
        bool dead;
        int x_location;
        int y_location;
        int attack_mod;
        int danger_level;
        int crit_chance;

        Enemy(int starting_health, int enemy_attack_mod){
          health = starting_health;
          dead = false;
          attack_mod = enemy_attack_mod;
          crit_chance = 3;
        }
        int randomize_attack(){
          int attack_val = rand()%3 + 1;
          if (rand() % crit_chance == 0){
              return attack3(attack_val);
          };
        }

        int attack1(int attack_damage){
            return player.damage(attack_damage);
        }
        int attack2(int attack_damage){
            return player.damage(attack_damage);
        }
        int attack3(int attack_damage){
            cout << "CRITICAL HIT" << endl;
            return player.damage(attack_damage);
        }
        void move(vector<int> pos){
            x_location = x_location+pos[0];
            y_location = y_location+pos[1];
        }





};


#endif //ENEMY_H


