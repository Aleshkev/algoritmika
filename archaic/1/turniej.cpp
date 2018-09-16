#include <bits/stdc++.h>

using namespace std;

typedef long long int I;


int main()
{
    cout.sync_with_stdio(false);
    I n; cin >> n;

    map<string, I> t;

    for(I i = 0; i < n; ++i) {
        string name;
        I score;
        cin >> name >> score;
        if(t.find(name) == t.end()) t.insert(make_pair(name, score));
        else t[name] += score;

        string max_name;
        I max_score = 0;
        for(map<string, I>::iterator it = t.begin(); it != t.end(); ++it) {
            if(it->second > max_score || (it->second == max_score && it->first < max_name)) {
                max_name = it->first;
                max_score = it->second;
            }
        }
        cout << max_name << '\n';
    }

    return 0;
}
