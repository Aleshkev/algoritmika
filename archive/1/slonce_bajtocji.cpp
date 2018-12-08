#include <iostream>

using namespace std;

typedef int I;

int main()
{
    I d; cin >> d;

    I curr = 100, step = curr / 2;
    while(step > 1) {
        I r = (curr + 1) * (curr + 1) - curr * curr;
        cout << curr << ": " << (curr + 1) * (curr + 1) << " - " << curr * curr << " = " << r << endl;
        if(r < d) {
            curr += step;
        } else if(r > d) {
            curr -= step;
        } else {
            break;
        }
        step /= 2;
    }

    cout << curr << " " << curr * curr << " " << (curr + 1) * (curr + 1) << endl;

    //I a, b; cin >> a >> b;
    return 0;
}
