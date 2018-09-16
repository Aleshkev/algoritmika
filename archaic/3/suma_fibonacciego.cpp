#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I lim = 1e9 + 7;

struct mat {
    I x1y1, x2y1, x1y2, x2y2;
    mat(I a, I b, I c, I d) : x1y1(a  % lim), x2y1(b % lim), x1y2(c % lim), x2y2(d % lim) {};

    mat operator*(const mat &o) {
        return mat(
            x1y1 * o.x1y1 + x2y1 * o.x1y2,
            x1y1 * o.x2y1 + x2y1 * o.x2y2,
            x1y2 * o.x1y1 + x2y2 * o.x1y2,
            x1y2 * o.x2y1 + x2y2 * o.x2y2
        );
    }
};
ostream &operator<<(ostream &o, const mat &m) {
    o << "[" << m.x1y1 << ", " << m.x2y1 << " | " << m.x1y2 << ", " << m.x2y2 << "]";
    return o;
}

mat quick_pow(mat &origin, I n) {
    if(n == 1) return origin;
    if(n == 2) return origin * origin;
    mat r = quick_pow(origin, n / 2);
    r = r * r;
    if(n % 2 == 1) {
        r = r * origin;
    }
    return r;
}

I nth_fibonacci(I n) {
    if(n == 1) return 1;
    if(n == 2) return 2;
    if(n == 3) return 3;

    mat origin(0, 1, 1, 1);
    mat power = quick_pow(origin, n - 1);

    cout << power << endl;

    return (power * mat(1, 0, 2, 0)).x1y1 % lim;
}

I sum_up_to(I x) {
    // To w zasadzie powinno byæ F(x + 2) - 2, ale (F(b + 2) - 2) - (F(a + 2) - 2) = F(b + 2) - F(a + 2).
    // Je¿eli siê odejmuje 2, musi to byæ (lim + F(x + 2) - 2) % lim, ale nadal czemuœ nie dzia³a :(
    return nth_fibonacci(x + 2);
}

int main()
{
    ios_base::sync_with_stdio(false);

    cout << mat(1, 2, 2, 3) * mat(1, 0, 2, 0) << endl;

    for(I i = 1; i < 10; ++i) {
        nth_fibonacci(i);
    }

    //I a, b;
    //cin >> a >> b;

    //cout << (lim + sum_up_to(b) - sum_up_to(a - 1)) % lim << '\n';

    return 0;
}
