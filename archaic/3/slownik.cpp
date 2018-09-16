#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);

    set<string> strings;
    for(;;) {
        string s;
        cin >> s;
        strings.insert(s);
        if(s == "prrr") {
            break;
        }
    }
    cout << strings.size() << '\n';

    return 0;
}
