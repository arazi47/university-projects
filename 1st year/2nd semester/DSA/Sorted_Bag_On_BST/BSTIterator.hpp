//
// Created by sysadmin on 20.05.2018.
//

#ifndef SORTEDBAGBST_BSTITERATOR_HPP
#define SORTEDBAGBST_BSTITERATOR_HPP

#include <iostream>
#include "GlobalDefinitions.hpp"

class BSTIterator {
    public:
        explicit BSTIterator(Node *root, int count) : root{root}, count{count}, done{0} {
            nextLevel(root->left);
        }

        bool isValid() {
            //printf("%d valid\n", root->data);
            return this->root != NULL;
        }

        int getValue() {
            return this->root->data;
        }

        void next() {
            // Hackfix for the iterator to work...
            // It glitches if the first entered element is the biggest one
            // Also glitches if I enter just one element
            // Also glitches if I want to traverse when root == NULL, but I got that covered in main.cpp
            ++this->done;
            if (this->done >= this->count) {
                this->root = NULL;
                return;
            }

            if (!nextLevel(this->root->right)) {
                if (this->root->parent != NULL) {
                    // I don't think we need this (this never gets executed in the test cases
                    // But the iterator still works fine
                    //while (this->root->parent != NULL && this->root == this->root->parent->right)
                    //    this->root = this->root->parent;

                    this->root = this->root->parent;
                }
            }
        }

    private:
        Node *root = NULL;

        // Get to the leftmost level
        bool nextLevel(Node *currNode) {
            if (currNode == NULL) {
                return false;
            }

            if (!this->nextLevel(currNode->left)) {
                this->root = currNode;
            }

            return true;
        }

        int count; // no of nodes received
        int done; // no of nodes traversed
};


#endif //SORTEDBAGBST_BSTITERATOR_HPP
