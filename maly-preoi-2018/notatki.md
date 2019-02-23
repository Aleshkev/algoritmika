

# Dzień 1

*Sanki elektryczne:* podzielić na silnie spójne składowe, *bla bla bla,* problemem jest znalezienie

## *Kandelabr*
  
*Brut #1 (20 p.):* `O(nmk lg k)`.

*Brut #2 (50 p.):* odpowiedź jest zawsze liczbą pierwszą; `O(n m rozkład(n))` (`rozkład(n) < lg n`). Przez błędy w testach dało się dostać 90 p.

*Algorytm MO:*
- na drzewie przedziałowym: najbardziej na lewo zero
- rozszerzając przedział o 1 najwyżej `6 lg` operacji

*Wzorcowe:* drzewo przedziałowe: każdy wierzchołek wektor segmentów zapytań, które całe zawierają się w przedziale repr. przez wierzchołek 


# Dzień 2

> — Macie jakieś pytania, rozumiecie to? \
> — Tak.

- *Międzygalaktyczne szlaki:* średnica; posortować liczby według 

- *Słowa:* dynamik `dp[i][b]`, `i` = długość, `b` = `bool`: czy było już podsłowo dł. `K`? \
  `dp[i][0] = sum(j=i-k, i - 1): dp[j][0]*(m-1) {+/- 1}` \
  `dp[i][1] = -//-  ale z [1]` \

  jeszcze przypadki gdy słowo z K jest na samym końcu:

  `+ dp[i - K]` - pozwalamy sobie na to, by raz miał długość <= (nie <) od danego K

  jeżeli jest dokładnie jedno słowo dł. K to nie ma dłuższego słowa z takich samych literek

      vv
      aaa
       ^^
  
  małe limity czasu; oszczędzać modulowanie %%%

- *Nim:* przegrywa iff po sxorowaniu wartości wychodzi 0. Chcemy znaleźć liczbę `x` stosików, które sxorują nam się do 0. Obserwacja: `(a_i, a_j)` można zamienić na `(a_i, a_i ^ a_j)`; dzielimy na kubełki wg. indeksu najbardziej znaczącego bitu; przetwarzamy kubełek `i`: wszystkie liczby z tego kubełka: eliminacja Gaussa - podobny pomysł: wybieramy 1 el. i łączymy z pozostałymi; w kubełku zostawimy 1 el. i przerzucimy do kubełków o mniejszych indeksach; wszystko trafi do śmietnika-kubełka `-1`; nie będzie podzbioru kubełków xorującego się do 1 1 występuje tylko raz; przyglądamy się tylko śmietnikowi gdzie jeżeli 1..., wynik 2 ^ (rozmiar śmietnika)

- *Kompletna podtablica:* każdą liczbę `k` można zamienić na `(1 << k)`; D&C, łączenie: min z lewej i prawej oraz przecięcia: sufiks b-orowy na lewej i prawej połowie, trzeba znaleźć `i` i `j` że ; w drzewie przedziałowym zmieniamy coś w liściu: idąc do góry aktualizujemy kolejne przedziały, przedzialy akt. w O(k), więc złozonoć to O(nk lg n + mk lg n)


# Dzień 3

- *Smoki:* BFS, bla bla, banalne.
- *Reporter:* spójrzmy na ruch 1. człowieka: co 1 sec rusza się o 1. Powiedzmy koleś ma D_1: ponieważ Cz rusza się o 1/sec, koleś ruszy się po D_1 sekundach, potem znowu po D_1, więc koleś rusza się co D_1 w prawo. Każdego zawodnika da się opisać jako z poz M_i co t_i rusza się o v_i. Obserwacja: nikt nikogo nie wyprzedzi, więc ich pozycje tworzą ciąg malejący: x_1 > ... > x_2. Robimy binsearcha: zapytanie l..r -> 1..r - 1..l +/- 1, niech będą P..inf:

  W P..inf jest jakaś pierwsza od lewej osoba, możemy ją zbinsearchować/1. osobę która się nie załapie

  ???: średnio poruszają się co sec, więc P_i = v_i ???

- *Turniej matematyczny:* bla bla bla iść po komórkach, niestety wzór nie działa co jest głupie i nieuczciwe, zabij się programie, okno jest na ścianie [rymuje się]

  rozpatrujemy po kolorach, potem po wierszach:
  - jaka jest najwyższa kolumna do góry
  - po kolei prostokąty od najwyższych wysokości do najniższych: kol. , od lewej do prawej 
  - (w, h) -> suma pól: sum_i sum_j i*(w-i+1)*j = sum_i i * (sum-i+1)h * (h + 1) / 2 = s (s + 1)s/2 - s(s + 1)(s + 1)/2 [z sumy kwadratów]
  - kolejka priorytetowa 
  - rozpatr. 3, dodajemy 3 do wyniku, obniżamy do wys. 2; jeżeli obok siebie dwa przedziały tej samej wys. to je łączymy

- *Piramida finansowa:* dla każdego wierzch poddrzewo o najw ilości wierzch, tablice dla niego kopiowaliśmy

  2 rozw: n lg^2 n, zliczać wierzch na mapie i przy liczeniu wyn z jego synów mniejsze mapy do większych

- *Rzutki:*
  - żeby sprawdzić czy pkt j w trjk iloczyn wekt ten sam znak
  - przy losowych punktach w kwadracie rozmiar otoczki wypukłej to lg n 
  - binsearch w logu 

- *Szyszki Tima:* wynik to MST
  - ponieważ: min(P_a % P_b, P_b % P_a) \
  P_a > P_b \
  P_a % P_b
  - na 30 punktów brut MST
  - dla każdego P_a zobaczyć jak wygladałoby modulo jeśli P_a jest mniejszą liczbą \
    P_b % P_a = P_b - k*P_a \
    Spójrzmy na każdą wielokrotność i z którą opłaca się zmodulować \
    k * P_a -> P_b -> P_c \
    Dla każdej wielokr k istn tylko 1 licz kt opłaca się modulować.
  - będziemy mieli n lg n różnych krawędzi
  - ile jest różnych wielokrotności liczb z wejścia? n/1 + n/2 + n/3 + ... + n/n =~ n lg n
  - dlaczego optymalne? jeżeli weźm kraw P_a-P_c, to może byśmy ... nei rozważyli, ale suma odl jest tka sama


# Dzień 4

ATCODER

Na OI jest domyślny nie najnowszy kompilator:
`g++4.9 -Wshadow -fsanitize=address,undefined, -D GLIBCXX_DEBUG -fdiagnostics-color=auto`

- *Dzielenie czegośtam:* dynamik bla bla bla, Kaszycki omawia XD co za font

  > Osobiście użyłem liczby sześćdziesiąt tysięcy pięćset trzydzieści pięć, ale to szczegół implementacyjny.

- *SLIP-y:* XD Taki jeden typ koło mnie nie zrozumiał treści i dostał 0 punktów XDDDD LOL LMAO <- nie przeklinamy bo dostajemy -9999999 punktów

- *Cenzura:* To bardzo proste, ale neistety rozw się pojawiło 5 minut przed końcem i nie pamiętałem jak działają hasze. To trochę smutne, jak wynik bitwy pod Stalingradem dla Hitlera.

  Iść sobie jak Stalin na Berlin, jak jakiś sufiks pasuje do wzorca to go wysyłamy na Syberię i kontynuujemy. Ponieważ jest max `sqrt(n)` różnych długości, można `O(n sqrt(n))` i jest *sehr gut*. 

  Typ koło mnie myślał o KMP jak hasze są dużo lepsze XD Teraz myśli, że cytowanie jest fajne, ale nie przewidział tego, że ja mogę cytować jego i nigdy nie skończy: "Typ koło mnie myślał o KMP jak hasze są dużo lepsze XD Teraz myśli, że cytowanie jest fajne, ale nie przewidział tego, że ja mogę cytować jego i nigdy nie skończy: "" XD Wygrałem

  O nie, znalazł metodę Kopy'ego Paste'a. ALe ja skopiuję tu fragment Mein Kampf i będzie go musiał przepisać:

  > German-Austria must return to the great German mother country, and not because of any economic considerations. No, and again no: even if such a union were unimportant from an economic point of view; yes, even if it were harmful, it must nevertheless take place. One blood demands one Reich. Never will the German nation possess the moral right to engage in colonial politics until, at least, it embraces its own sons within a single state. Only when the Reich borders include the very last German, but can no longer guarantee his daily bread, will the moral right to acquire foreign soil arise from the distress of our own people. Their sword will become our plow, and from the tears of war the daily bread of future generations will grow. And so this little city on the border seems to me the symbol of a great mission. And in another respect as well, it looms as an admonition to the present day. More than a hundred years ago, this insignificant place had the distinction of being immortalized in the annals at least of German history, for it was the scene of a tragic catastrophe which gripped the entire German nation. At the time of our fatherland's deepest humiliation, Johannes Palm of Nuremberg, burgher, bookseller, uncompromising nationalist and French hater, died there for the Germany which he loved so passionately even in her misfortune. He had stubbornly refused to denounce his accomplices who were in fact his superiors. In thus he resembled Leo Schlageter. And like him, he was denounced to the French by a representative of his government An Augsburg police chief won this unenviable fame, thus furnishing an example for our modern German officials in Herr Severing's Reich.

  O nie, tego nie przewidziałem. Ale nie szkodzi, gdyż ... hmm...

  W kazdym razie typ kolo mnie na pewno jest już znudzony i zaraz przestanie, font jeden.
  Nadal ja piszę szybciej, więc mnie nie dogoni Bua hah ha ha

  Jakby jeszcze tu ściągnąć Kubę, to by nie miał żadnych szans. 

  Nie ma żadnych dowodów na to, że Hitler wiedział o Holocauscie. 

  XD Ten typ przepisze wszystko

  Głosowałem w ostatnich wyborach na PiS, ale tylko dlatego, że najwyraźniej jakiś debil zabił Hitlera.

  ***

  Wracając do omówienia, można używać Aho Kozzaka czy coś aby było liniowe

- *Kreatywna księgowość:* Kuba nie dostał 100 punktów, ale on niemądry. Ja nie przeczytałem nawet treści zadania, więc tak jakby wygrałem.

  można zamienić problem na zera i jedynki: wyszukiwanie binarnie po wyniku, gdzie v[i] = 1 dla v[i] >= mid, 0 inaczej

  struktura zliczająca zera i jedynki na przedziale i ustawiająca przedział na zera i jedynki; drzewo przedziałowe

  O, to bardzo proste się wydaje, tylko to zabawne drzewko przedizaiłowe, ale to bardziej krzaczek.

  O(lg n (n + q lg n))

  Można też śmieszne ciągi montoniczne i to działa, bez wartości edukacyjnej :c

  > Część osób stwierdziła, że trzeba to za bardzo żyłować. Mamy lg^2 i chcemy to zmniejszcyć i mamy zwykłe drzewo przedziałowe i mamy np. operację ustaw na przedziale a..b jedynki, normalnie byśmy rozchodzili się na przedziały bazowe; ale czasami nie warto nawet schodzić

  przeskalować liczby, żeby log był mniejszy 31 -> 17

  w skrócie to tyle, nikt nie ma pytań 

- Czy chce ktoś usłyszeć co to Aho Corassik? Nie, bo tego nie ma na OI.
