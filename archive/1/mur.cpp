#include <iostream>
#include <cmath>

using namespace std;

typedef long long int I;
int main()
{
    cout.sync_with_stdio(false);

    I m;
    cin >> m;

    for(I i = 0; i < m; ++i) {
        I n;
        I point_x, point_y;
        cin >> n >> point_x >> point_y;

        I first_point_x, first_point_y;
        cin >> first_point_x >> first_point_y;

        I from_x, from_y;
        cin >> from_x >> from_y;

        bool positive = ((point_x - first_point_x) * (from_y - first_point_y) -
                         (point_y - first_point_y) * (from_x - first_point_x)) > 0;

        bool ok = true;

        for(I j = 0; j < n - 2; ++j) {
            I to_x, to_y;
            cin >> to_x >> to_y;

            I d = (point_x - from_x) * (to_y - from_y) - (point_y - from_y) * (to_x - from_x);

            if(positive ? d <= 0 : d >= 0) {
                ok = false;
            }

            from_x = to_x; from_y = to_y;
        }

        cout << (ok ? "TAK" : "NIE") << '\n';
    }

    return 0;
}
