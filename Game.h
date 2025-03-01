#ifndef HACK_GAME_H
#define HACK_GAME_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>

class Game {
private:
    //instance variables
    int levelsWon;
    int score;
public:
    //constructor
    Game() {
        levelsWon = 0;
        score = 0;
    }

    //method: get questions from csv file
    void getQuestionsFromFile(string filename, vector<Question>& questions) {
        ifstream fileIn;
        fileIn.open(filename);
        if (fileIn) {
          string header;
          getline(fileIn, header);

          string prompt, answer, level;

          while (fileIn && fileIn.peek() != EOF) {
            //take prompt
            getline(fileIn, prompt, ',');

            //take answer
            getline(fileIn, answer, ',');

            //take level
            getline(fileIn, level, ',');

            //create Question from those


            //add Question to questions vector
          }
        }
    }
    //other stuff I assume
};

#endif //HACK_GAME_H
