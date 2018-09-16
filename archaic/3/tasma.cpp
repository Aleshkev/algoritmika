#include <bits/stdc++.h>

using namespace std;

typedef long int I;

struct Span {
    I value;
    I a, b;
    Span(I v, I a, I b) : value(v), a(a), b(b) {};
};

int main()
{
    I m;
    scanf("%li", &m);

    for(I test = 0; test < m; ++test) {

        I n;
        scanf("%li", &n);

        vector<Span> v;

        for(I i = 0; i < n; ++i) {
            I e;
            scanf("%li", &e);
            if(!v.empty() && e == v.back().value) {
                ++v.back().b;
            } else {
                v.push_back(Span(e, i, i));
            }
        }

        /*for(I i = 0; i < v.size(); ++i) {
            cout << v[i].value << ", " << v[i].a << ":" << v[i].b << endl;
        }*/

        if(v.size() < 2) {
            printf("BRAK\n");
            continue;
        }

        I max_l = 0;
        for(I i = 0; i < 2; ++i) {
            for(I j = v.size() - 1; j >= I(v.size()) - 2; --j) {
                //cout << "walking " << i << ", " << j << endl;
                if(v[i].value != v[j].value) {
                    //cout << "found " << v[i].a << ":" << v[j].b << endl;
                    max_l = max(max_l, v[j].b - v[i].a);
                }
            }
        }
        printf("%li\n", max_l);

    }

    return 0;
}
