#include <bits/stdc++.h>

using namespace std;

typedef int I;
const I inf = 1e9;

int main()
{
    I n;
    scanf("%i", &n);

    static I t[1000000];
    for(I i = 0; i < n; ++i) {
        scanf("%i", &t[i]);
    }

    vector<pair<I, I> > u;

    I m;
    scanf("%i", &m);

    for(I i = 0; i < m; ++i) {
        I a, b;
        scanf("%i %i", &a, &b);
        u.push_back(make_pair(a, 1));
        u.push_back(make_pair(b + 1, -1));
    }
    u.push_back(make_pair(0, 0));

    sort(u.begin(), u.end());

    /*for(I i = 0; i < u.size(); ++i) {
        cout << u[i].first << ": " << u[i].second << endl;
    }*/

    I c = 0;
    for(I i = 0; i < u.size(); ++i) {
        c += u[i].second;
        u[i].second = c;
    }

    for(I i = 0; i < n; ++i) {
        I j = upper_bound(u.begin(), u.end(), make_pair(t[i], inf)) - u.begin();
        printf("%i\n", u[j - 1].second);
    }

    return 0;
}
