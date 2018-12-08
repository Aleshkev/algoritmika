#include <bits/stdc++.h>

using namespace std;

typedef long int I;
typedef pair<I, I> II;

struct Couch {
    I c, w, i;
};
bool by_c(Couch a, Couch b) {return a.c < b.c; }

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);

    I n;
    cin >> n;

    vector<Couch> couches(n);
    for(I i = 0; i < n; ++i) {
        cin >> couches[i].c >> couches[i].w;
        couches[i].i = i;
    }

    sort(couches.begin(), couches.end(), by_c);

    vector<I> to_remove;

    I max_w = 0;
    for(I i = 0; i < n; ++i) {
        if(max_w > couches[i].w) {
            to_remove.push_back(couches[i].i);
        } else {
            max_w = couches[i].w;
        }
    }

    sort(to_remove.begin(), to_remove.end());

    cout << to_remove.size() << '\n';
    for(I i = 0; i < to_remove.size(); ++i) {
        cout << to_remove[i] + 1 << ' ';
    }

    return 0;
}
