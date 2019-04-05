#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

vector<I> change_x = {0, 1, 0, -1}, change_y = {1, 0, -1, 0};

I n, t;
vector<I> manual;
I point_x, point_y;
void read() {
  cin >> n >> t;
  manual.resize(n);
  for (I &i : manual) cin >> i;
  cin >> point_x >> point_y;
}

I cycle_length, cycle_time_length, cycles;
void get_cycle_length() {
  cycle_length = vector<I>{1, 4, 2, 4}[n % 4];

  cycle_time_length = 0;
  for (I i = 0; i < n * cycle_length; ++i) {
    cycle_time_length += manual[i % n] + 1;
  }

  cycles = t / cycle_time_length;
}

I shift_x, shift_y;
void get_shift() {
  shift_x = 0, shift_y = 0;
  for (I i = 0; i < n * cycle_length; ++i) {
    shift_x -= change_x[i % 4] * manual[i % n];
    shift_y -= change_y[i % 4] * manual[i % n];
  }
}

bool line_point_meeting(I ax, I ay, I bx, I by) {
  I px = point_x, py = point_y;
  if (ax == bx) {
    if (ay > by) swap(ay, by);
    return px == ax && ay <= py && py <= by;
  } else if (ay == by) {
    if (ax > bx) swap(ax, bx);
    return py == ay && ax <= px && px <= bx;
  }
  throw bad_function_call();
}

I line_meetings(I ax, I ay, I bx, I by) {
  I px = point_x, py = point_y, shx = shift_x, shy = shift_y;

  if (shx == 0 && shy == 0) {
    return line_point_meeting(ax, ay, bx, by) * cycles;
  }

  if (ax == bx) {
    // Make a:b horizontal: swap coordinates.
    swap(ax, ay), swap(bx, by), swap(px, py), swap(shx, shy);
  } else if (ay != by)
    throw bad_function_call();

  if (shy != 0) {
    if (shy < 0) {
      // Make shy positive; symmetry of py on ay == by.
      py = 2 * ay - py, shy = -shy;
    }
    if (shx < 0) {
      // Make shx positive; symmetry of ax and bx on py.
      ax = 2 * px - ax, bx = 2 * px - bx, shx = -shx;
    }
    if (ax > bx) swap(ax, bx);

    if (ay < py) return 0;

    I delta = ay - py;
    return (delta % shy == 0 && delta / shy <= (cycles - 1) &&
                    ax <= px + shx * (delta / shy) &&
                    px + shx * (delta / shy) <= bx
                ? 1
                : 0);
  }

  if (py != ay) {
    // a, b, p not colinear: no collisions.
    return 0;
  }

  I p = px, sh = shx, a = ax - p, b = bx - p;

  if (sh < 0) {
    sh = -sh, a = -a, b = -b;
  }
  if (a > b) swap(a, b);
  if (b < 0) return 0;
  a = max(a, (I)0);
  b = min(b, (cycles - 1) * sh);
  if (b < a) return 0;
  return b / sh - (a + sh - 1) / sh + 1;
}

I f(I ax, I ay, I bx, I by, I px, I py, I shx, I shy, I c = 1000) {
  point_x = px, point_y = py;
  shift_x = shx, shift_y = shy;
  cycles = c;
  return line_meetings(ax, ay, bx, by);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  read();
  get_cycle_length();
  get_shift();

  I result = 0;

  I x = 0, y = 0;
  if (point_x == 0 && point_y == 0) ++result;

  I d = 0;

  if (cycles > 0) {
    for (I i = 0; i < n * cycle_length; ++i) {
      I old_x = x, old_y = y;
      x += change_x[d] * manual[i % n], y += change_y[d] * manual[i % n];

      result += line_meetings(old_x + change_x[d], old_y + change_y[d], x, y);

      d = (d + 1) % 4;
    }
    x -= shift_x * (cycles - 1), y -= shift_y * (cycles - 1);
  }

  I time_left = t - cycle_time_length * cycles;
  for (I i = 0; time_left > 0; ++i) {
    I old_x = x, old_y = y;
    x += change_x[d] * min(manual[i % n], time_left);
    y += change_y[d] * min(manual[i % n], time_left);
    time_left -= manual[i % n] + 1;

    result +=
        line_point_meeting(old_x + change_x[d], old_y + change_y[d], x, y);

    d = (d + 1) % 4;
  }
  cout << result << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}
