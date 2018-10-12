#include "RunTests.h"

void RunTests::testAddQuestion() {
    Session s(false);

    bool exceptionThrown = false;
    try {
        s.addQuestion("", "Dude");
    } catch(std::runtime_error) {
        exceptionThrown = true;
    }

    assert(exceptionThrown);

    s.addQuestion("Q text", "Dude");
    assert(s.getQuestions().size() == 1);

}

void RunTests::testGetAllAnswersForGivenQuestion() {
    Session s(false);
    s.addQuestion("Q text", "Dude");
    assert(s.getAnswersForQuestion(0).size() == 0);
    s.addAnswer(0, "Text", "Dudette");

    assert(s.getAnswersForQuestion(0).size() == 1);

    bool exceptionThrown = false;
    try {
        s.addAnswer(0, "", "Dudette");
    } catch(std::runtime_error) {
        exceptionThrown = true;
    }

    assert(exceptionThrown);
}

void RunTests::runTests() {
    RunTests::testAddQuestion();
    RunTests::testGetAllAnswersForGivenQuestion();
}
