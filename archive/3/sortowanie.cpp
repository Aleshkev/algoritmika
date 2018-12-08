#include <bits/stdc++.h>

using namespace std;

typedef int I;

int main()
{
    I n;
    cin >> n;

    vector<pair<I, string> > t(n);
    for(I i = 0; i < n; ++i) {
        cin >> t[i].second;
        t[i].first = t[i].second.size();
    }
    sort(t.begin(), t.end());

    for(I i = 0; i < n; ++i) {
        cout << t[i].second << '\n';
    }

    return 0;
}
