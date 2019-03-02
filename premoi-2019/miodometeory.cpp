#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

struct field {
  I x, y, z;

  field(I grid_x, I grid_y) {
    x = grid_x;
    z = grid_y - (grid_x + (grid_x & 1)) / 2;
    y = -x - z;
  }
  field(I x_, I y_, I z_) : x(x_), y(y_), z(z_) { assert(x + y + z == 0); }

  bool operator!=(const field &other) {
    return tie(x, y, z) != tie(other.x, other.y, other.z);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  auto towards = [](const field &start, const field &target) {
    I p_x = start.x, p_y = start.y, p_z = start.z;
    I x = target.x - start.x, y = target.y - start.y, z = target.z - start.z;

    if (x == y && y == z && z == 0) return field(p_x, p_y, p_z);

    if (x == z) {
      if (y > 0) return field(p_x - 1, p_y + 2, p_z - 1);
      if (y < 0) return field(p_x + 1, p_y - 2, p_z + 1);
    }
    if (x == y) {
      if (z > 0) return field(p_x - 1, p_y - 1, p_z + 2);
      if (z < 0) return field(p_x + 1, p_y + 1, p_z - 2);
    }
    if (y == z) {
      if (x > 0) return field(p_x + 2, p_y - 1, p_z - 1);
      if (x < 0) return field(p_x - 2, p_y + 1, p_z + 1);
    }

    if (x > z && x < y && y > z) return field(p_x, p_y + 1, p_z - 1);
    if (x > z && x > y && y > z) return field(p_x + 1, p_y, p_z - 1);
    if (x > z && x > y && y < z) return field(p_x + 1, p_y - 1, p_z);
    if (x < z && x > y && y < z) return field(p_x, p_y - 1, p_z + 1);
    if (x < z && x < y && y < z) return field(p_x - 1, p_y, p_z + 1);
    if (x < z && x < y && y > z) return field(p_x - 1, p_y + 1, p_z);
  };

  auto distance = [](const field &a, const field &b) {
    return max({abs(a.x - b.x), abs(a.y - b.y), abs(a.z - b.z)});
  };

  field player(1, 1);

  I n_stars;
  cin >> n_stars;

  for (I star_i = 0; star_i < n_stars; ++star_i) {
    I star_grid_x, star_grid_y, star_target_grid_x, star_target_grid_y;
    cin >> star_grid_x >> star_grid_y;
    cin >> star_target_grid_x >> star_target_grid_y;

    field star(star_grid_x, star_grid_y);
    field star_target(star_target_grid_x, star_target_grid_y);

    I min_distance = distance(player, star);

    while (star != star_target) {
      player = towards(player, star);
      star = towards(star, star_target);

      min_distance = min(min_distance, distance(player, star));
    }
    player = towards(player, star);

    cout << min_distance << endl;
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}
