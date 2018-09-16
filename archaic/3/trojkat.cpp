#include <bits/stdc++.h>

using namespace std;

typedef long long int I;

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);

    I n;
    cin >> n;

    vector<I> t(n);
    for(I i = 0; i < n; ++i) {
        cin >> t[i];
    }
    vector<I> u(n + 1);
    u[0] = 0;
    for(I i = 0; i < n; ++i) {
        u[i + 1] = u[i] + t[i];
    }

    I s = u[n];

    I x = 0, y = 0, z = 0;

    for(I i = 1; i <= n - 2; ++i) {
        I a = u[i];
        if(a >= s - a) {
            break;
        }
        for(I j = i + 1; j <= n - 1; ++j) {
            I b = u[j] - u[i];
            I c = u[n] - u[j];

            I max_abc = max(max(a, b), c);

            if(s > 2 * max_abc) {
                ++x;
            }
            if(u[n] / 2 - a < b && b < s / 2) {
                ++y;
            }

            cout << i << ":" << j << ": a=" << setw(2) << a << " b=" << setw(2) << b << " c=" << setw(2) << c << " ";
            cout << (u[n] / 2 - a) << " < " << b << " < " << s / 2 << " -> " << (u[n] / 2 - a < b && b < s / 2) << endl;
        }

        z += distance(upper_bound(&u[i + 1], &u[n], u[i] + s / 2 - a), upper_bound(&u[i + 1], &u[n], u[i] + s / 2));
    }

    cout << x << '\n';
    cout << x << " " << y << " " << z << '\n';;


    return 0;
}
