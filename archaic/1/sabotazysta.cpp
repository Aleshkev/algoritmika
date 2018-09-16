#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

typedef long long unsigned U;
typedef double F;

//U c = 0;

struct Node {
    Node *parent;
    vector<Node *> children;

    U population;  // Ilość pośrednich i bezpośrednich podwładnych

    F population_minus_1;
};


void calc(Node &node) {
    node.population = 1;
    for(U i = 0; i < node.children.size(); ++i) {
        Node &child = *node.children[i];

        calc(child);

        //++c;

        node.population += child.population;
    }
    node.population_minus_1 = node.population - 1;
}


int main()
{
    cout.sync_with_stdio(false);

    U n, k;  // Liczba pracowników, największa liczba zbuntowanych
    cin >> n >> k;

    Node *nodes = new Node[n];
    nodes[0].parent = NULL;  // Pracownik 1 jest szefem wszystkich
    for(U i = 1; i < n; ++i) {
        U j;  // Numer przełożonego
        cin >> j;
        --j;

        //++c;

        // Przełożony ma zawsze niższy numer niż podwładny, można więc założyć, że został już wczytany
        nodes[i].parent = &nodes[j];
        nodes[j].children.push_back(&nodes[i]);
    }

    calc(nodes[0]);  // Pierwszy pracownik, szef, jest na górze drzewa

    //c = 0;

    //U d = 0;

    F current_m = 0.5;
    for(F step = 0.25; step >= 0.0000005; step /= 2) {
        //++d;
        U max_revolting = 1;

        for(U i = 0; i < n; ++i) {
            Node *node = &nodes[i];

            if(node->children.empty()) {
                F revolting = 1;

                for(;;) {
                    //++c;
                    if(revolting / node->population_minus_1 > current_m) {
                        revolting = node->population;
                    } else {
                        break;
                    }

                    if(revolting > k) {
                        goto too_many_revolting;
                    }

                    if(node->parent == NULL) {
                        break;
                    } else {
                        node = node->parent;
                    }
                }

                if(revolting > max_revolting) {
                    max_revolting = revolting;
                }
            }
        }

        current_m -= step;
        continue;

        too_many_revolting: {
            current_m += step;
            continue;
        }
    }
    //cout << d << endl;

    //cout << c << '\n';

    cout << fixed << setprecision(6) << current_m << endl;

    return 0;
}
