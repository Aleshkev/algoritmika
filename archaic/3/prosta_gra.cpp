
// Autor:           Jonasz Aleszkiewicz (u65848)
// Nazwa zadania:   Prosta Gra
// Data przeslania: 2017-10-14 09:08:41.708999
#include <bits/stdc++.h>

using namespace std;

typedef int I;

int main()
{
    I n;
    scanf("%i", &n);

    I t[100];
    for(I i = 0; i < n; ++i) {
        scanf("%i", &t[i]);
    }

    sort(t, t + n);

    bool andrew = false;
    for(I i = 0; i + 1 < n; i += 2) {
        if(t[i] != t[i + 1]) {
            andrew = true;
            break;
        }
    }

    printf("%s\n", (andrew ? "Andrzej" : "Blazej"));

    return 0;
}
