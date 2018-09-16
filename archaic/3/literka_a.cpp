#include <bits/stdc++.h>

using namespace std;

typedef long int I;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);

    I n;
    cin >> n;

    string s;
    cin >> s;

    I best_len = 0, best_pos;
    for(I i = 0; i < n; ++i) {
        if(s[i] == 'a') {
            I start = i - 1, stop = i + 1;
            while(start >= 0 && s[start] != 'a') --start;
            while(stop < n && s[stop] != 'a') ++stop;
            //cout << start << " " << stop << endl;

            I len = stop - start - 1;
            if(len > best_len) {
                best_len = len;
                best_pos = start + 1;
            }
        }
    }

    cout << best_len << '\n';
    for(I i = 0; i < best_len; ++i) {
        cout << s[best_pos + i];
    } cout << '\n';

    return 0;
}
