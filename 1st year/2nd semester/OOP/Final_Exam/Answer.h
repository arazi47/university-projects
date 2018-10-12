#ifndef ANSWER_H
#define ANSWER_H

#include <string>

using namespace std;

class Answer
{
public:
    Answer(const int &id, const int &questionId, const string &creator, const string &text, const int &votes);

    const int getId() const { return this->id; }
    const int getQuestionId() const { return this->questionId; }
    const string getCreator() const { return this->creator; }
    const string getText() const { return this->text; }
    const int getVotes() const { return this->votes; }

    const string toString() const {
        return to_string(id) + " - " + to_string(questionId) + " - " + creator + " - " + text + " - " + to_string(votes);
    }

private:
    int id;
    int questionId;
    string creator;
    string text;
    int votes;
};

#endif // ANSWER_H
