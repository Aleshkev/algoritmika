#include <bits/stdc++.h>

using namespace std;
typedef int I;

struct Pt {
    I x, y;
    I i;
};
bool by_xy(Pt l, Pt r) {
    return (l.x == r.x ? l.y < r.y : l.x < r.x);
}
bool by_i(Pt l, Pt r) {
    return l.i < r.i;
}

I cross(Pt o, Pt a, Pt b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

void print_convex_hull(vector<Pt> &v) {
    sort(v.begin(), v.end(), by_xy);

    vector<Pt> lo, hi;

    for(I i = v.size() - 1; i >= 0; --i) {
        while(lo.size() >= 2 && cross(lo[lo.size() - 2], lo[lo.size() - 1], v[i]) < 0) {
            lo.pop_back();
        }
        lo.push_back(v[i]);
    }

    for(I i = 0; i < v.size(); ++i) {
        while(hi.size() >= 2 && cross(hi[hi.size() - 2], hi[hi.size() - 1], v[i]) < 0) {
            hi.pop_back();
        }
        hi.push_back(v[i]);
    }

    lo.pop_back();
    hi.pop_back();

    auto &result = lo;

    for(Pt p : hi) {
        result.push_back(p);
    }

    if(result.empty()) {
        for(Pt p : v) {
            result.push_back(p);
        }
    }

    sort(result.begin(), result.end(), by_i);

    for(Pt p : result) {
        cout << p.i + 1 << ' ';
    } cout << '\n';
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);

    I n, px, py;
    cin >> n >> px >> py;

    vector<Pt> v;
    v.resize(n);
    for(I i = 0; i < n; ++i) {
        cin >> v[i].x >> v[i].y;
        v[i].i = i;
    }
    print_convex_hull(v);
    sort(v.begin(), v.end(), by_i);
    v.resize(n * 2);
    for(I i = 0; i < n; ++i) {
        v[n + i].x = v[i].x + px;
        v[n + i].y = v[i].y + py;
        v[n + i].i = n + i;
    }
    print_convex_hull(v);

    return 0;
}
