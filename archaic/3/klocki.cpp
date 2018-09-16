#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
#define If PRIxMAX

I n;
I tree[5000000];
I tree_size, tree_base;

void init_tree() {
    tree_base = 1;
    while(tree_base < 2001000) tree_base *= 2;
}

void tree_add1(I x) {
    for(I i = tree_base + x; i > 0; i /= 2) {
        ++tree[i];
    }
}

I _tq(I qb, I qe, I i, I rb, I re) {
    if(qb <= rb && re <= qe) {
        return tree[i];
    }
    if(qe < rb || re < qb) {
        return 0;
    }

    I mid = (rb + re) / 2;
    return (_tq(qb, qe, i * 2 + 0, rb, mid) +
            _tq(qb, qe, i * 2 + 1, mid + 1, re));
}
I tree_query(I a, I b) {
    return _tq(a, b, 1, 0, tree_base - 1);
}

int main()
{
    scanf("%" If, &n);

    init_tree();

    static char s[1000001];
    scanf("%s", s);

    cout << "HELDSKL";

    static I t[1000001];
    t[0] = 0;
    for(I i = 1; i <= n; ++i) {
        t[i] = t[i - 1] + 1;//(s[i - 1] == 'Z' ? 1 : -1);
    }
    cout << "Init";
    for(I i = 0; i <= n; ++i) {
        t[i] += 1000010;
    }

    cout << t[n] - 1000010 << endl;

    /*for(I i = 0; i <= n; ++i) {
        cout << t[i] - 1000010 << ' ';
    } cout << endl;*/


    //cout << tree_base << endl;

    I c = 0;

    for(I i = 0; i <= n; ++i) {
        c += tree_query(0, t[i] - 1);
        tree_add1(t[i]);
    }

    printf("%" If "\n", c);



    return 0;
}
