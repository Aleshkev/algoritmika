#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int I;
typedef short int B;
const I MAX_I = 2e9 + 1;

int main()
{
    I n;
    cin >> n;

    static I occurences[I(1e6 + 1)] = {0};

    for(I i = 0; i < n; ++i) {
        I weight_c;
        cin >> weight_c;
        I weight = 0;
        I last_digit = -1;
        for(I j = 20; j >= 0; --j) {
            I digit = !!(weight_c & (1 << j));

            if(digit == last_digit) {
                weight <<= 1;
                weight += digit;
                last_digit = -1;
            } else {
                last_digit = digit;
            }
        }

        ++occurences[weight];
        cout << weight << '\n';
    }

    cout << distance(occurences, max_element(occurences, occurences + I(1e6 + 1))) << '\n';

    return 0;
}
