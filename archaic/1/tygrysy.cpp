#include <iostream>
#include <set>

using namespace std;

typedef long long unsigned U;
const U inf = 1e18;
typedef double F;

struct Tiger {
    U sz;
    U eat_sz;
};

bool operator<(const Tiger &l, const Tiger &r) {
    return l.eat_sz < r.eat_sz;
}

int main()
{
    U n;
    cin >> n;

    multiset<Tiger> tigers;

    for(U i = 0; i < n; ++i) {
        Tiger t;
        U k;
        cin >> t.sz >> k;
        t.eat_sz = t.sz / k;
        tigers.insert(t);
    }

    U c = 1;
    U min_sz = inf;
    for(multiset<Tiger>::iterator it = tigers.begin(); it != tigers.end(); ++it) {
        //cout << it->sz << " (" << it->eat_sz << "): " << c << " (" << min_sz << ")\n";
        if(it->eat_sz >= min_sz) {
            ++c;
            min_sz = it->sz;
        } else {
            min_sz = min(min_sz, it->sz);
        }
    }
    cout << c << endl;

    return 0;
}
