#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

void permutate(vector<char> &t, I lo, I hi) {
    if(lo == hi) {
        for(char i : t) cout << i; cout << '\n';
    } else {
        for(I i = lo; i <= hi; ++i) {
            swap(t[lo], t[i]);
            permutate(t, lo + 1, hi);
            swap(t[lo], t[i]);
        }
    }
}

int main()
{
    vector<char> s = {'A', 'B', 'C'};
    permutate(s, 0, s.size() - 1);

    return 0;
}
