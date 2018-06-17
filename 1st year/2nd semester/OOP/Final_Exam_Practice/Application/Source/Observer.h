#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>

class Observer
{
public:
    virtual void update() = 0;
    virtual ~Observer() {}
};

class Subject
{
private:
    std::vector<Observer*> observers;

public:
    virtual ~Subject() {}

    void registerObserver(Observer* obs)
    {
        this->observers.push_back(obs);
    }

    void unregisterObserver(Observer* obs)
    {
        this->observers.erase(std::find(this->observers.begin(), this->observers.end(), obs));
    }

    void notify()
    {
        for (auto obs : this->observers)
        {
            obs->update();
        }
    }
};

#endif // OBSERVER_H
