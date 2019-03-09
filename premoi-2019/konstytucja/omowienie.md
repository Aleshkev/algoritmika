
# Konstytucja – omówienie zadania

Zacznijmy od tego, że porównanie leksykograficzne słów w C++ jest wbudowane na kilka sposobów:
1. `a < b` jeżeli `a` i `b` są typu `string` – najprostszy i polecany sposób – zwraca `1` jeżeli `a` jest mniejsze leksykograficznie od `b`,
2. `lexicographical_compare(a.begin(), a.end(), b.begin(), b.end())` jeżeli `a` i `b` są typu `string` lub `lexicographical_compare(a, a + n, b, b + m)` jeżeli `a` i `b` są typu `char *` lub `char[]` – zwraca `1` jeżeli `a` jest mniejsze leksykograficznie od `b`,
3. `strcmp(a, b)` jeżeli `a` i `b` są typu `char *` lub `char[]` – zwraca wartosć ujemną jeżeli a < b, `0` jeżeli a = b oraz wartość dodatnią jeżeli a > b.

Problem można rozwiązać osobno dla każdej linii wejścia.

Linię dzielimy na $n$ słów pomijając wszystkie znaki niebędące literami, nazwijmy ten ciąg słów $A$. Stwórzmy ciąg słów $B$, gdzie $i$-ty element $B$ to $i$-ty element $A$, tylko zamieniony na małe litery. Przykład:

    A: Bca bca Abc abc aBC cDE
    B: bca bca abc abc abc cde

Warto tutaj dodać, że najprostszym sposobem na sprawdzenie czy coś jest literą jest `islower(x) || isupper(x)`. Można też `('a' <= x && x <= 'z') || ('A' <= x && x <= 'Z')`, ale na pewno zamiast pamiętania że `97` to w ASCII mała litera `a`, można użyć stałej znakowej: `'a'`.

*Rozpatrzmy znalezienie najmniejszego słowa:* można w łatwy i przyjemny sposób przejść dla każdego $i$ od $1$ do $n$, trzymając $i_{\min}$ – indeks najmniejszego leksykograficznie słowa znalezionego do tej pory. Jeżeli $B[i] < B[i_{\min}]$ znaczy to, że słowo o indeksie $i$ jest mniejsze leksykograficznie, czyli ustawiamy $i_{\min}$ na $i$. Przykład:

        A: Bca bca Abc abc aBC cDE
        B: bca bca abc abc abc cde
        i: 1   2   3   4   5   6
    i_min: 1   1   3   3   3   3

Gdy przejdziemy przez wszystkie słowa, najmniejszym leksykograficznie słowem w $B$ jest $B[i_{\min}]$. Ponieważ $B[i_{\min}]$ jest $A[i_{\min}]$ tylko małymi literami, a interesuje nas słowo w formie w jakiej pojawiło się na wejściu, wynikiem jest $A[i_{\min}]$.

Analogicznie można znaleźć największe słowo – jest to kwestia zamiany znaku $<$ na $>$.

Ponieważ każde słowo porównamy w $O(a_i \min a_j)$ z najwyżej jednym innym słowem, złożoność całości to $O(a_i + ... + a_n) = O(n)$, co jest optymalnym rozwiązaniem.
