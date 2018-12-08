#include <bits/stdc++.h>

using namespace std;

typedef long long int I;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    I n;
    cin >> n;

    /*vector<bool> is_prime(n + 1, true);
    for(I i = 2; i < n; ++i) {
        if(!is_prime[i]) {
            continue;
        }
        for(I j = i * i; j <= n; j += i) {
            is_prime[j] = false;
        }
        cout << i <<
    }

    //for(I i = 1; i <= n; ++i) cout << setw(2) << i << ' '; cout << '\n';
    //for(I i = 1; i <= n; ++i) cout << setw(2) << (is_prime[i] ? 'X' : '.') << ' '; cout << '\n';

    I best_i = 1, best_j = 0;

    for(I i = 1; i <= n; ++i) {
        if(is_prime[i]) {
            continue;
        }

        I j = i;
        while(j <= n && !is_prime[j]) {
            ++j;
        }
        --j;

        if(j - i > best_j - best_i) {
            best_i = i;
            best_j = j;
            cout << best_i << ", " << best_j << ", \n";
            //cout << best_i << ":" << best_j << " (" << best_j - best_i + 1 << ")\n";
        }

        i = j + 1;
    }*/

    const vector<I> r = {
        4, 4,
        8, 10,
        24, 28,
        90, 96,
        114, 126,
        524, 540,
        888, 906,
        1130, 1150,
        1328, 1360,
        9552, 9586,
        15684, 15726,
        19610, 19660,
        31398, 31468,
        155922, 156006,
        360654, 360748,
        370262, 370372,
        492114, 492226,
        1349534, 1349650,
        1357202, 1357332,
        2010734, 2010880,
        4652354, 4652506,
        17051708, 17051886,
        20831324, 20831532,
        47326694, 47326912,
        122164748, 122164968,
        189695660, 189695892,
        191912784, 191913030
    };

    I best_i = 1, best_j = 0;
    for(I i = 0; i < r.size(); i += 2) {
        if(r[i] <= n) {
            I j = min(n, r[i + 1]);
            if(j - r[i] > best_j - best_i) {
                best_i = r[i];
                best_j = j;
            }
        }

    }

    cout << best_i << ' ' << best_j << '\n';

    return 0;
}
