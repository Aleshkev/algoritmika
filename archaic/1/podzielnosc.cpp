#include <iostream>
#include <algorithm>

using namespace std;

//typedef unsigned SU;  // < 1 000 000, uzywane raczej niekonsekwentnie, tylko aby zaoszczedzic miejsce w tablicy
typedef long long unsigned U;  // To z kolei jest uzywane wszedzie indziej na wszelki wypadek

int main()
{
    cout.sync_with_stdio(false);

    U b, q;  // Podstawa systemu, ilosc zapytan
    cin >> b >> q;

    U sum = 0;  // Suma wszystkich cyfr

    U *begins = new U[b];
    U *ends = new U[b];
    for(U i = 0; i < b; ++i) {
        U c;  // Ilosc cyfr
        cin >> c;

        begins[i] = i > 0  ?  ends[i - 1]  :  0;
        ends[i] = begins[i] + c;

        sum += i * c;
    }

    U mod = sum % (b - 1);
    if(mod != 0) {
        --ends[mod];
        for(U i = mod + 1; i < b; ++i) {
            --begins[i];
            --ends[i];
        }
    }

    U len = ends[b - 1];  // Ilosc cyfr w liczbie

    /*  // Wypisuje liczbe(od konca)
    for(U i  = 0; i < b; ++i) {
        for(U j = 0; j < ends[i] - begins[i]; ++j) {
            cout << i;
        }
    } cout << endl;  */

    for(U i = 0; i < q; ++i) {
        U d;  // Numer cyfry (od konca, wlaczajac zero)
        cin >> d;

        if(d < len) {
            cout << upper_bound(begins, begins + b, d) - begins - 1 << '\n';
        } else {
            cout << "-1" << '\n';
        }
    }

    cout.flush();

    return 0;
}
