#include <bits/stdc++.h>

using namespace std;

typedef long int I;

int main()
{
    I n, m;
    scanf("%li %li", &n, &m);

    static vector<I> stations[1000000];
    for(I i = 0; i < m; ++i) {
        I j, x;
        scanf("%li %li", &j, &x);
        --j;

        stations[j].push_back(x);
    }

    for(I i = 0; i < n; ++i) {
        vector<I> &s = stations[i];

        if(s.empty()) {
            cout << "STACJA KAPUT\n";
            continue;
        }

        sort(s.begin(), s.end());

        printf("Min %li Max %li Sre %li Med %li ", s.front(), s.back(),
               accumulate(s.begin(), s.end(), 0) / s.size(),
               s.size() % 2 == 0 ? (s[s.size() / 2 - 1] + s[s.size() / 2]) / 2 : s[s.size() / 2]);

        for(I i = 0; i < s.size(); ++i) {
            printf("%li ", s[i]);
        } printf("\n");
    }

    return 0;
}
