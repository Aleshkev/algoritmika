#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

struct Op {
    I a, l, d;
};
ostream &operator<<(ostream &o, Op op) {
    o << "(" << op.a << ", " << op.l << ", " << op.d << ")";
    return o;
}

int main()
{
    cout.sync_with_stdio(false);

    I n, m;
    cin >> n >> m;

    vector<Op> op(m);

    for(I i = 0; i < m; ++i) {
        cin >> op[i].a >> op[i].l >> op[i].d;
        --op[i].a;
    }

    sort(op.begin(), op.end(), [](Op a, Op b) {return a.d < b.d; });

    I sqrt_n = sqrt(n) + 1;

    vector<I> t(n);

    for(I i = 0; i < m; ++i) {
        if(op[i].d <= sqrt_n) {
            vector<I> e(n);
            I current_d = op[i].d;
            while(i < m && op[i].d == current_d) {
                ++e[op[i].a];
                if(op[i].a + op[i].d * op[i].l < n) --e[op[i].a + op[i].d * op[i].l];
                ++i;
            }
            --i;

            for(I j = 0; j < n; ++j) {
                if(j - current_d >= 0) {
                    e[j] += e[j - current_d];
                }
                t[j] += e[j];
            }
        } else {
            for(I j = op[i].a; j <= op[i].a + (op[i].l - 1) * op[i].d; j += op[i].d) {
                ++t[j];
            }
        }
    }
    for(I i = 0; i < n; ++i) cout << t[i] << ' '; cout << '\n';

    return 0;
}
