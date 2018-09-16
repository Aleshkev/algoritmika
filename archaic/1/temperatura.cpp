#include <iostream>

using namespace std;

typedef long long int I;
const I inf = 1e18;

int main()
{
    cout.sync_with_stdio(false);

    I n; cin >> n;

    static I dol[1000001], gor[1000001];
    for(I i = 0; i < n; ++i) {
        cin >> dol[i] >> gor[i];
    }
    dol[n] = gor[n] = -inf;

    static I stck[1000001];
    I sb = 0, se = 0;

    I max_c = 1;

    I start = 0;
    for(I i = 0; i <= n; ++i) {

        /*cout << se << endl;

        cout << "> ";
        for(I j = 0; j <= 10; ++j) {
            if(j == sb) cout << "[";
            cout << dol[stck[j]] << " ";
            if(j == se - 1) cout << "]";
        } cout << endl;*/

        // Zjadanie elementów o mniejszych dołach od obecnego z końca stosu
        while(se > sb && dol[stck[se - 1]] <= dol[i]) {
            --se;
        }
        // Dodanie obecnego elementu na koniec stosu
        stck[se] = i;
        ++se;

        I max_dol = se > sb ? dol[stck[sb]] : -inf;
        //cout << max_dol << ": ";

        if(gor[i] < max_dol) {
            I c = i - start;
            if(c > max_c) max_c = c;

            // Znajdowanie nowego `start` i `max_dol`

            // Usuwanie
            while(sb < se && dol[stck[sb]] > gor[i]) {
                ++sb;
            }
            //cout << sb << ":" << se << endl;
            start = sb > 0 ? stck[sb - 1] + 1 : 0;

            /*max_dol = -inf;
            for(I j = i; j != -1; j = u[j]) {
                if(dol[j] > gor[i]) {
                    start = j + 1;
                    break;
                }
                if(dol[j] > max_dol) max_dol = dol[j];
            }*/



        }

        /*for(I j = 0; j <= 10; ++j) {
            if(j == sb) cout << "[";
            cout << stck[j] << " ";
            if(j == se - 1) cout << "]";
        } cout << endl;*/
    }

    cout << max_c << '\n';

    return 0;
}
