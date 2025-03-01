#ifndef HACK_GAME_H
#define HACK_GAME_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "Question.h"

using namespace std;

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

          string prompt, level, tempAnswer, tempCorrectAnswer;
          int numAnswers, numCorrectAnswers;
          bool multChoice;
          vector<answer> answers;
          vector<string> correctAnswers;

          while (fileIn && fileIn.peek() != EOF) {
            //take prompt
            getline(fileIn, prompt, ',');

            //get multChoice
            getline(fileIn, multChoice, ',');

            //get level
            getline(fileIn, level, ',');

            //read num answers and use for loop to get all the answers, set correct to false for all
            getline(fileIn, numAnswers, ',');
            for (int i = 0; i < numAnswers, i++) {
              getline(fileIn, tempAnswer, ',');
              answer ans;
              ans.choice = tempAnswer;
              ans.correct = false;
              answers.push_back(ans);
            }

            //read num correct answers and use for loop to get them all, put in second vector
            getline(fileIn, numCorrectAnswers, ',');
            for (int i = 0; i < numCorrectAnswers; i++) {
              getline(fileIn, tempCorrectAnswer, ',');
              correctAnswers.push_back(tempCorrectAnswer);
            }

            //iterate through for loops and change all correct answers to true
            for (int i = 0; i < correctAnswers.size(); i++) {
              for (int i = 0; i < answers.size(); i++) {
                if (correctAnswers[i].equals(answers[i].choice) {
                	answers[i].correct = true;
                }
              }
            }

            //create Question from those
			//add Question to questions vector
			questions.push_back(Question(prompt, multChoice, answers));

          }
        }
    }
    //other stuff I assume
};

#endif //HACK_GAME_H
