#include <bits/stdc++.h>

using namespace std;

typedef int32_t I;
const I inf = 2e9;

struct Query {
    I a, b, w, i;
};
bool by_a(Query x, Query y) {
    return x.a < y.a;
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    I n, m, k;
    cin >> n >> m >> k;

    vector<vector<I>> neighbors(2 * n);

    for(I i = 0; i < m; ++i) {
        I a, b;
        cin >> a >> b;
        --a; --b;
        neighbors[a].push_back(b + n);
        neighbors[b + n].push_back(a);
        neighbors[b].push_back(a + n);
        neighbors[a + n].push_back(b);
    }

    vector<Query> queries(k);
    for(I i = 0; i < k; ++i) {
        cin >> queries[i].a >> queries[i].b >> queries[i].w;
        --queries[i].a; --queries[i].b;
        queries[i].i = i;
    }
    sort(queries.begin(), queries.end(), by_a);
    vector<bool> answers(k);
    I z = 0;

    for(I from = 0; from < n; ++from) {
        vector<I> shortest_path(2 * n, inf);
        shortest_path[from] = 0;
        deque<I> q;
        q.push_back(from);
        while(!q.empty()) {
            I current = q.front();
            q.pop_front();

            for(I to : neighbors[current]) {
                if(shortest_path[to] == inf) {
                    shortest_path[to] = shortest_path[current] + 1;
                    q.push_back(to);
                }
            }
        }

        while(z < k && queries[z].a == from) {
            if(neighbors[queries[z].a].empty()) {
                answers[queries[z].i] = false;
            } else {
                I path = shortest_path[queries[z].b + (queries[z].w % 2) * n];
                answers[queries[z].i] = (queries[z].w >= path);
            }
            ++z;
        }
    }

    for(I i = 0; i < k; ++i) {
        cout << (answers[i] ? "TAK" : "NIE") << '\n';
    }

    return 0;
}
