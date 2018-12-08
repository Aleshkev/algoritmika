#include <bits/stdc++.h>

using namespace std;

typedef uint64_t I;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    uint32_t n;
    cin >> n;
    const uint32_t m = 1e6;
    static array<uint32_t, m + 1> is_coupon;
    for(I i = 0; i < n; ++i) {
        uint32_t x;
        cin >> x;
        is_coupon[x] = true;
    }

    static array<uint32_t, m + 1> is_bought;
    static array<uint32_t, m + 1> start_with;

    cin >> n;

    vector<I> r;

    I k = 0;
    for(uint32_t i = 0; i < n; ++i) {
        uint32_t x;
        cin >> x;

        I placed = 0;
        for(uint32_t j = start_with[x] + x; placed < x && j <= m; j += x) {
            if(is_bought[j]) {
                continue;
            }
            ++placed;
            if(is_coupon[j]) {
                r.push_back(k + placed);
            }
            is_bought[j] = true;
            start_with[x] = j;
            is_coupon[j] = false;
        }
        k += x;
    }
    cout << r.size() << '\n';
    for(I i : r) {
        cout << i << '\n';
    }

    return 0;
}
