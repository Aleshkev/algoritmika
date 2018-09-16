#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

struct Pair {
    I x, i;
};
bool operator<(Pair q, Pair p) {
    return q.x < p.x;
}
ostream &operator<<(ostream &o, Pair p) {
    o << p.x << " @" << p.i;
    return o;
}

int main()
{
    I m;
    cin >> m;

    vector<I> t(m);
    for(I i = 0; i < m; ++i) {
        cin >> t[i];
    }
    t.erase(unique(t.begin(), t.end()), t.end());
    I n = t.size();

    vector<I> u(t);
    sort(u.begin(), u.end());
    u.erase(unique(u.begin(), u.end()), u.end());

    for(I i = 0; i < n; ++i) {
        t[i] = lower_bound(u.begin(), u.end(), t[i]) - u.begin() + 1;
    }

    vector<Pair> v(n);
    for(I i = 0; i < n; ++i) {
        v[i].x = t[i];
        v[i].i = i;
    }
    sort(v.begin(), v.end());

    /*for(I i : t) cout << setw(2) << i << ' '; cout << '\n';
    for(Pair i : v) cout << setw(2) << i.x << ' '; cout << '\n';
    for(Pair i : v) cout << setw(2) << i.i << ' '; cout << '\n';*/

    vector<I> group_size(n);
    for(I i = 0; i < n; ++i) {
        group_size[i] = upper_bound(v.begin(), v.end(), v[i]) - lower_bound(v.begin(), v.end(), v[i]);
    }

    //for(I i = 0; i < n; ++i) cout << setw(2) << group_size[i] << ' '; cout << '\n';

    I cuts = n - 1;

    /* vector<bool> handled(n);
    for(I i = 0; i < n; ++i) {
        if(group_size[i] == 1) {
            I j = 0;
            while(v[i].i + j < n && t[v[i].i + j] == v[i].x + j && i + j < n && v[i + j].x == v[i].x + j) {
                ++j;
            } --j;

            cout << "alone group of " << v[i].x << "s saves " << j << " cuts!" << endl;

            cuts -= j;

            for(I k = 0; k <= j; ++k) {
                handled[i + k] = true;
            }
        }
    } */

    vector<I> is_pair(n);
    for(I i = 0; i < n - 1; ++i) {
        if(t[i] == t[i + 1] - 1) {
            is_pair[t[i]] = 1;
        }
    }

    //for(I i : is_pair) cout << i << ' '; cout << '\n';

    cuts -= accumulate(is_pair.begin(), is_pair.end(), 0);

    cout << cuts << '\n';

    return 0;
}
