#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
typedef long double F;
const F pi = 3.14159265358979;
const F inf = 1e100;

struct Vec {
    F x, y;
    F angle;
    F magn;
    F angle_to_next;
};
ostream &operator<<(ostream &o, Vec v) {
    o << "<" << v.x << ", " << v.y << ": angle = " << v.angle << " (to next = " << v.angle_to_next << "), magn = " << v.magn << ">";
    return o;
}

void prepare(I n, vector<Vec> &v) {
    for(I i = 0; i < n; ++i) {
        cin >> v[i].x >> v[i].y;

        v[i].angle = atan2(v[i].x, v[i].y);
        if(v[i].x == 0 && v[i].y < 0) {
            v[i].angle = pi;
        }

        v[i].magn = sqrt(v[i].x * v[i].x + v[i].y * v[i].y);
    }
    stable_sort(v.begin(), v.end(), [](Vec a, Vec b) {return a.angle < b.angle; });

    for(I i = 0; i < n - 1; ++i) {
        v[i].angle_to_next = v[i + 1].angle - v[i].angle;
    }
    v[n - 1].angle_to_next = 2 * pi - v[n - 1].angle + v[0].angle;
}

bool eq(F a, F b) {
    return abs(a - b) < 0.1;
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    I n;
    cin >> n;

    vector<Vec> v1(n), v2(n);
    prepare(n, v1);
    prepare(n, v2);

    /*for(I i = 0; i < n; ++i) {
        cout << v1[i] << ' ';
    } cout << '\n';
    for(I i = 0; i < n; ++i) {
        cout << v2[i] << ' ';
    } cout << '\n';*/

    F min_angle = inf;
    for(Vec v : v1) {
        min_angle = min(min_angle, v.angle_to_next);
    }

    vector<I> where_min;
    for(I i = 0; i < n; ++i) {
        if(v1[i].angle_to_next == min_angle) {
            where_min.push_back(i);
        }
    }

    bool any_ok = false;
    for(I i : where_min) {
        bool ok = true;
        for(I j = 0; j < n; ++j) {
            if(!eq(v1[(i + j) % n].angle_to_next, v2[j].angle_to_next) || !eq(v1[(i + j) % n].magn, v2[j].magn)) {
                ok = false;
                break;
            }
        }
        if(ok) {
            any_ok = true;
            break;
        }
    }
    cout << (any_ok ? "TAK" : "NIE") << '\n';

    return 0;
}
