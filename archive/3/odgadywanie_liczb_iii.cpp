#include <bits/stdc++.h>

using namespace std;

typedef long int I;

pair<bool, string> div11(const string &in) {
    I n = in.size();
    I out[210] = {0}, rest[210] = {0};
    rest[0] = in[0] - '0';
    for(I i = 1; i < n; ++i) {
        rest[i] = rest[i - 1] * 10 + (in[i] - '0');
        out[i] = rest[i] / 11;
        rest[i] %= 11;
    }
    stringstream s;
    I i = 0;
    while(out[i] == 0) ++i;
    for(; i < n; ++i) {
        s << out[i];
    }
    return make_pair(rest[n - 1] == 0, s.str());
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    I x = s.find('X');

    for(I i = 0; i < 10; ++i) {
        s[x] = '0' + i;
        pair<bool, string> r = div11(s);
        if(r.first) {
            cout << r.second << '\n';
            break;
        }

    }

    return 0;
}
