#include <iostream>
#include <algorithm>

using namespace std;

typedef int I;
const I inf = 1e9;
typedef pair<I, I> II;

int main()
{
    cout.sync_with_stdio(false);
    cout.tie(0);

    I n; cin >> n;

    static I w[1000000];
    for(I i = 0; i < n; ++i) {
        cin >> w[i];
    }

    static II v[1000000];
    for(I i = 0; i < n; ++i) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v, v + n);

    I c = 0;
    I last = -inf;
    for(I i = n - 1; i >= 0; --i) {
        I current = lower_bound(v, v + n, II(w[i], 0))->second;
        if(current < last) {
            ++c;
        }
        last = current;
    }
    if(last != 0) {
        ++c;
    }

    cout << c << endl;


    return 0;
}
