#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

vector<I> val;
vector<vector<I>> neighbors;
vector<I> dp;

void walk(I i) {
    if(dp[i] != -1) return;

    for(I neighbor : neighbors[i]) {
        walk(neighbor);
    }


}

int main()
{
    I n;
    cin >> n;

    val.resize(n);
    neighbors.resize(n);
    dp.resize(n);
    fill(dp.begin(), dp.end(), -1);

    for(I i = 0; i < n; ++i) {
        cin >> val[i];
    }

    for(I i = 0; i < n - 1; ++i) {
        I a, b;
        cin >> a >> b;
        --a; --b;
        neighbors[a].push_back(b);
        neighbors[b].push_back(a);
    }


    return 0;
}
