#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>

#include "Enemy.h"

using namespace std;

class Player {
private:
    int health;
    int maxHealth;
    int experience;
    bool shieldUp;
    int attackDamage;
    int critChance;

    int x;
    int y;

    void levelUp() {
        cout << "Level up!!! Now level " << getLevel() << endl;
        health += 2;
        maxHealth += 2;
        attackDamage += 1;
    }

public:
    Player() : health(10), maxHealth(10), experience(0), shieldUp(false), attackDamage(1), critChance(5), x(0), y(0) {};

    void damage(const int damage) {
        if (shieldUp) {
              cout << "Shield blocked " << damage << " points of damage" << endl;
              shieldUp = false;
        } else {
            health -= damage;
        }
    }

    void addExperience(const int exp) {
        const int oldLevel = exp / 10;
        this->experience += exp;

        if (getLevel() > oldLevel) {
            levelUp();
        }
    }

    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    void shield() {
        shieldUp = true;
    }

    void attack(Enemy enemy) const {
        int damage = attackDamage;

        if (rand() % critChance == 0) {
            damage *= 2;
        }

        enemy.hit(damage);
    }

    static vector<string> getAbilities() {
        return { "move", "shield", "attack" };
    }

    int getHealth() const {
        return health;
    }

    int getMaxHealth() const {
        return maxHealth;
    }

    int getExperience() const {
        return experience;
    }

    int getLevel() const {
      return experience / 10;
    }

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }
};

#endif //PLAYER_H
