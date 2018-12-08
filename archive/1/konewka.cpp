#include <bits/stdc++.h>

using namespace std;

typedef int I;
const I inf = INT_MAX - 10;

I n, k;
I sizu;

static pair<I, I> maxypair[2000000];
static I pend_maxypair[2000000] = {0};

static I growny[2000000];

void inc_growny(I q, I inc) {
    for(I i = sizu + q; i > 0; i /= 2) {
        growny[i] += inc;
    }
}
I _get_growny(I i, I rb, I re, I qb, I qe) {
    if(qe < rb || qb > re) {
        return 0;
    }
    if(qb <= rb && re <= qe) {
        return growny[i];
    }
    I mid = (rb + re) / 2;
    return (_get_growny(i * 2,     rb,      mid, qb, qe) +
            _get_growny(i * 2 + 1, mid + 1, re,  qb, qe));
}
I get_growny(I qb, I qe) {
    return _get_growny(1, 0, sizu - 1, qb, qe);
}

void _inc_maxypair(I i, I rb, I re, I qb, I qe, I inc) {
    if(qe < rb || qb > re) {
        return;
    }
    if(qb <= rb && re <= qe) {
        maxypair[i].first += inc;
        pend_maxypair[i] += inc;
        return;
    }

    maxypair[i * 2    ].first += pend_maxypair[i];
    maxypair[i * 2 + 1].first += pend_maxypair[i];
    pend_maxypair[i * 2    ] += pend_maxypair[i];
    pend_maxypair[i * 2 + 1] += pend_maxypair[i];
    pend_maxypair[i] = 0;

    I mid = (rb + re) / 2;
    _inc_maxypair(i * 2,     rb,      mid, qb, qe, inc);
    _inc_maxypair(i * 2 + 1, mid + 1, re,  qb, qe, inc);
    maxypair[i] = max(maxypair[i * 2], maxypair[i * 2 + 1]);
}
void inc_maxypair(I qb, I qe, I inc) {
    //clog << qb << ":" << qe << " += " << inc << endl;
    _inc_maxypair(1, 0, sizu - 1, qb, qe, inc);
}
void safe_inc_maxypair(I qb, I qe, I inc = 1) {
    inc_maxypair(qb, qe, inc);
    while(maxypair[1].first >= k) {
        //clog << "limit reached at " << maxypair[1].second << " (" << maxypair[1].first << ")!" << endl;
        inc_growny(maxypair[1].second, 1);
        inc_maxypair(maxypair[1].second, maxypair[1].second, -inf);
    }
}

void podlej(I a, I b) {
    safe_inc_maxypair(a, b, 1);
}
I dojrzale(I a, I b) {
    return get_growny(a, b);
}
void inicjuj(I n_, I k_, I *d) {
    n = n_, k = k_;

    for(sizu = 1; sizu < n; sizu <<= 1) {
        ;
    }

    for(I i = 0; i < sizu; ++i) {
        maxypair[sizu + i].second = i;
    }

    for(I i = 0; i < n; ++i) {
        safe_inc_maxypair(i, i, d[i]);
    }
}

/*
int main()
{
    cout.sync_with_stdio(false);

    I n_, k_;
    cin >> n_ >> k_;

    static I d[1000000];
    for(I i = 0; i < n_; ++i) {
        cin >> d[i];
    }

    inicjuj(n_, k_, d);

    for(I i = 1; i < sizu * 2; ++i) {
        cout << maxypair[i].first << " ";
        if(i == sizu - 1) cout << "| ";
    } cout << endl;

    char cmd;
    while(cin >> cmd) {
        I a, b;
        cin >> a >> b;
        if(cmd == 'd') {
            cout << dojrzale(a, b) << '\n';
            //cout << "sum(growny[" << a << ":" << b << "] = " << dojrzale(a, b) << endl;
        } else if(cmd == 'p') {
            podlej(a, b);
            for(I i = 1; i < sizu * 2; ++i) {
                cout << maxypair[i].first << " ";
                if(i == sizu - 1) cout << "| ";
            } cout << endl;
        }
    }

    return 0;
}*/
