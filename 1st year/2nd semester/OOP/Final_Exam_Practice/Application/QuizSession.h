#ifndef QUIZSESSION_H
#define QUIZSESSION_H

#include "Observer.h"
#include "Question.h"
//#include "FileManager.h"
#include <fstream>
#include <iostream>

using std::ifstream;
using std::ofstream;
using std::endl;
using std::vector;

class QuizSession : public Subject
{
public:
    QuizSession() {
        //FileManager::loadQuestions(this->questions);

        ifstream f("/home/sysadmin/PracticPractice/questions");
        int id;
        string text;
        string answer;
        int score;
        string delimiter;

        while (f >> id && getline(f, delimiter, ';') && getline(f, text, ';') && getline(f, answer, ';') && f >> score) {
            auto question = Question(id, text, answer, score);
            questions.push_back(question);
        }

        f.close();
    }

    ~QuizSession() {
        //FileManager::writeQuestions(this->questions);

        ofstream g("/home/sysadmin/PracticPractice/questions");
        for (const auto &q : questions) {
            g << q.getId() << ';' << q.getText() << ';' << q.getAnswer() << ';' << q.getScore() << endl;
        }

        g.close();
    }

    void addQuestion(Question &q) {
        questions.push_back(q);
        this->notify();
    }

    const vector<Question> &getQuestions() const { return this->questions; }

private:
    vector<Question> questions;
};

#endif // QUIZSESSION_H
