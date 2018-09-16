#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long int I;

int main()
{
    cout.sync_with_stdio(false);

    I n;
    cin >> n;

    I *prices = new I[n];
    for(I i = 0; i < n; ++i) {
        cin >> prices[i];
    }

    I *a = new I[n];  // O ile zwiększy się cena w (i + 1)
    a[n - 1] = 0;
    for(I i = 0; i < n - 1; ++i)
        cin >> a[i];

    I *b = new I[n];  // O ile zwiększy się cena w (i - 1)
    b[n - 1] = 0;
    for(I i = 0; i < n - 1; ++i)
        cin >> b[i];

    vector<I> *children = new vector<I>[n];  // Dla każdego wierzchołka, wierzchołki niżej w sortowaniu
    I *numparents = new I[n];
    fill(numparents, numparents + n, 0);

    for(I i = 0; i < n - 1; ++i) {
        I j = i + 1;
        if(a[i] <= b[i]) {
            children[i].push_back(j);
            ++numparents[j];
        } else {
            children[j].push_back(i);
            ++numparents[i];
        }
    }

    vector<I> order;
    order.reserve(n);

    for(I i = 0; i < n; ++i) {
        if(numparents[i] == 0) {
            order.push_back(i);
        }
    }

    for(I order_i = 0; order_i < n; ++order_i) {
        I i = order[order_i];

        for(I j = 0; j < children[i].size(); ++j) {
            I child = children[i][j];
            --numparents[child];
            if(numparents[child] == 0) {
                order.push_back(child);
            }
        }
    }

    I total_price = 0;
    for(I i = 0; i < n; ++i) {
        I j = order[i];
        total_price += prices[j];
        if(j < n - 1) {
            prices[j + 1] += a[j];
        }
        if(j > 0) {
            prices[j - 1] += b[j - 1];
        }
    }

    cout << total_price << '\n';

    for(I i = 0; i < order.size(); ++i) {
        cout << order[i] + 1 << ' ';
    } cout << '\n';

    return 0;
}
