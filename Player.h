#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>

using namespace std;

class Player {
private:
    int health;
    int speed;
    int experience;

    int x;
    int y;

public:
    Player() : health(100), speed(1), experience(0), x(0), y(0) {};

    void damage(int damage) {
        health -= damage;
    }

    void add_experience(int exp) {
        int old_level = exp / 10;
        this->experience += exp;

        if (getLevel() > old_level) {
          cout << "Level up!!! Now level " <<getLevel() << endl;
        }
    }

    void move(vector<int> pos) {
        x += pos[0];
        x += pos[1];
    }

    int getLevel() {
      return experience / 10;
    }
};

#endif //PLAYER_H
