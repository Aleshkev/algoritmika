#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

//      `
//  ``.`/o`
// .yhhsshy`
//  `.:+osdho:`                  .:oo+-
//        -mmdy/.               `ydmmmds`
//         sNmmdhs/`            -mmmNmmm-
//         `:hNNNmmhs-`         -dmNNNdy`
//           `:dNNNNNhys-``     `/mNNmy/
//             .omNNNNmNmhoo+///syyhhysy/::-.`
//               .+hmMMNNNNhyyoyhsyysssyysyyys:
//                  .+hNMNNhssshdhdddddddyymNdho`
//                     ./syyyyymddhhhdmNdhhhNNmdo`
//                        :yhyhNmdmmmmNMNNMdmmmdhy/
//                       `oyhhhNmmmmNNNMMMNNmdyyddd-
//                       :yyhhdddmdmNNNNMMNNNmNNmmNy
//                      `shydhmmdddmmmNNNNNNN--ohdh/
//                      -ddhddmmmddmddmNNNNmy
//                     .oddmdNNNmNNmhhhmmNNmy`
//                     -hmmddMMNNmNmddddmNNmh-
//                    `+dmmddMMMMNNmmmmmmNMmh:
//                    -mNNNNMMMMMMMNmmmmmMMmho
//                      `:hNMMMMMMNmmmmNNMMNNh
//                        +NNNMMMMNmmNNmmmd:.

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  I n, m, q;
  cin >> n >> m >> q;

  vector<vector<I>> graph(n), hparg(n);
  for (I i = 0; i < m; ++i) {
    I a, b;
    cin >> a >> b;
    --a, --b;

    // Napisałem SCC zanim dokończyłem czytać treść zadania, więc szkoda już
    // usuwać xd
    graph[a].push_back(b), hparg[b].push_back(a);
    hparg[a].push_back(b), graph[b].push_back(a);
  }

  vector<I> order;
  {
    vector<bool> visited(n);
    function<void(I)> dfs = [&](I i) {
      order.push_back(i);
      for (I j : graph[i]) {
        if (visited[j]) continue;
        visited[j] = true;
        dfs(j);
      }
    };
    for (I i = 0; i < n; ++i) {
      if (visited[i]) continue;
      visited[i] = true;
      dfs(i);
    }
  }
  reverse(order.begin(), order.end());

  vector<I> component(n);
  {
    vector<bool> visited(n);
    function<void(I)> dfs = [&](I i) {
      for (I j : graph[i]) {
        if (visited[j]) continue;
        visited[j] = true;
        component[j] = component[i];
        dfs(j);
      }
    };
    I k = 0;
    for (I i : order) {
      if (visited[i]) continue;
      visited[i] = true;
      component[i] = k++;
      dfs(i);
    }
  }

  for (I i = 0; i < q; ++i) {
    I a, b;
    cin >> a >> b;
    --a, --b;
    cout << (component[a] == component[b] ? "T" : "N") << "\n";
  }

#ifdef UNITEST
  cout.flush(), system("pause");
#endif
}
