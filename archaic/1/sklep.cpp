#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef unsigned U;

int main()
{
    cout.sync_with_stdio(false);

    U n;
    cin >> n;

    map<U, U> items;
    vector<U> order;

    for(U i = 0; i < n; ++i) {
        U a, k;
        cin >> a >> k;

        if(items.find(a) == items.end()) {
            items[a] = k;
            order.push_back(a);
        } else {
            items[a] += k;
        }
    }

    U m = order.size();
    cout << m << '\n';

    for(U i = 0; i < m; ++i) {
        cout << order[i] << ' ' << items[order[i]] << '\n';
    }

    return 0;
}
