#include <bits/stdc++.h>

using namespace std;

typedef long long int I;
typedef pair<I, I> II;

ostream &operator<<(ostream &o, const II &p) {
    o << '(' << p.first << ", " << p.second << ')';
    return o;
};


struct Span {
    I a, b;
    I index;
};
bool operator<(const Span &l, const Span &r) {
    return l.a < r.a;
}


I n, k;
Span t[1000000];


I lawyers_available_for_x(I x) {
    map<I, I> events;

    //cout << "for x=" << x << ": ";
    for(I i = 0; i < n; ++i) {
        if(t[i].b - t[i].a + 1 > x) {
            //cout << II(t[i].a, t[i].b - x) << ' ';
            events[t[i].a] += 1;
            events[t[i].b - x + 1] -= 1;
        }
    }
    //cout << "-> ";

    I c = 0;
    for(auto &e : events) {
        c += e.second;
        if(c >= k) {
            //cout << "true (" << e.first << ")\n";
            return e.first;
        }
    }
    //cout << "false\n" ;
    return -1;
}

void output_lawyers(I x) {
    map<I, vector<I> > add, rem;
    set<I> event_points;

    //cout << "adding events...";
    for(I i = 0; i < n; ++i) {
        if(t[i].b - t[i].a + 1 > x) {
            //cout << II(t[i].first, t[i].second - x) << ' ';
            add[t[i].a].push_back(t[i].index);
            rem[t[i].b - x + 1].push_back(t[i].index);
            event_points.insert(t[i].a);
            event_points.insert(t[i].b - x + 1);
        }
    }

    set<I> current;

    //cout << "walking... ";
    for(auto e : event_points) {
        //cout << "event " << e << endl;
        //cout << " adding: ";
        for(auto i : add[e]) {
            //cout << i << ' ';
            current.insert(i);
        } //cout << endl;
        //cout << " removing: ";
        for(auto i : rem[e]) {
            //cout << i << ' ';
            current.erase(current.find(i));
        } //cout << endl;
        //cout << " size: " << current.size() << endl;
        if(current.size() >= k) {
            //cout << e << endl;
            for(auto i : current) {
                cout << i + 1 << ' ';
            } cout << '\n';
            return;
        }
    }
}


int main()
{
    cout.sync_with_stdio(false);

    cin >> n >> k;

    for(I i = 0; i < n; ++i) {
        cin >> t[i].a >> t[i].b;
        t[i].index = i;
    }
    sort(t, t + n);

    for(I i = 1; i <= 12; ++i) {
        lawyers_available_for_x(i);
    }

    I lo = 1, hi = (1 << 20);
    I val;
    for(; lo < hi;) {
        I mid = (lo + hi) / 2;
        val = lawyers_available_for_x(mid);

        if(val != -1) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    --lo;
    //val = lawyers_available_for_x(lo);
    cout << lo << '\n';
    output_lawyers(lo);

    return 0;
}
