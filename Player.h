#ifndef PLAYER_H
#define PLAYER_H

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
};

#endif //PLAYER_H
