#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I inf = 1e18;

struct Fragment {
    I n;
    bool cut_after;
    Fragment(I n, bool c = false) : n(n), cut_after(c) {};
};
bool operator<(Fragment a, Fragment b) {
    return (a.n != b.n ? a.n < b.n : (I)a.cut_after < (I)b.cut_after);
}

ostream &operator<<(ostream &o, Fragment f) {
    o << f.n;
    if(f.cut_after) o << "'";
    return o;
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    I m;
    cin >> m;

    vector<I> t;
    for(I i = 0; i < m; ++i) {
        I x;
        cin >> x;
        if(!t.empty() && t.back() == x) {
            continue;
        }
        t.push_back(x);
    }
    I n = t.size();

    //for(I i : t) cout << i << ' '; cout << '\n';

    multiset<Fragment> s;
    s.emplace(-inf, true);
    s.emplace(inf, true);

    for(I i = 0; i < n; ++i) {

        auto hi = s.upper_bound(Fragment(t[i], true));
        auto lo = prev(hi);

        I lo_n = lo->n, hi_n = hi->n;

        //for(auto f : s) cout << f << ' '; cout << '\n';
        //cout << "lo: " << *lo << ", hi: " << *hi << '\n';

        if(!lo->cut_after) {
            //cout << "adding cut after " << *lo << '\n';
            s.erase(lo);
            s.emplace(lo_n, true);
        }

        I j = i;
        while(j < n && (j == i || t[j - 1] <= t[j]) && t[j] <= hi_n) {
            ++j;
        } --j;
        //cout << "inserting strip " << i << ":" << j << '\n';

        for(; i <= j - 1; ++i) {
            s.emplace(t[i]);
        }
        s.emplace(t[j], true);

        //cout << "jmp " << j << '\n';
        i = j;
    }
    //for(auto f : s) cout << f << ' '; cout << '\n';

    I c = 0;
    for(auto f : s) {
        c += f.cut_after;
    };
    c -= 3;

    cout << c << '\n';

    return 0;
}
