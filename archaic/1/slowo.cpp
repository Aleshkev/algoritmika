#include <iostream>

using namespace std;

typedef long long int I;

int main()
{
    I n, m;
    cin >> n >> m;

    const I sz = 'z' - 'a';

    I **t = new I*[sz];
    for(I i = 0; i < sz; ++i) {
        t[i] = new I[n + 1];
        fill(t[i], t[i] + n + 1, 0);
    }

    for(I i = 1; i <= n; ++i) {
        char c;
        cin >> c;

        if(i > 0) {
            for(I j = 0; j < sz; ++j) {
                t[j][i] = t[j][i - 1];
            }
        }

        ++t[c - 'a'][i];
    }

    for(I i = 0; i < m; ++i) {
        I a, b;
        cin >> a >> b;
        --a;

        I c = 0;
        for(I j = 0; j < sz; ++j) {
            if(t[j][b] - t[j][a] > 0) {
                ++c;
            }
        }
        cout << c << '\n';
    }

    return 0;
}
