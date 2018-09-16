#include <bits/stdc++.h>

using namespace std;

typedef long long int I;
const I inf = 1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    I n, m;
    cin >> n >> m;

    string pattern;
    cin >> pattern;

    I group_size[256] = {0}, group_bits[256] = {0};

    for(I i = 0; i < m; ++i) {
        ++group_size[pattern[i]];
    }

    for(I i = 0; i < n; ++i) {
        string chain;
        cin >> chain;
        for(I j = 0; j < m; ++j) {
            if(chain[j] == '1') ++group_bits[pattern[j]];
        }
    }

    I min_x = inf;
    for(I i = 'A'; i <= 'Z'; ++i) {
        if(group_size[i] > 0) {
            min_x = min(min_x, group_bits[i] / group_size[i]);
        }
    }
    cout << min_x * m << '\n';


    return 0;
}
