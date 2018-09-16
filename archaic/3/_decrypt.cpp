#include <bits/stdc++.h>

using namespace std;

typedef long long int I;
const I inf = (I)1e18;
typedef double F;


/* BINARY SEARCH */
I an_upper_bound(I t[], I n, I x) {
    I lo = 0, hi = n;
    while(lo < hi) {
        I mid = (lo + hi) / 2;
        if(x >= t[mid]) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return lo;
}
I a_lower_bound(I t[], I n, I x) {
    I lo = 0, hi = n;
    while(lo < hi) {
        I mid = (lo + hi) / 2;
        if(x > t[mid]) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return lo;
}

/* SEGMENT TREE */
template<typename T, T (*set_op)(T, T), T (*get_op)(T, T), T set_neutral, T get_neutral> struct Tree {
    I w;
    T *value, *for_later;
    Tree(I n) {
        for(w = 1; w < n; w *= 2);
        value = new T[2 * w];
        fill(value, value + 2 * w, get_neutral);
        for_later = new T[2 * w];
        fill(for_later, for_later + 2 * w, get_neutral);
    }

    T _query(I qb, I qe, I i, I rb, I re, T x) {
        if(qe < rb || qb > re) {
            return get_neutral;
        }
        if(qb <= rb && re <= qe) {
            value[i] = set_op(value[i], x);
            for_later[i] = set_op(for_later[i], x);
            return value[i];
        }

        value[2 * i + 0] = set_op(value[2 * i + 0], for_later[i]);
        for_later[2 * i + 0] = set_op(for_later[2 * i + 0], for_later[i]);
        value[2 * i + 1] = set_op(value[2 * i + 1], for_later[i]);
        for_later[2 * i + 1] = set_op(for_later[2 * i + 1], for_later[i]);
        for_later[i] = set_neutral;

        I mid = (rb + re) / 2;
        T result = get_op(_query(qb, qe, 2 * i + 0, rb, mid, x),
                          _query(qb, qe, 2 * i + 1, mid + 1, re, x));
        value[i] = get_op(value[2 * i + 0], value[2 * i + 1]);
        return result;
    }
    T query(I qb, I qe, T x = set_neutral) {
        return _query(qb, qe, 1, 0, w - 1, x);
    }
};
I set_op(I a, I b) {return a + b;}
I get_op(I a, I b) {return a + b;}


template<typename T, T MOD, T BASE, size_t N>
struct basehash
{
    T H[N];
    T base_pow[N];
    size_t n;
    template<typename Iterator>
    basehash(Iterator begin, Iterator end, T fix = 0)
    {
        n = distance(begin, end);
        Iterator it = begin;
        for(uint32_t i = 0; i < n; i++)
        {
            if(i > 0)
                H[i] = H[i-1] * BASE, H[i] %= MOD;
            H[i] += T(*it) + fix;
            H[i] %= MOD;

            if(i > 0)
                base_pow[i] = (base_pow[i-1] * BASE) % MOD;
            else
                base_pow[i] = 1;
            it++;
        }
    }
    const uint64_t& operator[] (size_t i) const { return H[i]; }
    uint64_t operator() (size_t i, size_t j) const
    {
        if(i == 0)
            return H[j];
        else
            return (2*MOD + H[j] - ((H[i-1]*base_pow[j - i + 1]) % MOD)) % MOD;
    }
};

int main()
{
    cout.sync_with_stdio(false);
    //cin.tie(0); cout.tie(0);

    I n, m;
    cin >> n >> m;

    Tree<I, set_op, get_op, 0, 0> tree(n);

    for(;;) {
        I a, b, c;
        cin >> a >> b >> c;

        cout << tree.query(a, b, c) << '\n';

        for(I i = 0; i < tree.w; ++i) {
            cout << tree.query(i, i) << ' ';
        } cout << '\n';
    }

    return 0;
}
