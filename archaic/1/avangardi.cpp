#include <iostream>

using namespace std;

typedef long long unsigned U;
typedef long long int I;
const U inf = 1e16;

int main()
{
    U n, m;  // Liczba skrzyżowań, liczba ulic
    cin >> n >> m;
    ++n;

    U **dist = new U *[n];
    for(U i = 0; i < n; ++i) {
        dist[i] = new U[n];
        for(U j = 0; j < n; ++j) {
            dist[i][j] = (i == j ? 0 : inf);
        }
    }

    for(U i = 0; i < m; ++i) {
        U a, b, len;
        cin >> a >> b >> len;
        --a; --b;
        dist[a][b] = min(dist[a][b], len);
    }

    for(U i = 0; i < n; ++i) {
        for(U j = 0; j < n; ++j) {
            for(U k = 0; k < n; ++k) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    U **new_dist = new U *[n];
    for(U i = 0; i < n; ++i) {
        new_dist[i] = new U[n];
        for(U j = 0; j < n; ++j) {
            new_dist[i][j] = dist[i][j];
        }
    }

    U o;  // Liczba zapytań
    cin >> o;
    U *questions_a = new U[o], *questions_b = new U[o];
    for(U i = 0; i < o; ++i) {
        cin >> questions_a[i] >> questions_b[i];
        --questions_a[i]; --questions_b[i];
    }

    U p;  // Liczba nowych dróg
    cin >> p;
    for(U i = 0; i < p; ++i) {
        U a, b, len;
        cin >> a >> b >> len;
        --a; --b;

        new_dist[a][b] = min(new_dist[a][b], len);
    }

    for(U i = 0; i < n; ++i) {
        for(U j = 0; j < n; ++j) {
            for(U k = 0; k < n; ++k) {
                new_dist[i][j] = min(new_dist[i][j], new_dist[i][k] + new_dist[k][j]);
            }
        }
    }

    for(U i = 0; i < o; ++i) {
        I dist0 = dist[questions_a[i]][questions_b[i]],
            dist1 = new_dist[questions_a[i]][questions_b[i]];
        if(dist0 >= inf) dist0 = -1;
        if(dist1 >= inf) dist1 = -1;
        cout << dist0 << "  " << dist1 << '\n';
    }

    return 0;
}
