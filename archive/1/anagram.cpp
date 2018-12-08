#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef int I;

int main()
{
    cout.sync_with_stdio(false);

    string s; cin >> s;
    I n; cin >> n;
    sort(s.begin(), s.end());

    for(I i = 0; i < n; ++i) {
        string x; cin >> x;
        if(x.size() != s.size()) {
            cout << "NIE" << '\n';
            continue;
        }
        sort(x.begin(), x.end());
        cout << (x == s ? "TAK" : "NIE") << '\n';
    }

    return 0;
}
