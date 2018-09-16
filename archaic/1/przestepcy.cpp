#include <iostream>
#include <vector>

using namespace std;

typedef int I;
typedef pair<I, I> II;

const I MAX_SZ = 1000010;

int main()
{
    cout.sync_with_stdio(false);

    I n, k; cin >> n >> k;  // Liczba domów, liczba kolorów
    static I t[MAX_SZ]; {  // Domy
        for(I i = 1; i <= n; ++i) {
            cin >> t[i];
        }
    }

    I m, l; cin >> m >> l;
    static I u[MAX_SZ], v[MAX_SZ]; {  // Jakie domy po kolei napadaj¹
        for(I i = 1; i <= m; ++i) {
            cin >> u[i];
        }
        for(I i = 1; i <= l; ++i) {
            cin >> v[i];
        }
    }

    static I next_same_color[MAX_SZ], prev_same_color[MAX_SZ]; {  // Indeks następnego/poprzedniego domu o tym samym kolorze
        fill(next_same_color + 1, next_same_color + n + 1, -1);

        static I last[MAX_SZ];
        fill(last + 1, last + k + 1, -1);
        for(I i = 1; i <= n; ++i) {
            prev_same_color[i] = last[t[i]];
            if(last[t[i]] != -1) {
                next_same_color[last[t[i]]] = i;
            }
            last[t[i]] = i;
        }
    }


    static I d[MAX_SZ], e[MAX_SZ];
    fill(d + 1, d + k + 1, -1); fill(e + 1, e + k + 1, -1);

    vector<I> curr;
    for(I i = 1; i <= n && curr.size() < m - 1; ++i) {
        if(t[i] == u[curr.size() + 1]) {
            curr.push_back(i);
        }
    }
    for(I i = 1; i <= n; ++i) {
        if(d[t[i]] != -1) continue;

        if(!curr.empty()) {
            /*for(I j = 0; j < curr.size(); ++j) {
                while(curr[j] <= i || (j > 0 && curr[j - 1] > curr[j])) {
                    curr[j] = next_same_color[curr[j]];
                    if(curr[j] == -1) goto end_d;
                }
            }*/

            for(I j = 0; j < curr.size(); ++j) {
                bool r = false;
                while(curr[j] <= i || (j > 0 && curr[j - 1] > curr[j])) {
                    r = true;
                    curr[j] = next_same_color[curr[j]];
                    if(curr[j] == -1) goto end_d;
                }
                if(!r) break;
            }

            d[t[i]] = curr.back();
        } else {
            d[t[i]] = i;
        }
    } end_d:

    /*for(I i = 1; i <= k; ++i) {
        cout << i << ": " << d[i] << endl;
    }*/

    curr.clear();
    for(I i = n; i >= 1 && curr.size() < l - 1; --i) {
        if(t[i] == v[curr.size() + 1]) {
            curr.push_back(i);
        }
    }
    for(I i = n; i >= 1; --i) {
        if(e[t[i]] != -1) continue;

        if(!curr.empty()) {
            for(I j = 0; j < curr.size(); ++j) {
                bool r = false;
                while(curr[j] >= i || (j > 0 && curr[j - 1] <= curr[j])) {
                    r = true;
                    curr[j] = prev_same_color[curr[j]];
                    if(curr[j] == -1) goto end_e;
                }
                if(!r) break;
            }

            e[t[i]] = curr.back();
        } else {
            e[t[i]] = i;
        }
    } end_e:

    /*for(I i = 1; i <= k; ++i) {
        cout << i << ": " << e[i] << endl;
    }*/

    static I h[MAX_SZ] = {0};

    for(I i = 1; i <= k; ++i) {
        if(d[i] == -1 || e[i] == -1 || d[i] >= e[i]) continue;

        ++h[d[i]];
        --h[e[i] - 1];
    }

    /*for(I i = 1; i <= n; ++i) {
        cout << h[i] << " ";
    } cout << endl;*/

    I level = 0;
    vector<I> result;
    for(I i = 1; i <= n; ++i) {
        if(level > 0 && t[i] == u[m]) {
            result.push_back(i);
        }
        level += h[i];
    }

    cout << result.size() << '\n';
    for(I i = 0; i < result.size(); ++i) {
        cout << result[i] << ' ';
    } cout << '\n';

    return 0;
}
