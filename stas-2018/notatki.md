
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

## Teoria gier

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

- *Przykład:* 1D-plansza, dł n &le; 5000, gracz który sprawi, że trzy krzyżyki są koło siebie, wygrywa. Każdy gracz stawia jednego krzyżyka w ruchu. Zmieniamy zasady: nie można stawiać krzyżyka w: `* * x * *`. Dla każdej długości skracamy planszę i dynamicznie liczymy nim-liczby dla tych stanów O(n&sup2;). Nim-liczba dla stanów dwóch gier jest xorem dwóch liczb po lewej i prawej.

- *Zad.: Antinim:* wygrywa ten, kto w zwykłym nimie by przegrał. Jaka jest strategia?

- *Hackenbush* [skąd się biorą te nazwy, nie mam pojęcia jak je zapisywać]: założyć, że gra jest drzewem/lasem; jak w wierzchołku dzieci mają nimliczby, poddrzewo do tego wierzchołka można zastąpić ścieżką o długości xora mexa poddrzewa (lub ost. wierzhcolkow w poddrzewie?). Dwa poddrzewa to tak naprawdę dwie osobne gry. Możemy je połączyć.

## Dynamiki na drzewach

*2019-01-18*

"Depek" to najgorsze co spotkało język polski od profesora Miodka.

Pojęcia: drzewo, poddrzewo, naddrzewo (drzewo - poddrzewo + wierzchołek).

- *Policzenie rozmiaru poddrzewa dla każdego wierzchołka.*

- *Najdłuższa ścieżka w drzewie, bez dwóch DFS/BFS-ów:* dla każdego wierzchołka policzyć dwie najdłuższe ścieżki idące tylko w dół; [...].

- *Dla każdego wierzchołka, suma odległości od wszystkich innych:* 1. wynik dla każdego poddrzewa (iść od dołu); 2. wynik dla każdego poddrzewa połączyć z wynikiem dla naddrzewa (iść od góry). Problemem może być cofnięcie krawędzi przy łączeniu (&approx; między poddrzewem a naddrzewem).

### Depeki na drzewie n&sup2;
- *Dane drzewo ważone, liczba `k`: chcemy odwiedzić `k` różnych pokoi w tym drzewie:* `dp[v][k] = Min`; dwa dynamiki: najtańszy w tę i z powrotem i najtańszy gdzieś; `dpw[v][k]`, `dp*nw[v][k]` (`w`racamy, `n`ie `w`racamy), `wyn[v]`

  Problem pomocniczy: dwóch synów, policzyć wynik:iter 1..k, w jednym bierzemy L, w drugim R

  `M*i=0^k in(dp[s1][i] + dp[s2][k-i])`

  na tym samym conteście: zadanko na symulację syfnej gry &larr; znaleźć, bo będzie kiedyś!

Trudne:
- *Żar*
- *Strajki*

Luźne kółko przed feriami
---
*2019-01-25*

Przydatne z teorii liczb:
- sito Erastotenesa
- odwrotność modulo
- rozszerzony algorytm Euklidesa

Najbardziej prawdopodonbe algorytmy grafowe:
- silnie spójne
- DFS
- toposort
- DP na grafodrzewach
- LCA – Least Common Anticipator

Najbardziej przydatne algorytmy:
- testowanie
- ascii art
- klepanie brutów

<div style="text-align: center">

```
_______________________________________________________
_______________________________________________________
   __  _   ___  __  ____ _  __ _ ___ _   _ _  __  ____ 
  /  \ |   |   /  \ |  | |  /  | |   |   | | /  \ |  | 
  |  | |   |   |       | | /   | |   |   | | |       | 
  |--| |   |-- \--\   /  |-    | |-- |   | | |      /  
  |  | |   |      |  /   | \   | |   | | | | |     /   
  |  | |__ |__ \__/ |__| |  \  | |__ |/ \| | \__/ |__| 
_______________________________________________________
_______________________________________________________
```

</div>

## Teoria liczb

*2019-02-22*

- (Liczba dzielników liczby n) &le; <sup>3</sup>√n \
  (Liczba dzielników liczby n) ≈ log n (ale może być mocno przekroczone o stałą)

- rozszerzony alg. Euklidesa: dla każdej liczby pamięta jej NWD(b, mod) = 1 = x &middot; b + <del>y &middot; mod</del>, znajduje odwrotność

- liczba &phi;: tocjent Eulera: żeby policzyć liczbę liczb względnie pierwszych z liczbą
  1. &phi;(n) = liczba liczb względnie pierwszych z n mniejszych-równych n
  2. &phi;(p) = p - 1 (p jest pierwsze)
  3. &phi;(p<sup>k</sup>) = p<sup>k-1</sup> (p - 1)
  4. &phi;(n &middot; m) = &phi;(n) &middot; &phi;(m) &hArr; NWD(n, m) = 1
  5. $x = p_1^{\alpha_1} \cdot p_2^{\alpha_2}$ \
    $\phi (x) = p_1 ^ {\alpha_1 - 1} (p_n - 1)$

- funkcja Mobiusa:
  1. &mu;(x) = 
      - 1 &emsp; x=1
      - 0 &emsp; x = p<sup>2</sup>k
      - -1 &emsp; 2 ∤ L
      - 1 &emsp; 2 ∣ L
  2. &mu;(n) = &mu;(m) = &mu;(n &middot; m)
  - *Zadanie Mały Las:* 

- faktoryzacja w <sup>4</sup>√ (pamięć stała), probabilistyczne, funkcja losująca musi być deterministyczna: p ≈ √n. Funkcja losowa modulo p: x_1, x_2, x_3, ..., w końcu gdzieś wróci do poprzedniego x (zasada szufladkowa), mamy cykl, z paradoksu dnia urodzin ma on jakąś długość c ≈ √p ≈ <sup>4</sup>√n. Zakładamy, że x_n i x_i (jakieś do którego wróciło) są różne (mała szansa, że są)
  - najprostsza funkcja wystarczająco pseudolosowa: `x^2 + c`, c = np. 17.


## 2-SAT

*2019-03-01*

- SAT
- k-SAT – w każdej formule dokładnie k zmiennych
- 2-SAT: da się zrobić dzięki temu, że $(x_1 \vee x_2) \Leftrightarrow ((\neg x_1 \Rightarrow x_2) \wedge (\neg x_2 \Rightarrow x_1))$.

  Robimy graf: wierzchołek $x_i$ oraz $\neg x_i$ dla każdego $1 \le i \le n$. Każda formuła to dwie krawędzie. Chcemy przydzielić każdemu wierzchołkowi 0 lub 1. Sprowadzamy graf do DAG (wewnątrz jednej silnie spójnej wszystkie wierzchołki muszą mieć tę samą wartość, inaczej da się przejść jakoś z 1 do 0, sprzeczność). Dla każdego wierzchołka sprawdzamy czy on i jego przeciwieństwo są w tej samej silnej spójnej, jeżeli tak to nie ma rozwiązania. Mamy DAG, którego można w łatwy i przyjemny sposób pokolorować.

  Przykład sprzeczności: gdy w grafie wyjdzie $\neg x_0 \rightarrow x_0 \rightarrow x_1 \rightarrow \neg x_1$. Ta sprzeczność jednak tak naprawdę nie istnieje, bo musi być krawędź $\neg x_1 \rightarrow \neg x_0$, a wtedy jest to jedna spójna, więc ten przypadek był już rozważony.


## Geometria

*2019-03-08*

- proste: $f(x) = ax + b$; nie działa na prostej pionowej, trzeba ją `if`ować. Dlatego zamiast tego jest drugi wzór, $ax + by + c = 0$
- iloczyn wektorowy = pole skierowane
  - z iloczynu wektorowego można ≈uzyskać kąt między wektorami: $a \times b = xy \sin \alpha$: jest to dwuznaczne, trzeba jeszcze użyć cosinusa
- iloczyn skalarny: $(x_1, y_1) \times (x_2, y_2) = I = x_1x_2 + y_1y_2 = xy \cos \alpha$
  - jeżeli jest kąt prosty, wychodzi 0
- sortowanie kątowe
- `atan2`: obliczenie kąta między $(a, b), (0, 0)$ a podstawą współrzędnych.
- otoczka wypukła, bez sortowania kątowego
- zamiatanie drzewem przedziałowym (pominięte)
- liczenie pola trójkąta: iloczynem wektorowym
- liczenie pola dowolnego wielokąta (również wklęsłego): suma pola skierowanego dla każdego trójkąta z boku X do punktu P = pole wielokąta
- sprawdzenie czy punkt jest w wielokącie


## Macierze

*2018-03-15*


## Różności, rzeczy implementacyjne

- większy skill klepacki przydaje się jak jest coś nietrywialnego do sklepania
- komunistyczna polityka Kubina "zrób wszystko publiczne to nie trzeba będzie się niczym przejmować"
- własne dobre double dzięki trzymaniu $10^k \cdot r$ gdzie $k$ jest `int`em a $r$ `long double`m, działają dobrze gdy wynik $\in [0, 1]$


## Skojarzenia

*2019-04-26*

Będzie teoretycznie bo jest mało zadanek.

- zad: podać przykład grafu gdzie wszystkie wierzchołki mają stopień 3 i nie ma skojarzenia doskonałego

## Algorytmy randomizowane

najw klika w grafie, ale graf jest specyficzny: dla każdego wierzchołka możemy odpalić f(v), które zmieni graf w graf tylko z krawędziami które są na klice. Można znalezc klikę puszczając to dla kżdego wierzch w O(nF), F = złożoność f(v). Chcemy z tego zrobić funkcję liniową. Jeszcze jedno magiczne założenie: klika jest wielkości co najmniej 1/5 grafu. Można wtedy wybrać losowe $n$ wierzch i za każdym razem jest 4/5 szansy że wierzchołek nie będzie na klice, więc szansa że nie będzie odpowiedzi to $(\frac{4}{5})^n$; $n$ = log_4/5 * 1/2*10^8

Żeby policzyć odpowiednie $n$:

$$\log_\frac{4}{5} \frac{1}{2\cdot10^8} = n$$


pkty na płaszczyznie, mamy znalezc prosta zawierajaca co najmniej n/2 punktów lub stwierdzic że takiej nie ma. Losujemy pary punktów, liczymy ile pktów ma prosta między nimi, prawdopodobieństwo że jest dobrze to 1/4, bo pktów na tej prostej pesymistycznie jest n/4. Jeżeli przez 60 prób nic się nie znajdzie, pewnie nie ma takiej prostej.

Algorytmy las vegas i monte carlo

monte carlo – metoda działa dokładnie określoną liczbę czasu i z pewnym prawdopodobieństwem zwraca dobry wynik, np. hasze; np. przybliżanie $\pi$ przez losowanie punktów w kwadracie

las vegas – zwraca dobry wynik ale niekoniecznie w skończonym czasie. nas będą tkie interesowały, po prostu jak się skończy czas stwierdzamy, że nie ma takiej odpowiedzi.

mamy daną tablicę zer i jedynek, znajdź szybko jakieś 0. Normalnie idziemy po tablicy, może być test gdzie są same jedynki i potem same zera, random_shuffle rozw problem i jest fajnie szybko. bellman-ford można też tym zoptymalizować i jest coś nieporównywalnie szybszego, prawie szybkie jak Dijkstra.

istnieją biblioteczki adapcyjne, które się przystosowują do zapytań :O
CF na sylwestra?

znaleźć najmniejszy okrąg opisujący punkty. Środek ciężkości nie działa. Alg liniowy istnieje, ale jest trudny. Zastanównmy się nad algorytmem w $O(n^3)$. Bierzemy pkt, wyrzucamy go, rekurencyjnie odpalamy dla pktów bez tego i znajdujemy jakiś okrąg. Opcja #1: pkt jest wewnątrz okręgu, mamy wynik. Opcja #2: zapamiętujemy, że on leży na krawędzi, i już więcej go nie wyrzucimy. Odpalamy od nowa, inny punkt wyrzucamy, możliwe że go wyrzucamy, tak samo dla 3 pktów. Jeżeli znajdujemy 3 pkty na krawędzi, mamy okrąg deterministycznie w $O(n^3)$ :O

(Schodzimy od początku aż trafimy na 1 punkt na krawędzi, jeżeli dojdziemy do końca, restartujemy do ostatnio znalezionego punktu na krawędzi.) Chcemy więc w jak najmniejszym zbiorze znajdywać punkty na krawędzi.

Ścieżka dł k gdzie $k \approx \log n$. Kolorujemy na k kolorków

### Zadanka optymalizacyjne

zad z IOI: mamy planszę, pola, na niektórych polach są krzaki, chcemy jak najfajniejszy labirynt,: fajność = bierzemy największą spójną w labiryncie i ile tam jest liści. 

żarzanie: mamy wynik i idziemy w losowych kierunkach, wybieramy ten najlepszy. Czasami robimy specjalnie błąd żeby wyjsć z lokalnego maksimum.

`rand()` jest zły, lepiej `rand() * RAND_MAX + rand()` (+ jakieś stałe)

Żeby niepraktycznie sprawdzić czy dwa słowa są cykliczne można każdej literze alfabetu przyporządkować losową macierz 3x3. Jeżeli iloczyn macierzy obu słów jest taki sam, słowa są równe. Bardzo duża szansa działania, świetna sztuczka.
