#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

int main()
{
    I n;
    cin >> n;

    vector<vector<I>> najbaroj(n);
    for(I i = 0; i < n - 1; ++i) {
        I a, b;
        cin >> a >> b;
        --a; --b;
        najbaroj[a].push_back(b);
        najbaroj[b].push_back(a);
    }

    if(n <= 20) {
        I min_c = 1e18;

        for(I m = 1; m <= (1 << n); ++m) {
            if(__builtin_popcount(m) > min_c) {
                continue;
            }

            vector<I> burned_neighbors(n);
            deque<I> to_visit;

            for(I i = 0; i < n; ++i) {
                if(m & (1 << i)) {
                    to_visit.push_back(i);
                }
            }

            vector<bool> visited(n);

            I automagic = 0;
            while(!to_visit.empty()) {
                I current = to_visit.front();
                to_visit.pop_front();

                if(visited[current]) {
                    continue;
                } else {
                    visited[current] = true;
                }

                ++automagic;

                for(I najbaro : najbaroj[current]) {
                    ++burned_neighbors[najbaro];
                    if(burned_neighbors[najbaro] == 2) {
                        to_visit.push_back(najbaro);
                    }
                }
            }
            if(automagic == n) {
                //cout << "ok for " << m << '\n';
                min_c = min(min_c, (I)__builtin_popcount(m));
            }
        }
        cout << min_c << '\n';
    }  {
        vector<I> burned_neighbors(n);
        deque<I> to_visit;

        I lone = 0;
        for(I i = 0; i < n; ++i) {
            if(najbaroj[i].size() < 2) {
                to_visit.push_back(i);
                ++lone;
            }
        }

        I automagic = 0;
        while(!to_visit.empty()) {
            I current = to_visit.front();
            to_visit.pop_front();

            ++automagic;

            for(I najbaro : najbaroj[current]) {
                ++burned_neighbors[najbaro];
                if(burned_neighbors[najbaro] == 2) {
                    to_visit.push_back(najbaro);
                }
            }
        }

        //cout << lone << ", " << automagic << '\n';
        cout << (n - automagic) / 2 + lone << '\n';
    }
    return 0;


    return 0;
}
