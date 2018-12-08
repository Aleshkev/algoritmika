#include <iostream>

using namespace std;

typedef long long unsigned U;
typedef long long int I;

int main()
{
    cout.sync_with_stdio(false);

    U n, goalX;  // Liczba przeszkod, x mety
    cin >> n >> goalX;

    I minA = 0, maxB = 0;
    U minAFlaps = 0;

    bool lost = false;

    U lastX = 0;
    for(U i = 0; i < n; ++i) {
        U x;  // x przeszkody
        I a, b;  // poczatek i koniec przerwy w przeszkodzie
        cin >> x >> a >> b;

        U deltaX = x - lastX;

        I newMinA = minA - deltaX;
        if(newMinA <= a) {
            if((x + a) % 2 == 0) {
                ++a;
            }

            minAFlaps += (a - newMinA + 1) / 2;
            newMinA = a + 1;
        }
        minA = newMinA;

        I newMaxB = maxB + deltaX;
        if(newMaxB >= b) {
            if((x + b) % 2 == 0) {
                --b;
            }

            newMaxB = b - 1;
        }
        maxB = newMaxB;

        if(minA > maxB) {
            // Nie da sie przejsc poziomu
            lost = true;
            break;
        }

        lastX = x;
    }

    if(!lost) {
        cout << minAFlaps << '\n';
    } else {
        cout << "NIE" << '\n';
    }

    cout.flush();

    return 0;
}
