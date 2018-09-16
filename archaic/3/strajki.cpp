#include <bits/stdc++.h>

using namespace std;

typedef int I;
const I inf = 1e18;

struct Node {
    I parent;
    I nactivechildren;
    bool active;
    Node() : parent(-1), nactivechildren(0), active(true) {};
};

I n;
vector<vector<I>> graph;
vector<Node> tree;
I m;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    graph.resize(n);
    for(I i = 0; i < n - 1; ++i) {
        I a, b;
        cin >> a >> b;
        --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    tree.resize(n);
    vector<I> q;
    vector<bool> visited;
    visited.resize(n);
    q.push_back(0);
    visited[0] = true;
    while(!q.empty()) {
        I current = q.back();
        q.pop_back();

        for(I another : graph[current]) {
            if(visited[another]) {
                continue;
            }
            tree[another].parent = current;
            ++tree[current].nactivechildren;
            q.push_back(another);
            visited[another] = true;
        }
    }

    I ngroups = 1;

    cin >> m;
    for(I i = 0; i < m; ++i) {
        I q;
        cin >> q;
        bool start = (q > 0);
        q = abs(q) - 1;

        Node &node = tree[q];

        if(start) {
            ngroups += -1 + node.nactivechildren + (node.parent != -1 && tree[node.parent].active ? 1 : 0);
            node.active = false;
            if(node.parent != -1) --tree[node.parent].nactivechildren;
        } else {
            ngroups -= -1 + node.nactivechildren + (node.parent != -1 && tree[node.parent].active ? 1 : 0);
            node.active = true;
            if(node.parent != -1) ++tree[node.parent].nactivechildren;
        }
        /*cout << "     i: "; for(I j = 0; j < n; ++j) cout << setw(2) << j << ' '; cout << '\n';
        cout << "parent: "; for(I j = 0; j < n; ++j) cout << setw(2) << tree[j].parent << ' '; cout << '\n';
        cout << "active: "; for(I j = 0; j < n; ++j) cout << setw(2) << tree[j].active << ' '; cout << '\n';
        cout << "childr: "; for(I j = 0; j < n; ++j) cout << setw(2) << tree[j].nactivechildren << ' '; cout << '\n';
        cout << "groups: ";*/
        cout << ngroups << '\n';
    }

    return 0;
}
