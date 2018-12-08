#include <bits/stdc++.h>

using namespace std;

typedef long long int I;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    I c, w;
    cin >> c >> w;

    //vector<I> t;
    //t.push_back(c);
    I last = c;
    I r = 0;
    for(I i = 1; ; ++i) {
        I current = last * w + r % 10;
        r /= 10;
        r += current / 10;
        current %= 10;
        if(current == c && r == 0) {
            cout << i << '\n';
            break;
        }
        last = current;
    }

    //for(I i = t.size() - 1; i >= 0; --i) cout << t[i] << ' '; cout << '\n';


    return 0;
}
