#include <bits/stdc++.h>

using namespace std;

typedef int I;

struct Arc {
    Arc(I first_, I last_) : first(first_), last(last_) {};
    I first, last;
};

int main()
{
    I n;
    scanf("%i", &n);

    vector<Arc> arcs;

    static I begins[I(2e5 + 1)];
    fill(begins, begins + I(2e5 + 1), -1);
    begins[n] = 0;

    static char s[I(2e5 + 1)];
    scanf("%s", s);

    I prefix_sum = n;
    for(I i = 1; i <= n; ++i) {
        prefix_sum += (s[i - 1] == '+' ? 1 : -1);

        if(begins[prefix_sum] != -1) {
            arcs.push_back(Arc(begins[prefix_sum], i));
        }
        begins[prefix_sum] = i + 1;
    }

    /*for(I i = 0; i < arcs.size(); ++i) {
        cout << arcs[i].first << ':' << arcs[i].last << endl;
    }*/

    I score = 0;
    I max_last = -1;
    I m = arcs.size();
    for(I i = 0; i < m; ++i) {
        if(arcs[i].first <= max_last) {
            continue;
        }
        max_last = arcs[i].last;
        ++score;
    }

    printf("%i\n", score);

    return 0;
}
