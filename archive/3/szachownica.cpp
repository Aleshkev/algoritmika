#include <bits/stdc++.h>

using namespace std;

typedef long int I;

struct Segment {
    I start, stop;
    I i;
};
bool by_start(Segment l, Segment r) {return l.start < r.start; }
struct reversed_by_stop {bool operator()(Segment l, Segment r) {return l.stop > r.stop; }};

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(0);

    I n;
    cin >> n;

    vector<Segment> x_segments(n), y_segments(n);
    for(I i = 0; i < n; ++i) {
        cin >> x_segments[i].start >> y_segments[i].start >> x_segments[i].stop >> y_segments[i].stop;
        x_segments[i].i = y_segments[i].i = i;
    }
    sort(x_segments.begin(), x_segments.end(), by_start);
    sort(y_segments.begin(), y_segments.end(), by_start);

    vector<I> x_positions(n), y_positions(n);

    priority_queue<Segment, vector<Segment>, reversed_by_stop> x_q, y_q;

    for(I i = 1, j = 0; i <= n; ++i) {
        while(j < n && x_segments[j].start <= i) {
            x_q.push(x_segments[j]);
            ++j;
        }
        if(!x_q.empty()) {
            x_positions[x_q.top().i] = i;
            x_q.pop();
        }
    }
    for(I i = 1, j = 0; i <= n; ++i) {
        while(j < n && y_segments[j].start <= i) {
            y_q.push(y_segments[j]);
            ++j;
        }
        if(!y_q.empty()) {
            y_positions[y_q.top().i] = i;
            y_q.pop();
        }
    }

    for(I i = 0; i < n; ++i) {
        cout << x_positions[i] << ' ' << y_positions[i] << '\n';
    }


    return 0;
}
