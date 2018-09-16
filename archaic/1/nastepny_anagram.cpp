#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

typedef int I;

int main()
{
    cout.sync_with_stdio(false);

    string s; cin >> s;
    I n = s.size();

    /*next_permutation(s.begin(), s.end());
    cout << s << endl;
    prev_permutation(s.begin(), s.end());
    cout << s << endl;*/

    bool any = false;
    for(I i = n - 2; i >= 0; --i) {
        if(s[i] < s[i + 1]) {
            I k;
            for(k = n - 1; s[i] >= s[k]; --k);
            swap(s[i], s[k]);
            sort(s.begin() + i + 1, s.end());
            any = true;
            break;
        }
    }
    if(!any) {
        sort(s.begin(), s.end());
    }

    cout << s << '\n';

    return 0;
}
