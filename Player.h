#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>

#include "Enemy.h"

using namespace std;

class Player {
private:
    int health;
    int experience;
    bool shieldUp;
    int attackDamage;
    int critChance;

    int x;
    int y;

    void levelUp() {
        cout << "Level up!!! Now level " << getLevel() << endl;
        health += 2;
        attackDamage += 1;
    }

public:
    Player() : health(10), experience(0), shieldUp(false), attackDamage(1), critChance(5), x(0), y(0) {};

    void damage(int damage) {
        if (shieldUp) {
              cout << "Shield blocked " << damage << " points of damage" << endl;
              shieldUp = false;
        } else {
            health -= damage;
        }
    }

    void addExperience(int exp) {
        const int oldLevel = exp / 10;
        this->experience += exp;

        if (getLevel() > oldLevel) {
        }
    }

    vector<string> getAbilities() {
        return { "move", "shield", "attack" };
    }

    void move(vector<int> pos) {
        x += pos[0];
        y += pos[1];
    }

    void shield() {
        shieldUp = true;
    }

    void attack(Enemy enemy) {
        int damage = attackDamage;

        if (rand() % critChance == 0) {
            damage *= 2;
        }

        enemy.hit(damage);
    }

    int getHealth() {
        return health;
    }

    int getExperience() {
        return experience;
    }

    int getLevel() {
      return experience / 10;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }
};

#endif //PLAYER_H
