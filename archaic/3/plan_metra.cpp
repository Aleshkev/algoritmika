#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
typedef pair<I, I> II;
ostream &operator<<(ostream &o, II p) {
    o << '(' << p.first << ", " << p.second << ')';
    return o;
}

bool check(I x, const vector<II> &v) {
    if(x == 0) {
        //cout << "ignoring " << 0 << endl;
        return false;
    }
    vector<II> in_nodes;  /// (lt, i)
    in_nodes.emplace_back(0, 0);
    in_nodes.emplace_back(x, v.size() - 1);
    for(I i = 1; i < v.size() - 1; ++i) {
        I a = v[i].first, b = v[i].second;

        if(a + b == x) {
            in_nodes.emplace_back(a, i);
        }
    }
    sort(in_nodes.begin(), in_nodes.end());


    /*cout << "trying " << x << endl;
    cout << "in-nodes: ";
    for(auto p : in_nodes) {
        cout << p << ' ';
    } cout << endl;*/

    vector<vector<I>> connected_out_nodes;
    connected_out_nodes.resize(v.size());

    for(I i = 1; i < v.size() - 1; ++i) {
        I a = v[i].first, b = v[i].second;

        if(a + b == x) {
            continue;
        }

        I lt = (x + a - b) / 2, rt = (x + b - a) / 2;
        if(lt != x - rt) {
            //cout << "inv mod\n";
            return false;
        }
        auto it = upper_bound(in_nodes.begin(), in_nodes.end(), II(lt, -1));
        if(it == in_nodes.end() || it->first != lt) {
            return false;
        }

        connected_out_nodes[it->second].push_back(i);
    }

    cout << "TAK\n";

    for(I i = 0; i < in_nodes.size() - 1; ++i) {
        cout << in_nodes[i].second + 1 << ' ' << in_nodes[i + 1].second + 1 << ' ' << in_nodes[i + 1].first - in_nodes[i].first << '\n';
    }
    for(I i = 0; i < v.size(); ++i) {
        for(I j = 0; j < connected_out_nodes[i].size(); ++j) {
            I k = connected_out_nodes[i][j];

            I a = v[k].first, b = v[k].second;

            cout << i + 1 << ' ' << k + 1 << ' ' << (a + b - x) / 2 << '\n';
        }
    }

    return true;
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    I n;
    cin >> n;

    if(n <= 1) {
        cout << "NIE\n";
        return 0;
    } else if(n == 2) {
        cout << "TAK\n1 2 1\n";
        return 0;
    }

    vector<II> v;
    v.resize(n);
    v[0].first = v[0].second = 0;
    v[n - 1].first = v[n - 1].second = 0;
    for(I i = 1; i < n - 1; ++i) {
        cin >> v[i].first;
    }
    for(I i = 1; i < n - 1; ++i) {
        cin >> v[i].second;
    }

    II m = *min_element(&v[1], &v[v.size() - 1]);
    //cout << "min = " << m << endl;

    if(check(abs(m.first - m.second), v));
    else if(check(m.first + m.second, v));
    else {
        cout << "NIE\n";
    }

    return 0;
}
