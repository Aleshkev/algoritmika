#include <bits/stdc++.h>

typedef intmax_t I;

using namespace std;

I gcd(I a, I b) {
    return __gcd(a, b);
}

int main() {
    cout.sync_with_stdio(false);
    cin.tie(0);

    static I u[1000000];
    static I t[3000000];
    I w = 1;
    while(w < 1000000) w <<= 1;

    I n;
    cin >> n;
    for(I i = 0; i < n; ++i) {
        I x;
        cin >> x;
        if(x > 0) {
            ++u[x];
            if(u[x] == 1) t[w + x] = x;
        } else {
            x = -x;
            --u[x];
            if(u[x] == 0) t[w + x] = 0;
        }
        for(I j = (w + x) / 2; j > 0; j /= 2) {
            t[j] = gcd(t[j * 2], t[j * 2 + 1]);
        }
        cout << t[1] << '\n';
    }

    return 0;
}
