#include <bits/stdc++.h>

using namespace std;

typedef long int I;
typedef pair<I, I> II;

int main()
{
    I n, m;
    scanf("%li %li", &n, &m);

    char original[200001];//, result[200001];
    scanf("%s", original);

    static I q[200000], time[200000];
    //fill(q, q + n, -1);
    fill(time, time + n, -1);
    for(I i = 0; i < m; ++i) {
        I l, p;
        scanf("%li %li", &l, &p);
        --l; --p;
        q[p] = l;
        time[p] = i;
    }

    /*for(I i = 0; i < n; ++i) {
        cout << original[i] << " ";
    } cout << endl;
    for(I i = 0; i < n; ++i) {
        if(q[i] != -1) {
            cout << q[i];
        } else {
            cout << " ";
        } cout << " ";
    } cout << endl;
    for(I i = 0; i < n; ++i) {
        if(time[i] != -1) {
            cout << time[i];
        } else {
            cout << " ";
        } cout << " ";
    } cout << endl;*/

    I max_time = -1, j = 0;
    for(I i = 0; i < n; ++i, ++j) {
        if(time[i] > max_time) {
            max_time = time[i];
            j = q[i];
        }
        original[i] = original[j];
    }

    printf("%s\n", original);

    return 0;
}
