#include <bits/stdc++.h>

using namespace std;

typedef int I;


struct Seq {
    I lvl;
    I c;
    I bx, by;
    I ex, ey;
    Seq(I _lvl, I _c, I _bx, I _by, I _ex, I _ey) : lvl(_lvl), c(_c), bx(_bx), by(_by), ex(_ex), ey(_ey) {};
};
bool operator<(const Seq &l, const Seq &r) {return l.lvl < r.lvl; };
ostream &operator<<(ostream &o, const Seq &l) {
    cout << "<Seq lvl=" << l.lvl << " c=" << char('A'+l.c) << " begin=(" << l.bx << ", " << l.by << ") end=(" << l.ex << ", " << l.ey << ")>";
    return o;
}

typedef vector<Seq> SeqVec;


void do_cell(char **t, I **used_lvl, SeqVec **seq_t, priority_queue<Seq> &q, I x, I y) {
    for(I i = 0; i < seq_t[x][y].size(); ++i) {
        q.push(seq_t[x][y][i]);
    }
    if(!q.empty() && q.top().lvl > used_lvl[x][y]) {
        Seq p = q.top();
        t[x][y] = 'A' + (p.c + max(abs(p.bx - x), abs(p.by - y))) % 26;
        used_lvl[x][y] = p.lvl;
    }
}

int main()
{
    cout.sync_with_stdio(false);

    I h, w, k;
    scanf("%i %i %i", &h, &w, &k);

    char **t = new char*[w];
    for(I i = 0; i < w; ++i) t[i] = new char[h], fill_n(t[i], h, '.');
    I **used_lvl = new I*[w];
    for(I i = 0; i < w; ++i) used_lvl[i] = new I[h], fill_n(used_lvl[i], h, 0);

    SeqVec **seq_n = new SeqVec*[w];
    for(I i = 0; i < w; ++i) seq_n[i] = new SeqVec[h];
    SeqVec **seq_s = new SeqVec*[w];
    for(I i = 0; i < w; ++i) seq_s[i] = new SeqVec[h];
    SeqVec **seq_w = new SeqVec*[w];
    for(I i = 0; i < w; ++i) seq_w[i] = new SeqVec[h];
    SeqVec **seq_e = new SeqVec*[w];
    for(I i = 0; i < w; ++i) seq_e[i] = new SeqVec[h];

    SeqVec **seq_ne = new SeqVec*[w];
    for(I i = 0; i < w; ++i) seq_ne[i] = new SeqVec[h];
    SeqVec **seq_nw = new SeqVec*[w];
    for(I i = 0; i < w; ++i) seq_nw[i] = new SeqVec[h];
    SeqVec **seq_se = new SeqVec*[w];
    for(I i = 0; i < w; ++i) seq_se[i] = new SeqVec[h];
    SeqVec **seq_sw = new SeqVec*[w];
    for(I i = 0; i < w; ++i) seq_sw[i] = new SeqVec[h];

    I x, y;
    if(k > 0) {
        scanf("%i %i", &y, &x); --x; --y;
    }

    I c = 0;
    for(I i = 1; i < k; ++i) {
        I bx = x, by = y;
        scanf("%i %i", &y, &x); --x; --y;
        I ex = x, ey = y;

        if(bx == ex) {
            if(by > ey) {
                seq_n[bx][by].push_back(Seq(i, c, bx, by, ex, ey));
            } else if(by < ey) {
                seq_s[bx][by].push_back(Seq(i, c, bx, by, ex, ey));
            }
        } else if(by == ey) {
            if(bx < ex) {
                seq_e[bx][by].push_back(Seq(i, c, bx, by, ex, ey));
            } else if(bx > ex) {
                seq_w[bx][by].push_back(Seq(i, c, bx, by, ex, ey));
            }
        } else {
            I dx = ex - bx, dy = ey - by;
            if(dx > 0) {
                if(dy > 0) {
                    if(dx > dy) {
                        seq_se[bx][by].push_back(Seq(i, c, bx, by, bx + dy, by + dy));
                        seq_e[bx + dy][by + dy].push_back(Seq(i, c + dy, bx + dy, by + dy, ex, ey));
                    } else {
                        seq_se[bx][by].push_back(Seq(i, c, bx, by, bx + dx, by + dx));
                        seq_s[bx + dx][by + dx].push_back(Seq(i, c + dx, bx + dx, by + dx, ex, ey));
                    }
                } else {
                    if(dx > -dy) {
                        seq_ne[bx][by].push_back(Seq(i, c, bx, by, bx - dy, by + dy));
                        seq_e[bx - dy][by + dy].push_back(Seq(i, c - dy, bx - dy, by + dy, ex, ey));
                    } else {
                        seq_ne[bx][by].push_back(Seq(i, c, bx, by, bx + dx, by - dx));
                        seq_n[bx + dx][by - dx].push_back(Seq(i, c + dx, bx + dx, by - dx, ex, ey));
                    }
                }
            } else {
                if(dy > 0) {
                    if(-dx > dy) {
                        seq_sw[bx][by].push_back(Seq(i, c, bx, by, bx - dy, by + dy));
                        seq_w[bx - dy][by + dy].push_back(Seq(i, c + dy, bx - dy, by + dy, ex, ey));
                    } else {
                        seq_sw[bx][by].push_back(Seq(i, c, bx, by, bx + dx, by - dx));
                        seq_s[bx + dx][by - dx].push_back(Seq(i, c - dx, bx + dx, by - dx, ex, ey));
                    }
                } else {
                    if(-dx > -dy) {
                        seq_nw[bx][by].push_back(Seq(i, c, bx, by, bx + dy, by + dy));
                        seq_w[bx + dy][by + dy].push_back(Seq(i, c - dy, bx + dy, by + dy, ex, ey));
                    } else {
                        seq_nw[bx][by].push_back(Seq(i, c, bx, by, bx + dx, by + dx));
                        seq_n[bx + dx][by + dx].push_back(Seq(i, c - dx, bx + dx, by + dx, ex, ey));
                    }
                }
            }
        }

        c += max(abs(ex - bx), abs(ey - by));
        c %= 26;
    }

    //seq_n[0][3].push_back(Seq(2, 3, 0, 3, 0, 2));

    for(I x = 0; x < w; ++x) {  // N
        priority_queue<Seq> q;
        for(I y = h - 1; y >= 0; --y) {
            do_cell(t, used_lvl, seq_n, q, x, y);
            while(!q.empty() && q.top().ey >= y) q.pop();
        }
    }
    for(I x = 0; x < w; ++x) {  // S
        priority_queue<Seq> q;
        for(I y = 0; y < h; ++y) {
            do_cell(t, used_lvl, seq_s, q, x, y);
            while(!q.empty() && q.top().ey <= y) q.pop();
        }
    }
    for(I y = 0; y < h; ++y) {  // W
        priority_queue<Seq> q;
        for(I x = w - 1; x >= 0; --x) {
            do_cell(t, used_lvl, seq_w, q, x, y);
            while(!q.empty() && q.top().ex >= x) q.pop();
        }
    }
    for(I y = 0; y < h; ++y) {  // E
        priority_queue<Seq> q;
        for(I x = 0; x < w; ++x) {
            do_cell(t, used_lvl, seq_e, q, x, y);
            while(!q.empty() && q.top().ex <= x) q.pop();
        }
    }

    for(I u = 0; u < h; ++u) {  // SE
        priority_queue<Seq> q;
        for(I x = 0, y = u; x < w && y < h; ++x, ++y) {
            do_cell(t, used_lvl, seq_se, q, x, y);
            while(!q.empty() && q.top().ex <= x) q.pop();
        }
    } for(I v = 1; v < w; ++v) {
        priority_queue<Seq> q;
        for(I x = v, y = 0; x < w && y < h; ++x, ++y) {
            do_cell(t, used_lvl, seq_se, q, x, y);
            while(!q.empty() && q.top().ex <= x) q.pop();
        }
    }

    for(I u = 0; u < h; ++u) {  // NE
        priority_queue<Seq> q;
        for(I x = 0, y = u; x < w && y >= 0; ++x, --y) {
            do_cell(t, used_lvl, seq_ne, q, x, y);
            while(!q.empty() && q.top().ex <= x) q.pop();
        }
    } for(I v = 1; v < w; ++v) {
        priority_queue<Seq> q;
        for(I x = v, y = h - 1; x < w && y >= 0; ++x, --y) {
            do_cell(t, used_lvl, seq_ne, q, x, y);
            while(!q.empty() && q.top().ex <= x) q.pop();
        }
    }

    for(I u = 0; u < h; ++u) {  // NW
        priority_queue<Seq> q;
        for(I x = w - 1, y = u; x >= 0 && y >= 0; --x, --y) {
            do_cell(t, used_lvl, seq_nw, q, x, y);
            while(!q.empty() && q.top().ex >= x) q.pop();
        }
    } for(I v = 0; v < w - 1; ++v) {
        priority_queue<Seq> q;
        for(I x = v, y = h - 1; x >= 0 && y >= 0; --x, --y) {
            do_cell(t, used_lvl, seq_nw, q, x, y);
            while(!q.empty() && q.top().ex >= x) q.pop();
        }
    }

    for(I u = 0; u < h; ++u) {  // SW
        priority_queue<Seq> q;
        for(I x = w - 1, y = u; x >= 0 && y < h; --x, ++y) {
            do_cell(t, used_lvl, seq_sw, q, x, y);
            while(!q.empty() && q.top().ex >= x) q.pop();
        }
    } for(I v = 0; v < w - 1; ++v) {
        priority_queue<Seq> q;
        for(I x = v, y = 0; x >= 0 && y < h; --x, ++y) {
            do_cell(t, used_lvl, seq_sw, q, x, y);
            while(!q.empty() && q.top().ex >= x) q.pop();
        }
    }

    for(I y = 0; y < h; ++y) {
        for(I x = 0; x < w; ++x) {
            printf("%c", t[x][y]);
        } printf("\n");
    }

    return 0;
}
