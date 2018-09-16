#include <iostream>

using namespace std;

typedef unsigned I;

int main()
{
    cout.sync_with_stdio(false);

    I n, k;
    cin >> n >> k;

    I *t = new I[n];
    for(I i = 0; i < n; ++i) {
        cin >> t[i];
    }

    I *prefixes = new I[n];
    prefixes[0] = t[0];
    for(I i = 1; i < n; ++i) {
        prefixes[i] = prefixes[i - 1] ^ t[i];
    }

    I *prefixes_xored = new I[n];
    for(I i = 0; i < n; ++i) {
        prefixes_xored[i] = prefixes[i] ^ k;
    }

    for(I i = 0; i < n; ++i) {
        cout << prefixes[i] << " ";
    } cout << endl;
    for(I i = 0; i < n; ++i) {
        cout << prefixes_xored[i] << " ";
    } cout << endl;

    return 0;
}
