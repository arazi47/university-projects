#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v{1, 2, 3, 4, 5};
    vector<int>::iterator it = find(v.begin(), v.end(), 4);
    v.insert(it, 8);    // 1 2 3 8 4 5
    it = v.begin() + 2; // 1 2 10 8 4 5
    *it = 10;
    vector<int> x;
    copy_if(v.begin(), v.end(), back_inserter(x), [](int a){
        return a % 2 == 0;
    });

    // 2 10 8 4
    for (auto a : x) {
        cout << a << ' ';
    }

    return 0;
}