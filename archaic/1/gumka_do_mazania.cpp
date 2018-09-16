#include <bits/stdc++.h>

using namespace std;

typedef long long int I;
const I inf = 1e18;

int main()
{
    cout.sync_with_stdio(false);
    I n; cin >> n;

    static string strings[10000];
    static I string_begin[10000], string_size[10000];
    for(I i = 0; i < n; ++i) {
        cin >> strings[i];
        string_begin[i] = 0;
        string_size[i] = strings[i].size();
    }

    string r;

    for(char ch = 'z'; ch >= 'a'; --ch) {
        I min_c = inf;
        for(I i = 0; i < n; ++i) {
            I c = 0;
            for(I j = string_begin[i]; j < string_size[i]; ++j) {
                if(strings[i][j] == ch) ++c;
            }
            min_c = min(c, min_c);
            if(min_c == 0) break;
        }

        for(I i = 0; i < n; ++i) {
            for(I j = string_begin[i], c = min_c; c > 0; ++j) {
                if(strings[i][j] == ch) {
                    string_begin[i] = j + 1;
                    --c;
                }
            }
        }

        for(I i = 0; i < min_c; ++i) {
            r += ch;
        }
    }

    if(r < "bitek") r = "bitek";

    cout << r << endl;

    return 0;
}
