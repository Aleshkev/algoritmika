#include <iostream>
#include <vector>

using namespace std;

typedef long long int I;

int main()
{
    cout.sync_with_stdio(false);

    I w, h;  // Szerokość, wysokość planszy
    cin >> h >> w;

    // Wczytywanie planszy
    I **t = new I*[w];
    for(I x = 0; x < w; ++x) {
        t[x] = new I[h];
    }
    for(I y = 0; y < h; ++y) {
        for(I x = 0; x < w; ++x) {
            cin >> t[x][y];
        }
    }

    I n, m;  // Liczba ruchów, długość węża
    cin >> n >> m;

    I *v = new I[n];  // v[i] -> ile segmentów węża w `i`-tym ruchu jest na pasującym polu
    fill(v, v + n, 0);

    // Na pierwszej komórce na planszy wąż pojawia się na początku
    I a = t[0][0] - 1 - 1;
    if(0 <= a && a < n) {
        ++v[a];
    }

    I hx = 0, hy = 0;  // Obecna pozycja głowy węża
    for(I i = 0; i < n; ++i) {
        char c;
        cin >> c;

        // Ruch węża
        if(c == 'N') {
            --hy;
        } else if(c == 'E') {
            ++hx;
        } else if(c == 'S') {
            ++hy;
        } else if(c == 'W') {
            --hx;
        }

        // Dodanie 1 do odpowiedniego elementu `v`
        if(t[hx][hy] <= m) {
            I j = i + t[hx][hy] - 1;
            if(j < n) {
                ++v[j];
            }
        }

        cout << v[i] << ' ';
    }

    return 0;
}
