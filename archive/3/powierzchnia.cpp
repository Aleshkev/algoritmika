#include <bits/stdc++.h>

using namespace std;

typedef long long int I;
typedef long double F;

F w, h, p1x, p1y, p2x, p2y;

F vert_intersect(F ax) {
    const F dy = p2y - p1y, dx = p2x - p1x;
    const F w = ax - p1x;
    const F ay = p1y + w * dy / dx;
    return (0 <= ay && ay <= h ? ay : -1);
}
F horiz_intersect(F ay) {
    const F dx = p2x - p1x, dy = p2y - p1y;
    const F h = ay - p1y;
    const F ax = p1x + h * dx / dy;
    return (0 <= ax && ax <= w ? ax : -1);
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);

    cin >> w >> h >> p1x >> p1y >> p2x >> p2y;

    const F lt_i = vert_intersect(0), rt_i = vert_intersect(w);
    const F bott_i = horiz_intersect(0), top_i = horiz_intersect(h);

    F half;
    if(lt_i != -1 && rt_i != -1) {
        half = (lt_i + rt_i) * w / 2.0;
    } else if(bott_i != -1 && top_i != -1) {
        half = (bott_i + top_i) * h / 2.0;
    } else if(lt_i != -1 && bott_i != -1) {
        half = lt_i * bott_i / 2.0;
    } else if(bott_i != -1 && rt_i != -1) {
        half = (w - bott_i) * rt_i / 2.0;
    } else if(rt_i != -1 && top_i != -1) {
        half = (w - top_i) * (h - rt_i) / 2.0;
    } else if(top_i != -1 && lt_i != -1) {
        half = (h - lt_i) * top_i / 2.0;
    } else {
        throw out_of_range("SOMETHING WENT TERRIBLY WRONG");
    }

    cout << fixed << setprecision(2) << min(half, w * h - half) << '\n';

    return 0;
}
