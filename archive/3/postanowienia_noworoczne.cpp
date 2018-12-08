#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    I n, k;
    cin >> n >> k;

    vector<I> t(n);
    for(I i = 0; i < n; ++i) {
        cin >> t[i];
    }

    vector<I> original_pos(n + 1);
    for(I i = 0; i < n; ++i) {
        original_pos[t[i]] = i;
    }

    sort(t.begin(), t.end());

    do {
        I c = 0;
        for(I i = 0; i < n; ++i) {
            c += abs(original_pos[t[i]] - i);
        }
        if(c <= k) {
            break;
        }
    } while(next_permutation(t.begin(), t.end()));



    for(I i = 0; i < n; ++i) {
        cout << t[i] << ' ';
    } cout << '\n';

    return 0;
}
