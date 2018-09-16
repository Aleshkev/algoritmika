#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    I n, s;
    cin >> n >> s;

    I c = 0;
    unordered_map<I, I> first_c;
    I max_l = 0;
    first_c[0] = -1;
    for(I i = 0; i < n; ++i) {
        I x;
        cin >> x;

        c += x;
        if(!first_c.count(c)) {
            first_c[c] = i;
        }

        if(first_c.count(c - s)) {
            max_l = max(max_l, i - first_c[c - s]);
        }
    }
    if(max_l > 0) {
        cout << max_l << '\n';
    } else {
        cout << "BRAK\n";
    }

    return 0;
}
