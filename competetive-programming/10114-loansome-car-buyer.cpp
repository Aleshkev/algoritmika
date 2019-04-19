#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
typedef double F;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  for (;;) {
    I loan_months;
    F down_payment, loan;
    I q;
    cin >> loan_months >> down_payment >> loan >> q;
    if (loan_months < 0) break;
    vector<F> deprecation(loan_months + 1, -1);
    while (q--) {
      I i;
      F v;
      cin >> i >> v;
      deprecation[i] = v;
    }
    for (I i = 1; i <= loan_months; ++i)
      if (deprecation[i] == -1) deprecation[i] = deprecation[i - 1];

    F car_worth = down_payment + loan, owe = loan,
      payment = loan / (F)loan_months;
    for (I i = 0; i <= loan_months; ++i) {
      car_worth *= (1 - deprecation[i]);
      if (i > 0) owe -= payment;
      if (owe < car_worth) {
        cout << i << " month" << (i != 1 ? "s" : "") << '\n';
        break;
      }
    }
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
  return 0;
}