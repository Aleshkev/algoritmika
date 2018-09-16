#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I inf = 1e18;

int main()
{
    cout.sync_with_stdio(false);

    I n, k;
    cin >> n >> k;
    --k;

    vector<vector<I>> who_wants(n);
    vector<I> what_bajtus_wants;

    for(I i = 0; i < n; ++i) {
        I m;
        cin >> m;
        for(I j = 0; j < m; ++j) {
            I x;
            cin >> x;
            --x;
            who_wants[x].push_back(i);
            if(i == k) {
                what_bajtus_wants.push_back(x);
            }
        }
    }

    vector<I> distance(n, inf);
    deque<I> bfs;
    bfs.push_back(k);
    distance[k] = 0;
    while(!bfs.empty()) {
        I current = bfs.front();
        bfs.pop_front();

        for(I volunteer : who_wants[current]) {
            if(distance[volunteer] == inf) {
                distance[volunteer] = distance[current] + 1;
                bfs.push_back(volunteer);
            }
        }
    }

    I min_distance = inf;
    for(I wish : what_bajtus_wants) {
        min_distance = min(min_distance, distance[wish]);
    }
    if(min_distance < inf) {
        cout << min_distance << '\n';
    } else {
        cout << "Beeeeeeeeeeeeeee" << '\n';
    }

    return 0;
}
