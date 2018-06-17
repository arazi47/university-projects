#include "Repository.h"

Repository::Repository(QuizSession &qs)
{
    FileManager::loadParticipants(qs, this->players);
}

Repository::~Repository() {

}
