#include <bits/stdc++.h>

using namespace std;

typedef long long int I;
typedef long double F;


struct Stone {
    F x, y;
};


F sq_sum(const Stone &a, const Stone &b) {
    const F dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}


int main()
{
    I n, start;
    F jump_length;
    scanf("%lli %lli %llf", &n, &start, &jump_length);
    --start;

    Stone stones[1000];

    for(I i = 0; i < n; ++i) {
        scanf("%llf %llf", &stones[i].x, &stones[i].y);
    }

    I jump_length_sq = jump_length * jump_length;

    vector<I> stck;
    bool visited[1000];
    fill(visited, visited + n, false);

    stck.push_back(start);
    visited[start] = true;

    F max_distance_sq = 0.0;

    while(!stck.empty()) {
        I current = stck.back();
        stck.pop_back();

        //cout << "visiting " << current << endl;

        max_distance_sq = max(max_distance_sq, sq_sum(stones[start], stones[current]));

        for(I i = 0; i < n; ++i) {
            if(visited[i]) {
                continue;
            }

            if(sq_sum(stones[current], stones[i]) <= jump_length_sq) {
                //cout << " appending " << i << endl;
                stck.push_back(i);
                visited[i] = true;
            }
        }
    }

    printf("%.3llf\n", sqrt(max_distance_sq) + jump_length);

    return 0;
}
