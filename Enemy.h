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
        int experience;
        string type;


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
          int attack_val = rand()%3 + 1 + attack_mod;
          if (rand() % crit_chance == 0){
              return attack3(attack_val)*2;
          };
        }

        int attack1(int attack_damage){
            return player.damage(attack_damage);
        }
        int attack2(int attack_damage){
            return player.damage(attack_damage);
        }
        int attack3(int attack_damage){
            std::cout << "CRITICAL HIT" << std::endl;
            return player.damage(attack_damage);
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
          return type;
        }
        int get_health(){
          return health;
        }
        string return_image(){

        }






};


#endif //ENEMY_H


