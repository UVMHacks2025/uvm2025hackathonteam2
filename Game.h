#ifndef HACK_GAME_H
#define HACK_GAME_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>

//#include "Level.h"
#include "Player.h"
#include "Question.h"

using namespace std;

class Game {
private:
    //instance variables
	// vector<Level> levels;
	// Player player;

    vector<Question> global_questions;

    int levelsWon;
    int score;
public:
    //constructor
    Game() : levelsWon(0), score(0) {
		getQuestionsFromFile("questions.csv", global_questions);

		cout << global_questions[0].getPrompt() << endl;
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
				fileIn >> multChoice >> comma;

            	//get level
            	getline(fileIn, level, ',');

            	//read num answers and use for loop to get all the answers, set correct to false for all
				fileIn >> numAnswers >> comma;
            	for (int i = 0; i < numAnswers; i++) {
              		getline(fileIn, tempAnswer, ',');
              		answer ans;
              		ans.choice = tempAnswer;
              		ans.correct = false;
              		answers.push_back(ans);
            	}

            	//read num correct answers and use for loop to get them all, put in second vector
            	fileIn >> numCorrectAnswers >> comma;
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
          	}

        	fileIn.close();
        }
    }
    //other stuff I assume

    // create levels

    // create player

    // create game loop

    // win by getting to end (in future, could make endless)
};

#endif //HACK_GAME_H
