# Grafy tudzież ich trzymanie w komputerze

- graf to wierzchołki połączone krawędziami
  - (przykład)
- przykład użycia: miasta i drogi między nimi
- będziemy sobie oznaczać liczbę wierzchołków $n$, liczbę krawędzi $m$
- tekst jest liniowy, wejścia do zadań są tekstem: jak zapisać graf w jakikolwiek sposób?
- rozwiązanie: pary wierzchołków $(a, b)$ między którymi jest krawędź
- problem: będąc w wierzchołku nie wiemy jakie inne wierzchołki są połączone
  - trzeba przeszukać wszystkie pary
- rozwiązanie: macierz sąsiedztwa: $n \times n$ pól, w polu o współrzędnych $(x, y)$ trzymamy `1` jeżeli jest krawędź z $x$ do $y$, inaczej `0`
  - (przykład)
  - można sprawdzić czy istnieje $x \rarr y$ w $O(1)$
- inne rozwiązanie: lista sąsiedztwa: $n$ wektorów, trzymamy w wektorze numer $i$ indeksy wierzchołków, do których jest krawędź z wierzchołka numer $i$
  - (przykład)
  - trzymając wierzchołki, z którymi jest połączony $i$, znamy wierzchołki, z którymi jest połączony $i$
- istnieją grafy skierowane: w nich chociaż możemy przejść z $a$ do $b$ to nie możemy odwrotnie
  - w macierzy sąsiedztwa trzymamy `1` jeżeli jest $x \rarr y$
    - oznacza to, że macierz nie będzie symetryczna
    - (przykład)
  - w liście sąsiedztwa trzymamy $j$ jeżeli jest $i \rarr j$
    - (przykład)
- nie wszystkie grafy są spójne: może się zdarzyć, że nie ze wszystkich wierzchołków można dojść do wszystkich innych
  - jeżeli w treści zadania nie jest napisane, że się da, trzeba założyć, że się nie da
  - powyższe sposoby nadal działają
- graf jest drzewem jeżeli nie ma cykli
  - (przykład)
  - warunki równoważne
    - jest $n - 1$ krawędzi
    - z każdego wierzchołka można dojść do każdego innego na dokładnie jeden sposób
  - wybranie korzenia jest _ukorzenieniem_
  - (przykład ukorzenionego drzewa)
  - rodzicem wierzchołka jest wierzchołek z nim połączony najbliżej korzenia (oprócz korzenia, on nie ma rodzica)
  - dziećmi wierzchołka są pozostałe polączone wierzchołki
  - w drzewie warto osobno trzymać rodzica i dzieci

## Egzyztendzjalizm

- są stany int128_t, których żaden komputer nigdy nie miał w pamięci
