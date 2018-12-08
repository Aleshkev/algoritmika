#include <bits/stdc++.h>

using namespace std;

typedef int I;

unordered_map<string, I> name_to_i;

struct Node {
    I parents[18];
    I level;
    I root_distance;

    Node() {
        fill(parents, parents + 18, -1);
        level = 0;
        root_distance = 0;
    }
};
vector<Node> nodes;

void init(string new_town_name) {
    name_to_i[new_town_name] = 0;
    nodes.emplace_back();
}
void nowa_osada(string new_town_name, string old_town_name, I distance) {
    I new_town = name_to_i[new_town_name] = nodes.size();
    I old_town = name_to_i[old_town_name];

    nodes.emplace_back();
    Node &new_node = nodes[new_town], &old_node = nodes[old_town];
    new_node.level = old_node.level + 1;
    new_node.root_distance = old_node.root_distance + distance;

    new_node.parents[0] = old_town;
    for(I i = 1; i < 18; ++i) {
        new_node.parents[i] = (new_node.parents[i - 1] != -1 ? nodes[new_node.parents[i - 1]].parents[i - 1] : -1);
    }
}
int odleglosc(string a, string b) {
    I a_town = name_to_i[a], b_town = name_to_i[b];
    I orig_a_town = a_town, orig_b_town = b_town;

    I common_level = min(nodes[a_town].level, nodes[b_town].level);
    I a_needs = nodes[a_town].level - common_level, b_needs = nodes[b_town].level - common_level;
    for(I i = 0; i < 18; ++i) {
        if(a_needs & (1 << i)) {
            a_town = nodes[a_town].parents[i];
        }
        if(b_needs & (1 << i)) {
            b_town = nodes[b_town].parents[i];
        }
    }

    while(nodes[a_town].parents[0] != nodes[b_town].parents[0]) {
        for(I i = 1; i < 18; ++i) {
            if(nodes[a_town].parents[i] == nodes[b_town].parents[i]) {
                a_town = nodes[a_town].parents[i - 1];
                b_town = nodes[b_town].parents[i - 1];
                break;
            }
        }
    }
    I lca = (a_town == b_town ? a_town : nodes[a_town].parents[0]);

    I result = nodes[orig_a_town].root_distance + nodes[orig_b_town].root_distance - 2 * nodes[lca].root_distance;

    //cout << "LCA(" << a_town << ", " << b_town << ") = " << lca << '\n';

    return result;
}

int main()
{
    for(;;) {
        char cmd;
        cin >> cmd;
        if(cmd == 'I') {
            string nm;
            cin >> nm;
            init(nm);
        } else if(cmd == 'N') {
            string nw, old;
            I dist;
            cin >> nw >> old >> dist;
            nowa_osada(nw, old, dist);
        } else {
            string a, b;
            cin >> a >> b;
            cout << odleglosc(a, b) << endl;
        }
    }
}
