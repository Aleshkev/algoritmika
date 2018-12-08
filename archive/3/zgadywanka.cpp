#include <bits/stdc++.h>

using namespace std;

typedef long int I;
struct bignum;
ostream &operator<<(ostream &out, bignum &n);
struct bignum {
    static const I lim = 300;
    vector<I> digits;

    bignum() {
        digits.resize(lim);
    }

    void normalize() {
        for(I i = 0; i < lim - 1; ++i) {
            digits[i + 1] += digits[i] / 10;
            digits[i] %= 10;
        }
    }

    bignum &operator+=(I x) {
        for(I i = 0; x > 0; ++i) {
            digits[i] += x % 10;
            x /= 10;
        }
        normalize();
        return *this;
    }

    bignum &operator*=(I x) {
        for(I i = 0; i < lim; ++i) {
            digits[i] *= x;
        }
        normalize();
        return *this;
    }

    void pow2() {
        bignum r;
        vector<bignum> t(10);
        for(I i = 0; i < 10; ++i) {
            copy(digits.begin(), digits.end(), t[i].digits.begin());
            t[i] *= i;
        }

        for(I i = 0; i < lim / 2; ++i) {
            I j = digits[i];
            for(I k = 0; k < lim / 2; ++k) {
                r.digits[i + k] += t[j].digits[k];
            }
            r.normalize();
        }

        copy(r.digits.begin(), r.digits.end(), digits.begin());
    }
};

istream &operator>>(istream &in, bignum &n) {
    string s;
    in >> s;
    for(I i = 0; i < s.size(); ++i) {
        n.digits[i] = s[s.size() - i - 1] - '0';
    }
    return in;
}
ostream &operator<<(ostream &out, bignum &n) {
    I i = n.lim - 1;
    while(i > 0 && n.digits[i] == 0) --i;
    while(i >= 0) out << n.digits[i], --i;
    return out;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    I q;
    for(I i = 0; i < s.size(); ++i) {
        if(s[i] == '?') {
            q = i;
            break;
        }
    }
    q = s.size() - q - 1;

    bignum n;
    cin >> n;
    n += 250;
    n *= 3;
    n.pow2();
    //cout << n << endl;

    cout << n.digits[q] << '\n';


    return 0;
}
