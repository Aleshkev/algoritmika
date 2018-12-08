#include <iostream>

using namespace std;

typedef long long int I;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    I n; cin >> n;

    static I t[500000];
    for(I i = 0; i < n; ++i) {
        cin >> t[i];
    }

    static I u[500000];
    u[0] = -1;
    for(I i = 1; i < n; ++i) {
        u[i] = i - 1;
        while(u[i] != -1 && t[u[i]] < t[i]) {
            u[i] = u[u[i]];
        }
    }
    static I v[500000];
    v[n - 1] = n;
    for(I i = n - 1 - 1; i >= 0; --i) {
        v[i] = i + 1;
        while(v[i] != n && t[v[i]] <= t[i]) {
            v[i] = v[v[i]];
        }
    }

    I c = 0;
    for(I i = 0; i < n; ++i) {
        c += (i - u[i]) * (v[i] - i) * t[i];
    }

    cout << c << '\n';

    return 0;
}
