#include <bits/stdc++.h>

using namespace std;

typedef long long int I;
const I lim = numeric_limits<I>::max() / 2;

I div2(vector<I> &t10) {
    I n = t10.size();
    I even = true;
    for(I i = 0; i < n; ++i) {
        if(i < n - 1) t10[i + 1] += 10 * (t10[i] % 2);
        else if(t10[i] % 2 != 0) even = false;
        t10[i] /= 2;
    }

    return !even;
}


struct BigNum {
    static const I width = 50;
    I digits[width + 1];
    static const I base = 10000000;
    static const I basedigits = 7;

    BigNum(I x = 0) {
        fill(digits, digits + width, 0);
        *this += x;
    }
    BigNum(const BigNum &x) {
        for(I i = 0; i < width; ++i) {
            digits[i] = x.digits[i];
        }
    }

    void recarry() {
        for(I i = 0; i < width - 1; ++i) {
            digits[i + 1] += digits[i] / base;
            digits[i] %= base;
        }
    }

    BigNum &operator*=(I x) {
        for(I i = 0; i < width - 1; ++i) {
            digits[i] *= x;
        }
        recarry();
        return *this;
    }
    BigNum operator*(I x) {
        return BigNum(*this) *= x;
    }

    BigNum &operator+=(const BigNum &x) {
        for(I i = 0; i < width - 1; ++i) {
            digits[i] += x.digits[i];
        }
        recarry();
        return *this;
    }
    BigNum operator+(const BigNum &x) {
        return BigNum(*this) += x;
    }
    BigNum &operator+=(I x) {
        for(I y = x, i = 0; y > 0; y /= base, ++i) {
            digits[i] += y % base;
        }
        recarry();
        return *this;
    }
};
istream &operator>>(istream &in, BigNum &bignum) {
    string s;
    in >> s;
    for(I i = 0; i < s.size(); ++i) {
        bignum.digits[s.size() - i - 1] = s[i] - '0';
    }
    return in;
}
ostream &operator<<(ostream &o, const BigNum &bignum) {
    I i = bignum.width - 1;
    while(i >= 0 && bignum.digits[i] == 0) --i;
    if(i >= 0) {
        o << bignum.digits[i];
        for(I j = i - 1; j >= 0; --j) {
            o << setfill('0') << setw(bignum.basedigits) << bignum.digits[j];
        }
    } else {
        o << '0';
    }
    return o;
}

BigNum bpow(I a, I b) {
    if(b == 0) {
        return BigNum(1);
    }
    BigNum x = a;
    for(I i = 1; i < b; ++i) {
        x *= a;
    }
    return x;
}


int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s10;//('9', 200);
    cin >> s10;

    vector<I> t10(s10.size());
    for(I i = 0; i < s10.size(); ++i) {
        t10[i] = s10[i] - '0';
    }

    vector<I> t2;

    for(I i = 0; ; ++i) {
        bool all_0 = true;
        for(I i = 0; i < t10.size(); ++i) {
            if(t10[i] != 0) {
                all_0 = false;
                break;
            }
        }
        if(all_0) {
            break;
        }
        t2.push_back(div2(t10));
    }

    reverse(t2.begin(), t2.end());

    I n = t2.size();

    vector<BigNum> bpow(n);
    bpow[0] = 1;
    for(I i = 1; i < n; ++i) {
        bpow[i] = bpow[i - 1] * 2;
    }


    I ones_before = 0;

    BigNum c;
    for(I i = 0; i < n; ++i) {
        if(t2[i] == 0) {
            continue;
        }

        I k = n - i - 1;
        if(k == 0) {
            break;
        }

        c += bpow[k - 1] * k + bpow[k] * ones_before;
        ++ones_before;
    }
    c += ones_before;
    if(t2[n - 1] == 1) {
        c += ones_before + 1;
    }

    cout << c << '\n';


    return 0;
}
