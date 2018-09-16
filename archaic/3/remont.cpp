#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I inf = 1e18;

int main()
{
    I n, m;
    cin >> n >> m;

    vector<I> needed(n + 1, inf);
    needed[0] = 0;

    vector<I> ws(m);
    for(I i = 0; i < m; ++i) {
        cin >> ws[i];
    }
    sort(ws.begin(), ws.end(), greater<I>());

    for(I i = 0; i < m; ++i) {
        I w = ws[i];
        for(I j = 0; j + w <= n; ++j) {
            needed[j + w] = min(needed[j + w], needed[j] + 1);
        }
    }

    for(I i = 0; i < min((I)10, n + 1); ++i) {
        cout << needed[i] << ' ';
    } cout << endl;

    I max_len = 0;
    for(I i = n; i >= 0; --i) {
        if(needed[i] < inf) {
            max_len = i;
            break;
        }
    }
    cout << max_len << ' ' << needed[max_len] << '\n';



    return 0;
}
