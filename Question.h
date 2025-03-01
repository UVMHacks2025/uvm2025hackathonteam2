#ifndef HACK_QUESTION_H
#define HACK_QUESTION_H

#include <string>
#include <vector>
using std::ostream;
using std::string;
using std::vector;

struct answer {
    string choice;
    bool correct;
};

class Question {
private:
    string prompt;
    vector<answer> answers;
    bool isMcq;
public:
    //Constructor
    Question() {
        prompt = "";
        isMcq = false;
        answers.clear();
    };

    //Getters
    string getPrompt() const {
        return prompt;
    }
    vector<answer> getAnswers() const {
        return answers;
    }
    bool getIsMcq() const {
        return isMcq;
    }
    int getNumAnswers() const {
        return answers.size();
    }

    //Setters
    void setPrompt(const string &prompt) {
        this->prompt = prompt;
    }
    void setAnswers(const vector<answer> &answers) {
        this->answers = answers;
    }
    void setIsMcq(bool isMcq) {
        this->isMcq = isMcq;
    }

    void addAnswer(const string &choice, const bool correct) {
        answers.push_back({choice, correct});
    }

    bool removeAnswer(const string& choice) {
        bool removed = false;
        for (int i = 0; i < answers.size(); i++) {
            if (answers[i].choice == choice) {
                answers.erase(answers.begin() + i);
                --i;
                removed = true;
            }
        }
        return removed;
    }

    bool removeAnswer(int index) {
        if (index >= answers.size() || index < 0) {
            return false;
        }
        answers.erase(answers.begin() + index);
        return true;
    }

    void removeAllAnswers() {
        answers.clear();
    }

    bool isCorrect(string choice) {
        for (answer &a : answers) {
            if (a.choice == choice && a.correct) {
                return true;
            }
        }
        return false;
    }

    bool isCorrect(int index) {
        if (index >= answers.size() || index < 0) {
            return false;
        }
        return answers[index].correct;
    }

};

#endif //HACK_QUESTION_H
