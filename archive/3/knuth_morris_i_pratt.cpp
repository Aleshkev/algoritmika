#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

I s_hash[1000000];
I prim = 313, mod = I(1e9) + 7;
I prim_pow[1000000];
char str[1000000];
I n;
void init() {
    s_hash[0] = str[0];
    for(I i = 1; i < n; ++i) {
        s_hash[i] = (s_hash[i - 1] * prim % mod + str[i]) % mod;
    }

    prim_pow[0] = 1;
    for(I i = 1; i < n; ++i) {
        prim_pow[i] = prim_pow[i - 1] * prim % mod;
    }
}
I get_hash(I i, I j) {
    return (s_hash[j] - s_hash[i - 1] * str[j - i + 1] + mod) % mod;
}

int main()
{
    cin >> n;
    cin >> str;

    init();

    for(;;) {

    }

    return 0;
}
