#include <iostream>
#include <cstdlib>
//#include <cmath>

using namespace std;

typedef long long unsigned U;
typedef long long int I;
typedef double F;

struct Cabb {
    I x, y;

    U parent;
    U pop;
};

Cabb *cabbs;

U find_root(U i) {
    if(cabbs[i].parent != i) {
        cabbs[i].parent = find_root(cabbs[i].parent);
    }
    return cabbs[i].parent;
}

void make_union(U a, U b) {
    U root_a = find_root(a), root_b = find_root(b);
    if(root_a != root_b) {
        cabbs[root_a].parent = root_b;
        cabbs[root_b].pop += cabbs[root_a].pop;
    }
}

int main()
{
    cout.sync_with_stdio(false);

    U n, s;  // Liczba kapust, maksymalna długość skoku
    cin >> n >> s;

    U s_squared = s * s;

    cabbs = new Cabb[n];
    for(U i = 0; i < n; ++i) {
        cin >> cabbs[i].x >> cabbs[i].y;
        cabbs[i].parent = i;
        cabbs[i].pop = 1;
    }

    for(U i = 0; i < n; ++i) {
        for(U j = 0; j < i; ++j) {
            if(find_root(i) != find_root(j)) {
                U dx = abs(cabbs[i].x - cabbs[j].x), dy = abs(cabbs[i].y - cabbs[j].y);
                if(dx * dx + dy * dy < s_squared) {
                    make_union(i, j);
                }
            }
        }
    }

    cout << cabbs[find_root(0)].pop << '\n';


    return 0;
}
