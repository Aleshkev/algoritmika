#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
typedef pair<I, I> II;

I feld_h, feld_w;

struct Tile {
    II parent;
    I h;
    Tile(II p, I h) : parent(p), h(h) {};
};
bool by_h(Tile l, Tile r) {
    return abs(l) < abs(r);
}
Tile tiles[1000][1000];

II find_root(II x) {
    if(tiles[x.first][x.second] != x) {
        tiles[x.first][x.second] = find_root(tiles[x.first][x.second]);
    }
    return tiles[x.first][x.second];
}
void join(II a, II b) {
    a = find_root(a);
    b = find_root(b);

    tiles[b.first][b.second].parent = a;
}

bool handled[1000][1000];



int main()
{
    vector<Tile> to_handle;

    cin >> feld_h >> feld_w;
    for(I y = 0; y < feld_h; ++y) {
        for(I x = 0; x < feld_w; ++x) {
            cin >> tiles[x][y].h;
            tiles[x][y].parent = {x, y};
            handled[x][y] = false;

            if(tiles[x][y].h > 0) {
                to_handle.push_back(tiles[x][y]);
            } else {
                handled[x][y] = true;
            }
        }
    }

    sort(to_handle.begin(), to_handle.end(), by_h);

    for(Tile t : to_handle) {
        if(handled[t.parent.first][t.parent.second]) {
            continue;
        }

        vector<II> stck;
        stck.push_back(t.parent);
        handled[t.parent.first][t.parent.second] = true;
        while(!stck.empty()) {
            II top = stck.back();
            stck.pop_back();

            if(!handled[top.first - 1])
        }
    }

    return 0;
}
