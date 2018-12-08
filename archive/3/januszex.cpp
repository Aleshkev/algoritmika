#include <bits/stdc++.h>

using namespace std;

typedef int I;

struct Span {
    I a, b;

    Span(I a, I b) : a(a), b(b) {};

    bool operator<(const Span &other) {
        return a < other.a;
    };
};

int main()
{
    char JANUSZEX[] = "januszex";
    I EIGHT = sizeof(JANUSZEX) - 1;

    I n, m;
    scanf("%i %i", &n, &m);

    //cout << n << m;

    static I t[200000];
    for(I i = 0; i < n; ++i) {
        char c;
        scanf(" %c", &c);
        char *j = strchr(JANUSZEX, c);
        t[i] = j != NULL ? j - JANUSZEX : EIGHT;
    }

    /*for(I i = 0; i < n; ++i) {
        cout << setw(2) << t[i] << ' ';
    } cout << '\n';*/

    vector<Span> spans;

    for(I i = 0; i < n; ++i) {
        if(t[i] != 0) {
            continue;
        }

        I current = 0;
        I b = i + 1;
        while(b < n) {
            if(t[b] == current + 1) {
                ++current;
                if(current == EIGHT - 1) {
                    break;
                }
            }
            ++b;
        }
        if(b < n) {
            spans.push_back(Span(i, b + 1));
        }
    }

    /*for(I i = 0; i < spans.size(); ++i) {
        cout << spans[i].a << ":" << spans[i].b << ' ';
        for(I j = spans[i].a; j < spans[i].b; ++j) {
            cout << t[j] << ' ';
        } cout << '\n';
    }*/

    /*for(I i = 0; i < n; ++i) {
        cout << setw(2) << u[i] << ' ';
    } cout << '\n';*/

    for(I i = 0; i < m; ++i) {
        I a, b;
        scanf("%i %i", &a, &b);
        --a;

        I score = 0;

        I taken_to = 0;
        for(vector<Span>::iterator it = lower_bound(spans.begin(), spans.end(), Span(a, -1)); it != spans.end() && it->b <= b; ++it) {
            if(it->a < taken_to) {
                continue;
            }
            ++score;
            taken_to = it->b;
        }

        //cout << ": " << score << endl;
        printf("%i\n", score);
    }



    return 0;
}
