#ifndef QUESTION_H
#define QUESTION_H

#include <string>

using namespace std;

class Question
{
public:
    Question(const int &id, const string &text, const string &creator);

    const int getId() const { return this->id; }
    const string getText() const { return this->text; }
    const string getCreator() const { return this->creator; }

    const string toString() const {
        return to_string(id) + " - " + text + " - " + creator;
    }

private:
    int id;
    string text;
    string creator;

};

#endif // QUESTION_H
