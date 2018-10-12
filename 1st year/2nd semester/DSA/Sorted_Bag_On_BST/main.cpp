#include <iostream>
#include "AbstractSortedBag.hpp"
#include "BSTIterator.hpp"
#include "BST.hpp"
#include "RunTests.hpp"

using std::cout;
using std::endl;
using std::cin;

// Descending order
void printPreOrder(Node *root) {
    if (root != NULL) {
        printPreOrder(root->right);
        cout << root->data << ' ';
        printPreOrder(root->left);
    }
}

// Ascending order
void printInOrder(Node *root) {
    if (root != NULL) {
        printInOrder(root->left);
        cout << root->data << ' ';
        printInOrder(root->right);
    }
}

void insertTestValues(BST &t) {
    t.add(222);
    t.add(10);
    t.add(30);
    t.add(60);
    t.add(707);
    t.add(50);
    t.add(40);
}

void showMenu() {
    cout << "0. Exit\n"
            "1. Add a purchase\n"
            "2. Search if a purchase with the given cost exists\n"
            "3. Remove a purchase\n"
            "4. Display all purchases (in-order traversal)\n"
            "5. Display number of purchases\n"
            "6. Check if the purchase list is empty\n"
            "7. Display all purchases (iterator)\n"
            "8. Display cheapest purchase\n"
            "9. Display the most expensive purchase\n";
}

int main() {
    RunTests::runTests();

    BST t("sd");
    insertTestValues(t);
    while (true) {
        showMenu();

        cout << ">> ";

        int option;
        cin >> option;

        switch (option) {
            case 0:
                return 0;

            case 1: {
                int cost;
                cout << "What is the cost of the expense? ";
                cin >> cost;

                t.add(cost);
            } break;

            case 2: {
                int cost;
                cout << "Enter the cost you wish to find: ";
                cin >> cost;

                if (t.search(cost))
                    cout << "The given cost exists.\n";
                else
                    cout << "The given cost does not exist.\n";
            } break;

            case 3: {
                int cost;
                cout << "Enter the cost you wish to remove: ";
                cin >> cost;

                if (t.search(cost)) {
                    t.remove(cost);
                    cout << "Success!\n";
                } else {
                    cout << "Fail! (given cost could not be found)\n";
                }
            } break;

            case 4: {
                if (t.getRelation() == "<") {
                    printInOrder(t.getRoot());
                    cout << endl;
                }
                else if (t.getRelation() == ">") {
                    printPreOrder(t.getRoot());
                    cout << endl;
                } else if (t.getRelation() == "sd") {
                    printInOrder(t.getRoot());
                    cout << endl;
                }
            } break;

            case 5: {
                cout << "The number of purchases is " << t.count() << ".\n";
            } break;

            case 6: {
                if (t.isEmpty()) {
                    cout << "There are no purchases in the list!\n";
                } else {
                    cout << "There are definitely purchases in the list.\n";
                }
            } break;

            case 7: {
                if (!t.isEmpty()) {
                    auto it = t.getIterator();
                    while (it.isValid()) {
                        cout << it.getValue() << ' ';
                        it.next();
                    }

                    cout << "\n";
                }
            } break;

            case 8: {
                if (!t.isEmpty()) {
                    cout << "The cheapest purchase is " << t.findMin() << ".\n";
                } else {
                    cout << "The shopping list is empty!\n";
                }
            } break;

            case 9: {
                if (!t.isEmpty()) {
                    cout << "The most expensive purchase is " << t.findMax() << ".\n";
                } else {
                    cout << "The shopping list is empty!\n";
                }
            } break;

            default: {
                cout << "Unknown option entered!\n";
            } break;
        }
    }

    return 0;
}