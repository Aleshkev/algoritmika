#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long unsigned U;

int main()
{
    U n;
    cin >> n;

    vector<U> t;

    U lp = 0;

    for(U i = 0; i < n; ++i) {
        char c;
        cin >> c;

        //cout << c << ' ';

        if(c == '[' || c == '{') c = '(';
        else if(c == ']' || c == '}') c = ')';

        if(c == '(') {
            if(t.empty()) {
                t.push_back(1);
            }
            t.push_back(1);
        } else if(c == ')') {
            if(! t.empty()) {
                t.pop_back();
            }
            if(! t.empty()) {
                lp += t.back();
                ++t.back();
            }
        }

        //for(U i = 0; i < t.size(); ++i) {
        //    cout << t[i] << ' ';
        //} cout << '\n';
    }
    cout << lp << '\n';

    return 0;
}
