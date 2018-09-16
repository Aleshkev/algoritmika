#include <bits/stdc++.h>

using namespace std;

typedef int I;

int main()
{
    system("chcp 65001 >NUL");

    I n;
    cin >> n;

    I majority = n % 2 == 0 ? n / 2 : n / 2 + 1;

    map<char, string> u;
    u.insert(make_pair('A', "Asia / Antek / Alek"));
    u.insert(make_pair('B', "Bartek"));
    u.insert(make_pair('D', "Dominik / Dieu"));
    u.insert(make_pair('J', "Jowita / Jasiek / Jonasz"));
    u.insert(make_pair('K', "Kamil / Kuba / Kacper / Krzysiek / Kajtek"));
    u.insert(make_pair('M', "Mikołaj / Maciek / Miron / Mateusz / Michał"));
    u.insert(make_pair('O', "Oskar"));
    u.insert(make_pair('P', "Piotrek / Paweł"));
    u.insert(make_pair('R', "Rysiek"));

    map<char, I> t;

    for(I i = 0; i < n; ++i) {
        char ch;
        cin >> ch;
        ++t[ch];
    }

    for(char ch = 'A'; ch <= 'Z'; ++ch) {
        if(t[ch] >= majority) {
            cout << u[ch] << '\n';
            return 0;
        }
    }
    cout << "EVERYONE POWER\n";
}
