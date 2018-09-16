#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I inf = 1e18;
typedef pair<I, I> II;

struct NextCell {
    I x, y;
    I c;
    NextCell(I x, I y, I c) : x(x), y(y), c(c) {};
};
bool operator>(NextCell a, NextCell b) {
    return a.c > b.c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    I w, h, m;
    cin >> w >> h >> m;

    vector<vector<I>> cost(w, vector<I>(h, 1));

    for(I i = 0; i < m; ++i) {
        I x, y;
        char c;
        cin >> x >> y >> c;
        --x; --y;
        y = h - y - 1;
        if(c == 'o') {
            cost[x][y] = 0;
        } else if(c == 'x') {
            cost[x][y] = inf;
        }
    }

    //for(I y = 0; y < h; ++y) {for(I x = 0; x < w; ++x) cout << radiation[x][y] << ' '; cout << '\n';}; cout << '\n';
    //for(I y = 0; y < h; ++y) {for(I x = 0; x < w; ++x) cout << passable[x][y] << ' '; cout << '\n';}; cout << '\n';

    vector<vector<I>> min_dist(w, vector<I>(h, inf));

    priority_queue<NextCell, vector<NextCell>, greater<NextCell>> q;
    for(I x = 0; x < w; ++x) {
        q.emplace(x, 0, cost[x][0]);
    }

    const I change_x[6] = {-1, 1, 0, -1, 0, 1};
    const I change_y[6] = {0, 0, -1, -1, 1, 1};

    while(!q.empty()) {
        NextCell current = q.top();
        q.pop();
        I x = current.x, y = current.y, dist = current.c;
        if(dist >= inf || dist >= min_dist[x][y]) {
            continue;
        }
        min_dist[x][y] = dist;

        for(I i = 0; i < 6; ++i) {
            I new_x = x + change_x[i], new_y = y + change_y[i];
            if(new_x < 0 || new_x >= w || new_y < 0 || new_y >= h || cost[new_x][new_y] >= inf) {
                continue;
            }
            q.emplace(new_x, new_y, dist + cost[new_x][new_y]);
        }
    }

    //for(I y = 0; y < h; ++y) {for(I x = 0; x < w; ++x) cout << setw(2) << (min_dist[x][y] < inf ? min_dist[x][y] : -1) << ' '; cout << '\n';}; cout << '\n';

    I r = inf;
    for(I x = 0; x < w; ++x) {
        r = min(r, min_dist[x][h - 1]);
    }

    cout << (r < inf ? r : -1) << '\n';

    return 0;
}
