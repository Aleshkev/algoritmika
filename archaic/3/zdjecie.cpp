#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

I n, rows, len;
I t[200000];

bool is_ok(I x) {
    I rows_found = 0;
    for(I i = 0; i < n - len + 1; ++i) {
        if(t[i + len - 1] - t[i] <= x) {
            ++rows_found;
            i += len - 1;
        }
    }
    /*cout << "is_ok(" << x << ") -> " << rows_found << " (" << (rows_found >= rows ? "true" : "false") << ")\n "; for(I i = 0; i < n; ++i) cout << setw(2) << t[i] << ' '; cout << "\n ";
    rows_found = 0;
    for(I i = 0; i <= n - len + 1; ++i) {
        if(t[i + len - 1] - t[i] <= x) {
            ++rows_found;
            i += len;

            for(I j = 0; j < len; ++j) cout << setw(2) << char('A' + rows_found - 1) << ' '; continue;
        }
        cout << "   ";
    }
    cout << '\n';*/
    return rows_found >= rows;
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> rows >> len;

    for(I i = 0; i < n; ++i) {
        cin >> t[i];
    }
    sort(t, t + n);

    I lo = 0, hi = 1e9;
    while(lo < hi) {
        I mid = (lo + hi) / 2;
        bool ok = is_ok(mid);

        if(ok) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    cout << lo << '\n';

    return 0;
}
