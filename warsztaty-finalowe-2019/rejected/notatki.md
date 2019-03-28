
- *Rzeźby:*
    1. $A$ dowolne
        - idziemy od jak największych bitów i spr czy ten bit musi być
        - wcześniej wyliczyliśmy większe bity: dla każdego bitu dynamik
        - ciąg liczb: iterujemy się, w punkcie zastanawiamy się czy da się jakiś prefiks dł. $i$ 
        - dasie[i][b] - czy da się pref podzielić na dokładnie b grup żeby sumy każdej grupy nie miały obecnie niechcianego bitu

        ```
        for(i = 0 .. i - 1) 
            if dasię[j][b - 1] && warunek
            dasię[i][b] = 1
        ```
        - O(n^3 B), B = liczba bitów
    2. $A = 1$, O(n^2 B)
        zamiast trzymać dynamika: dla kt najmniejszego b da się podzielić 
        nei ma jednego wymiaru ejsjt fajnie
        dal każdego i po kżdym j mniejszym 
        jeśli jest warunek oraz jeśli dasię[j] i który [j] < b i warunek to wtedy dasię[i] = 1, który[i] = który[i] min który[j] + 1
        który ma być jak najmniejszy, nie można breakować
        jeśli się da nie trzeba zapalać tego bitu

- *Wieżowce:*
    - ogólnie to taki szybszy fakcik: mamy ciąg $a_1, ..., a_n$.
    Wiemy o nim, że $\sum_i a_i = n$ i $\forall_i a_i \le i$.
    Wtedy $\sum \frac{n}{i} a _i \le n\sqrt{n}.$

    Wywalamy dla $b_i, p_i$ wszystkie pieseły, dla których: $b_j$ i $p_j$ jeżeli $p_i = p_j$ i $b_i \mod p_i = b_j \mod p_j$

    Patrzymy na fakcik, mówi nam że możemy dla każdej reszty modulo p przejść się po max p piesełach. 

    Można liniowo Dijkstrę w $O(n + x)$ jeżeli maksymalna odległość $\le x$

- *Szacowanie pola pod funkcją:* dzielimy na części, wagi to ciąg 1, 4, 2, 4, 2, ..., 4, 1, liczymy średnie pole w pasku.

Dzień II

- *Łódki:*
  - dividi sur intervoj: n segmentoj, patoroj. 

Dzień III

- *Wydobycie*
- *Wirusy:* PRzeżyją zawsze tylko te które mają nap ierwszym miejscu swój nr
