#include <iostream>

using namespace std;

typedef size_t U;
const U inf = 1000000000 + 1;

int main()
{
    U n, k, m;
    cin >> n >> k >> m;


    U **distances = new U *[n];
    for(U i = 0; i < n; ++i) {
        distances[i] = new U[n];

        for(U j = 0; j < n; ++j) {
            distances[i][j] = (i == j ? 0 : inf);
        }
    }


    for(U i = 0; i < k; ++i) {
        U a, b, w;
        cin >> a >> b >> w;
        --a; --b;

        distances[a][b] = distances[b][a] = min(distances[a][b], w);
    }


    for(U from = 0; from < n; ++from) {
        for(U to = 0; to < n; ++to) {
            for(U via = 0; via < n; ++via) {
                distances[from][to] = min(distances[from][to],
                                          distances[from][via] + distances[via][to]);
            }
        }
    }


    for(U i = 0; i < m; ++i) {
        U a, b, w;
        cin >> a >> b >> w;
        --a; --b;

        U shortest_path_via_this_edge = min(distances[0][a] + w + distances[b][n - 1],
                                            distances[0][b] + w + distances[a][n - 1]);
        if(shortest_path_via_this_edge < distances[0][n - 1]) {
            distances[a][b] = distances[b][a] = w;

            //for(U from = 0; from < n; ++from) {
            //    for(U to = 0; to < n; ++to) {
            //        distances[from][to] = min(distances[from][to],
            //                                  min(distances[from][a] + w + distances[b][to],
            //                                      distances[from][b] + w + distances[a][to]));
            //    }
            //}
            for(U from = 0; from < n; ++from) {
                for(U to = 0; to < n; ++to) {
                    for(U via = 0; via < n; ++via) {
                        distances[from][to] = min(distances[from][to],
                                                  distances[from][via] + distances[via][to]);
                    }
                }
            }

            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }


    return 0;
}
