#include <cstdio>
#include <algorithm>

using namespace std;

typedef int I;

int main()
{
    I n; scanf("%i", &n);

    static I t[100000];
    for(I i = 0; i < n; ++i) {
        scanf("%i", &t[i]);
        --t[i];
    }

    I c = 0;
    for(I i = 0; i < n; ++i) {
        while(t[i] != i) {
            swap(t[i], t[t[i]]);
            ++c;
        }
    }

    printf("%i", c);

    return 0;
}
