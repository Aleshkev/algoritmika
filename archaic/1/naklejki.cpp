#include <iostream>
#include <string>

using namespace std;

typedef int I;

int main()
{
    cout.sync_with_stdio(false);

    I n, m; cin >> n >> m;
    static char s[100001]; cin >> s;

    static I d[100000], t[100000];
    fill(d, d + n, -1); fill(t, t + n, -1);

    for(I i = 0; i < m; ++i) {
        I p, l; cin >> p >> l; --p; --l;
        d[l] = l - p;
        t[l] = i;
    }

    I shift = 0, max_t = -1;
    for(I i = 0; i < n; ++i) {
        if(t[i] > max_t) {
            shift = d[i];
            max_t = t[i];
        }
        s[i] = s[i - shift];
    }

    cout << s << '\n';

    return 0;
}
