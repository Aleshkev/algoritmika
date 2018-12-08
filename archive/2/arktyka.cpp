#include <iostream>

using namespace std;

typedef long long int I;

// Tablica sum prefiksowych
I prefix_sums[1000][1000];

I count_floes(I beginx, I beginy, I square_size) {
    // Liczy liczbę kier w kwadracie o początku w punkcie (beginx, beginy) i boku square_size
    I endx = beginx + square_size - 1, endy = beginy + square_size - 1;
    I floes = prefix_sums[endx][endy];
    if(beginx > 0) floes -= prefix_sums[beginx - 1][endy];
    if(beginy > 0) floes -= prefix_sums[endx][beginy - 1];
    if(beginx > 0 && beginy > 0) floes += prefix_sums[beginx - 1][beginy - 1];
    return floes;
}

int main() {
    cout.sync_with_stdio(false);

    I h, w, l; cin >> h >> w >> l;

    static bool t[1000][1000];  // Mapa Oceanu Arktycznego
    for(I y = 0; y < h; ++y) {
        for(I x = 0; x < w; ++x) {
            char c; cin >> c;
            t[x][y] = (c == '#');
        }
    }

    // Wypełnianie tablicy sum prefiksowych
    prefix_sums[0][0] = t[0][0];
    for(I x = 1; x < w; ++x) {
        prefix_sums[x][0] = prefix_sums[x - 1][0] + t[x][0];
    }
    for(I y = 1; y < h; ++y) {
        prefix_sums[0][y] = prefix_sums[0][y - 1] + t[0][y];
    }
    for(I x = 1; x < w; ++x) {
        for(I y = 1; y < h; ++y) {
            prefix_sums[x][y] = (prefix_sums[x - 1][y] + prefix_sums[x][y - 1] -
                                 prefix_sums[x - 1][y - 1] + t[x][y]);
        }
    }

    // Wynik
    I score = 0;

    for(I y = 0; y < h; ++y) {
        for(I x = 0; x < w; ++x) {
            I max_size = min(w - x, h - y);  // Kwadrat nie może wychodzić za planszę

            // Wyszukiwanie binarne
                I current_size = max_size / 2;
                if(current_size == 0) current_size = 1;

                I step = max_size / 4;
                if(step == 0) step = 1;

                while(step >= 1) {
                    I floes = count_floes(x, y, current_size);

                    if(floes < l) {
                        current_size += step;
                    } else if(floes > l) {
                        current_size -= step;
                    } else {
                        break;
                    }

                    step /= 2;
                }

            // Teraz wiemy już gdzie na pewno jest odpowiednia liczba kier. Ale może być też odpowiednia liczba w mniejszym
            // lub większym kwadracie.
            // W zasadzie nie wiemy, że jest odpowiednia liczba kier, ale w takim razie nie wchodzimy w tę pętlę.
            for(I current_local_size = current_size - 1; current_local_size > 0; --current_local_size) {
                if(count_floes(x, y, current_local_size) == l) {
                    ++score;
                }
            }
            for(I current_local_size = current_size; current_local_size <= max_size; ++current_local_size) {
                if(count_floes(x, y, current_local_size) == l) {
                    ++score;
                }
            }
        }
    }

    cout << score << '\n';

    return 0;
}
