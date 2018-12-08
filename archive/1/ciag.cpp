#include <iostream>
#include <vector>

using namespace std;

typedef long long int I;
typedef short int B;

int main()
{
    I n;
    cin >> n;

    I score = 0;

    // 'Obcięty' ciąg - bez ujemnych liczb na początku, dodatnich na końcu i bez zer
    // (zera i tak trzeba zamienić, więc wystarczy dodać 1 do wyniku)
    vector<B> seq;

    // Ta pętla wczytuje ciąg pomijając liczby dodatnie z początku i zera
    // Ustawia także `last` na ostatni element ciągu
    I last;
    bool found_positive = false;
    for(I i = 0; i < n; ++i) {
        I a;
        cin >> a;

        if(a == 0) {
            ++score;
        } else if(a < 0) {
            if(found_positive) {
                seq.push_back(-1);
            }
        } else {
            found_positive = true;
            seq.push_back(1);
        }

        last = a;
    }

    // Ta pętla usuwa liczby dodatnie z końca
    while((!seq.empty()) && seq.back() > 0) {
        seq.pop_back();
    }

    // Długość obciętego ciągu
    I m = seq.size();

    /// <moje-wątpliwości>

        // Ta pętla liczy ile jest ujemnych i dodatnich liczb w ciągu
        I c_neg = 0, c_pos = 0;
        for(I i = 0; i < m; ++i) {
            if(seq[i] < 0) {
                ++c_neg;
            } else {
                ++c_pos;
            }
        }

        // Trzeba zamienić jak najmniej liczb
        score += min(c_neg, c_pos);

    /// </moje-wątpliwości>

    // p musi być z jakiegoś powodu mniejsze od n
    // Więc jeśli ostatni element ciągu był ujemny, trzeba go i tak zamienić na dodatni
    // (tak myślę, bez tego nie przechodzi 2. przykładu z treści zadania)
    if(last < 0) {
        ++score;
    }

    cout << score << '\n';

    return 0;
}
