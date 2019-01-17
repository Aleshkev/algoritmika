
### *Osobiste notatki, kumulują się tu błędy Stasia i mojego zrozumienia tematu w momencie ich pisania, a potem nie chce mi się ich poprawiać, więc jakość jest nie najlepsza.*


Teksty
---
*2018-11-23*

- prefiksosufiksy
  - KMP (tak naprawdę MP)
  - lemat o okresowości
- "daszki"
  - alg. Manachera

    *`slo` = słowo; `pal` = tablica palindromów*
    ```cpp
    void manacher(int n) {
      int r = 0
      for(int i = 1; i <= n;) {
        while(slo[i + r + 1] == slo[i - r - 1]) {
          r++;
        }
        pal[i] = r;
        for(int j = 1;; j++) {
          if(pal[i - j] + i + j >= i + r) {
            break;
          }
          pal[i + j] = pal[i - j];
        }
        i = i + j;
        r = r - j;
        r = max(r, 0);
      }
    }
    ```

    *Przykład działania:*
    ```
    # a a a b a b a a b
    0 0 1 0 1 4 1 0 ^
                   (j = 3)
    ```
  - tablica PREF: `PREF[i]` - długość najdłuższego prefiksu `S[1..i - 1]`, który jest też prefiksem `S[i..n]`

    ```
    <[ abc ]     .[ abc ]   >
                 ^
                 i
    ```
  - *maxrot na KI: można liniowo: alg. Duvala*

Hasze
---
*2018-12-07*

Rozwiązania zadań
---
*2018-12-14*

- *Szyfr.*
- *Przyjęcie:*
  graf będzie dwudzielny jeżeli połączymy ze sobą pary z wejścia oraz dla `i = 1..n` krawędź od `2i` do `2i + 1` — krawędź oznacza, że dwa wierzchołki nie mają takiego samego dania.

- *Śmieci:*
  tej samej krawędzi nie opłaca się brać dwa razy (ćw. udowodnić); czyli chcemy każdą krawędź, którą trzeba zmienić przejechać dokładnie raz: trzeba znaleźć w każdej spójnej z takich krawędzi cykl Eulera. Ponieważ (z treści zadania) nie można dwa razy przejechać przez ten sam wierzchołek w jednej ścieżce, przy szukaniu cyklu trzeba po odwiedzeniu dwa razy tego samego wierzchołka odcinać część ścieżki.

- *Rak:*
  bez magicznych krawędzi problem "do jak dużej silnej spójnej składowej należę?". Graf warstwowy: kopia z odwróconymi krawędziami, magiczne krawędzie teleportują; na tym znajdywanie silnie spójnych składowych i policzenie liczby unikatowych domków.

- *Bombki:*
  posortujemy ciąg pudełek i zrobimy na tym dynamika.
  
  Trzeba mając dwa pudełka powiedzieć, które jest lepsze: czy bardziej nam się opłaca postawić `j` na `i` niż `i` na `j`? Można zgadnąć, że warunek to `a[i] + b[i] > a[j] + b[j]` (`a` = waga, `b` = wytrzymałość).

- *Najdłuższe rosnące podciągi.*

- *Pawian:*
  graf dwudzielny ma dwie części. My mamy graf podzielony na spójne, więc każdą spójną trzeba przydzielić do lewej (`L`) lub do prawej (`R`) części grafu dwudzielnego. Liczba krawędzi w grafie dwudzielnym to `L * R`, jest maksymalna jeżeli ich rozmiary `l` i `r` są jak najbliżej siebie, czyli jak najbliżej `(l + r) / 2`.

  Problem plecakowy: można na bitsetach, ale się nie powinno i Staś poprawi limity. Można osobno rozpatrzyć jedynki i dwójki, co mocno zbija stałą.

  Możemy dostać tylko `sqrt(n)` różnych liczb, co można wykorzystać.

- *Poczta elektroniczna:*
  
  `dp[i][j]`

  `dp[i][i] = 1` \
  Iterujemy po dł. ciągu: `dp[i][j] = min(dp[i][k], dp[k + 1][j])` \
  jeżeli `s[i] == s[j]`, 1

Teoria gier
---
*2019-01-04*

Specjalna dziedzina, istnieje tylko 6 zadań które znalazł Staś, z czego niektórych nie może dać bo muszą móc być na conteście.

Gry:
- kompletne/niekompletne
- skończone/nieskończone
- deterministyczne/niedeterministyczne
- symetryczne/niesymetryczne

*Klucz do prawie wszystkich zadań na kółku:* jeżeli wykonując jakiś ruch da się dojść do stanu przegrywającego, stan jest wygrywający.

- Problem:
  ```
  [START]
    v
    O > O
    ^   v
    \-- O
        v
        O
        v
  [PRZEGRYWAJĄCY]
  ```

- Znany przykład: *drabina:* drabina wysokości `h`, każdy gracz może przesunąć się o dowolną liczbę od `1` do `k` jednostek.

- Kolejny przykład: na szachownicy: król w lewym dolnym rogu, może iść tylko w prawo lub do góry; gracze na zmianę go przesuwają o jedno pole. Są specjalne trampoliny; jeżeli król na nim jest to może się jeszcze raz ruszyć w tym samym ruchu. W prawym górnym rogu stoi skoczek. Kto pierwszy zbije go królem, wygrywa. Rozwiązać można dynamikiem: miejsce skoczka to pozycja przegrywająca (bo oznacza to, że przeciwnik już go zbił).

- *Nim:* strategię wygrywająca ma gracz pierwszy iff xor wszystkich wielkości stosów nie jest równy `0`. (*Dowód:* indukcyjnie, dla 0 stan jest przegrywający, dalej ze stanu gdzie xor &ne; 0, można przejść zawsze do stanu gdzie xor = 0.)

- *Nim na schodkach:* ... Sprowadza się do zwykłego Nim na nieparzystych schodkach.

- *Twierdzenie Sprague-Grundy'ego:* zakłada, że przegrywa kto nie ma ruchu
&rarr; wychodzi z niego dowód na rozw. do nim.

- *Nim-liczba* 

- *Przykład:* 1D-plansza, dł n &le; 5000, gracz który sprawi, że trzy krzyżyki są koło siebie, wygrywa. Każdy gracz stawia jednego krzyżyka w ruchu. Zmieniamy zasady: nie można stawiać krzyżyka w: `_ _ x _ _`. Dla każdej długości skracamy planszę i dynamicznie liczymy nim-liczby dla tych stanów O(n&sup2;). Nim-liczba dla stanów dwóch gier jest xorem dwóch liczb po lewej i prawej.

- *Zad.:* *Antinim:* wygrywa ten, kto w zwykłym nimie by przegrał. Jaka jest strategia?

- *Hackenbush* [skąd się biorą te nazwy, nie mam pojęcia jak je zapisywać]: założyć, że gra jest drzewem/lasem; jak w wierzchołku dzieci mają nimliczby, poddrzewo do tego wierzchołka można zastąpić ścieżką o długości xora mexa poddrzewa (lub ost. wierzhcolkow w poddrzewie?). Dwa poddrzewa to tak naprawdę dwie osobne gry. Możemy je połączyć.
