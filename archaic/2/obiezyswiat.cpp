#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef long long int I;

struct Node {
    vector<I> edges;
};

int main()
{
    cout.sync_with_stdio(false);

    I n, m;
    cin >> n >> m;

    Node *tree = new Node[n];

    for(I i = 0; i < n - 1; ++i) {
        I a, b;
        cin >> a >> b;
        --a; --b;

        tree[a].edges.push_back(b);
        tree[b].edges.push_back(a);
    }

    bool *visited = new bool[n];
    fill(visited, visited + n, false);
    visited[0] = true;
    stack<I> dfs, levels;
    dfs.push(0);
    levels.push(1);

    I max_level = 0, max_node = 0;
    while(!dfs.empty()) {
        I node = dfs.top();
        I level = levels.top();
        dfs.pop(); levels.pop();

        for(I i = 0; i < tree[node].edges.size(); ++i) {
            I child = tree[node].edges[i];
            if(!visited[child]) {
                dfs.push(child);
                levels.push(level + 1);
                visited[child] = true;
            }
        }

        if(level > max_level) {
            max_level = level;
            max_node = node;
        }
    }

    //cout << "max_node=" << max_node << endl;

    fill(visited, visited + n, false);
    visited[max_node] = true;
    dfs.push(max_node);
    levels.push(1);
    I new_max_level = 0, new_max_node;
    while(!dfs.empty()) {
        I node = dfs.top();
        I level = levels.top();
        dfs.pop(); levels.pop();

        for(I i = 0; i < tree[node].edges.size(); ++i) {
            I child = tree[node].edges[i];
            if(!visited[child]) {
                dfs.push(child);
                levels.push(level + 1);
                visited[child] = true;
            }
        }

        if(level > new_max_level) {
            new_max_level = level;
            new_max_node = node;
        }
    }

    //cout << "new_max_node=" << new_max_node << " (new_max_level=" << new_max_level << ")" << endl;

    I c = new_max_level;
    I budget_left = m - new_max_level + 1;
    //cout << c << " cities can be visited in straight line, " << budget_left << " credits left" << endl;
    if(budget_left <= 0) {
        //cout << "not enough credits!" << endl;
        cout << m + 1 << '\n';
        return 0;
    }

    //cout << n - c << " cities left to visit with " << budget_left << " credits" << endl;
    I cities_left = n - c;
    while(cities_left > 0 && budget_left >= 2) {
        --cities_left;
        ++c;
        budget_left -= 2;
    }
    //cout << c << " cities can be visited including these on sides" << endl;

    cout << c << endl;

    return 0;
}
