//
// Created by sysadmin on 06.06.2018.
//

#include "RunTests.hpp"
#include "BST.hpp"
#include <cassert>

void RunTests::testSearch() {
    BST t;
    t.add(10);
    t.add(30);
    t.add(5);

    assert(t.search(10) == true);
    assert(t.search(-5) == false);
    assert(t.search(30) == true);
    assert(t.search(40) == false);
    assert(t.search(5) == true);
}

void RunTests::testRemove() {
    BST t;

    t.add(10);
    t.add(30);

    assert(t.search(10) == true);
    t.remove(10);
    assert(t.search(10) == false);

    assert(t.search(30) == true);
    t.remove(30);
    assert(t.search(30) == false);

    t.add(10);
    t.add(20);
    t.add(30);
    t.add(25);
    t.add(35);
    t.add(20);
    t.add(19);
    t.add(15);

    t.remove(19);
    t.remove(30);
}

void RunTests::testCount() {
    BST t;
    assert(t.count() == 0);
    t.add(5);
    t.add(10);

    assert(t.count() == 2);
    t.remove(10);
    assert(t.count() == 1);
    t.remove(5);
    assert(t.count() == 0);
}

void RunTests::testIsEmpty() {
    BST t;
    assert(t.isEmpty() == true);
    t.add(10);
    assert(t.isEmpty() == false);
    t.remove(10);
    assert(t.isEmpty() == true);
}

void RunTests::testMinMax() {
    BST t;

    assert(t.findMin() == -1);
    assert(t.findMax() == -1);

    t.add(10);
    t.add(30);
    t.add(5);

    assert(t.findMin() == 5);
    assert(t.findMax() == 30);
    t.remove(5);
    assert(t.findMin() == 10);
    t.remove(30);
    assert(t.findMax() == 10);
}

void RunTests::testIterator() {
    BST t;
    t.add(10);
    t.add(5);
    t.add(30);

    auto it = t.getIterator();
    assert(it.isValid() == true);
    assert(it.getValue() == 5);
    it.next();
    assert(it.isValid() == true);
    assert(it.getValue() == 10);
    it.next();
    assert(it.isValid() == true);
    assert(it.getValue() == 30);
    it.next();
    assert(it.isValid() == false);
}

void RunTests::runTests() {
    RunTests::testSearch();
    RunTests::testRemove();
    RunTests::testCount();
    RunTests::testIsEmpty();
    RunTests::testMinMax();
    RunTests::testIterator();
}
