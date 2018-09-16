#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I inf = 1e18;

struct Node {
    I parent;
    I lt, rt;
    I zeit;
    Node() : parent(-1), lt(-1), rt(-1), zeit(inf) {};
};

int main()
{
    I n, m;
    cin >> n >> m;

    vector<Node> tree(n);

    for(I i = 0; i < n; ++i) {
        Node &node = tree[i];
        cin >> node.lt >> node.rt;
        --node.lt; --node.rt;
        tree[node.lt].parent = i;
        tree[node.rt].parent = i;
    }

    for(I i = 0; i < m; ++i) {
        I j, k;
        cin >> j >> k;
        --j;
        if(k == 1) {
            tree[tree[j].lt].zeit = k;
        } else {
            tree[tree[j].rt].zeit = k;
        }
    }

    for(I i = 0; i < n; ++i) cout << tree[i].parent << ' '; cout << '\n';
    for(I i = 0; i < n; ++i) cout << tree[i].zeit << ' '; cout << '\n';

    //I root = 0;
    //while(tree[root].parent != -1) root = tree[root].parent;

    vector<bool> visited(n);

    for(I i = 0; i < n; ++i) {
        if(!visited[i]) {
            cout << "unvisited! interrogate! ";
            vector<I> ancestors;
            I j = i;
            while(tree[j].parent != -1) {
                j = tree[j].parent;
                visited[j] = true;
                ancestors.push_back(j);
            }

            for(I k = ancestors.size() - 1 - 1; k >= 0; --k) {
                tree[ancestors[k]].zeit = min(tree[ancestors[k]].zeit, tree[ancestors[k + 1]].zeit);
            }
        }
        cout << tree[i].zeit << '\n';
    }

    return 0;
}
