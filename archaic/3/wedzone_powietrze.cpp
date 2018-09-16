#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

struct Node {
    vector<I> children;
    vector<I> weights;
    I parent;
    I w;
    bool must_visit;
    I score;
};

int main()
{
    ios_base::sync_with_stdio(false);

    I n, m;
    cin >> n >> m;

    vector<Node> tree(n);
    for(I i = 0; i < n - 1; ++i) {
        I a, b, w;
        cin >> a >> b >> w;
        --a; --b;
        tree[a].children.push_back(b);
        tree[b].children.push_back(a);
        tree[a].weights.push_back(w);
        tree[b].weights.push_back(w);
    }

    vector<I> seq;
    vector<I> dfs;
    dfs.push_back(0);
    seq.push_back(0);
    while(!dfs.empty()) {
        I current = dfs.back();
        dfs.pop_back();

        for(I i = 0; i < tree[current].children.size(); ++i) {
            I child = tree[current].children[i];
            if(tree[current].parent == child) {
                continue;
            }
            tree[child].parent = current;
            tree[child].w = tree[current].weights[i];
            dfs.push_back(child);
            seq.push_back(child);
        }
    }
    tree[0].parent = -1;

    //for(I i : seq) cout << i << ' '; cout << '\n';

    for(I i = 0; i < m; ++i) {
        I x;
        cin >> x;
        --x;
        tree[x].must_visit = true;
    }

    for(I i = n - 1; i >= 0; --i) {
        I now = seq[i];

        if(tree[now].parent != -1 && (tree[now].must_visit || tree[now].score > 0)) {
            tree[tree[now].parent].score += tree[now].score + 2 * tree[now].w;
        }

        //cout << now << ": " << tree[now].score << '\n';
    }

    cout << tree[0].score << '\n';

    return 0;
}
