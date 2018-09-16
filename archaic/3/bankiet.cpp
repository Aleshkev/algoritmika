#include <bits/stdc++.h>

using namespace std;

typedef int I;

I t[30000];
I ngroups;
I root(I x) {
    if(t[x] != x) {
        t[x] = root(t[x]);
    }
    return t[x];
}
void join(I a, I b) {
    a = root(a), b = root(b);
    if(a == b) {
        return;
    }

    t[b] = a;
    --ngroups;
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    I n;
    cin >> n;

    for(I i = 0; i < n; ++i) {
        t[i] = i;
    }
    ngroups = n;

    for(I i = 0; i < n; ++i) {
        I l;
        cin >> l;
        --l;
        join(i, l);
    }

    cout << ngroups << '\n';

    return 0;
}
