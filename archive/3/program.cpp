#include <bits/stdc++.h>

using namespace std;

typedef long int I;

int main()
{
    I n;
    cin >> n;

    static char s[1000000 + 1];
    cin >> s;

    bool ok = true;
    I max_level = 0;

    vector<char> needed;
    for(I i = 0; i < n; ++i) {
             if(s[i] == '(') needed.push_back(')');
        else if(s[i] == '[') needed.push_back(']');
        else if(s[i] == '{') needed.push_back('}');
        else {
            if(needed.empty() || s[i] != needed.back()) {
                ok = false;
                break;
            } else {
                max_level = max(max_level, (I)needed.size());
                needed.pop_back();
            }
        }
    }
    if(!needed.empty()) {
        ok = false;
    }

    if(ok) {
        cout << max_level << '\n';
    } else {
        cout << "NIE\n";
    }

    return 0;
}
