## geometria

iloczyn wektorowy

- pole trójkąta o wierzchołkach $O = (0, 0)$, $A$, $B$ jest równe $A_x \cdot B_y - A_y \cdot B_x$ czyli $A \times B$
- takie pole jest dodatnie ($A \times B > 0$) jeżeli odcinek $OB$ jest na prawo od $OA$, inaczej ujemne – pole skierowane
- ten wzór można wyprowadzić z dorysowania bounding boxa do trójkąta i liczenia pola przez odjęcie odpowiednich trójkącików
- jeżeli jest więcej wierzchołków ($O, C_1, C_2, ..., C_n$) to pole jest równe $\sum_{i = 1}^{n} C_{i - 1} \times C_i$
- zawsze należy napisać własnego structa `P { int x, y; }` z `operator*` i `operator-`

przecinanie się dwóch odcinków

- $(AB$ przecina $CD)$ $\iff$ $f(ABC) \cdot f(ABD) \le 0$ gdzie $f$ to pole skierowane

sposoby zapisu prostej

- $Ax + By + C = 0$
- $y = ax + b$
- $p_1, p_2$

## Latarnie

- standardowy trik jak się coś odbija
- skalujemy prostokąty i wrzucamy wszystkie na płaszczyznę
- dla każdego $k$:
  - zamiatamy płaszczyznę biorąc pod uwagę tylko prostokąty odpowiadające $i$-tej kopii ścianki, $i \le k$
  - jeżeli w danym miejscu jest $k$ prostokątów, są wszystkie $1, 2, ..., k$ czyli da się dojść
- wystarczy sprawdzić $k = 2^x - 1$
- złożoność $O(\log 2\,000 \cdot (600 \cdot 2\,000) \log n)$, $\log 2\,000$ się amortyzuje
- $|\frac{p_1}{q_1} - \frac{p_2}{q_2}| \ge 1\,000\,000^{-1}$ jeżeli $p, q \le 1\,000$, więc już zamiatanie można robić na liczbach rzeczywistych (dla drzewa przedziałowego skalujemy współrzędne)

### suma kwadratów liczb na przedziale w $O(1)$

- problem: na przedziale $[l, r]$ chcemy $a[l]^2 + a[l + 1]^2 + ... + a[r - 1]^2 + a[r]^2$
- trzymamy normalne sumy prefiksowe $p_0$ oraz $p_1$
- $p_{x, i} = p_{x, i - 1} + i \cdot a[i]^x$

### wzór Picka
