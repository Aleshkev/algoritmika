#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I inf = 1e18;

vector<I> t;

struct Trair {
    I a, b, c;
    Trair(I a, I b, I c) : a(a), b(b), c(c) {};

};
bool operator<(const Trair &q, const Trair &p) {
    return tie(q.a, q.b, q.c) < tie(p.a, p.b, p.c);
}

struct BySum {
    bool operator()(const Trair &q, const Trair &p) {
        return t[q.a] + t[q.b] + t[q.c] > t[p.a] + t[p.b] + t[p.c];
    }
};


int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    I n, k;
    cin >> n >> k;

    t.resize(n);
    for(I i = 0; i < n; ++i) {
        cin >> t[i];
    }
    sort(t.begin(), t.end());
    t.push_back(inf);

    set<Trair> visited;

    priority_queue<Trair, vector<Trair>, BySum> q;
    Trair last(0, 0, 0);
    q.push(last);
    for(I i = 0; i < k; ++i) {
        last = q.top();
        q.pop();
        if(visited.count(last) > 0) {
            --i;
            continue;
        } else {
            visited.insert(last);
        }
        //cout << i << ": " << last.a << ", " << last.b << ", " << last.c << " (" << t[last.a] + t[last.b] + t[last.c] << ")" << endl;
        q.emplace(last.a + 1, last.b, last.c);
        q.emplace(last.a, last.b + 1, last.c);
        q.emplace(last.a, last.b, last.c + 1);
    }
    cout << t[last.a] + t[last.b] + t[last.c] << '\n';

    return 0;
}
