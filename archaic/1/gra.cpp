#include <bits/stdc++.h>

using namespace std;

typedef long int I;

bool loses(I n) {
    static map<I, bool> cache;

    if(cache.count(n) > 0) return cache[n];

    bool r = true;
    if(n == 0) {
        r = true;
    } else {
        for(I k = 1; k <= n; k <<= 1) {
            if(k == n || loses(n - k)) {
                r = false;
            }
        }
    }
    cache[n] = r;
    return r;
}

int main()
{
    I n;
    scanf("%li", &n);

    for(I i = 0; i < n; ++i) {
        I k = i;
        scanf("%li", &k);


        printf("%s\n", k % 3 == 0 ? "TAK" : "NIE");
    }

    return 0;
}
