//
// Created by sysadmin on 20.05.2018.
//

#ifndef SORTEDBAGBST_BST_HPP
#define SORTEDBAGBST_BST_HPP

#include <iostream>
#include <string>
#include "GlobalDefinitions.hpp"
#include "AbstractSortedBag.hpp"
#include "BSTIterator.hpp"

using std::cout;
using std::endl;
using std::string;

class BST {
    public:
        BST();
        explicit BST(const string &relation);
        ~BST();

        bool search(int data);
        void remove(int data);
        int count();
        void add(int data);

        // Descending order
        //void printPreOrder();

        // Ascending order
        //void printInOrder();

        bool isEmpty();

        int findMin();
        int findMax();

        BSTIterator getIterator();

        const string getRelation() const { return this->relation; }

    private:
        Node *root;
        int nodeCount;

        Node *getRoot() { return this->root; }

        /*
        * Deletes the given node and all its children
        */

        void destroy(Node *t);

        /*
        * Create a new node with the given 'data' and insert it (in order) in the BST
        */

        Node *insert(Node *parent, Node *root, int data);
        Node *search(Node *root, int data);
        Node *remove(Node *root, int data);

        Node *findMin(Node *t);
        Node *findMax(Node *t);

        string relation;

        int sumOfDigits(int n);
};

#endif //SORTEDBAGBST_BST_HPP
