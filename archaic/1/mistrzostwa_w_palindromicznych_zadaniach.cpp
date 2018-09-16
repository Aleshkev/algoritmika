#include <iostream>
#include <string>

using namespace std;

typedef long long int I;

int main()
{
    I n, k;
    cin >> n >> k;

    string s;
    s.resize(n, ' ');

    char ch = 'a';
    for(I i = n / 2; i >= 0 && ch < 'a' + k; --i) {
        s[i] = ch;
        ++ch;
    }
    for(I i = n / 2 + 1; ch < 'a' + k; ++i) {
        s[i] = ch;
        ++ch;
    }
    --ch;

    for(I i = 0;  i < n; ++i) {
        if(s[i] == ' ') {
            s[i] = ch;
        }
    }

    cout << s << '\n';

    return 0;
}
