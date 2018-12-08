#include <iostream>
#include <set>

using namespace std;

typedef long long int I;

int main()
{
    I n, m, q;  // Liczba przypraw, wynik powinien być wypisany modulo m, liczba wydarzeń
    cin >> n >> m >> q;

    I *spices = new I[n];
    for(I i = 0; i < n; ++i) {
        cin >> spices[i];
    }
    bool *allowed = new bool[n];
    fill(allowed, allowed + n, true);

    // Liczy potrzebny rozmiar drzewa
    I tree_size = 1, tree_base = 1;
    while(tree_base < n) {
        tree_base <<= 1;
        tree_size += tree_base;
    }
    ++tree_size;

    // Przebudowywuje drzewo
    I *tree = new I[tree_size];
    fill(tree, tree + tree_size, 1);
    for(I i = 0; i < n; ++i) {
        if( ! allowed[i]) {
            continue;
        }
        for(I v = tree_base + i; v > 0; v /= 2) {
            tree[v] *= spices[i];
        }
    }

    /*cout << "tree=\n    ";
    for(I i = 0; i < n; ++i) {
        I v = tree_base + i;
        cout << tree[v] << " ";
    } cout << endl;
    cout << "    " << tree[1] << endl;*/

    for(I i = 0; i < q; ++i) {
        bool type;
        cin >> type;

        if(type == 0) {
            I p, w;  // Jest od teraz w odmian p-tej przyprawy
            cin >> p >> w;
            --p;
            I old_w = spices[p];
            spices[p] = w;

            if(allowed[p]) {
                for(I v = tree_base + p; v > 0; v /= 2) {
                    if(old_w > 0) {
                        tree[v] /= old_w;
                    }
                    tree[v] *= w;
                }
            }

            /*cout << "tree=\n    ";
            for(I ii = 0; ii < n; ++ii) {
                I v = tree_base + ii;
                cout << tree[v] << " ";
            } cout << endl;
            cout << "    " << tree[1] << endl;*/
        } else {
            I k;  // Wielkość zaleceń
            cin >> k;

            fill(allowed, allowed + n, true);
            for(I j = 0; j < k; ++j) {
                I b;
                cin >> b;
                --b;
                allowed[b] = false;
            }

            fill(tree, tree + tree_size, 1);
            for(I l = 0; l < n; ++l) {
                if( ! allowed[l]) {
                    continue;
                }
                for(I v = tree_base + l; v > 0; v /= 2) {
                    tree[v] *= spices[l];
                }
            }

            /*cout << "tree=\n    ";
            for(I ii = 0; ii < n; ++ii) {
                I v = tree_base + ii;
                cout << tree[v] << " ";
            } cout << endl;
            cout << "    " << tree[1] << endl;*/

            cout << tree[1] % m << '\n';
        }
    }

    return 0;
}
