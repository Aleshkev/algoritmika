#include <iostream>
#include <vector>

using namespace std;

typedef long long int I;

struct Point {
    Point() {};
    Point(I x_, I y_) : x(x_), y(y_) {};
    I x, y;
};

const I inf = 9;

int main()
{
    I n;
    cin >> n;

    bool **passable = new bool*[n];
    for(I i = 0; i < n; ++i) {
        passable[i] = new bool[n];
    }

    Point army;
    Point baytograd;
    for(I y = 0; y < n; ++y) {
        for(I x = 0; x < n; ++x) {
            char c;
            cin >> c;
            if(c == 'M') {
                baytograd.x = x, baytograd.y = y;
                passable[x][y] = true;
            } else if(c == 'W') {
                army.x = x, army.y = y;
                passable[x][y] = true;
            } else if(c == '.') {
                passable[x][y] = true;
            } else {
                passable[x][y] = false;
            }
        }
    }

    I **shortest_path = new I*[n];
    for(I i = 0; i < n; ++i) {
        shortest_path[i] = new I[n];
        fill(shortest_path[i], shortest_path[i] + n, inf);
    }

    vector<Point> waiting;
    waiting.push_back(army);
    shortest_path[army.x][army.y] = -1;
    while(!waiting.empty()) {
        Point served = waiting.back();
        waiting.pop_back();

        I c = shortest_path[served.x][served.y] + 1;
        I x, y = served.y;
        for(x = served.x + 1; x < n && passable[x][y] && shortest_path[x][y] > c; ++x) {
            shortest_path[x][y] = c;
            waiting.push_back(Point(x, y));
        }
        for(x = served.x - 1; x >= 0 && passable[x][y] && shortest_path[x][served.y] > c; --x) {
            shortest_path[x][y] = c;
            waiting.push_back(Point(x, y));
        }
        x = served.x;
        for(y = served.y + 1; y < n && passable[x][y] && shortest_path[x][y] > c; ++y) {
            shortest_path[x][y] = c;
            waiting.push_back(Point(x, y));
        }
        for(y = served.y - 1; y >= 0 && passable[x][y] && shortest_path[x][y] > c; --y) {
            shortest_path[x][y] = c;
            waiting.push_back(Point(x, y));
        }
    }

    cout << shortest_path[baytograd.x][baytograd.y] + 1 << '\n';

    return 0;
}
