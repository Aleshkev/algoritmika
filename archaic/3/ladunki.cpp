#include <bits/stdc++.h>

using namespace std;

typedef int I;

I n, m;
bool t[25][25];  // t[a][b] jest true jeśli istnieje połączenie od a do b
I v[25][25];  // Dla każdego x, v[x] jest tablicą kolorów. v[x][i] jest kolorem i-tego wierzchołka jeśli DFS doszedł dokładnie do x.

bool walk(I x, I *colors_now, I lvl = 0) {

    bool color_available[] = {true, true, true};
    for(I i = 0; i < n; ++i) {
        if(t[x][i] && colors_now[i] != -1) {
            color_available[colors_now[i]] = false;
        }
    }
    /*cout << setw(lvl) << "" << "WALKING " << x << " - available colors: ";
    for(I i = 0; i < 3; ++i) {
        cout << (color_available[i] ? char('A' + i) : '-') << " ";
    } cout << endl;*/

    for(I color = 0; color < 3; ++color) {
        if(!color_available[color]) {
            continue;
        }

        //cout << setw(lvl) << "" << "trying " << char('A' + color) << endl;

        I *colors_for_subtree = v[x];
        copy(colors_now, colors_now + n, colors_for_subtree);
        colors_for_subtree[x] = color;

        for(I i = 0; i < n; ++i) {
            if((!t[x][i]) || colors_for_subtree[i] != -1) {
                continue;
            }

            if(!walk(i, colors_for_subtree, lvl + 1)) {
                goto next_color;
            }
        }

        copy(colors_for_subtree, colors_for_subtree + n, colors_now);

        //cout << setw(lvl) << "" << "-success (" << char('A' + color) << ")" << endl;

        return true;

        next_color:
            if(x == 0) break;
            else continue;
    }

    //cout << setw(lvl) << "" << "-failure" << endl;

    return false;
}

int main()
{
    cout.sync_with_stdio(false);

    cin >> n >> m;

    for(I i = 0; i < m; ++i) {
        I a, b;
        cin >> a >> b;
        --a; --b;

        t[a][b] = t[b][a] = true;
    }

    fill(v[0], v[0] + n, -1);

    bool all_ok = true;

    for(I i = 0; i < n; ++i) {
        if(v[0][i] == -1) {
            if(!walk(i, v[0])) {
                all_ok = false;
                break;
            }
        }
    }

    if(all_ok) {
        for(I i = 0; i < n; ++i) {
            cout << char('A' + v[0][i]);
        } cout << '\n';
    } else {
        cout << "NIE\n";
    }

    return 0;
}
