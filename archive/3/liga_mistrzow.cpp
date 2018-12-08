#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

I median(I a, I b, I c) {
    vector<I> v = {a, b, c};
    sort(v.begin(), v.end());
    //return v[1];
    return a ^ b ^ c ^ min({a, b, c}) ^ max({a, b, c});  // Magia xor.
}

void quick_sort(I *t, I lo, I hi) {
    if(is_sorted(t + lo, t + hi)) {
        return;
    }

    I pivot = median(t[lo], t[hi - 1], t[(lo + hi) / 2]);
    I i = lo;  // t[x] <= pivot if x < i
    for(I j = lo; j < hi; ++j) {
        if(t[j] <= pivot) {
            swap(t[i], t[j]);
            ++i;
        }
    }

    quick_sort(t, lo, i);
    quick_sort(t, i + 1, hi);
}

int main() {
    ios_base::sync_with_stdio(false);

    I n;
    const I max_n = 7e6;
    cin >> n;

    static I t[max_n];
    for(I i = 0; i < n; ++i) {
        //t[i] = rand() % I(1e10);
        cin >> t[i];
    }

    //sort(t, t + n);
    quick_sort(t, 0, n);

    for(I i = 0; i < n; ++i) cout << t[i] << ' '; cout << '\n';

    return 0;
}
