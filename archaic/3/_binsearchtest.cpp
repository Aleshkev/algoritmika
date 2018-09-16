#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main()
{
    vector<I> t = {1, 2, 3, 3, 4, 4, 4, 4, 5, 6};

    I a = -1, b = t.size();
    I x = 5;
    while(b - a > 1) {
        I mid = (a + b) / 2;
        if(t[mid] <= x) {
            a = mid;
        } else {
            b = mid;
        }
    }
    cout << a << " " << b << endl;

    return 0;
}
