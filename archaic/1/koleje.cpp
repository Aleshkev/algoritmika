#include <bits/stdc++.h>

using namespace std;

typedef long long int I;
const I inf = 1e18;


I val[1200000] = {0};
I wait[1200000];

I tget(I i, I rb, I re, I qb = 1, I qe = inf) {
    if(qb <= rb && re <= qe) return val[i];
    if(qe < rb || re < qb) return 0;

    I mid = (rb + re) / 2;

    val[i * 2    ] += wait[i];
    val[i * 2 + 1] += wait[i];
    wait[i * 2] += wait[i];
    wait[i * 2 + 1] += wait[i];
    wait[i] = 0;

    return max(tget(i * 2,     rb,      mid, qb, qe),
               tget(i * 2 + 1, mid + 1, re,  qb, qe));
}

void tset(I i, I rb, I re, I qb, I qe, I incval) {
    if(qb <= rb && re <= qe) {
        val[i] += incval, wait[i] += incval;
        return;
    }
    if(qe < rb || re < qb) return;

    I mid = (rb + re) / 2;
    tset(i * 2,     rb,      mid, qb, qe, incval);
    tset(i * 2 + 1, mid + 1, re,  qb, qe, incval);
    val[i] = max(val[i * 2], val[i * 2 + 1]);
}


int main()
{
    I n, m, z;
    scanf("%lli %lli %lli", &n, &m, &z);
    I sz = 1;
    while(sz < n) sz <<= 1;

    for(I i = 0; i < z; ++i) {
        I p, k, l;
        scanf("%lli %lli %lli", &p, &k, &l);
        p -= 1;
        k -= 2;
        if(tget(1, 0, sz - 1, p, k) + l <= m) {
            printf("T\n");
            tset(1, 0, sz - 1, p, k, l);
        } else {
            printf("N\n");
        }
    }


    return 0;
}
