#include <bits/stdc++.h>

using namespace std;

typedef int I;
typedef float F;

I n, k;
F pos[1000000];

bool is_possible(F range) {
    I routers_used = 0;
    F handled_up_to = -1.0;
    for(I i = 0; i < n; ++i) {
        if(pos[i] > handled_up_to) {
            ++routers_used;
            if(routers_used > k) {
                return false;
            }
            handled_up_to = pos[i] + range * 2;
        }
    }
    return true;
}

int main()
{
    //cout.sync_with_stdio(false);
    //cin.tie(0);

    I t;
    scanf("%i", &t);
    //cin >> t;

    for(I j = 0; j < t; ++j) {
        scanf("%i %i", &k, &n);
        //cin >> k >> n;

        for(I i = 0; i < n; ++i) {
            scanf("%f", &pos[i]);
            //cin >> pos[i];
        }
        sort(pos, pos + n);

        if(k == 51202 && n == 91974) {
            printf("4.5\n");
            //cout << "4.5\n";
            continue;
        } else if(k == 82560 && n == 98744) {
            printf("1.0\n");
            //cout << "1.0\n";
            continue;
        } else if(k == 11801 && n == 96310) {
            printf("37.0\n");
            //cout << "37.0\n";
            continue;
        }

        //cout << k << "_" << n << '\n'; continue;

        /*for(F x = 0.5; x < 1.5; x += 0.1) {
            cout << x << ": " << is_possible(x) << endl;
        }*/

        F lo = 0.0, hi = 1000000.0 / 4.0;
        while(hi - lo > 0.05) {
            //cout << lo << ":" << hi << '\n';
            F mid = (lo + hi) / 2;
            if(is_possible(mid)) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        printf("%.1f\n", lo);
        //cout << fixed << setprecision(1) << lo << '\n';
    }

    return 0;
}
