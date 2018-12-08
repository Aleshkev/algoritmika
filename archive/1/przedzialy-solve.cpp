#include <bits/stdc++.h>

using namespace std;

typedef int I;


int main()
{
    I n, m; scanf("%i %i", &n, &m);

    map<I, I> t;
    for(I i = 0; i < n; ++i) {
        I a, b; cin >> a >> b;
        if(t.find(a) == t.end()) {
            t.insert(make_pair(a, 1));
        } else {
            ++t[a];
        }
        if(t.find(b + 1) == t.end()) {
            t.insert(make_pair(b + 1, -1));
        } else {
            --t[b + 1];
        }
    }

    vector<pair<I, I> > u;
    u.push_back(make_pair(-1, 0));
    I c = 0;
    for(map<I, I>::iterator i = t.begin(); i != t.end(); ++i) {
        c += i->second;
        u.push_back(make_pair(i->first, c));
    }
    sort(u.begin(), u.end());

    for(I i = 0; i < m; ++i) {
        I x; scanf("%i", &x);
        printf("%i\n", (--upper_bound(u.begin(), u.end(), make_pair(x, 0)))->second);
    }


    return 0;
}
