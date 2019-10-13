---
marp: true
---

# podstawy STL-a

_Standard Template Library_

---

## wektory

---

- problem: chcemy wypisać dla $x \in a$ wszystkie $i$ że $a_i = x$ (${a_i \le 10^6}$, ${|a| = n \le 10^6}$)
  - można to zrobić tak: dla każdej możliwej wartości trzymamy tablicę z indeksami, na których występuje ta wartość
  - tablica $10^6 \times 10^6$ jest za duża, trzeba by też trzymać $10^6$ indeksów gdzie zostanie dodany kolejny indeks

---

- chcemy nie zajmować niepotrzebnie pamięci
- rozwiązanie: dynamiczne tablice
  - przydzielamy nowe miejsce jeżeli skończy się obecne
  - jeżeli tak to robimy, optymalną strategią jest przydzielenie 2 razy więcej miejsca niż jest obecnie
  - wtedy dla $n$ elementów zużyjemy sumarycznie $2 + 4 + 8 + 16 + ... + 2^{\lceil \log_2 n \rceil + 1}$ pamięci, czyli nie więcej niż $3n$
  - to oznacza też, że średnio dodanie nowego elementu jest liniowe ($\frac{3n}{n} \cdot n = 3n \approx n$)

---

- problem: implementacja tego jest skomplikowana
- rozwiązanie: wektory z STL-a

---

- `#include <bits/stdc++.h>` pozwala używać wszystkiego z STL-a
- `vector<T> v;` deklaruje wektor z elementami dowolnego typu `T`
  - np. `vector<int> v;`
- `v[i]` zwraca `i`-ty element
- `v.push_back(x);` dodaje `x` na koniec
- `v.pop_back();` usuwa element z końca
- `v.size()` zwraca obecny rozmiar (jako `unsigned`)
  - dla pewności można pisać zawsze `(int)v.size()`
- `v.empty()` $\equiv$ `v.size() == 0` – czy wektor jest pusty
- `v.back()` $\equiv$ `v[v.size() - 1]` – ostatni element
- `v.resize(n)` – robi, że wektor będzie miał dokładnie `n` elementów; usuwa elementy z końca jeżeli jest ich za dużo, dodaje domyślne wartości (zera dla typów liczbowych) jeżeli jest ich za mało
- `v.clear();` $\equiv$ `while(!v.empty()) v.pop_back();` $\equiv$ `v.resize(0);` – usuwa wszystkie elementy

---

```cpp
#include <bits/stdc++.h>

int main() {
    vector<int> v;

    v.push_back(5);
    v.push_back(3);
    v.push_back(4);
    // v == {5, 3, 4}
    v.pop_back();
    // v == {5, 3}
    cout << v.size() << "\n";   // 2
    cout << v.empty() << "\n";  // 0 (false)
    cout << v.back() << "\n";   // 3
    v.resize(6);
    // v == {5, 3, 0, 0, 0, 0}
    v.resize(1);
    // v == {5}
    v.clear();
    // v == {}
    cout << v.empty() << "\n";  // 1 (true)
}
```

---

```cpp
vector<int> v = {5, 3, 4};
```

---

## typy

- czym jest „dowolny typ” `T` z wcześniej?
- jest to np. `int`, `double`, `long long`, ale też bardziej skomplikowane
- w C i C++, jak mamy deklarację zmiennej, np. `int &*zmienna[10]`, to po usunięciu nazwy dostajemy jej _typ_: `int &*[10]`
- oznacza to, że `vector<int>` sam w sobie jest typem, możemy więc zrobić wektor wektorów: `vector<vector<int>> v;`
  - wtedy `v[0]` jest typu `vector<int>`, który też możemy indeksować, czyli 1. element 0. wektora to `v[0][1]`

---

## iteratory

- iteratory są jakby wskaźnikami na obecną pozycję w przechodzeniu struktury
- `v.begin()` zwraca iterator na początek, `v.end()` na koniec (jeden po ostatnim elemencie)
- iteratory nie powinny być używane po zmianie wielkości wektora
- iteratory w wektorach:
  - `it + 10` – przejście iteratorem o `10` elementów
  - `it2 - it1` – odległość od `it1` do `it2`
  - np. `it - v.begin()` zwraca indeks na którym jest operator `it`

---

## przedziały według STL-a

- STL często przyjmuje przedziały `[first, last)` – funkcje zaczynają od `first` i jak napotkają `last` się zatrzymują
- np. `sort(first, last)`: `sort(t, t + n);` `sort(v.begin(), v.end());`

---

## sort

- `sort(first, last)` – sortuje zakres rosnąco
- `reverse(first, last)` – odwraca zakres
- `sort(first, last, comparator)` – sortuje zakres według komparatora:

  ```cpp
  bool czy_a_przed_b(int a, int b) {
      return a > b;
  }
  int main() {
      vector<int> v;
      v.push_back(5);
      v.push_back(-2);
      v.push_back(1);
      sort(v.begin(), v.end(), czy_a_przed_b);

      // v == {5, 1, -2}
  }
  ```

---

## queue

- metafora: kolejka w sklepie
  - możemy dodać nową osobę na tył kolejki, wziąć jedną osobę z przodu
- `queue<T> q;`
  - `q.push(x)` – dodaje `x` na tył
  - `q.front()` – zwraca wartość z przodu
  - `q.pop()` – usuwa wartość z przodu

---

## stack

- metafora: stos kartek
  - możemy dodać nową kartkę na wierzch, zabrać ostatnio dodaną
- `stack` istnieje w STL-u, ale jest wolniejszy od wektora, nie należy go używać
- operacje dla wektora:
  - `push_back()`
  - `back()`
  - `pop_back()`
