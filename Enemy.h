//
// Created by Atticus Tarleton on 3/1/25.
//

#ifndef ENEMY_H
#define ENEMY_H
#include "Question.h"
#include <iostream>
#include "Player.h"
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
        int experience;
        int type;


        Enemy(int starting_health, int enemy_attack_mod, int x_location_start, int y_location_start){
          health = starting_health;
          dead = false;
          attack_mod = enemy_attack_mod;
          crit_chance = 3;
          experience = 2;
          x_location = x_location_start;
          y_location = y_location_start;
        }

        int randomize_attack(){
            int attack_val = rand()%3 + attack_mod;
            if (rand() % crit_chance == 0){
                return attack3(attack_val)*2;
            }
            if (rand() % crit_chance == 1){
                return attack1(attack_val);
            }
            if (rand() % crit_chance == 2){
                return attack2(attack_val);
            }

        }

        int attack1(int attack_damage){
            return (attack_damage) + 1;
        }

        int attack2(int attack_damage){
            return (attack_damage) + 2;
        }

        int attack3(int attack_damage){
            std::cout << "CRITICAL HIT" << std::endl;
            return (attack_damage);
        }

        void move(vector<int> pos){
            x_location = x_location+pos[0];
            y_location = y_location+pos[1];
        }

        vector<int> get_location(){
          vector<int> location;
          location.push_back(x_location);
          location.push_back(y_location);
          return location;
        }

        bool is_dead(){
          return dead;
        }

        bool hit(int damage){
          health -= damage;
          if(health <= 0){
            dead = true;
          }
          return dead;
        }

        string get_type(){
            string string_type = "ITS BROKEN";
            switch (type) {
            case 0:
                string_type = "goat";
                break;
            case 1:
                string_type = "sheep";
                break;
            case 2:
                string_type = "bat";
                break;
            }
          return string_type;
        }

        int get_health(){
          return health;
        }

        string return_image(){
            if (type == 0)
			    return "BAAAAAAAAAA";
            if (type == 1)
                return "FLUFFFFFFFF";
            if (type == 2)
                return "Not Quite a Vampire";
        }

};


#endif //ENEMY_H


