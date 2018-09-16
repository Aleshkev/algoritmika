#include <bits/stdc++.h>

using namespace std;

typedef long long int I;

int main()
{
    vector<I> primes;  // Liczby pierwsze do 3000

    static bool is_prime[3001];
    is_prime[1] = false;
    fill(is_prime + 2, is_prime + 3001, true);
    for(I i = 2; i <= 3000; ++i) {
        if(!is_prime[i]) continue;
        primes.push_back(i);
        for(I j = i * 2; j <= 3000; j += i) {
            is_prime[j] = false;
        }
    }

    static I t[21][3001];  // t[V][W] = na ile sposobów można otrzymać liczbę W używając V liczb pierwszych

    // t[1][W] jest 1 jeśli W jest pierwsze i 0 w przeciwnym przypadku
    for(I w = 1; w <= 3000; ++w) {
        t[1][w] = (is_prime[w] ? 1 : 0);
    }

    for(I v = 1; v <= 20; ++v) {
        for(I w = 1; w <= 3000; ++w) {
            if(t[v][w] == 0) continue;

            // Indeks liczby pierwszej większej od W
            I gt_prime = distance(primes.begin(), upper_bound(primes.begin(), primes.end(), w));

            for(I i = gt_prime; i < primes.size(); ++i) {
                I prime = primes[i];

                if(w + prime > 3000) break;

                t[v + 1][w + prime] += t[v][w];
            }
        }
    }

    // Wypisuje tabelkę (do cerr, więc nie jest traktowana jako błędny wynik)
    cerr << "   | ";
    for(I w = 1; w <= 30; ++w) {
        cerr << setw(2) << w << " ";
    } cerr << endl;
    cerr << "---+-";
    for(I w = 1; w <= 30; ++w) {
        cerr << "---";
    } cerr << endl;
    for(I v = 1; v <= 6; ++v) {
        cerr << setw(2) << v << " | ";
        for(I w = 1; w <= 30; ++w) {
            cerr << setw(2) << t[v][w].size() << " ";
        } cerr << endl;
    }

    I v, w; cin >> w >> v;
    cout << t[v][w] << endl;


    return 0;
}
