#ifndef QUESTION_H
#define QUESTION_H

#include <string>

using std::string;
using std::to_string;

class Question
{
public:
    Question() = default;

    Question(const int &id, const string &text, const string &answer, const int &score) :
        id{id}, text{text}, answer{answer}, score{score} {}

    ~Question() = default;

    const int getId() const { return this->id; }
    const string getText() const { return this->text; }
    const string getAnswer() const { return this->answer; }
    const int getScore() const { return this->score; }
    const string toString() const {
        string result;

        result += to_string(getId()) + " - ";
        result += getText() + " - ";
        result += to_string(getScore());

        return result;
    }

private:
    int id;
    string text;
    string answer;
    int score;
};

#endif // QUESTION_H
