#include <bits/stdc++.h>

using namespace std;

typedef int I;

struct Gem {
    char str[200 + 1];
    I len;
};
bool operator<(const Gem &l, const Gem &r) {
    return l.len < r.len;
}

int main()
{
    I n;
    scanf("%i", &n);

    static Gem t[250];
    for(I i = 0; i < n; ++i) {
        scanf("%s", &t[i].str);
        t[i].len = strlen(t[i].str);
    }

    sort(t, t + n);
    for(I i = 0; i < n; ++i) {
        printf("%s\n", t[i].str);
    }

    return 0;
}
