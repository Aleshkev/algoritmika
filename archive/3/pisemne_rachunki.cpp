#include <bits/stdc++.h>

using namespace std;

typedef long long int I;


struct num {
    static const I ndigits = 200 + 1;
    static const I comma = 100;
    I digits[ndigits + 1];

    num() {
        fill(digits, digits + ndigits + 1, 0);
    }

    void add(const num &o) {
        for(I i = 0; i < ndigits; ++i) {
            digits[i] += o.digits[i];
        }
    }
    void carry() {
        for(I i = 0; i < ndigits; ++i) {
            digits[i + 1] += digits[i] / 10;
            digits[i] = (digits[i]) % 10;
        }
    }
};

istream &operator>>(istream &in, num &o) {
    string s;
    in >> s;
    reverse(s.begin(), s.end());

    I comma = s.find(',');
    for(I i = 0; i < s.size(); ++i) {
        if(s[i] == ',') continue;
        o.digits[]
    }

    return in;
}
ostream &operator<<(ostream &out, const num &o) {
    for(I i = o.ndigits - 1; i >= 0; --i) {
        out << o.digits[i] << ' ';
        if(i == o.comma) {
            out << ". ";
        }
    }

    return out;
}

int main()
{
    num n;
    cin >> n;

    cout << n << endl;
    return 0;
}
