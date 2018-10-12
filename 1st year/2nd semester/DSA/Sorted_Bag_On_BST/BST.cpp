//
// Created by sysadmin on 20.05.2018.
//

#include "BST.hpp"

BST::BST() : root(NULL), nodeCount(0), relation("<") {}

BST::BST(const string &relation) : root(NULL), nodeCount(0), relation(relation) {}

BST::~BST() {
    this->destroy(this->root);
}

void BST::destroy(Node *t) {
    if (t == NULL) {
        return;
    }

    this->destroy(t->left);
    this->destroy(t->right);
    delete t;
}

bool BST::search(int data) {
    Node *t = this->search(this->root, data);

    return t != NULL;

}

void BST::remove(int data) {
    if (this->search(this->root, data) != NULL) {
        this->root = this->remove(this->root, data);
        --this->nodeCount;
    }
}

int BST::count() {
    return this->nodeCount;
}

Node *BST::insert(Node *parent, Node *root, int data) {
    // BST is empty
    if (root == NULL) {
        root = new Node();
        root->data = data;
        root->parent = parent;
        root->left = NULL;
        root->right = NULL;

    } /*else if (data < root->data) {
        root->left = this->insert(root, root->left, data);
    } else {
        root->right = this->insert(root, root->right, data);
    }*/

    else if (relation == "sd") // sum of digits
    {
        //cout << data << ' ' << sumOfDigits(data) << ' ' << root->data << ' ' << sumOfDigits(root->data) << endl;
        if (sumOfDigits(data) < sumOfDigits(root->data)) {
            root->left = this->insert(root, root->left, data);
        } else {
            root->right = this->insert(root, root->right, data);
        }
    } else {
        if (data < root->data) {
            root->left = this->insert(root, root->left, data);
        } else {
            root->right = this->insert(root, root->right, data);
        }
    }

    return root;
}

void BST::add(int data) {
    this->root = this->insert(NULL, this->root, data);
    ++this->nodeCount;
}

Node *BST::findMin(Node *t) {
    if (t == NULL) {
        return NULL;
    } else if (t->left == NULL) {
        return t;
    }

    return this->findMin(t->left);
}

Node *BST::findMax(Node *t) {
    if (t == NULL) {
        return NULL;
    } else if (t->right == NULL) {
        return t;
    }

    return this->findMax(t->right);
}

BSTIterator BST::getIterator() {
    return BSTIterator(root, this->count());
}

Node *BST::search(Node *root, int data) {
    if (root != NULL) {
        if (data == root->data) {
            return root;
        }

        return this->search(data > root->data ? root->right : root->left, data);
    }

    return NULL;
}

Node *BST::remove(Node *root, int data) {
    if (root == NULL)
        return root;
    else if (data < root->data)
        root->left = this->remove(root->left, data);
    else if (data > root->data)
        root->right = this->remove(root->right, data);
    else {
        if (root->left == NULL && root->right == NULL) {
            // no children
            delete root;
            root = NULL;
        }
        else if (root->left == NULL) {
            // 1 child
            //Node *tmp = root;
            root = root->right;
            //delete tmp;
        }
        else if (root->right == NULL) {
            // 1 child
            //Node *tmp = root;
            root = root->left;
            //delete tmp;
        }
        else {
            // 2 children
            Node *tmp = this->findMin(root->right);
            root->data = tmp->data;
            root->right = this->remove(root->right, tmp->data);
        }
    }

    return root;
}

bool BST::isEmpty() {
    return this->root == NULL;
}

int BST::findMin() {
    Node *t = this->findMin(this->root);
    if (t != NULL) {
        return t->data;
    }

    return -1;
}

int BST::findMax() {
    Node *t = this->findMax(this->root);
    if (t != NULL) {
        return t->data;
    }

    return -1;
}

int BST::sumOfDigits(int n) {
    int s = 0;
    while (n) {
        s += (n % 10);
        n /= 10;
    }

    return s;
}
