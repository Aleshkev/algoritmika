#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
typedef pair<I, I> II;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    I h, w, k;
    cin >> h >> w >> k;

    static I t[3000][3000];
    for(I y = 0; y < h; ++y) {
        for(I x = 0; x < w; ++x) {
            //t[x][y] = x + y;
            cin >> t[x][y];
        }
    }

    static I u[(I)1e5 + 10] = {0};

    I max_d = 0, sum_d = 0;

    for(I y = 0; y <= h - k; ++y) {
        I d = 0;

        for(I dx = 0; dx < k; ++dx) {
            for(I dy = y; dy < y + k; ++dy) {
                if(u[t[dx][dy]] == 0) {
                    ++d;
                }
                ++u[t[dx][dy]];
            }
        }

        max_d = max(max_d, d);
        sum_d += d;
        //cout << d << " ";

        /*cout << "(";
        for(I i = 0; i < 20; ++i) {
            for(I j = 0; j < u[i]; ++j) {
                cout << i << " ";
            }
        } cout << ") ";*/

        for(I x = 1; x <= w - k; ++x) {

            for(I dy = y; dy < y + k; ++dy) {
                //cout << "[rem" << x - 1 << "," << dy << "]";
                --u[t[x - 1][dy]];
                if(u[t[x - 1][dy]] == 0) {
                    --d;
                }

                //cout << "[add" << x + k - 1 << "," << dy << "]";
                if(u[t[x + k - 1][dy]] == 0) {
                    ++d;
                }
                ++u[t[x + k - 1][dy]];
            }

            max_d = max(max_d, d);
            sum_d += d;
            //cout << d << " ";

            /*cout << "(";
            for(I i = 0; i < 20; ++i) {
                for(I j = 0; j < u[i]; ++j) {
                    cout << i << " ";
                }
            } cout << ") ";*/
        }

        for(I dx = w - k; dx < w; ++dx) {
            for(I dy = y; dy < y + k; ++dy) {
                --u[t[dx][dy]];
            }
        }
        //cout << endl;
    }

    cout << max_d << ' ' << sum_d << '\n';

    return 0;
}
