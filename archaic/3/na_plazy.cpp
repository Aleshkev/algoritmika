#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
typedef pair<I, I> II;

struct Pt {
    I x, y;
    I i;
};
bool by_xy(Pt l, Pt r) {
    return (l.x != r.x ? l.x < r.x : l.y < r.y);
}
bool by_i(Pt l, Pt r) {
    return l.i < r.i;
}

I cross(Pt o, Pt a, Pt b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    I n;
    cin >> n;

    vector<Pt> t;
    t.resize(n);
    for(I i = 0; i < n; ++i) {
        t[i].i = i;
        cin >> t[i].x >> t[i].y;
    }
    sort(t.begin(), t.end(), by_xy);

    vector<Pt> hi;
    for(I i = 0; i < t.size(); ++i) {
        while(hi.size() >= 2 && cross(hi[hi.size() - 2], hi[hi.size() - 1], t[i]) < 0) {
            hi.pop_back();
        }
        hi.push_back(t[i]);
    }
    vector<Pt> lo;
    for(I i = t.size() - 1; i >= 0; --i) {
        while(lo.size() >= 2 && cross(lo[lo.size() - 2], lo[lo.size() - 1], t[i]) < 0) {
            lo.pop_back();
        }
        lo.push_back(t[i]);
    }

    vector<Pt> result;
    for(I i = 0; i < hi.size() - 1; ++i) {
        result.push_back(hi[i]);
    }
    for(I i = 0; i < lo.size() - 1; ++i) {
        result.push_back(lo[i]);
    }
    if(result.size() == 0) {
        for(I i = 0; i < t.size(); ++i) {
            result.push_back(t[i]);
        }
    }
    sort(result.begin(), result.end(), by_i);

    for(Pt p : result) cout << p.i + 1 << ' ';

    return 0;
}
