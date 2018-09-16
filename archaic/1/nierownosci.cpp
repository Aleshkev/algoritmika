#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long unsigned U;


int main() {
    U n;
    cin >> n;

    bool *t = new bool[8];
    fill_n(t, 8, true);
    for(U i = 0; i < n; ++i) {
        char l, op, r;
        cin >> l >> op >> r;
        t[(op == '<' ? l : r) - 'A'] = false;
    }
    char mx = 'A' + (find(t, t + 8, true) - t);

    cout << mx<< endl;

    return 0;
}
