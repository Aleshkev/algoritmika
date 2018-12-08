#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main()
{
    const I max_n = 5e5;
    static char s[max_n + 1];
    cin >> s;
    I n = strlen(s);

    I nchar[26] = {0};
    for(I i = 0; i < n; ++i) {
        ++nchar[s[i] - 'a'];
    }

    I nunique = 0;
    for(I i = 0; i < 26; ++i) {
        nunique += (nchar[i] > 0);
    }

    sort(nchar, nchar + 26, greater<I>());

    I ncharprefix[26];
    partial_sum(nchar, nchar + 26, ncharprefix);

    for(I i = 0; i < 26; ++i) {
        cout << n - ncharprefix[i] << ' ';
        if(ncharprefix[i] == n) {
            break;
        }
    } cout << '\n';


    return 0;
}
