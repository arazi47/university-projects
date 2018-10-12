//
// Created by sysadmin on 23.03.2018.
//

#ifndef LAB5_6_CONTROLLER_H
#define LAB5_6_CONTROLLER_H

#include <iostream>
#include <vector>
#include "Axolotl.h"
#include "validator.h"
//#include "UndoOperation.h"
#include <memory>

//class UndoOperation;

using namespace std;


class Controller {
    public:
        Controller() = default;

        explicit Controller(bool loadPets);
        //Controller(const Controller &ctrl) = delete;
        //void operator=(const Controller &ctrl) = delete;

        ~Controller() = default;

        void insertTestElements();

        bool addAxolotl(vector<Axolotl>& vec, int breed, string name, int age, string photograph, bool record = true);
        int searchAxolotl(const string& name);
        void deleteAxolotl(int index, bool record = true);
        void updateAxolotl(int index, int breed, string name, int age, string photograph, bool record = true);

        vector<Axolotl>& getVector();
        vector<Axolotl>& getUserAdoptionVector();
        vector<Axolotl> buildFilteredVector(int targetBreed, int targetAge);
        vector<Axolotl> filterByNameStartingWith(string startingWith);

        bool nameAlreadyExists(vector<Axolotl>& vec, string name);

        int searchElement(string name);
        void updateElement(int index, Axolotl::Breed breed, string &name, int age, string &photograph);

        void undo() {
            if (!undoOperations.empty()) {

                // this check needs to be before the undo, otherwise we lose the old data!
                if (undoOperations.back()->getType() == "update") {
                    redoOperations.emplace_back(new UndoUpdate(*this, vec[undoOperations.back()->petIndex], undoOperations.back()->petIndex));
                }

                undoOperations.back()->undo();

                // This line wouldn't work if I'd use unique ptr vectors
                //redoOperations.push_back(undoOperations.back());

                if (undoOperations.back()->getType() == "add")
                    redoOperations.emplace_back(new UndoRemove(*this, vec[undoOperations.back()->petIndex]));
                else if (undoOperations.back()->getType() == "remove")
                    //redoOperations.emplace_back(new UndoAdd(*this, undoOperations.back()->petIndex));
                    redoOperations.emplace_back(new UndoAdd(*this, undoOperations.back()->petIndex, undoOperations.back()->getAxolotl()));
                //else // undo & redo for update is still update
                  //  cout << "original name:" << undoOperations.back()->getAxolotl().getName() <<endl;
                    //redoOperations.emplace_back(new UndoUpdate(*this, undoOperations.back()->getOriginalAxolotl(), undoOperations.back()->petIndex));

                undoOperations.pop_back();
            }
        }

        void redo() {
            if (!redoOperations.empty()) {
                redoOperations.back()->undo();
                redoOperations.pop_back();
            }
        }

    private:
        vector<Axolotl> vec;
        vector<Axolotl> userAdoptionVector;


        ///////////////////////////////

        class UndoOperation {
            public:
                UndoOperation(int petIndex) : petIndex(petIndex) {}
                virtual void undo() = 0;
                virtual string getType() {
                    return "You shouldn't ever see this";
                }
                int petIndex;

                virtual Axolotl getAxolotl() {
                    return Axolotl();
                    }
        };

        class UndoAdd : public UndoOperation {
            public:
                UndoAdd(Controller &ctrl, int petIndex, Axolotl ax) : UndoOperation(petIndex), ctrl{ctrl}, petIndex{petIndex}, ax(ax) {}

                void undo() override {
                    // petIndex unused, it can safely be removed
                    // Basically because when we remove something and then undo
                    // The pet is not always added at the same index, it gets added to the end of the list
                    // Thus making petIndex irrelevant
                    //ctrl.deleteAxolotl(petIndex, false);
                    //cout << "SEARCHING FOR " << ax.getName() << "FOUND AT " << ctrl.searchAxolotl(ax.getName()) << endl;

                    // Instead, we search for the name of the pet
                    ctrl.deleteAxolotl(ctrl.searchAxolotl(ax.getName()), false);
                }

                string getType() override {
                    return "add";
                }

                Axolotl getAxolotl() override {
                    return ax;
                }

            private:
                Controller &ctrl;
                int petIndex;
                Axolotl ax;

        };

        class UndoRemove : public UndoOperation {
            public:
                UndoRemove(Controller &ctrl, Axolotl axolotl) : UndoOperation(ctrl.searchAxolotl(axolotl.getName())), ctrl{ctrl}, axolotl(axolotl) {};

                void undo() override {
                    ctrl.addAxolotl(ctrl.getVector(), Axolotl::getIntFromBreed(axolotl.getBreed()), axolotl.getName(), axolotl.getAge(), axolotl.getPhoto(), false);
                }

                string getType() override {
                    return "remove";
                }

                Axolotl getAxolotl() override {
                    return axolotl;
                }

            private:
                   Controller &ctrl;
                   Axolotl axolotl;
        };

        class UndoUpdate : public UndoOperation {
            public:
                UndoUpdate(Controller &ctrl, Axolotl axolotl, int petIndex) : UndoOperation(petIndex), ctrl{ctrl}, axolotl(axolotl), petIndex{petIndex} {};

                void undo() override {
                    ctrl.updateAxolotl(petIndex, Axolotl::getIntFromBreed(axolotl.getBreed()), axolotl.getName(), axolotl.getAge(), axolotl.getPhoto(), false);

                }

                string getType() override {
                    return "update";
                }

                Axolotl getAxolotl() override {
                    return this->axolotl;
                }


            private:
                   Controller &ctrl;
                   Axolotl axolotl;
                   int petIndex;
        };

        ///////////////////////////////

        //vector<unique_ptr<UndoOperation>> undoOperations;
        //vector<unique_ptr<UndoOperation>> redoOperations;
        vector<UndoOperation*> undoOperations;
        vector<UndoOperation*> redoOperations;
};


#endif //LAB5_6_CONTROLLER_H
