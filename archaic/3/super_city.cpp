#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
typedef pair<I, I> II;

bool is_valid(I x, const vector<II> &v) {
    if(x == 0) {
        return false;
    }

    map<I, bool> m;
    m[0] = m[x] = true;
    for(II p : v) {
        if(p.first + p.second == x) {
            m[p.first] = true;
        }
    }

    for(II p : v) {
        const I a = p.first, b = p.second;
        const I lt = (x + a - b) / 2;
        const I rt = (x + b - a) / 2;
        if(lt != x - rt || !m[lt]) {
            return false;
        }
    }

    return true;
}

int main()
{
    I n;
    cin >> n;

    vector<II> v;
    v.resize(n);
    for(I i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());

    const I a = v[0].first, b = v[0].second;
    if(is_valid(abs(a - b), v)) {
        cout << abs(a - b) << '\n';
    } else if(is_valid(a + b, v)) {
        cout << a + b << '\n';
    } else {
        cout << "don't worry be happy\n";
    }

    return 0;
}
