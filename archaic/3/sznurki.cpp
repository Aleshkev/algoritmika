#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    I n, k;
    cin >> n >> k;

    I complete = 0;
    I current = 0;
    for(I i = 0; i < n; ++i) {
        I x;
        cin >> x;

        current += x;
        if(current >= k) {
            ++complete;
            current = 0;
        }
    }

    cout << complete << '\n';



    return 0;
}
