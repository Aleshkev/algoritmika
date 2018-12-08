#include <bits/stdc++.h>

using namespace std;

typedef long int I;

int main()
{
    I m;
    scanf("%li", &m);
    for(I k = 0; k < m; ++k) {
        I n, p;
        scanf("%li %li", &n, &p);

        const I lim = 10000;
        I t[lim + 1] = {0};

        for(I i = 0; i < n; ++i) {
            I s, v;
            scanf("%li %li", &s, &v);

            for(I j = p - s; j >= 0; --j) {
                if(j == 0 || t[j] > 0) {
                    t[j + s] = max(t[j + s], t[j] + v);
                }
            }
        }

        //for(I i = 1; i <= p; ++i) cout << t[i] << ' '; cout << '\n';

        printf("%li\n", *max_element(t, t + p + 1));
    }

    return 0;
}
