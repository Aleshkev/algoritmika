#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

typedef long long unsigned U;

struct City {
    U i;  // Indeks w tablicy miast

    vector<City *> froms;
    vector<City *> tos;

    U t;  // Czas przetworzenia
};

int main()
{
    U n;  // Liczba miast
    cin >> n;

    City *cities = new City[n];
    for(U i = 1; i < n; ++i) {
        for(U j = 0; j < i; ++j) {
            bool b;
            cin >> b;

            if(b) {
                cities[j].tos.push_back(&cities[i]);
                cities[i].froms.push_back(&cities[j]);
            } else {
                cities[i].tos.push_back(&cities[j]);
                cities[j].froms.push_back(&cities[i]);
            }
            cities[i].i = i;
        }
    }


    City *cities_transposed = new City[n];
    for(U i = 0; i < n; ++i) {
        cities_transposed[i].froms = cities[i].tos;
        cities_transposed[i].tos = cities[i].froms;
    }


    bool *visited = new bool[n];
    fill_n(visited, n, false);

    stack<City *> pending;
    pending.push(&cities[0]);

    U t = 1;

    while(!pending.empty()) {
        City *c = pending.top();
        pending.pop();
        visited[c->i] = true;

        cout << c->i << ' ';

        bool any_visited = false;
        for(U i = 0; i < c->tos.size(); ++i) {
            if(!visited[c->tos[i]->i]) {
                any_visited = true;

                pending.push(c->tos[i]);
                visited[c->tos[i]->i] = true;
            }
        }

        if(!any_visited) {
            c->t = t;
            ++t;
        }
    } cout << endl;

    for(U i = 0; i < n; ++i) {
        cout << cities[i].t << ' ';
    } cout << endl;


    for(U i = 0; i < cities[1].froms.size(); ++i) {
        cout << cities[1].froms[i] - cities << ' ';
    } cout << endl;

    return 0;
}
