#include <bits/stdc++.h>

using namespace std;

typedef long int I;
const I inf = 2e9;

I n, m, q;
I first_population, last_population;
I distance_from_first[100000], distance_from_last[100000];
vector<I> metro[100000];

const I max_population = 1e9;

void fill_distances(I start, I distances[]) {
    fill(distances, distances + n, inf);
    distances[start] = 0;

    queue<I> q;
    q.push(start);
    while(!q.empty()) {
        I current = q.front();
        q.pop();

        for(I i = 0; i < metro[current].size(); ++i) {
            I next = metro[current][i];
            if(distances[next] >= inf) {
                distances[next] = distances[current] + 1;
                q.push(next);
            }
        }
    }
}

I reverse_number(I x) {
    I c = 0;
    while(x > 0) {
        c *= 10;
        c += x % 10;
        x /= 10;
    }
    return c % max_population;
}

void revolution(I v, I d) {
    if(v == 0) first_population = (first_population + d) % max_population;
    else if(v == n - 1) last_population = (last_population + d) % max_population;

    if(distance_from_first[v] <= d) first_population = reverse_number(first_population);
    if(distance_from_last[v] <= d) last_population = reverse_number(last_population);
}

I get_result() {
    return first_population <= last_population ? 0 : n - 2;
}

/*I dbg() {
    cout << first_population << ", ..., " << last_population << '\n';
    cout << "0:i = "; for(I i = 0; i < n; ++i) if(distance_from_first[i] != inf) cout << setw(2) << distance_from_first[i] << ' '; else cout << " . "; cout << '\n';
    cout << "i:n = "; for(I i = 0; i < n; ++i) if(distance_from_last[i] != inf) cout << setw(2) << distance_from_last[i] << ' '; else cout << " . "; cout << '\n';

}*/

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    cin >> first_population;
    I _t; for(I i = 2; i < n; ++i) cin >> _t;
    cin >> last_population;

    cin >> m;

    for(I i = 0; i < m; ++i) {
        I a, b;
        cin >> a >> b;
        --a; --b;

        metro[a].push_back(b);
        metro[b].push_back(a);
    }
    fill_distances(0, distance_from_first);
    fill_distances(n - 1, distance_from_last);

    //dbg();

    cin >> q;

    for(I i = 0; i < q; ++i) {
        I v, d;
        cin >> v >> d;
        --v;
        revolution(v, d);
        //dbg();

        cout << get_result() + 1 << '\n';
    }


    return 0;
}
