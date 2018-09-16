//#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long unsigned U;

int main()
{
    /*
    cout.sync_with_stdio(false);

    U _;
    cin >> _;

    string a, b;
    cin >> a >> b;

    U n;
    cin >> n;

    for(U i = 0; i < n; ++i) {
        U ai, bi;
        cin >> ai >> bi;

        swap(a[ai], b[bi]);

        int eq = a.compare(b);
        cout << (eq == 0 ? '0' :
                 eq > 0  ? '1' :
                           '2') << '\n';
    }*/

    U _;
    scanf("%llu", &_);

    const U maxlen = 1e6 + 1;
    char a[maxlen], b[maxlen];
    scanf("%s %s", a, b);

    U n;
    scanf("%llu", &n);

    for(U i = 0; i < n; ++i) {
        U ai, bi;
        scanf("%llu %llu", &ai, &bi);

        U t = a[ai]; a[ai] = b[bi]; b[bi] = t;

        int eq = strcmp(a, b);
        printf("%c\n", (eq == 0 ? '0' :
                      eq > 0 ? '1' :
                          '2'));
    }


    return 0;
}
