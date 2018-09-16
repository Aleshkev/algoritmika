#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
typedef double F;
const F inf = 1e100;

inline F form(I a, I b, I c, I d, I m) {
    return abs(floor(a / (F(m) + b)) - c * log(F(m) + d));
}

int main()
{
    I n;
    cin >> n;

    for(I q = 0; q < n; ++q) {
        F a, b, c, d;
        cin >> a >> b >> c >> d;

        /*I best_m = 0;
        F best_f = inf;
        for(I m = 1; ; ++m) {
            F f = form(m);
            if(f < best_f) {
                best_f = f;
                best_m = m;
            } else {
                break;
            }
        }
        cout << best_m << '\n';*/

        I lo = 1, hi = 1e10;
        while(lo < hi) {
            I mid = (lo + hi) / 2;
            F lt = form(a, b, c, d, mid), rt = form(a, b, c, d, mid + 1);
            if(lt < rt) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        cout << lo << '\n';
    }

    return 0;
}
