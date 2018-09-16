#include <bits/stdc++.h>

using namespace std;

typedef int I;
typedef long double F;
typedef pair<F, F> FF;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0); cout.tie(0);

    I n, m;
    scanf("%i %i", &n, &m);

    map<F, I> events;

    for(I i = 0; i < n; ++i) {
        F x1, y1, x2, y2;
        scanf("%llf %llf %llf %llf", &x1, &y1, &x2, &y2);

        F a1 = atan2(y1, x1), a2 = atan2(y2, x2);
        if(a1 > a2) swap(a1, a2);

        ++events[a1];
        --events[nextafter(a2, 1e18)];
    }

    map<F, I> processed;
    I s = 0;
    processed[0.0] = s;
    for(auto e : events) {
        s += e.second;
        processed[e.first] = s;
    }

    for(I i = 0; i < m; ++i) {
        F x, y;
        scanf("%llf %llf", &x, &y);
        F a = atan2(y, x);
        printf("%i ", prev(processed.upper_bound(a))->second);
    }
    puts("\n");

    return 0;
}
