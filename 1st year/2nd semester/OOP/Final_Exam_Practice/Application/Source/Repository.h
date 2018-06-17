#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "FileManager.h"
#include "participantwnd.h"

class Repository
{
public:
    Repository(QuizSession &qs);
    ~Repository();

    vector<ParticipantWnd*> &getPlayers() { return this->players; };
     const int getPlayerCount() const { return this->players.size(); }

private:
    vector<ParticipantWnd*> players;
};

#endif // REPOSITORY_H
