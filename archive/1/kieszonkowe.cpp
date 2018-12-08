#include <bits/stdc++.h>

using namespace std;

typedef long long int I;

struct S {
    I hi, lo;
    I sum;
};

bool operator<(const S &l, const S &r) {
    return l.sum != r.sum ? l.sum < r.sum : l.hi < r.hi;
}

int main()
{
    I n, k;
    cin >> n >> k;

    static S t[1000000];
    for(I i = 0; i < n; ++i) {
        cin >> t[i].hi;
    }
    for(I i = 0; i < n; ++i) {
        cin >> t[i].lo;
        t[i].sum = t[i].hi + t[i].lo;
    }

    sort(t, t + n);

    /*for(I i = 0; i < n; ++i) {
        cout << t[i].hi << " ";
    }
    cout << endl;
    for(I i = 0; i < n; ++i) {
        cout << t[i].lo << " ";
    }
    cout << endl;*/

    I c = 0;
    for(I i = n - 1; i >= n - k / 2; --i) {
        c += t[i].sum;
    }
    if(k % 2 > 0) {
        c += t[n - k / 2 - 1].hi;
    }
    cout << c << '\n';


    return 0;
}
