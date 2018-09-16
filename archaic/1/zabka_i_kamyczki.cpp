#include <cstdio>

using namespace std;

typedef int I;

I u[20][100000];
I t[100000];
/*
I steps(I a, I b) {
    if(a >= b) return 0;

    I i = 0;
    while(u[i + 1][a] < b) {
        ++i;
    }

    return (1 << i) + (u[i][a] < b ? steps(u[i][a], b) : 0);
}

I steps_i(I a, I b) {
    I c = 0;
    while(a < b) {
        I i = 0;
        while(u[i + 1][a] < b) {
            ++i;
        }

        c += (1 << i);

        if(u[i][a] >= b) break;

        a = u[i][a];
    }
    return c;
}*/

int main()
{
    I n, s;
    scanf("%i %i", &n, &s);

    t[0] = 0;
    for(I i = 1; i <= n - 1; ++i) {
        I d;
        scanf("%i", &d);
        t[i] = t[i - 1] + d;
    }

    /*cout << "t = [ ";
    for(I i = 0; i < n; ++i) {
        cout << t[i] << " ";
    } cout << "]" << endl;*/


    for(I i = 0, j = 0; i < n; ++i) {
        while(j < n && t[i] + s >= t[j]) {
            ++j;
        }
        --j;
        u[0][i] = j;
    }

    /*cout << "u[0] = [ ";
    for(I i = 0; i < n; ++i) {
        cout << u[0][i] << " ";
    } cout << "]" << endl;*/

    for(I d = 1; d < 18; ++d) {
        for(I i = 0; i < n; ++i) {
            u[d][i] = u[d - 1][u[d - 1][i]];
        }

        /*cout << "u[" << d << "] = [ ";
        for(I i = 0; i < n; ++i) {
            cout << u[d][i] << " ";
        } cout << "]" << endl;*/
    }

    I m;
    scanf("%i", &m);
    for(I i = 0; i < m; ++i) {
        I a, b;
        scanf("%i %i", &a, &b);
        --a; --b;
        if(a > b) a ^= b ^= a ^= b;

        I c = 0;
        while(a < b) {
            I i = 0;
            while(u[i + 1][a] < b) {
                ++i;
            }

            c += (1 << i);

            if(u[i][a] >= b) break;

            a = u[i][a];
        }

        printf("%i\n", c);
    }



    return 0;
}
