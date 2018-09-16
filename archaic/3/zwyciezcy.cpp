#include <bits/stdc++.h>

using namespace std;

typedef long long int I;

int main()
{
    I n;
    cin >> n;

    vector<I> winners;
    I highscore = 0;

    for(I i = 0; i < n; ++i) {
        I score;
        cin >> score;

        if(score > highscore) {
            winners.clear();
            highscore = score;
        }
        if(score == highscore) {
            winners.push_back(i);

        }
    }

    for(I i = 0; i < winners.size(); ++i) {
        cout << char('A' + winners[i]);
    } cout << '\n';

    return 0;
}
