#include <bits/stdc++.h>

using namespace std;

typedef long int I;
const I inf = 1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    I n;
    cin >> n;
    const I max_n = 1e5;

    static char s[max_n + 1];
    cin >> s;

    static I last[128];
    fill(last, last + 128, inf);

    static I nearest[max_n];
    fill(nearest, nearest + n, inf);

    for(I i = 0; i < n; ++i) {
        if(last[s[i] - 'a'] != inf) {
            nearest[i] = i - last[s[i] - 'a'];
        }
        last[s[i] - 'a'] = i;
    }

    fill(last, last + 128, inf);

    for(I i = n - 1; i >= 0; --i) {
        if(last[s[i] - 'a'] != inf) {
            nearest[i] = min(nearest[i], last[s[i] - 'a'] - i);
        }
        last[s[i] - 'a'] = i;
    }

    replace(nearest, nearest + n, inf, (I)0);

    /*for(I i = 0; i < n; ++i) {
        cout << nearest[i] << ' ';
    } cout << endl;*/

    I m;
    cin >> m;
    for(I i = 0; i < m; ++i) {
        I x;
        cin >> x;
        --x;
        cout << nearest[x] << ' ';
    } cout << '\n';

    return 0;
}
