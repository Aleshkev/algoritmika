#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

bool line_point_collision(I ax, I ay, I bx, I by, I px, I py) {
  if (ax == bx) {
    if (ay > by) swap(ay, by);
    return px == ax && ay <= py && py <= by;
  } else if (ay == by) {
    if (ax > bx) swap(ax, bx);
    return py == ay && ax <= px && px <= bx;
  }
  throw bad_function_call();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  I n, t;
  cin >> n >> t;

  vector<I> program(n);
  for (I &i : program) cin >> i;

  I x, y;
  cin >> x >> y;

  vector<I> change_x = {0, 1, 0, -1}, change_y = {1, 0, -1, 0};

  I score = 0;

  I cx = 0, cy = 0, cd = 0, time_left = t, instruction = 0;
  if (x == 0 && y == 0) {
    ++score;
  }
  while (time_left > 0) {
    I lx = cx, ly = cy;
    cx += change_x[cd] * min(program[instruction], time_left);
    cy += change_y[cd] * min(program[instruction], time_left);

    if (line_point_collision(lx + change_x[cd], ly + change_y[cd], cx, cy, x,
                             y)) {
      ++score;
    }

    time_left -= abs(cx - lx) + abs(cy - ly);
    cd = (cd + 1) % 4;
    --time_left;  // Cost of rotation.
    instruction = (instruction + 1) % n;
  }

  cout << score << endl;

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}
