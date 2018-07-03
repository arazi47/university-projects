#include "Session.h"
#include <iostream>

Session::Session(bool load) : load{load} {
    if (load) {
        readAnswers();
        readQuestions();
    }
}

Session::~Session() {
    if (load) {
        writeAnswers();
        writeQuestions();
    }
}

void Session::readQuestions() {
    ifstream f("/home/sysadmin/PracticExamOOP/questions");
    int id;
    string text;
    string creator;

    // First getline(f, text, ';') is just to get past the delimiter
    while (f >> id && getline(f, text, ';') && getline(f, text, ';') && f >> creator) {
        questions.emplace_back(Question(id, text, creator));
    }

    sortQuestions();
}

void Session::readAnswers() {
    ifstream f("/home/sysadmin/PracticExamOOP/answers");

    int id;
    int questionId;
    string creator;
    string text;
    int votes;

    // First getline(f, creator ';') is used just to get past the delimiter!
    while (f >> id >> questionId && getline(f, creator, ';') && getline(f, creator, ';') && getline(f, text, ';') && f >> votes) {
        //cout << id << ' ' << questionId << ' ' << creator << ' ' << text << ' ' << votes << endl;
        answers.emplace_back(Answer(id, questionId, creator, text, votes));
    }
}

void Session::writeAnswers() {
    ofstream g("/home/sysadmin/PracticExamOOP/answers");
    for (const auto &ans : answers) {
        g << ans.getId() << ' ' << ans.getQuestionId() << ';' << ans.getCreator() << ';' << ans.getText() << ';' << ans.getVotes() << endl;
    }
}

void Session::writeQuestions() {
    ofstream g("/home/sysadmin/PracticExamOOP/questions");
    for (const auto &q : questions) {
        g << q.getId() << ';' << q.getText() << "; " << q.getCreator() << endl;
    }
}

vector<Answer> Session::getAnswersForQuestion(int questionId) {
    vector<Answer> v;
    for (const auto &ans : this->answers) {
        if (ans.getQuestionId() == questionId) {
            v.push_back(ans);
        }
    }

    return v;
}

vector<Answer> Session::getTopThreeAnswers(int questionId) {
    vector<Answer> v = this->getAnswersForQuestion(questionId);

    if (v.size() > 3) {
        v.erase(v.begin() + 3, v.end());
    }

    sort(v.begin(), v.end(), [](const Answer &a1, const Answer &a2){
        return a1.getVotes() > a2.getVotes();
    });

    return v;
}

void Session::addAnswer(const int &questionId, const string &text, const string &creator) {
    if (text.empty()) {
        throw std::runtime_error("Answer text is empty!");
    }

    answers.emplace_back(Answer(answers.size(), questionId, creator, text, 0));
    this->notify();
}

void Session::addQuestion(const string &text, const string &creator) {
    if (text.empty()) {
        throw std::runtime_error("Question text is empty!");
    }

    questions.emplace_back(Question(questions.size(), text, creator));
    this->notify();
}

vector<Question> Session::sortByMatchingCharacters(string input) {
    vector<Question> v = questions;
    sort(v.begin(), v.end(), [this, input](const Question &q1, const Question &q2){
       return matchingCharacters(input, q1.getText()) > matchingCharacters(input, q2.getText());
    });

    return v;
}
