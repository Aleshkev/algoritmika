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

*Wyjaśnienie:* 1 ℶ 1 = 2(1) + 1 = 3

<div class="example">

```
1 # 1 # 1 # 1
```
```
15
```
</div>

*Wyjaśnienie:* 1 ℶ 1 ℶ 1 ℶ 1 ℶ = ((1 ℶ 1) ℶ 1) ℶ 1 = (3 ℶ 1) ℶ 1 = 7 ℶ 1 = 15

<div class="example">

```
(1 # 1) # (1 # 1)
```
```
9
```
</div>

*Wyjaśnienie:* (1 ℶ 1) ℶ (1 ℶ 1) = 3 ℶ 3 = 9

<div class="example">

```
(((100)) # (200))
```
```
400
```
</div>

<div class="example">

```
2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2 # 2
```
```
147483632
```
</div>

*(przykład składa się z 30 dwójek)*


## Wzorcówka #1 (rekurencyjna)

Okazuje się, że wyrażenie z wejścia, jeżeli wsadzimy je całe w nawiasy dla pewności (`1 # 1` &rarr; `(1 # 1)`) spełnia następującą gramatykę:
  ```
  liczba := ["0" | "1" | ... | "9"]+
  wyrażenie := liczba | ["(" wyrażenie ["#" wyrażenie]* ")"]
  ```
Więc można napisać łatwo funkcję parsującą takie wyrażenie (`vzor.cpp`).

## Wzorcówka #2 (stos)

Ogólnie prosty stos i można iść po kolei.

## Sprytna wzorcówka w Pythonie

Python, ponieważ jest dynamicznym językiem, umie interpretować podobne wyrażenia. Więc poniższy program rozwiązuje problem:

```py
import re

class X(int):
    def __add__(self, other):
        return X((int(2 * self) + other) % (10 ** 9 + 7))

e = input().replace('#', '+')
e = re.sub("([0-9]+)", r"X(\1)", e)
print(eval(e))
```

Na szczęście nie można przesyłać rozwiązań w Pythonie.