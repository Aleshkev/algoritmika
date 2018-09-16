#include <iostream>
#include <cstring>

using namespace std;

typedef int I;

int main()
{
    char str[101];
    cin >> str;
    I n = strlen(str);
    const I mod[] = {4, 2, 4}, rest[] = {0, 1, 2};
    for(I i = 0; i < 3; ++i) {
        for(I j = 0; j < n; ++j) {
            cout << (j % mod[i] == rest[i] ? str[j] : '.');
        }
        cout << '\n';
    }

    return 0;
}
