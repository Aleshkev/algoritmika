
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

Dzień V

- *Koraliki:* dwa warunki

    dynamik, 4 stany: mamy wierzchołek, krawędź wychodzącą do góry, krawędź wychodząca do góry jest czerwona albo niebieska, jest niesparowana. Jeśli byśmy parowali te kraw z czyms wyzszcym, drugi koniec bylby niebieski
    1* 
    2* też jest niesparowana, ale do gory jest czarny koniec
    3* sparowana, koniec jest w niebieskich 
    4* też jest sparowana, koniec jest czarny
    ten dynamik [i <= 4] jest maxem stanów 1..i, np. d[4] = max(d[1], d[2], d[3], d[4])
    popatrzmy jak stany zaleza od siebie
    że w stanie 1:
      koniec bedzie niebieski jesli nie bedzi jakby warunek czwartego stanu, bo jesli bylby war 4 stanu, to bylaby krawedz, spar 2 kraw kt maja koniec czarny. Tutaj bierzemy sume po dyn 3 z dzieci
    stan 2: w 2 stanie moze byc dalej czarna, nasz wierzch moze byc czarny: sa dwie opcje ze wierzch j czarn, 1: wchodzi krawedz o wierzhc
    wchodzi krawedz o konc czarn 
    mielibysmy tu syt w naszej obserw, tu musi wchodzić 3 stan
    max wyn z (stan[4] , do reszty stan[3])
    2: tu sa takie sparowane kraw miedzy dziecmi, kraw musza byc nieb, z jednej strony moze wchodzic nieb a zdrugiej czarny
    3*: parujemy sobie ja do gory to wtedy na pewno nie moze wchodzi 4 ale moze wchodzic 3
    a tutaj musi wchodzic 1 zeby war z 3
    max w 4 to max z czegos takiego ...

- Kupiec (cykle)
  tresc jest taka ze jest 100 miast 9900 jednokierunkowych polaczen, kazde pol jest jednokierunkowe, ma wage, ona jest do 10^7, a jest tez tak ze pomiedzy dwoma miastami w jednym kierunku jest co najwyzej jedna krawedz
  Jest k produktow, k do 1000. Kazde miasto dla kazdego prod ma cene kupna i sprzedazy, wazny warunek: cena kupna > cena sprzedazy
  Kupiec ma plecak z co najwyzej 1 przedm naraz, chodzi sobie po krawedziach
  Robi operacje kupna i sprzedazy, ile ich che
  ... [treść]

  mamy zdef efektywność cyklu, jeżeli w grafie mamy taki cykl, mamy wiedze ze jest start. wierzch i oprocz tego ze wybieramy jakis cykl, wybieramy co bedzie robil
  efektywnosc = zysk / dlugosc

  mamy wyznaczyc najw czesc calkowita jaka moze miec efektywnosc

  tkie zadania robi sie Floyd-Warshallem, ale tu byloby za duzo wierzchołków (gdzie jesteśmy * co mamy w plecaku, n * k, jeszcze do trzeciej bo to Floyd Warshall).

  jak rozw jest cykl nieprosty, zawsze oplaca sie wziac jakas jego czesc
  jak mamy cykl to kupuje cos wczesniej niz sprzedaje
  zach tablice inc[a][b] - ile najwiecej mozna zarobic kup w miescie a i sprzed w b
  jezeli wybierzemy a i b, typ przedmiotu nas nie obchodzi
  preprocesujemy to na poczatku, O(n^2 k)

  pozbywamy sie k w ogóle 

  zrobmy sobei druga tablice, odl[a][b] - min odleglosc na sciezce od a do b, liczymy w O(n^3)

  wiemy ze cykl rozw. sklada sie z czesci "kupujemy w a - sprzedajemy w b", pomiedzy a i b idziemy najkrotsza trasa
  wynik mozna wiec binsearchowac po wyniku
  
  mamy zysk/odl, sprawdzmy czy umiemy uzyskac iloraz >= x
  zys >= odl * x
  zysk - odl * x >= 0
  Wymnozymy odleglosci miedzy miastami *x, szukamy czy jest cykl o dodatniej sumie
  odwracamy znaki, sprawdzamy czy jest ujemny cykl

- *Skok:* mamy ukryta tab, ...

  Dzielimy na n części, jakoś wychodzi 2. subtask

  Zadanie podobne:
  184.MAX GAP
  leet.com

  bajtem.pl
  