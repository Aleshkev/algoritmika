#include <iostream>
#include <vector>

using namespace std;


typedef long long unsigned U;


typedef unsigned u;
struct BigU {
    vector<u> digits;

    BigU &operator+=(const BigU &other) {
        reserve_digits(other.digits.size());

        for(U i = 0; i < other.digits.size(); ++i) {
            digits[i] += other.digits[i];
            while(digits[i] >= 10) {
                reserve_digits(i + 1 + 1);

                ++digits[i + 1];
                digits[i] -= 10;
            }
        }

        return *this;
    }

private:
    void reserve_digits(U n) {
        if(digits.size() < n) {
            digits.resize(n, 0);
        }
    }
};



ostream &operator<<(ostream &o, const BigU &bigu) {
    for(U i = bigu.digits.size(); i-- > 0; ) {
        cout << bigu.digits[i];
    }
    return o;
}

istream &operator>>(istream &stream, BigU &bigu) {
    string s;
    stream >> s;

    bigu.digits.clear();

    for(U i = s.size(); i-- > 0; ) {
        bigu.digits.push_back(s[i] - '0');
    }

    return stream;
}

int main()
{
    U n;
    cin >> n;

    BigU c;

    for(U i = 0; i < n; ++i) {
        BigU a;
        cin >> a;
        c += a;
    }

    cout << c;

    return 0;
}
