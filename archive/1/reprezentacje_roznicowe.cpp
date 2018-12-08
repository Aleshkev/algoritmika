#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long unsigned U;

struct Diff {
    Diff() {};
    Diff(U x_) : x(x_) {};
    Diff(U x_, U p_, U q_) : x(x_), p(p_), q(q_) {};

    U x;
    U p, q;
};
bool operator<(Diff l, Diff r) {return l.x < r.x; };

int main()
{
    const U len = 75;  // Ile elementów ma być wygenerowanych od razu

    set<Diff> r;  // Używam teraz set-ów które idealnie pasują do zadania. Są uporządkowane i szukają elementów binary-searchem
    r.insert(Diff(1, 2, 1));

    vector<U> a;
    a.push_back(-1);
    a.push_back(1);
    a.push_back(2);

    U s = 1;
    for(U i = 3; i < len; ++i) {
        if(i % 2 != 0) {
            a.push_back(a[i - 1] * 2);
        } else {
            // Ta pętla znajduje najmniejszą liczbę, która nie pojawia się w ciągu `r`
            for(; r.find(Diff(s)) != r.end(); ++s) {
                ;
            }

            a.push_back(a[i - 1] + s);
        }

        for(int j = i - 1; j > 0; --j) {
            r.insert(Diff(a[i] - a[j], i, j));
        }
    }

    for(set<Diff>::iterator i = r.begin(); i != r.end(); ) {
        if(i->p % 2 == 0 && i->q == i->p - 1) {
            r.erase(i++);
        } else {
            ++i;
        }
    }

    U n;  // Liczba przypadków testowych
    cin >> n;

    for(U i = 0; i < n; ++i) {
        U x;
        cin >> x;

        set<Diff>::iterator diff = r.find(Diff(x));

        if(diff != r.end()) {  // Element jest w obliczonych różnicach
            cout << diff->p << " " << diff->q << '\n';
        } else {
            U index = distance(r.begin(), r.lower_bound(Diff(x)));
            U first = (x - index) * 2;
            cout << first << ' ' << first - 1 << '\n';
        }
    }

    return 0;
}
