#include <bits/stdc++.h>

using namespace std;

typedef long long int I;

int main()
{
    cout.sync_with_stdio(false);
    cout.tie(0);

    I n, m;
    cin >> n >> m;

    map<I, I> k;

    for(I i = 0; i < n; ++i) {
        I a; cin >> a;
        map<I, I>::iterator it = k.find(a);
        if(it == k.end()) {
            k.insert(make_pair(a, 1));
        } else {
            ++it->second;
        }
    }

    static I t[1000001] = {0};
    for(map<I, I>::iterator i = k.begin(); i != k.end(); ++i) {
        for(I j = i->first; j <= 1000000; j += i->first) {
            t[j] += i->second;
        }
    }

    for(I i = 0; i < m; ++i) {
        I a, b; cin >> a >> b;
        cout << t[__gcd(a, b)] << '\n';
    }

    return 0;
}
