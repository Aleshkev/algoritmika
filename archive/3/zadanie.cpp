#include <bits/stdc++.h>

using namespace std;
typedef intmax_t I;

bool is_correct(const string &s, const vector<I> &t) {
    I n = t.size();
    /*vector<I> calculated(n);
    calculated[0] = 0;
    for(I i = 1; i < n; ++i) {
        I max_c = 0;
        for(I j = 1; j <= i; ++j) {
            if(s.compare(0, j, s, i - j + 1, j) == 0) {
                max_c = max(max_c, j);
            }
        }
        calculated[i] = max_c;
    }*/

    vector<I> lps(n);
    lps[0] = 0;
    I i = 1, len = 0;
    while(i < n) {
        if(s[i] == s[len]) {
            ++len;
            lps[i] = len;
            ++i;
        } else {
            if(len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                ++i;
            }
        }
    }

    return lps == t;
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    I q;
    cin >> q;

    for(I qi = 0; qi < q; ++qi) {
        I n;
        cin >> n;

        vector<I> t(n);
        for(I i = 0; i < n; ++i) {
            cin >> t[i];
        }

        if(2 + 2 == 4 || n <= 15) {
            /*vector<string> results;
            for(I m = 0; m < (1 << n); ++m) {
                string s(n, ' ');
                for(I i = 0; i < n; ++i) {
                    s[i] = ((m & (1 << i)) ? 'b' : 'a');
                }
                if(s[0] != 'a') {
                    continue;
                }

                if(is_correct(s, t)) {
                    //for(I i = 0; i < n; ++i) cout << setw(2) << s[i] << ' '; cout << '\n';
                    //for(I i = 0; i < n; ++i) cout << setw(2) << calculated[i] << ' '; cout << '\n';
                    results.push_back(s);
                    /// TODO: break
                }
            }
            for(auto s : results) cout << s << ' '; if(results.empty()) cout << "NIE"; cout << '\n';*/

            string result(n + 1, ' ');
            result[0] = 'b';
            result[1] = 'a';
            for(I i = 1; i < n; ++i) {
                result[i + 1] = result[t[i]];
            }
            result = result.substr(1);
            if(is_correct(result, t)) {
                cout << "TAK\n" << result << '\n';
            } else {
                cout << "NIE\n";
            }

            /*if(!results.empty() && result != results.back()) {
                cout << " --- === INVESTIGATION NEEDED! === --- " << endl;
            }*/

        } else {

        }
    }

    return 0;
}
