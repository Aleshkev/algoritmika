//#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long unsigned U;

#define PU "llu"
#define PI "lld"

typedef long long int I;
typedef pair<I, I> IIP;
const U inf = 1e18;

bool by_second(IIP l, IIP r) {return l.second < r.second;};

int main() {
    I n;
    //cin >> n;
    scanf("%"PI, &n);

    //cout << "t";
    I *t = new I[n + 10];  // Wszystkie liczby
    for(I i = 0; i < n; ++i) {
        //cin >> t[i];
        scanf("%"PI, &t[i]);
    }


    I first_neg = inf, last_neg = inf;  // Indeks pierwszej i ostatniej negatywnej sumy prefiksowej

    //cout << "u";
    I *u = new I[n + 10];  // Sumy prefiksowe wszystkich liczb
    u[0] = t[0];
    for(I i = 1; i < n; ++i) {
        u[i] = u[i - 1] + t[i];
    }
    for(I i = 0; i < n; ++i) {
        if(u[i] < 0) {
            first_neg = min(first_neg, i);
            last_neg = i;
        }
    }

    if(last_neg == inf) {
        printf("1 1\n");
        return 0;
        //cout << "nolastneg";
    }

    //cout << "v";
    I *v = new I[n + 10];  // Sumy prefiksowe liczone od last_neg (i w lewo i w prawo)
    v[last_neg] = t[last_neg];
    for(I i = last_neg - 1; i >= 0; --i) {
        v[i] = v[i + 1] + t[i];
    }
    v[last_neg + 1] = t[last_neg + 1];
    for(I i = last_neg + 1 + 1; i < n; ++i) {
        v[i] = v[i - 1] + t[i];
    }

    //cout << "w";
    I *w = new I[n + 10];  // Tablica "dolkow"
    w[last_neg] = v[last_neg];
    for(I i = last_neg - 1; i >= 0; --i) {
        w[i] = min(w[i + 1], v[i]);
    }

    //cout << "s";
    IIP *s = new IIP[n + 10];  // Tablica par <indeks, wartosc> do binary search'a
    for(I i = last_neg + 1; i < n; ++i) {
        s[i].first = i;
        s[i].second = v[i];
    }
    sort(s + last_neg + 1, s + n, by_second);
    for(I i = n - 1 - 1; i >= last_neg + 1; --i) {
        s[i].first = min(s[i].first, s[i + 1].first);
    }

    //cout << ".";
    bool any_found = false;
    for(I i = 0; i <= first_neg; ++i) {
        I needed = -(w[i] + (i > 0 ? u[i - 1] : 0));
        IIP *a = lower_bound(s + last_neg + 1, s + n, IIP(0, needed), by_second);

        if(a != s + n) {
            I j = a->first;
            //cout << i + 1 << " " << j + 1 << "\n";
            printf("%"PI" %"PI, i + 1, j + 1);
            any_found = true;
            break;
        }
    }
    if(!any_found) {
        //cout << "NIE\n";
        printf("NIE\n");
    }

    return 0;
}
