#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    I n;
    cin >> n;

    I c_l = 0, c_r = 0;
    I l = 0, r = 0;

    char str[1000000];
    cin >> str;

    //I n = strlen(str);

    for(I i = 0; i < n; ++i) {
        l += (str[i] == '(');
        r += (str[i] == ')');

        c_l += max((I)0, r - l);
        l += max((I)0, r - l);
    }
    c_r = max((I)0, l - r);
    cout << c_l << ' ' << c_r << '\n';

    return 0;
}
