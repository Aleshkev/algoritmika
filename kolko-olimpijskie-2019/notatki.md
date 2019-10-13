
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
