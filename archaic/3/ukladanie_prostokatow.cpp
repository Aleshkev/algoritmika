#include <bits/stdc++.h>

using namespace std;

typedef long long int I;

bool is_prime(I x) {
    for(I i = 2; i * i <= x; ++i) {
        if(x % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    I x;
    while(cin >> x) {
        if(x == 0) {
            break;
        }

        cout << (x % 2 == 0 || is_prime(x - 2) ? "T" : "N") << '\n';
    }

    return 0;
}
