#include <iostream>

using namespace std;

typedef long long int I;

const I inf = 3e18;

int main()
{
    cout.sync_with_stdio(false);

    I n;
    cin >> n;
    I m = n + 1;

    I *durabilities = new I[m], *weights = new I[m], *parents = new I[m];

    for(I i = 1; i < m; ++i) {
        I durability, weight, parent;
        cin >> durability >> weight >> parent;
        durabilities[i] = durability; parents[i] = parent;
        weights[i] = 0;  // incremented in loop below

        for(I j = i; j != 0; j = parents[j]) {
            weights[j] += weight;

            if(weights[j] > durabilities[j]) {
                cout << i << '\n';
                return 0;
            }
        }
    }

    cout << "NIE\n";

    return 0;
}
