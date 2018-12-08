#include <iostream>

using namespace std;

typedef long long int I;

void print_c(I c) {
    if(c < 60) {
        cout << c << " second";
        if(c > 1) cout << 's';
        return;
    }
    c = (c + 30) / 60;
    if(c < 60) {
        cout << c << " minute";
        if(c > 1) cout << 's';
        return;
    }
    c = (c + 30) / 60;
    if(c < 24) {
        cout << c << " hour";
        if(c > 1) cout << 's';
        return;
    }
    c = (c + 12) / 24;
    if(c < 30) {
        cout << c << " day";
        if(c > 1) cout << 's';
        return;
    }
    c = (c + 15) / 30;
    if(c < 12) {
        cout << c << " month";
        if(c > 1) cout << 's';
        return;
    }
    c = (c + 6) / 12;
    cout << c << " year";
    if(c > 1) cout << 's';
}

int main()
{
    while(true) {
        I n;
        cin >> n;

        I c_naive = n * (n + 1) / 2;
        I c_optimized = n;

        print_c(c_naive);
        cout << "  ";
        print_c(c_optimized);
        cout << endl;
    }

    return 0;
}
