
# Plan centralny
*PLA*

Towarzysz Stalinteger, pierwszy sekretarz rządzącej w Związku Biteckim partii, w swojej daczy zamyślony pochyla się nad mapą krajów nadbajtańskich. Przygarnął je pod swoją opiekę na pocieszenie po wielkiej wojnie, do której jako pacyfista ze smutkiem został zmuszony dołączyć. Ich gospodarka prężnie się rozwija i teraz pozostaje mu tylko optymalnie i uczciwie rozmieścić przyszłoroczną produkcję zasobów.

Ponieważ większość doświadczonych algorytmików na terenach Związku Biteckiego wypoczywa na północy Związku, nowo skonstruowany komputer w 
Biteckiej Akademii Nauk skonstruowany na personalne życzenie towarzysza Stalintegera stoi bezczynny, chociaż bardzo by się w tej sytuacji przydał.

Na szczęście zostałeś Ty. Towarzysz Stalinteger poprosił Ciebie o napisanie programu, który mu pomoże. Ponieważ nie ufa on algorytmom dynamicznym, rozmieszczenie zasobów zoptymalizuje samemu &ndash; chce tylko programu pozwalającego mu zmieniać i wypisywać obecny stan, aż do momentu, w którym przywódca będzie zadowolony.

W krajach nadbajtańskich jest $n \leq 10^5$ miast nabrzeżnych. Tak dużo ponieważ z paradoksu linii brzegowej wiemy, że granica z morzem ma nieskończoną długość i mieści się tam dużo miast. Przynajmniej tak to rozumie towarzysz Stalinteger, więc tak rzeczywiście jest.

Ponieważ miasta są numerowane od $1$ do $n$, w praktyce można je traktować jako ciąg liczb $C$ o długości $n \leq 10^5$. Stalinteger ma $m \leq 10^5$ operacji na przedziałach $[a, b]$, $1 \leq a \leq b \leq n$ i w $m$ liniach wejścia podaje operacje, które muszą być wykonane:
1. `a b ?` &ndash; program ma wypisać sumę liczb na przedziale $[a, b]$;
2. `a b + x`; $-10^9 \leq x \leq 10^9$ &ndash; program ma dodać $x$ do wszystkich liczb na przedziale $[a, b]$;
3. `a b = y` &ndash; program ma ustawić na $y$ wszystkie liczby na przedziale $[a, b]$;
4. `a b > z`; $b - a \leq z \leq n - b$ &ndash; program ma przenieść wszystkie liczby z przedziału $[a, b]$ do przedziału $[a + z, b + z]$, tj. $C_{a+z+i}$ ma być ustawione na $C_{a+i}$ dla każdego $1 \leq i \leq b - a$, a następnie wyzerować przedział $[a, b]$.

Można założyć, że wartość żadnej liczby w ciągu nie przekroczy nigdy $10^9$.

## Wejście

W pierwszej linii wejścia dwie liczby $n$ i $m$. W kolejnych $m$ liniach znajdują się zapytania w wyżej opisanej postaci, po jednym na linię.

## Wyjście

Tyle linii wyjścia ile było operacji wypisania sumy na przedziale, jedna liczba na każdą linię.

## Testy przykładowe

TODO: Chyba nie działają, ale przyps.

1. Wejście:
    ```
    5 9
    1 2 + 1
    2 2 + 1
    1 5 + 10
    1 2 > 3
    1 1 ?
    2 2 ?
    3 3 ?
    4 4 ?
    5 5 ?
    ```
    Wyjście:
    ```
    0
    0
    10
    11
    12
    ```
    *Wyjaśnienie:* $n = 5$, $m = 9$, ciąg po operacjach dodawania to $\{11, 12, 10, 10, 10\}$, po operacji przesunięcia $\{0, 0, 10, 11, 12\}$.

2. Wejście:
    ```
    100 9
    1 50 + 10
    51 100 + 20
    1 50 > 50
    1 50 ?
    1 50 + 100
    1 25 =
    1 25 ?
    26 50 ?
    51 100 ?
    ```
    Wyjście:
    ```
    0
    0
    2500
    500
    ```

## Podzadania

TODO: Chyba nie przewidują ustawiania na wartości inne niż 0. Poza tym procenty nie sumują się do 100%. 

1. $n, m \leq 10^3$: 10% punktów;
2. występują tylko operacje dodawania i wypisywania: 5% punktów;
3. występują tylko operacje dodawania, ustawiania i wypisywania: 5% punktów;
4. występuje mniej niż $10$ operacji dodawania, ustawiania i wypisywania: 20% punktów;
5. brak ograniczeń: 70% punktów.
