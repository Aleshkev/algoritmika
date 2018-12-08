#include <iostream>

using namespace std;

typedef int I;

int main() {
    cout.sync_with_stdio(false);

    I n; cin >> n;

    static I a[1000000], b[1000000];  // a[i], b[i] -> najniższa, najwyższa możliwa temperatura w i-tym dniu
    for(I i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    I max_c = 0;  // Największa znaleziona dotychczas długość
    I c = 1;  // Obecna długość ciągu
    I max_a = a[0];  // Maksymalna najniższa temperatura - kolejny element musi móc mieć wyższą
    for(I i = 1; i < n; ++i) {
        if(b[i] >= max_a) {  // Można dodać element do ciągu
            ++c;
            max_a = max(max_a, a[i]);
        } else {  // Nie można
            max_c = max(max_c, c);

            // Zaczynamy nowy ciąg
            max_a = a[i];
            c = 0;

            // Dodajemy wszystkie nierosnące elementy przed obecnym
            // (bez tego program przechodził jeszcze mniej testów)
            for(I j = i; j >= 0 && a[j] <= a[i]; --j) {
                ++c;
            }
        }
    }
    max_c = max(max_c, c);  // potrzebne jeśli największy ciąg jest na końcu

    cout << max_c << '\n';

    return 0;
}
