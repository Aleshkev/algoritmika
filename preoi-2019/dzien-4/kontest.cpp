#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

struct Q {
  I player, time, add;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  []() {
    I m, t;
    cin >> m >> m >> t;

    if (m == 0) {
      cout << 1 << '\n';
      return;
    }

    vector<Q> queries(m);
    for (Q &i : queries) cin >> i.player >> i.time >> i.add;

    vector<I> players;
    for (Q &i : queries) players.push_back(i.player);
    sort(players.begin(), players.end());
    players.erase(unique(players.begin(), players.end()), players.end());
    for (Q &i : queries)
      i.player = (lower_bound(players.begin(), players.end(), i.player) -
                  players.begin());
    I n = players.size();

    vector<I> lead_time(n);

    vector<I> score(n);
    I max_score = 0;
    vector<I> current_lead(n), time_added(n, 0);
    iota(current_lead.begin(), current_lead.end(), 0);

    sort(queries.begin(), queries.end(), [](const Q &l, const Q &r) {
      return tie(l.time, l.player) < tie(r.time, r.player);
    });

    for (Q &q : queries) {
      if (q.add == 0) continue;

      score[q.player] += q.add;
      if (score[q.player] > max_score) {
        max_score = score[q.player];

        for (I i = 0; i < current_lead.size(); ++i) {
          lead_time[current_lead[i]] += q.time - time_added[i];
        }
        current_lead.clear(), time_added.clear();
      }
      if (score[q.player] == max_score) {
        current_lead.push_back(q.player);
        time_added.push_back(q.time);
      }
    }

    for (I i = 0; i < current_lead.size(); ++i) {
      lead_time[current_lead[i]] += t - time_added[i] + 1;
    }

    cout << players[max_element(lead_time.begin(), lead_time.end()) -
                    lead_time.begin()]
         << '\n';
  }();

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}
