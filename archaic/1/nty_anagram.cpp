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
    for(I i = 0; i < n - 1; ++i) {
        next_permutation(s.begin(), s.end());
    }

    cout << s << endl;

    return 0;
}
