#include <bits/stdc++.h>

using namespace std;

typedef int I;

int main()
{
    string s; cin >> s;

    I n = s.size();

    next_permutation(s.begin(), s.begin() + n / 2);

    for(I i = 0; i < n / 2; ++i) {
        s[n - i - 1] = s[i];
    }

    cout << s << endl;

    return 0;
}
