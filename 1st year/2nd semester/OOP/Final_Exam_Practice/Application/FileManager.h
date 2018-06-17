#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Question.h"
#include "participantwnd.h"
#include <fstream>
#include <vector>

class FileManager;

using namespace std;

class FileManager
{
public:
    static void loadQuestions(vector<Question> &v);
    static void writeQuestions(const vector<Question> &v);

    static void loadParticipants(QuizSession &qs, vector<ParticipantWnd*> &v);
};

#endif // FILEMANAGER_H
