#include <bits/stdc++.h>

using namespace std;

typedef uintmax_t I;
typedef pair<I, I> II;

bool cmp(II a, II b) {
    return (a.first != b.first ? a.first > b.first : a.second < b.second);
}

int main()
{
    I lamp_width, nproducents, nlamps;
    cin >> lamp_width >> nproducents >> nlamps;

    vector<II> bad_bulbs(nproducents);
    for(I i = 0; i < nproducents; ++i) {
        bad_bulbs[i].second = i;
    }

    for(I i = 0; i < nlamps; ++i) {
        I lamp_state, ibulb, iproducent;
        cin >> lamp_state >> ibulb >> iproducent;
        ibulb = lamp_width - ibulb - 1; --iproducent;

        if(!(lamp_state & (1 << ibulb))) {
            //cout << "wrong, " << iproducent << '\n';
            ++bad_bulbs[iproducent].first;
        }
    }


    sort(bad_bulbs.begin(), bad_bulbs.end(), cmp);
    //for(I i = 0; i < nproducents; ++i) cout << bad_bulbs[i].first << ' '; cout << '\n';
    //for(I i = 0; i < nproducents; ++i) cout << bad_bulbs[i].second << ' '; cout << '\n';

    for(I i = 0; i < min((I)10, nproducents); ++i) {
        cout << bad_bulbs[i].second + 1 << ' ';
    } cout << '\n';

    return 0;
}
