#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "Observer.h"
#include <fstream>
#include "Question.h"
#include "Answer.h"
#include <string>

using namespace std;

class Session : public Subject
{
public:
    Session(bool load = true);
    ~Session();

    const vector<Question> &getQuestions() const { return questions; }
    const vector<Answer> &getAnswers() const { return answers; }

    // Descending by number of answers
    void sortQuestions() {
        sort(questions.begin(), questions.end(), [this](const Question &q1, const Question &q2){
            return getCntAnswersForQuestion(q1.getId()) > getCntAnswersForQuestion(q2.getId());
        });
    }

    int getCntAnswersForQuestion(int questionId) {
        int cnt = 0;
        for (const auto &ans : answers) {
            if (ans.getQuestionId() == questionId) {
                ++cnt;
            }
        }

        return cnt;
    }

    /*
     * Input: questionId - int
     * Output: vector<Answer>
     * Desc: Returns all the answer for the question with the given question id
     */
    vector<Answer> getAnswersForQuestion(int questionId);

     int matchingCharacters(string s1, string s2) {
          int len = s1.size() > s2.size() ? s2.size() : s1.size();
          int cnt = 0;
          for (int i = 0; i < len; ++i) {
            if (s1[i] == s2[i]) {
                ++cnt;
            }
        }

        return cnt;
     }

     vector<Question> sortByMatchingCharacters(string input);

     /*
      * Input: text - string, creator - string
      * Output: void
      * Desc: Adds a question with the given text and creator/poster in the questions vector
      */
     void addQuestion(const string &text, const string &creator);

     void addAnswer(const int &questionId, const string &text, const string &creator);

     // Get top three answers (or less, if there are not that many) for a given question
     // Sorted descending by the number of upvotes
     vector<Answer> getTopThreeAnswers(int questionId);

private:
    void readQuestions();
    void readAnswers();

    void writeAnswers();
    void writeQuestions();

    vector<Question> questions;
    vector<Answer> answers;

    bool load;
};

#endif // REPOSITORY_H
