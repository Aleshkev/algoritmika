#include <iostream>

using namespace std;

typedef int I;

int main()
{
    I n, l; cin >> n >> l;

    I fertilizers[10] = {0};
    I needed_any = 0;

    for(I i = 0; i < l; ++i) {
        char plant;
        cin >> plant;
        if(plant == 'D') {
            ++needed_any;
        } else {
            plant -= '1';
            --fertilizers[plant];
        }
    }

    I any_fertilizers = 0;
    for(I i = 0; i < n; ++i) {
        I c; cin >> c;
        fertilizers[i] += c;
        if(fertilizers[i] < 0) {
            cout << "NIE\n"; return 0;
        } else {
            any_fertilizers += fertilizers[i];
        }
    }

    if(needed_any > any_fertilizers) {
        cout << "NIE\n"; return 0;
    }

    cout << "TAK\n";
    return 0;
}
