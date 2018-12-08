#include <iostream>
#include <algorithm>

using namespace std;

typedef int I;
const I inf = 1e8;

inline I abs(I a) {
    return a >= 0 ? a : -a;
}

struct Shroom {
    I position;
    I time;
    I weight;
};
bool by_time(const Shroom &l, const Shroom &r) { return l.time < r.time; };

int main()
{
    cout.sync_with_stdio(false);

    I n, m;
    cin >> n >> m;

    //-- Polaczenia --//

    I **distances = new I*[n];
    for(I i = 0; i < n; ++i) {
        distances[i] = new I[n];
        fill(distances[i], distances[i] + n, inf);
        distances[i][i] = 0;
    }

    for(I i = 0; i < m; ++i) {
        I a, b, d;
        cin >> a >> b >> d;
        --a; --b;
        distances[a][b] = distances[b][a] = min(d, distances[a][b]);
    }

    for(I i = 0; i < n; ++i) {
        for(I j = 0; j < n; ++j) {
            for(I k = 0; k < n; ++k) {
                if(distances[i][k] + distances[k][j] < distances[i][j]) {
                    distances[i][j] = distances[i][k] + distances[k][j];
                }
            }
        }
    }

    /*for(I i = 0; i < n; ++i) {
        for(I j = 0; j < n; ++j) {
            cout << distances[i][j] << " ";
        } cout << endl;
    }*/

    I o;
    cin >> o;

    Shroom *shrooms = new Shroom[o];
    for(I i = 0; i < o; ++i) {
        cin >> shrooms[i].position >> shrooms[i].time >> shrooms[i].weight;
        --shrooms[i].position;
    }

    sort(shrooms, shrooms + o, by_time);

    I *dp = new I[o];

    if(distances[0][shrooms[0].position] <= shrooms[0].time) {
        dp[0] = shrooms[0].weight;
    } else {
        dp[0] = 0;
    }

    for(I i = 1; i < o; ++i) {
        dp[i] = 0;
        for(I j = 0; j < i; ++j) {
            //cout << "distances[" << j << "][" << i << "] = " << distances[i][j] << " <= " << shrooms[i].time - shrooms[j].time << endl;
            if(distances[shrooms[j].position][shrooms[i].position] <= (shrooms[i].time - shrooms[j].time)) {
                //cout << "     true" << endl;
                dp[i] = max(dp[i], dp[j] + shrooms[i].weight);
            }
        }
    }

    /*for(I i = 0; i < o; ++i) {
        cout << dp[i] << " ";
    } cout << endl;*/

    cout << *max_element(dp, dp + o) << '\n';

    return 0;
}
