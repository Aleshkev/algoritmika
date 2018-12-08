#include <iostream>

using namespace std;

typedef long long unsigned U;
typedef long long int I;

int main()
{

    U n;
    char real_most_freq;
    cin >> n >> real_most_freq;

    char *word = new char[n];
    for(U i = 0; i < n; ++i) {
        cin >> word[i];
    }

    U *occurences = new U['Z' - 'A' + 1];
    fill_n(occurences, 'Z' - 'A' + 1, 0);
    for(U i = 0; i < n; ++i) {
        ++occurences[word[i] - 'A'];
    }

    char hidden_most_freq = '_';
    U _hidden_most_freq_occurences = 0;
    for(U i = 0; i < 'Z' - 'A' + 1; ++i) {
        if(occurences[i] > _hidden_most_freq_occurences) {
            hidden_most_freq = 'A' + i;
            _hidden_most_freq_occurences = occurences[i];
        }
    }

    I shift = (hidden_most_freq - real_most_freq);

    for(U i = 0; i < n; ++i) {
        char c = word[i] - shift;
        if(c < 'A') {
            c += 'Z' - 'A' + 1;
        } else if(c > 'Z') {
            c -= 'Z' - 'A' + 1;
        }
        cout << c;
    } cout << '\n';

    return 0;
}
