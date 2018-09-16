#include <bits/stdc++.h>

using namespace std;

typedef int I;
typedef pair<I, I> II;

int main()
{
    I n, m;
    cin >> n >> m;

    vector<vector<I>> graph(n);
    for(I i = 0; i < m; ++i) {
        I a, b;
        cin >> a >> b;
        --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bool all_ok = true;

    vector<I> came_from(n, -1);

    vector<bool> visited(n), visited_again(n);

    vector<I> directly_came_from(n, -1);
    for(I i = 0; i < n; ++i) {
        //cout << i << ": " << endl;
        if(visited[i]) {
            continue;
        }

        I in_cycle = -1;

        vector<I> dfs = {i};
        //cout << "dfs1: ";
        while(!dfs.empty()) {
            I current = dfs.back();
            dfs.pop_back();
            //cout << current << ' ';

            visited[current] = true;

            for(I other : graph[current]) {
                if(visited[other]) {
                    if(directly_came_from[current] != other) {
                    //cout << current << " marked " << other << '\n';
                        in_cycle = other;
                    }
                } else {
                    directly_came_from[other] = current;
                    dfs.push_back(other);
                }
            }
        }
        //cout << " (in cycle " << in_cycle << ")\n";

        if(in_cycle == -1) {
            all_ok = false;
            break;
        }

        dfs.push_back(in_cycle);

        //cout << "dfs2: ";
        while(!dfs.empty()) {
            I current = dfs.back();
            dfs.pop_back();

            visited_again[current] = true;

            //cout << current << ' ';

            for(I other : graph[current]) {
                if(visited_again[other]) {
                    continue;
                } else {
                    //cout << "(to " << other << ") ";
                    came_from[other] = current;
                    dfs.push_back(other);
                }
            }
        }

        for(I e : graph[in_cycle]) {
            if(came_from[e] != in_cycle) {
                came_from[in_cycle] = e;
                break;
            }
        }

        //cout << '\n';
    }

    //for(I i = 0; i < n; ++i) cout << came_from[i] << ' '; cout << '\n';

    if(all_ok) {
        cout << "TAK\n";
        for(I i = 0; i < n; ++i) cout << came_from[i] + 1 << '\n';
    } else {
        cout << "NIE\n";
    }



    return 0;
}
