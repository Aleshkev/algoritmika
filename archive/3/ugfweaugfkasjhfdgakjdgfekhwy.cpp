#include <bits/stdc++.h>
using namespace std;


pair<long long, long long> input[9001];
long long maxi[9001][3];
long long ans;
int main()
{
    cin.tie(0);
    long long n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
    {
        cin >> input[i].first >> input[i].second;
    }
    sort(input, input + n);
    for(int i = 0; i < n; ++i)
    {
        if(i > 0)
        {
            maxi[i][0] = maxi[i - 1][0];
            maxi[i][0] = maxi[i - 1][1];
            maxi[i][0] = maxi[i - 1][2];
        }
        int u = input[i].second;
        //cout << u << '\n';
        if (u > maxi[i][0])
        {
            int j = maxi[i][0];
            maxi[i][0] = u;
            u = j;
        }
        if (u > maxi[i][1])
        {
            int j = maxi[i][1];
            maxi[i][1] = u;
            u = j;
        }
        if (u > maxi[i][2])
        {
            int j = maxi[i][2];
            maxi[i][2] = u;
            u = j;
        }
        //cout << maxi[i][0] << " " << maxi[i][1] << " " << maxi[i][2] << '\n';
    }
    for(int z1 = 0; z1 < n; ++z1)
    {
        int z3 = n;
        for(int z2 = z1 + 1; z2 < n; ++z2)
        {
            int mas = m - input[z1].first - input[z2].first;
            while(input[z3].first > mas && z3 > z2) --z3;
            if(z3 <= z2) break;

            if(maxi[z3][0] == input[z1].second)
            {
                if(maxi[z3][1] == input[z2].second)
                {
                    ans = max(ans, input[z1].second + input[z2].second + maxi[z3][2]);
                }
                ans = max(ans, input[z1].second + input[z2].second + maxi[z3][1]);
            }
            else if(maxi[z3][0] == input[z2].second)
            {
                if(maxi[z3][1] == input[z1].second)
                {
                    ans = max(ans, input[z1].second + input[z2].second + maxi[z3][2]);
                }
                ans = max(ans, input[z1].second + input[z2].second + maxi[z3][1]);
            }
            else ans = max(ans, input[z1].second + input[z2].second + maxi[z3][0]);
        }
    }
    cout << ans << '\n';
    for(int i = 0; i < n; ++i) cout << maxi[i][0] << ' ';
    cout << '\n';
    for(int i = 0; i < n; ++i) cout << maxi[i][1] << ' ';
    cout << '\n';
    for(int i = 0; i < n; ++i) cout << maxi[i][2] << ' ';
    cout << '\n';
    return 0;
}
