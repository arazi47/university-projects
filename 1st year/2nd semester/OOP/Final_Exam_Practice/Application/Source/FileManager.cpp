#include "FileManager.h"

#include <iostream>
using namespace std;

#include "QuizSession.h"


void FileManager::loadQuestions(vector<Question> &v) {
    ifstream f("/home/sysadmin/PracticPractice/questions");
    int id;
    string text;
    string answer;
    int score;
    string delimiter;

    while (f >> id && getline(f, delimiter, ';') && getline(f, text, ';') && getline(f, answer, ';') && f >> score) {
        auto question = Question(id, text, answer, score);
        v.push_back(question);
    }

    f.close();
}

void FileManager::writeQuestions(const vector<Question> &v) {
    ofstream g("/home/sysadmin/PracticPractice/questions");
    for (const auto &q : v) {
        g << q.getId() << ';' << q.getText() << ';' << q.getAnswer() << ';' << q.getScore() << endl;
    }

    g.close();
}

void FileManager::loadParticipants(QuizSession &qs, vector<ParticipantWnd*> &v) {
    ifstream f("/home/sysadmin/PracticPractice/participants");
    string name;
    while (f >> name) {
        v.emplace_back(new ParticipantWnd(qs, name));
    }

    f.close();
}
