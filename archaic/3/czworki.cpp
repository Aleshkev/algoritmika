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

    vector<I> t(n);
    for(I i = 0; i < n; ++i) {
        cin >> t[i];
    }
    sort(t.begin(), t.end());

    vector<int16_t> diff_reachable(500000 + 1);

    //vector<I> diffs;
    for(I i = 0; i < n; ++i) {
        for(I j = i; j < n; ++j) {
            ++diff_reachable[t[j] - t[i]];
            //diffs.push_back(t[j] - t[i]);
        }
    }
    //diffs.push_back(0);
    //sort(diffs.begin(), diffs.end());

    I c = 0;
    for(I i = 0; i < n; ++i) {
        for(I j = 0; j < n; ++j) {
            if(t[i] + t[j] <= 500000) {
                c += diff_reachable[t[i] + t[j]];
            }
        }
    }

    cout << c << '\n';


    return 0;
}
