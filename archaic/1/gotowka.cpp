#include <iostream>
#include <algorithm>

using namespace std;

typedef long long unsigned U;
typedef long long int I;

U c = 0;

void per(I *t, U n, U i = 0) {
    if(i == n - 1) {

        I balance = 0;
        bool ok = true;
        for(U j = 0; j < n; ++j) {
            balance += t[j];
            if(balance < 0) {
                ok = false;
                break;
            }
        }
        if(ok) {
            ++c;
        }

    } else {
        for(U j = i; j < n; ++j) {
            swap(t[i], t[j]);
            per(t, n, i + 1);
            swap(t[i], t[j]);
        }
    }

}

int main()
{
    U n;
    cin >> n;

    I *t = new I[n];
    for(U i = 0; i < n; ++i) {
        cin >> t[i];
    }

    per(t, n);

    cout << c << '\n';

    return 0;
}
