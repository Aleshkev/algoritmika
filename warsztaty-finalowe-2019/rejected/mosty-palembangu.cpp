#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I inf = 1e18;
typedef pair<I, I> II;
typedef double F;

template <typename T>
ostream &operator<<(ostream &o, const vector<T> &v) {
  o << "[";
  for (auto i = v.begin(); i != v.end(); ++i) {
    o << *i;
    if (i != prev(v.end())) o << ", ";
  }
  o << "]";
  return o;
}
ostream &operator<<(ostream &o, II i) {
  o << "(" << i.first << ", " << i.second << ")";
  return o;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  I k, n;
  cin >> k >> n;

  I permanent = 0;
  vector<II> segments;
  vector<I> points;
  for (I i = 0; i < n; ++i) {
    char c, z;
    I a, b;
    cin >> c >> a >> z >> b;
    if (a > b) swap(a, b);
    permanent += b - a;
    if (c == z) continue;
    ++permanent;  // Szerokość rzeki = 1.

    points.push_back(a), points.push_back(b);
    segments.push_back({a, b});
  }
  sort(points.begin(), points.end());
  points.erase(unique(points.begin(), points.end()), points.end());

  auto cost = [](II segment, I x) {
    if (segment.first <= x && x <= segment.second)
      return I(0);
    else if (x < segment.first)
      return 2 * (segment.first - x);
    else
      return 2 * (x - segment.second);
  };

  // cout << "permanent: " << permanent << '\n';
  // cout << points << endl;

  // I correct_ans = inf;
  // if (segments.empty()) {
  //   correct_ans = permanent;
  // } else if (k == 1) {
  //   for (I i : points) {
  //     I c = 0;
  //     for (II s : segments) {
  //       c += cost(s, i);
  //     }
  //     correct_ans = min(correct_ans, c + permanent);
  //   }
  // } else if (k == 2) {
  //   for (I i : points) {
  //     for (I j : points) {
  //       I c = 0;
  //       for (II s : segments) {
  //         c += min(cost(s, i), cost(s, j));
  //       }
  //       correct_ans = min(correct_ans, c + permanent);
  //     }
  //   }
  // }

  // cout << correct_ans << '\n';

  auto scale = [&](I x) {
    return lower_bound(points.begin(), points.end(), x) - points.begin();
  };

  I quick_ans = inf;
  if (segments.empty()) {
    quick_ans = permanent;
  } else if (k == 1) {
    I m = points.size();

    vector<I> inc_right(m), inc_left(m);
    for (II s : segments) {
      ++inc_right[scale(s.second)];
      ++inc_left[scale(s.first)];
    }

    vector<I> v_right(m), v_left(m);
    {
      v_right[0] = 0;
      I a = inc_right[0];
      for (I i = 1; i < m; ++i) {
        v_right[i] = v_right[i - 1] + 2 * a * (points[i] - points[i - 1]);
        a += inc_right[i];
      }
    }
    {
      v_left[m - 1] = 0;
      I a = inc_left[m - 1];
      for (I i = m - 1 - 1; i >= 0; --i) {
        v_left[i] = v_left[i + 1] + 2 * a * (points[i + 1] - points[i]);
        a += inc_left[i];
      }
    }
    // cout << segments << endl;
    // cout << "inc r: " << inc_right << endl;
    // cout << "v   r: " << v_right << endl;
    // cout << "inc l: " << inc_left << endl;
    // cout << "v   l: " << v_left << endl;

    vector<I> v(m);
    for (I i = 0; i < m; ++i) v[i] = v_left[i] + v_right[i];

    quick_ans = *min_element(v.begin(), v.end()) + permanent;
  } else if (k == 2) {
    for (I i : points) {
      for (I j : points) {
        I c = 0;
        for (II s : segments) {
          c += min(cost(s, i), cost(s, j));
        }
        quick_ans = min(quick_ans, c + permanent);
      }
    }
  }

  cout << quick_ans << '\n';

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}
