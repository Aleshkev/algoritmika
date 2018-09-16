#include <bits/stdc++.h>

using namespace std;

typedef long long int I;
const I lim = 1e9 + 7;

struct matrix {
    static const I w = 2;
    vector<I> fields;
    matrix() {
        fields.resize(w * w);
    }
    matrix(const vector<I> v) : fields(v) {}

    I &at(I x, I y) {
        //cout << "at(" << x << ", " << y << ") -> " << fields[y * w + x] << endl;
        return fields[y * w + x];
    }

    matrix operator*(matrix o) {
        matrix r;
        for(I x = 0; x < w; ++x) {
            for(I y = 0; y < w; ++y) {
                for(I i = 0; i < w; ++i) {
                    r.at(x, y) += at(x, i) * o.at(i, y) % lim;
                }
            }
        }
        return r;
    }
};

ostream &operator<<(ostream &o, matrix m) {
    /*for(I i = 0; i < m.w * m.w; ++i) {
        if(i % m.w == 0) {
            if(i == 0) cout << "[ ";
            else cout << "  ";
        }
        cout << setw(2) << m.fields[i];
        if(i < m.w * m.w - 1) {
            cout << ", ";
            if((i + 1) % m.w == 0) cout << endl;
        }
        else cout << "  ]";
    }*/

    for(I y = 0; y < m.w; ++y) {
        if(y == 0) cout << "[ ";
        else cout << "  ";
        for(I x = 0; x < m.w; ++x) {
            cout << setw(2) << m.at(x, y) << " ";
        }
        if(y < m.w - 1) cout << endl;
        else cout << " ]";
    }
    return o;
}

matrix qpow(matrix b, I n) {
    if(n == 1) return b;
    if(n == 2) return b * b;
    matrix r = qpow(b, n / 2);
    r = r * r;
    if(n % 2 == 1) {
        r = r * b;
    }
    return r;
}

I nth_fibonacci(I n) {
    if(n == 0 || n == 1) return 0;
    if(n == 2 || n == 3) return 1;
    matrix origin;
    origin.at(1, 0) = origin.at(1, 1) = origin.at(0, 1) = 1;
    matrix multiplier = qpow(origin, n - 1);
    /*for(I i = 2; i < n; ++i) {
        multiplier = multiplier * origin;
    }*/
    //cout << matrix({1, 0, 2, 0}) * multiplier << endl;
    matrix base;
    base.at(0, 1) = 1;
    return (base * multiplier).at(0, 0) % lim;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    /*cout << matrix({1, 0, 2, 0}) * matrix({1, 2, 2, 3})  << endl;

    for(I i = 1; i <= 10; ++i) {
        cout << nth_fibonacci(i) << '\n';
    }*/

    I n;
    cin >> n;

    cout << nth_fibonacci(n) << ' ' << (n > 1 ? nth_fibonacci(n - 1) : 1) << '\n';

    return 0;
}
