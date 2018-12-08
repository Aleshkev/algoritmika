#include <bits/stdc++.h>

using namespace std;

typedef long long int I;
typedef pair<I, I> II;

void append_prime_factors(vector<I> &v, I x) {
    for(I i = 2; i <= sqrt(x); ++i) {
        while(x % i == 0) {
            v.push_back(i);
            x /= i;
        }
    }
    if(x > 1) {
        v.push_back(x);
    }
}

struct BigNum {
    static const I ndigits = 200;
    vector<I> digits;

    BigNum() {
        digits.resize(ndigits);
        digits.back() = 1;
    }

    BigNum &operator*=(I x) {
        for(I i = 0; i < ndigits; ++i) {
            digits[i] *= x;
        }
        for(I i = ndigits - 1; i > 0; --i) {
            digits[i - 1] += digits[i] / 10;
            digits[i] %= 10;
        }
        return *this;
    }
};
ostream &operator<<(ostream &o, BigNum &x) {
    I i = 0;
    while(x.digits[i] == 0) ++i;
    for(; i < x.ndigits; ++i) cout << x.digits[i];

    return o;
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    I n = s.size();

    I occurences[256];
    fill(occurences, occurences + 256, 0);
    for(I i = 0; i < n; ++i) {
        ++occurences[I(s[i])];
    }

    vector<vector<I> > prime_factors(n + 1);
    for(I i = 2; i <= n; ++i) {
        append_prime_factors(prime_factors[i], i);
    }

    map<I, I> needed_mul;
    for(I i = 1; i <= n; ++i) {
        for(I j = 0; j < prime_factors[i].size(); ++j) {
            ++needed_mul[prime_factors[i][j]];
        }
    }

    for(char c = 'a'; c <= 'z'; ++c) {
        for(I j = 1; j <= occurences[I(c)]; ++j) {
            for(I k = 0; k < prime_factors[j].size(); ++k) {
                --needed_mul[prime_factors[j][k]];
            }
        }
    }

    BigNum b;

    for(map<I, I>::iterator i = needed_mul.begin(); i != needed_mul.end(); ++i) {
        for(I j = 0; j < i->second; ++j) {
            b *= i->first;
        }
    }

    cout << b << '\n';

    return 0;
}
