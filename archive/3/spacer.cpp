#include <bits/stdc++.h>

using namespace std;

typedef long int I;
typedef pair<I, I> II;

struct Tree {
    I width;
    vector<I> values;
    Tree(I capacity) {
        for(width = 1; width < capacity; width *= 2);
        values.resize(width * 2);
    }

    void set_at(I i, I x) {
        I v = width + i;
        if(x <= values[v]) {
            return;
        }
        values[v] = x;
        for(v /= 2; v > 0; v /= 2) {
            values[v] = max(values[2 * v], values[2 * v + 1]);
        }
    }
    I get_at(I qb, I qe, I rb, I re, I i) {
        if(re < qb || rb > qe) {
            return 0;
        }
        if(qb <= rb && re <= qe) {
            return values[i];
        }
        I mid = (rb + re) / 2;
        return max(get_at(qb, qe, rb, mid, 2 * i), get_at(qb, qe, mid + 1, re, 2 * i + 1));
    }
    I get_at(I a, I b) {
        return get_at(a, b, 0, width - 1, 1);
    }
};

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    I n;
    cin >> n;

    vector<II> points;
    vector<I> xs, ys;

    for(I i = 0; i < n; ++i) {
        I x, y;
        cin >> x >> y;
        /*if(y < 0 || abs(x) > y) {
            continue;
        }*/

        I rot_x = x - y, rot_y = x + y;

        //cout << " " << rot_x << ", " << rot_y << '\n';

        points.push_back(II(rot_x, rot_y));
        xs.push_back(rot_x);
        ys.push_back(rot_y);
    }

    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    n = points.size();

    for(I i = 0; i < n; ++i) {
        points[i].first = lower_bound(xs.begin(), xs.end(), points[i].first) - xs.begin();
        points[i].second = lower_bound(ys.begin(), ys.end(), points[i].second) - ys.begin();
    }

    sort(points.begin(), points.end());

    I zero_x = lower_bound(xs.begin(), xs.end(), 0) - xs.begin();
    I zero_y = lower_bound(ys.begin(), ys.end(), 0) - ys.begin();
    bool is_zero_point = binary_search(points.begin(), points.end(), II(zero_x, zero_y));
    if(!is_zero_point) {
        points.push_back(II(zero_x, zero_y));
        sort(points.begin(), points.end());
        ++n;
    }

    vector<vector<I> > by_x(xs.size());
    for(I i = 0; i < n; ++i) {
        by_x[points[i].first].push_back(points[i].second);
    }

    Tree tree(ys.size());
    for(I x = 0; x < by_x.size(); ++x) {
        sort(by_x[x].begin(), by_x[x].end());

        for(I i = by_x[x].size() - 1; i >= 0; --i) {
            I y = by_x[x][i];
            I r = tree.get_at(y, tree.width - 1) + (x == zero_x && y == zero_y ? is_zero_point : 1);
            tree.set_at(y, r);

            //cout << x << ", " << y << ": " << r << '\n';

            if(x == zero_x && y == zero_y) {
                cout << r << '\n';
            }
        }
    }


    return 0;
}
