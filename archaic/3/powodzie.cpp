#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
typedef pair<I, I> II;
ostream &operator<<(ostream &o, const II &p) {
    o << '(' << p.first << ", " << p.second << ')';
    return o;
}

const I lim = 1000000007;


I field_size_y, field_size_x, max_water_level;


struct Group {
    II parent;
    I combinations;
    I last_join_h;
    Group(II p) : parent(p), combinations(1), last_join_h(0) {};
};
vector<vector<Group>> fau;
void fau_init() {
    for(I x = 0; x < field_size_x; ++x) {
        fau.emplace_back();
        for(I y = 0; y < field_size_y; ++y) {
            fau[x].push_back(Group({x, y}));
        }
    }
}
II fau_find_root(II x) {
    II *parent = &fau[x.first][x.second].parent;
    if(*parent != x) {
        *parent = fau_find_root(*parent);
    }
    return *parent;
}
void fau_join(II a, II b, I current_h) {
    II root_a = fau_find_root(a), root_b = fau_find_root(b);
    if(root_a == root_b) {
        return;
    }

    Group *group_a = &fau[root_a.first][root_a.second], *group_b = &fau[root_b.first][root_b.second];

    group_b->parent = root_a;
    group_a->combinations = ((group_a->combinations + (current_h - group_a->last_join_h) % lim) *
                             (group_b->combinations + (current_h - group_b->last_join_h) % lim)) % lim;
    group_a->last_join_h = current_h;
}
/*void fau_debug() {
    for(I y = 0; y < field_size_y; ++y) {
        for(I x = 0; x < field_size_x; ++x) {
            II r = fau_find_root({x, y});
            Group g = fau[r.first][r.second];
            cout << g.combinations << ' ';
        } cout << '\n';
    }
}*/


struct Dam {
    II a, b;
    I h;
    Dam(II a, II b, I h) : a(a), b(b), h(h) {};
};
bool by_h(Dam l, Dam r) {
    return l.h < r.h;
}
vector<Dam> dams;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> field_size_y >> field_size_x >> max_water_level;

    fau_init();

    for(I y = 0; y < field_size_y; ++y) {
        for(I x = 0; x < field_size_x - 1; ++x) {
            I h;
            cin >> h;
            dams.push_back(Dam({x, y}, {x + 1, y}, min(h, max_water_level)));
        }
    }
    for(I y = 0; y < field_size_y - 1; ++y) {
        for(I x = 0; x < field_size_x; ++x) {
            I h;
            cin >> h;
            dams.push_back(Dam({x, y}, {x, y + 1}, h));
        }
    }
    sort(dams.begin(), dams.end(), by_h);

    for(I i = 0; i < dams.size(); ++i) {
        fau_join(dams[i].a, dams[i].b, dams[i].h);
    }

    I c = 0;
    for(I x = 0; x < field_size_x; ++x) {
        for(I y = 0; y < field_size_y; ++y) {
            if(fau[x][y].parent != make_pair(x, y)) {
                continue;
            }
            fau[x][y].combinations += max_water_level - fau[x][y].last_join_h;
            c += fau[x][y].combinations % lim;
            c %= lim;
        }
    }

    cout << c << '\n';

    return 0;
}
