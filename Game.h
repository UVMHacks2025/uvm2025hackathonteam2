#ifndef HACK_GAME_H
#define HACK_GAME_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>

#include "Level.h"
#include "Interface.h"
#include "Player.h"
#include "Question.h"

using namespace std;

class Game {
private:
    //instance variables
    Player player;
    vector<Level> levels;
    Interface interface;
    vector<Question> global_questions;

    int currentLevel;
    int levelsWon;
    int score;
public:
    //constructor
    Game() : currentLevel(0), levelsWon(0), score(0) {
        interface = Interface(global_questions);
        for (int i = 0; i < 5; i++) {
            levels.push_back(Level(player, i));
        }

        getQuestionsFromFile("questions.csv", global_questions);
		/*
        for (int i = 0; i < global_questions.size(); i++) {
            bool result = interface.ask(global_questions[i]);
            if (result) {
                cout << "Correct!" << endl;
            } else {
                cout << "Wrong!" << endl;
            }
        }
		*/
    }

    Player* getPlayer() {
        return &player;
    }

    Interface* getInterface() {
        return &interface;
    }

    Level* getCurrentLevel() {
        return &levels[currentLevel];
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
            char comma;

            while (fileIn && fileIn.peek() != EOF) {
                //take prompt
                getline(fileIn, prompt, ',');

                //get multChoice
                string choiceIn;
                getline(fileIn, choiceIn, ',');
                multChoice = choiceIn == "true" || choiceIn == " true";

                //get level
                getline(fileIn, level, ',');

                //read num answers and use for loop to get all the answers, set correct to false for all
                string numIn;
                getline(fileIn, numIn, ',');
                numAnswers = stoi(numIn);
                for (int i = 0; i < numAnswers; i++) {
                    getline(fileIn, tempAnswer, ',');
                    answer ans;
                    ans.choice = tempAnswer;
                    ans.correct = false;
                    answers.push_back(ans);
                }

                //read num correct answers and use for loop to get them all, put in second vector
                string numCorrectIn;
                getline(fileIn, numCorrectIn, ',');
                numCorrectAnswers = stoi(numCorrectIn);
                for (int i = 0; i < numCorrectAnswers; i++) {
                    getline(fileIn, tempCorrectAnswer, ',');
                    correctAnswers.push_back(tempCorrectAnswer);
                }

                //iterate through for loops and change all correct answers to true
                for (int i = 0; i < correctAnswers.size(); i++) {
                    for (int j = 0; j < answers.size(); j++) {
                        if (correctAnswers[i] == answers[j].choice) {
                            answers[j].correct = true;
                        }
                    }
                }

                //create Question from those
                //add Question to questions vector
                questions.push_back(Question(prompt, multChoice, answers));

                answers.clear();
                correctAnswers.clear();
            }

            fileIn.close();
        }
    }
};

#endif //HACK_GAME_H
