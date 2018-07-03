#include "Answer.h"

Answer::Answer(const int &id, const int &questionId, const string &creator, const string &text, const int &votes) :
    id{id}, questionId{questionId}, creator{creator}, text{text}, votes{votes}
{

}
