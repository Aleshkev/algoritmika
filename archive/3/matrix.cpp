#include <bits/stdc++.h>

using namespace std;

typedef int I;

struct Street {
    I a, b;
    I lag_t;
};
bool time_greater(const Street &l, const Street &r) {
    return l.lag_t > r.lag_t;
}

I k, n, m;
Street streets[1000000];
struct Group {
    I parent;
    I nphones;
};
Group t[1000000];
multiset<I> nphones;

I find_root(I a) {
    if(t[a].parent != a) {
        t[a].parent = find_root(t[a].parent);
    }
    return t[a].parent;
}

void join(I a, I b) {
    I root_a = find_root(a), root_b = find_root(b);
    if(root_a == root_b) {
        return;
    }

    t[root_b] = root_a;
    nphones.erase(nphones.find(t[root_a].nphones));
    nphones.erase(nphones.find(t[root_b].nphones));
    t[root_a].nphones += t[root_b].nphones;
    nphones.insert(t[root_a].nphones);
}

int main()
{
    cin >> k >> n >> m;

    for(I i = 0; i < k; ++i) {
        I x;
        cin >> x;
        --x;
        ++t[x].nphones;
    }

    for(I i = 0; i < m; ++i) {
        cin >> streets[i].a >> streets[i].b >> streets[i].lag_t;
        --streets[i].a; --streets[i].b;
    }
    sort(streets, streets + m, time_greater);

    for(I i = 0; i < n; ++i) {
        t[i].parent = i;
    }

    for(I i = 0; i < m; ++i) {
        join(streets[i].a, streets[i].b);
        if(*nphones.rbegin() < )
    }

    return 0;
}
