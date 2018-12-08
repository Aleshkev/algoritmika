//#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef int I;

int main() {
    vector<I> t;
    I a;
    while(scanf("%i", &a) != EOF/*cin >> a*/) {
        t.push_back(a);
    }
    I n = t.size();

    // Bardzo szybki brute-force
    for(I i = 1; i < n; ++i) {
        I j = i;
        while(j < n) {
            j += t[j] + 1;
        }
        if(j == n) {
            //cout << i << ' ';
            printf("%i ", i);
        }
    }
    //cout << n << '\n';
    printf("%i\n", n);

    return 0;
}
