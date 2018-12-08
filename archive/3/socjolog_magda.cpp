#include <bits/stdc++.h>

using namespace std;

typedef int I;

struct Node {
    I height;

    vector<I> neighbors;
};

int main()
{
    I n, m;
    scanf("%i %i", &n, &m);

    static Node tree[1000000];

    for(I i = 0; i < n; ++i) {
        scanf("%i", &tree[i].height);
    }

    for(I i = 0; i < m; ++i) {
        I a, b;
        scanf("%i %i", &a, &b);
        --a; --b;

        tree[a].neighbors.push_back(b);
        tree[b].neighbors.push_back(a);
    }

    static bool visited[1000000];
    fill(visited, visited + n, false);

    vector<I> diffs;

    for(I i = 0; i < n; ++i) {
        if(visited[i]) continue;

        I min_h, max_h;
        min_h = max_h = tree[i].height;

        vector<I> stck;
        stck.push_back(i);
        while(!stck.empty()) {
            I j = stck.back();
            stck.pop_back();

            min_h = min(min_h, tree[j].height);
            max_h = max(max_h, tree[j].height);

            for(I k = 0; k < tree[j].neighbors.size(); ++k) {
                I g = tree[j].neighbors[k];
                if(visited[g]) continue;
                stck.push_back(g);
                visited[g] = true;
            }
        }

        diffs.push_back(max_h - min_h);
    }

    sort(diffs.begin(), diffs.end());

    for(I i = 0; i < diffs.size(); ++i) {
        printf("%i ", diffs[i]);
    } puts("\n");


    return 0;
}
