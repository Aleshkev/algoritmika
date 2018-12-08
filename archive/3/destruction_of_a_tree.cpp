#include <bits/stdc++.h>

using namespace std;

typedef long long int I;

I n;
const I max_n = 3e5;

bool removed[max_n];
vector<I> children[max_n];
I population[max_n];

void naseleniye_dfs(I i) {
    population[i] = 0;
    for(I j : children[i]) {
        naseleniye_dfs(j);
        population[i] += population[j] + 1;
    }
}

void razrushitelnyy_dfs(I i) {
    for(I j : children[i]) {
        if(population[j] % 2 == 1) {
            razrushitelnyy_dfs(j);
        }
    }
    cout << i + 1 << '\n';
    removed[i] = true;
    for(I j : children[i]) {
        if(!removed[j]) {
            razrushitelnyy_dfs(j);
        }
    }
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    if(n % 2 == 0) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";

    I start;
    static vector<I> graph[max_n];
    for(I i = 0; i < n; ++i) {
        I j;
        cin >> j;
        --j;
        if(j == -1) {
            start = i;
            continue;
        }
        graph[i].push_back(j);
        graph[j].push_back(i);
    }

    vector<I> dfs;
    dfs.push_back(start);
    static bool visited[max_n];
    visited[start] = true;

    while(!dfs.empty()) {
        I i = dfs.back();
        dfs.pop_back();

        for(I j : graph[i]) {
            if(!visited[j]) {
                dfs.push_back(j);
                children[i].push_back(j);
                visited[j] = true;
            }
        }
    }

    naseleniye_dfs(start);
    for(I i = 0; i < n; ++i) {
        //cout << i << ": " << population[i] << '\n';
    }

    razrushitelnyy_dfs(start);
}
