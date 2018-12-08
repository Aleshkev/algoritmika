#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I inf = 1e18;

I n;
vector<I> distances, weights;
I total_cost = 0, min_cost = inf;

I cost(I i, I j) {
    return total_cost - (weights[i] * (distances[j] - distances[i]) -
                         weights[j] * (distances[n + 1] - distances[j]));

}

void solve(I min_pos1, I max_pos1, I min_pos2, I max_pos2) {
    if(min_pos1 >= min_pos2) {
        min_pos2 = min_pos1 + 1;
    }
    if(max_pos1 >= max_pos2) {
        max_pos1 = max_pos2 - 1;
    }
    if(min_pos1 > max_pos1 || min_pos2 > max_pos2) {
        return;
    }

    I pos2 = (min_pos2 + max_pos2) / 2;

    I optimal_cost = inf;
    I pos1;
    for(I i = min_pos1; i <= min(max_pos1, pos2 - 1); ++i) {
        I i_cost = cost(i, pos2);
        if(i_cost < optimal_cost) {
            pos1 = i;
            optimal_cost = i_cost;
        }
    }

    min_cost = min(min_cost, optimal_cost);

    solve(min_pos1, pos1, min_pos2, pos2 - 1);
    solve(pos1, max_pos1, pos2 + 1, max_pos2);
}

int main() {
    cout.sync_with_stdio(false);

    cin >> n;

    distances.resize(n + 1 + 1);
    weights.resize(n + 1 + 1);

    distances[1] = 0;
    cin >> weights[1] >> distances[2];
    total_cost = weights[1] * distances[2];

    for(I i = 2; i <= n; ++i) {
        I w, d;
        cin >> w >> d;
        weights[i] = weights[i - 1] + w;
        distances[i + 1] = distances[i] + d;
        total_cost += weights[i] * d;
    }

    solve(1, n - 1, 2, n);

    cout << min_cost << '\n';

    return 0;
}
