#include <iostream>
#include <map>

using namespace std;

typedef long long int I;

int main()
{
    cout.sync_with_stdio(false);

    I n, m;
    cin >> n >> m;

    I *t = new I[n];
    for(I i = 0; i < n; ++i) {
        cin >> t[i];
    }

    for(I i = 0; i < m; ++i) {
        I k;
        cin >> k;

        map<I, I> u;

        I colors = 0;
        I first = 0, last = 0;
        I c = 0;

        while(first < n) {
            while(colors < k && last < n) {
                if(u.find(t[last]) == u.end()) {
                    ++colors;
                    u.insert(pair<I, I>(t[last], 0));
                }
                ++u[t[last]];

                ++last;

                while(last < n && u.find(t[last]) != u.end()) {
                    ++u[t[last]];
                    ++last;
                }
            }

            I len = last - first;
            c += len;

            if(--u[t[first]] == 0) {
                u.erase(t[first]);

                --colors;
            }

            ++first;
        }

        cout << c << '\n';

    }

    return 0;
}
