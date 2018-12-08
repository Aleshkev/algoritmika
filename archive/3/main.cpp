#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    I n, m;
    cin >> n >> m;

    vector<vector<I>> connected(n);

    for(I i = 0; i < m; ++i) {
        I a, b;
        cin >> a >> b;
        --a; --b;
        connected[a].push_back(b);
        connected[b].push_back(a);
    }

    /*vector<I> group_size(n);
    fill(group_size.begin(), group_size.end(), -1);
    for(I i = 0; i < n; ++i) {
        if(group_size[i] != -1) {
            continue;
        }

        group_size[i] = 1;
        vector<I> dfs;
        dfs.push_back(i);
        while(!dfs.empty()) {
            I current = dfs.back();
            dfs.pop_back();

            for(I other : connected[current]) {
                if(group_size[other] == -1) {

                    ++group_size[i];
                    dfs.push_back(other);
                }
            }
        }
    }

    for(I i = 0; i < n; ++i) cout << group_size[i] << ' '; cout << '\n';*/


    vector<I> color(n);
    fill(color.begin(), color.end(), -1);

    vector<I> colors_used(2);

    for(I i = 0; i < n; ++i) {
        if(color[i] != -1) {
            continue;
        }

        vector<I> dfs;
        color[i] = rand() % 2;
        dfs.push_back(i);
        while(!dfs.empty()) {
            I current = dfs.back();
            dfs.pop_back();

            for(I other : connected[current]) {
                if(color[other] == -1) {
                    color[other] = (color[current] + 1) % 2;
                    ++colors_used[color[other]];

                    dfs.push_back(other);
                }
            }
        }
    }

    vector<I> no = {count(color.begin(), color.end(), 0), count(color.begin(), color.end(), 1)};

    I c = 0;
    for(I i = 0; i < n; ++i) {
        c += no[(color[i] + 1) % 2] - connected[i].size();
    }
    c /= 2;

    cout << c << '\n';

    return 0;
}
