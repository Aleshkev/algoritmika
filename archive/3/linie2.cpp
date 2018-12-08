#include <bits/stdc++.h>

using namespace std;

typedef int I;
typedef double F;

int main()
{
    I k;
    scanf("%i", &k);

    I c = 0;

    I i = 0;
    for(;;) {
        char line[400 + 1];

        gets(line);

        I len = strlen(line);

        if(len == 2) break;

        ++i;

        if(len == k) {
            ++c;
        }
    }

    printf("Wszystkich linii bylo %i, linii o dlugosci %i bylo %i\n", i - 1, k, c);

    return 0;
}
