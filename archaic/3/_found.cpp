#include <bits/stdc++.h>

using namespace std;

typedef long long I;

const I maxa = 1500;

int main()
{
    I m;
    cin >> m;

    for(I q = 0; q < m; ++q) {
        I n;
        cin >> n;

        vector<I> divisible(maxa + 1), indivisible(maxa + 1);

        for(I i = 0; i < n; ++i) {
            I x;
            cin >> x;
            ++indivisible[x];
        }

        bool ok = true;
        for(I i = 0; ; ++i) {
            if(divisible[i] + indivisible[i] == 0) {
                break;
            }

            if((indivisible[i] + divisible[i]) % 2 == 1) {
                if(divisible[i] % 2 == 1) {
                    --divisible[i];
                } else {
                    if(divisible[i] >= 2) {
                        divisible[i] -= 1;
                        divisible[i] -= 2;
                    } else {
                        ok = false;
                        break;
                    }
                }
            }
            divisible[i + 1] += (indivisible[i] + divisible[i]) / 2;
        }

        /*for(I i = 0; i < 10; ++i) {
            cout << indivisible[i] << ' ' << divisible[i] << '\n';
        }*/
        cout << (ok ? "TAK" : "NIE") << '\n';

    }

    return 0;
}
