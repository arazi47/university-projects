#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>

#include "Complex.hpp"
#include "Vector.hpp"

using namespace std;

void tests() {
    Complex a{}, b{1, 2}, c{6,4}, d{b};
    assert(a.getReal() == 0 && a.getImaginary() == 0);
    assert(c.getImaginary() == 4);
    assert(b == d);

    Complex res1 = c / 2;
    cout << res1 << '\n';

    try {
        Complex res2 = b / 0;
    } catch (runtime_error &e) {
        assert(strcmp(e.what(), "Division by zero!") == 0);
    }

    Vector<string> v1 { vector<string>{"hello", "bye"}};
    v1.printAll(cout);

    Vector<Complex> v2 { vector<Complex>{a, b, c, d}};
    v2.printAll(cout);
}

int main() {
    tests();
    return 0;
}