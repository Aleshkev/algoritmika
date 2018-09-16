#include <bits/stdc++.h>

using namespace std;

typedef long long int I;
const I lim = 1e9 + 9;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    I n;
    cin >> n;

    vector<I> last_component(n + 1);
    fill(last_component.begin(), last_component.end(), -1);
    for(I i = 2; i < n; ++i) {
        if(last_component[i] != -1) {
            continue;
        }
        for(I j = i * i; j <= n; j += i) {
            last_component[j] = i;
        }
    }
    //for(I i = 1; i <= n; ++i) cout << setw(2) << i << ' '; cout << '\n';
    //for(I i = 1; i <= n; ++i) cout << setw(2) << number_came_from[i] << ' '; cout << '\n';

    /*for(;;) {
        I x;
        cin >> x;

        while(number_came_from[x] != -1) {
            cout << number_came_from[x] << ' ';
            x /= number_came_from[x];
        } cout << x << '\n';
    }*/

    vector<I> t(n);
    for(I i = 0; i < n; ++i) {
        cin >> t[i];
        --t[i];
    }

    vector<I> times_used(n + 1);

    vector<bool> visited(n);
    for(I i = 0; i < n; ++i) {
        if(visited[i]) {
            continue;
        }

        I first = i, current = t[i], loop_size = 1;
        while(current != first) {
            visited[current] = true;
            current = t[current];
            ++loop_size;
        }

        vector<I> primes;
        I x = loop_size;
        while(last_component[x] != -1) {
            primes.push_back(last_component[x]);
            x /= last_component[x];
        }
        primes.push_back(x);
        sort(primes.begin(), primes.end());

        for(I j = 0; j < primes.size();) {
            I m = 1;
            while(j + m < primes.size() && primes[j + m] == primes[j]) ++m;
            times_used[primes[j]] = max(times_used[primes[j]], m);
            j += m;
        }
    }

    I c = 1;
    for(I i = 1; i <= n; ++i) {
        for(I j = 1; j <= times_used[i]; ++j) {
            c *= i;
            c %= lim;
        }
    }

    cout << c << '\n';

    //cout.flush();
    //_Exit(0);

    return 0;
}
