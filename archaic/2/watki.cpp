#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long int I;

struct Node {
    I level;
    vector<I> neighbors;
    vector<I> neighbors_path_lengths;
    vector<I> children;
    I parent;

    I path_len;

    I l;
    bool alive;
};
bool operator<(Node &l, Node &r) {
    return &l.level < &r.level;
}

Node *graph;

I find_path(I a, I b, I inc) {
    while(a != b) {
        if(graph[a].level >= graph[b].level) {
            graph[a].l += inc;
            a = graph[a].parent;
        } else {
            graph[b].l += inc;
            b = graph[b].parent;
        }
    }
    cout << "found " << a << " " << b << endl;
}

int main()
{
    I n;
    cin >> n;

    graph = new Node[n];

    for(I i = 0; i < n; ++i) {
        graph[i].l = 0;
    }

    for(I i = 0; i < n - 1; ++i) {
        I a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        graph[a].neighbors.push_back(b);
        graph[b].neighbors.push_back(a);
        graph[a].neighbors_path_lengths.push_back(c);
        graph[b].neighbors_path_lengths.push_back(c);
    }

    bool *visited = new bool[n];
    fill(visited, visited + n, false);
    vector<I> dfs;
    dfs.push_back(0);
    vector<I> levels;
    levels.push_back(0);
    visited[0] = true;

    while(!dfs.empty()) {
        I i = dfs.back();
        dfs.pop_back();
        I level = levels.back();
        levels.pop_back();

        graph[i].level = level;

        for(I j = 0; j < graph[i].neighbors.size(); ++j) {
            I neighbor = graph[i].neighbors[j];
            if(!visited[neighbor]) {
                dfs.push_back(neighbor);
                levels.push_back(level + 1);
                visited[neighbor] = true;

                graph[i].children.push_back(neighbor);
                graph[neighbor].parent = i;
                graph[neighbor].path_len = graph[i].neighbors_path_lengths[j];
            }
        }
    }

    /*for(I i = 0;;) {
        char c;
        cin >> c;
        if(c == 'I') {
            I a;
            cin >> a;
            cout << "level=" << graph[a].level << " children=";
            for(I j = 0; j < graph[a].children.size(); ++j) {
                cout << graph[a].children[j] << " ";
            } cout << " pathlen=" << graph[a].path_len << " l=" << graph[a].l << endl;
        } else if(c == 'P') {
            I a, b;
            cin >> a >> b;
            find_path(a, b, 1);
        }
    }*/

    set<I> alive;

    I m;
    cin >> m;
    for(I i = 0; i < m; ++i) {
        I a;
        cin >> a;
        --a;
        for(set<I>::iterator j = alive.begin(); j != alive.end(); ++j) {
            I self = a, other = *j;
            if(graph[self].alive) {
                alive.erase(self);
                find_path(self, other, -1);
            } else {
                alive.insert(self);
                find_path(self, other, 1);
            }
        }

        I c = 0;
        for(I j = 0; j < n; ++j) {
            if(graph[j].l > 0) {
                c += graph[j].path_len;
            }
        }
        cout << c << endl;
    }

    return 0;
}
