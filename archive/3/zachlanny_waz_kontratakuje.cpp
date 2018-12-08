#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    I h, w;
    cin >> h >> w;

    static I t[10000] = {0};

    cin >> t[0];
    for(I x = 1; x < w; ++x) {
        cin >> t[x];
        t[x] += t[x - 1];
    }

    //cout << "---" << endl;

    //for(I x = 0; x < w; ++x) cout << setw(3) << t[x] << ' '; cout << '\n';

    for(I y = 1; y < h; ++y) {
        I e;
        cin >> e;
        t[0] = t[0] + e;
        for(I x = 1; x < w; ++x) {
            cin >> e;
            t[x] = e + max(t[x - 1], t[x]);
        }

        //for(I x = 0; x < w; ++x) cout << setw(3) << t[x] << ' '; cout << '\n';
    }

    cout << t[w - 1] << '\n';

    return 0;
}
