#include <bits/stdc++.h>

using namespace std;

typedef long long int I;

int main()
{
    I a, b;
    cin >> a >> b;

    string s;

    {
        stringstream ss;
        ss << a * b;
        s = ss.str();
    }

    for(I i = 0; i < s.size(); ++i) {
        cout << s[i];
        if(i < s.size() - 1) {
            cout << '-';
        }
    } cout << '\n';


    return 0;
}
