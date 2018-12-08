#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
typedef pair<I, I> II;

struct Pt {
    I x, y;
    Pt() {};
    Pt(I x, I y) : x(x), y(y) {};
};
bool operator<(Pt l, Pt r) {
    return l.x < r.y || (l.x == r.x && l.y < r.y);
}
ostream &operator<<(ostream &o, Pt p) {
    o << "[" << p.x << ", " << p.y << "]";
    return o;
}

I cross(Pt o, Pt a, Pt b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

Pt buffer_a[62000000], buffer_b[6200000];


I convex_hull(Pt *points, I n_points, Pt *new_points) {
    Pt *hi = new_points;
    I n_hi = 0;
    for(I i = 0; i < n_points; ++i) {
        while(n_hi >= 2 && cross(hi[n_hi - 2], hi[n_hi - 1], points[i]) <= 0) {
            --n_hi;
        }
        hi[n_hi++] = points[i];
    }

    Pt *lo = new_points + n_hi - 1;
    I n_lo = 0;
    for(I i = n_points - 1; i >= 0; --i) {
        while(n_lo >= 2 && cross(lo[n_lo - 2], lo[n_lo - 1], points[i]) <= 0) {
            --n_lo;
        }
        lo[n_lo++] = points[i];
    }

    return n_hi + n_lo - 2;
}


int main()
{
    cout.sync_with_stdio(0);
    cin.tie(0);

    I n;
    cin >> n;

    Pt *points = buffer_a, *other_buffer = buffer_b;
    I n_points = 0;
    points[n_points++] = Pt(0, 0);

    for(I i = 0; i < n; ++i) {
        I px, py;
        px = i % 9 + 1;
        py = min(10 - px, (I)1);
        //cin >> px >> py;

        for(I j = 0, k = n_points; j < k; ++j) {
            points[n_points++] = Pt(points[j].x + px, points[j].y + py);
        }
        sort(points, points + n_points);
        cout << i << ": " << n_points << endl;

        n_points = convex_hull(points, n_points, other_buffer);
        swap(points, other_buffer);
    }

    I max_d = 0;
    for(I i = 0; i < n_points; ++i) {
        //cout << points[i] << endl;

        max_d = max(max_d, points[i].x * points[i].x + points[i].y * points[i].y);
    }
    cout << max_d << '\n';


    return 0;
}
