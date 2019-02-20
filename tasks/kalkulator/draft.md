# Kalkulator &emsp;<small>*KLK*</small>

Bajtek wymyślił innowacyjną nową operację między dwoma liczbami: a ℶ b = 2a + b. Łączy się ona w lewo, czyli a ℶ b ℶ c = (a ℶ b) ℶ c.

Bajtek nie zna jeszcze dokładnych zastowań, ale chciałby już teraz mieć program, który policzy wynik dla dowolnego wyrażenia składającego się z dowolnie dużych liczb, nawiasów i jego operacji. Ponieważ C++ nie przewidział ℶ, na wejściu ten operator zostanie przedstawiony jako `#`.

Ponieważ wynik może być duży, a Bajtek nie lubi czytać dużych liczb, wystarczy mu wynik modulo 10<sup>9</sup> + 7.

## Przykłady

<style>
  .example {
    display: flex;
    flex-direction: row;
  }
  .example > * {
    flex: 1 1 0;
    margin: 1em .5em;
  }
</style>

<div class="example">

```
1 # 1
```
```
3
```
</div>
1 ℶ 1 = 2(1) + 1 = 3

---

<div class="example">

```
1 # 1 # 1 # 1
```
```
15
```
</div>
1 ℶ 1 ℶ 1 ℶ 1 ℶ = ((1 ℶ 1) ℶ 1) ℶ 1 = (3 ℶ 1) ℶ 1 = 7 ℶ 1 = 15

---

<div class="example">

```
(1 # 1) # (1 # 1)
```
```
9
```
</div>
(1 ℶ 1) ℶ (1 ℶ 1) = 3 ℶ 3 = 9

---

<div class="example">

```
(((100)) # (200))
```
```
400
```
</div>

---

<div class="example">

```
2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2
↑ 30 dwójek
```
```
147483632
↑ chyba, nie jestem pewien
```
</div>

## Wzorcówka #1 (rekurencyjna)

Okazuje się, ża zachodzi następujący fakt:
- wyrażenie z wejścia spełnia taką gramatykę:
  ```
  liczba := ["0" | "1" | ... | "9"]+
  wyrażenie := liczba | ["(" wyrażenie ["#" wyrażenie]* ")"]
  ```
Więc można napisać łatwo funkcję parsującą takie wyrażenie:
```cpp
I i = 0;

I expression() {
  if (isdigit(s[i])) {
    // Zjadamy liczbę.
    I number = 0;
    while (i < n && isdigit(s[i])) {
      number = (number * 10 + s[i++] - '0') % mod;
    }
    return number;
  }

  // Jeżeli nie liczbę, to zjadamy wyrażenie w nawiasie.

  assert(s[i] == '('), ++i;

  I ans = expression();

  while (s[i] != ')') {
    assert(s[i] == '#'), ++i;

    I x = expression();
    ans = (2 * ans + x) % mod;
  }

  assert(s[i] == ')'), ++i;

  return ans;
}
```
Jeżeli `s` to wejście z dodanymi nawiasami na początku i końcu i z usuniętymi białymi znakami, `expression()` zwróci poprawny wynik.

## Wzorcówka #2

Ogólnie prosty stos i można iść po kolei.
