#include <iostream>

using namespace std;

typedef long long int I;

I n;
static I val[10000000];
static I wait[10000000];

I _tget(I i, I rb, I re, I qb, I qe) {
    if(rb > qe || re < qb) return 0;
    if(qb <= rb && re <= qe) return val[i];

    val[i * 2] += (re - rb + 1) * wait[i] / 2;
    val[i * 2 + 1] += (re - rb + 1) * wait[i] / 2;
    wait[i * 2] += wait[i];
    wait[i * 2 + 1] += wait[i];
    wait[i] = 0;

    I mid = (rb + re) / 2;
    return (_tget(i * 2, rb, mid, qb, qe) +
            _tget(i * 2 + 1, mid + 1, re, qb, qe));
}
I tget(I qb, I qe) {
    return _tget(1, 0, n - 1, qb, qe);
}

void _tset(I i, I rb, I re, I qb, I qe, I inc) {
    if(rb > qe || re < qb) return;
    if(qb <= rb && re <= qe) {
        val[i] += (re - rb + 1) * inc;
        wait[i] += inc;
        return;
    }

    I mid = (rb + re) / 2;
    _tset(i * 2, rb, mid, qb, qe, inc);
    _tset(i * 2 + 1, mid + 1, re, qb, qe, inc);
    val[i] = val[i * 2] + val[i * 2 + 1];
}
void tset(I qb, I qe, I inc) {
    _tset(1, 0, n - 1, qb, qe, inc);
}

int main()
{
    cout.sync_with_stdio(false);
    cout.tie(0);

    I m;
    cin >> n >> m;

    I k = 1;
    while(k <= n) k <<= 1;
    n = k;

    for(I i = 0; i < m; ++i) {
        char ch;
        cin >> ch;
        if(ch == 'W') {
            I a, b, inc;
            cin >> a >> b >> inc;
            tset(a, b, inc);
        } else {
            I a, b;
            cin >> a >> b;
            cout << tget(a, b) << '\n';
        }
    }

    return 0;
}
