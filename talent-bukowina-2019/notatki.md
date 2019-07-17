
## dzień #1 grupa b

### podciąg

> Wy już tu zaczęliście? Myślałem, że to ja jestem prezesem.

zachłannie brać najmn leks literkę, ale patrzymy ile literek musi zostać. drzewko przedziałowe do znajdywania pozycji najmniejszej literki na przedziale.

można bez drzewa przedziałowego gąsienicą i 26 kolejkami, lub setem.

### obchodzenie drzewa skokami

ojciec wybrany - nie wybieramy, rozchodzimy się w dół
ojciec niewybrany - wybieramy, rozchodzimy się w dół

przy wychodzeniu trzeba uważać żeby nie przeskoczyć o 4

### ogniwa łańcuchowe

$f_1[i]$ – w ile operacji możemy minimalnie zrobić żeby była 1, $f_0$ analogicznie

$f_0[1] = f_1[1] = 0$, bo pierwszy możemy zamienić w początkowym ruchu

$f_1[i] = f_1[i - 1] + 1 + f_0[i - 1]$

$f_0[i] = f_1[i - 1] + 1 + f_0[i - 1]$, czyli $f_0[i] = f_1[i]$, niech $= f$.

ostatnie zera obcinamy, nic nie zmieniają.

$d_0[i]$ – `dp`, ile minimalnie na $i$-tym prefiksie musimy zrobić operacji żeby był wyzerowany, $d_1[i]$ analogicznie

dla zera: musimy wyzerować pref o 1 mniejszy, więc $d_1[i] = d_1[i - 1] + 1 + f[i - 1]$
dla 1: swap($d_0[i]$, $d_1[i]$);

## dzień #1 grupa b 

### prawie pasuje

*w dramatycznej ciszy autor zadania rysuje na tablicy drzewo sufiksowe*

dostawiamy znak spoza alfabetu, rysujemy drzewko, przy zapytaniu schodzimy w dół poszukując miejsc gdzie się maks o 1 nie zgadza.

zaczynamy w korzeniu sprawdzamy czy się pokrywa, jeden mismatch jest dopuszczalny. jak są już dwa to opuszczamy gałąź.

preprocessujemy ilość dzieci w drzewie i używamy do wyniku.

### wiercenia

[na kartce]

### to tamto z grafem

## wykład #1

### drzewo sufiksowe

jak drzewo trie wszystkich sufiksów, tylko z kompresją.

wstawiając zmieniamy krawędzie:
1. `x` → `xa`
2. `xb` → `xa` + `xb`
3. `xa` → `xa`

procesujemy wszystkie podsłowa: dla `abac`: `a`, `ab`, `b`, `aba`, `ba`, `a`, ..., tak dodajemy w $O(n)$ czyli całość $O(n^3)$.

jeżeli `aba` dodamy przypadkiem 3. to `ba` i `a` też przypadkiem 3., więc można po prostu dodać do końca etykietek krawędzi do liścia.

nie nisczczymy liści tylko wstawiamy wierzchołki przed nimi, dodając coś na koniec dodajemy tylko na koniec etykietki liścia, więc wierzchołek jak raz jest liściem to już zawsze nim będzie.

etykietki przechowujemy $(p, o)$ – początek i koniec-słowa/długość w dużym słowie.

nie ma wierzchołków z jednym dzieckiem i jednym rodzicem $\implies$ jest najwyżej $2n - 1$ wierzchołków $\implies$ sytuacja 2. zajdzie najwyżej $n$ razy.

sumaryczna złożoność sytuacji:
1. $O(n)$
2. $O(n^2)$ – dążymy nadal do zbicia tego.
3. $O(n)$

tworzymy krawędzie sufiksowe.

po przejściu przez krawędź sufiksową schodzimy w dół i możemy pomijać porównywanie wszystkich znaków.

to umożliwia obsługę wszystkich zapytań w czasie liniowym.

## dzień #2 grupa a

### gra w skierowany

zajmujemy się podzbiorami wierzchołków: dla każdego podzbioru wierzchołków 

dzielimy wierzchołki na grupy z nimberem 0 i nie-0.
