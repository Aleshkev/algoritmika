#include <bits/stdc++.h>

using namespace std;

uint16_t n;
int64_t x[5000], y[5000];

inline int64_t pow2(int64_t x) {
    return x * x;
}

struct Pair {
    uint16_t a, b;
    int64_t dist;
    Pair() {}
    Pair(uint16_t a, uint16_t b) : a(a), b(b) {
        dist = pow2(x[a] - x[b]) + pow2(y[a] - y[b]);
    }
};

Pair v[500000];

bool by_distance(const Pair &a, const Pair &b) {
    return a.dist < b.dist;
}

uint16_t fau[5000];
uint16_t find_root(uint16_t i) {
    if(fau[i] != i) {
        fau[i] = find_root(fau[i]);
    }
    return fau[i];
}
bool unite(uint16_t a, uint16_t b) {
    uint16_t root_a = find_root(a), root_b = find_root(b);
    if(root_a != root_b) {
        fau[root_b] = root_a;
        return true;
    }
    return false;
}

int main()
{
    scanf("%hu", &n);

    //cout << n << " = " << n << endl;

    for(uint16_t i = 0; i < n; ++i) {
        //cout << (int)i << ' ';
        //x[i] = i;
        //y[i] = -i + 132878;
        scanf("%lli %lli", &x[i], &y[i]);
    }

    //cout << "input read" << endl;

    uint64_t m = 0;//n * n - n * (n + 1) / 2;
    for(uint16_t i = 0; i < n; ++i) {
        for(uint16_t j = i + 1; j < n; ++j) {
           // cout << "(" << i << ", " << j << ": " << m << ")" << ' ';
            v[m++] = Pair(i, j);
        }
    }
    //cout << "pairs created" << endl;
    sort(v, v + m, by_distance);
    //cout << "pairs sorted" << endl;

    for(uint16_t i = 0; i < n; ++i) {
        fau[i] = i;
    }
    //cout << "find-and-union initialized" << endl;

    int64_t c = 0;
    for(size_t i = 0; i < m; ++i) {
        if(unite(v[i].a, v[i].b)) {
            c = max(c, v[i].dist);
        }
    }
    //cout << "result calculated" << endl;
    printf("%lli\n", int64_t(ceil(double(sqrt(c)))) * (n - 1));

    return 0;
}
