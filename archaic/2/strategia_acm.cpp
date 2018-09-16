#include <iostream>

using namespace std;

typedef long long int I;

int main()
{
    I n;
    cin >> n;

    set<pair<I, I> > t;

    map<I, I> exercises;
    for(I i = 0; i < n; ++i) {
        I t, l;
        cin >> t >> l;
        exercises.insert(pair<I, I>(t, l));
    }

    return 0;
}
