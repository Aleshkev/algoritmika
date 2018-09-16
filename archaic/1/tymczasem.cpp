#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long int I;

struct Point {
    Point() {};
    Point(I x_, I y_) : x(x_), y(y_) {};
    I x, y;
};

const I inf = 1e18;

int main()
{
    cout.sync_with_stdio(false);

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

    bool **visited_vertically = new bool*[n];
    bool **visited_horizontally = new bool*[n];
    for(I i = 0; i < n; ++i) {
        visited_horizontally[i] = new bool[n];
        fill(visited_horizontally[i], visited_horizontally[i] + n, false);
        visited_vertically[i] = new bool[n];
        fill(visited_vertically[i], visited_vertically[i] + n, false);
    }

    queue<Point> waiting;
    waiting.push(army);
    shortest_path[army.x][army.y] = -1;
    while(!waiting.empty()) {
        Point served = waiting.front();
        waiting.pop();

        I c = shortest_path[served.x][served.y] + 1;
        I x, y = served.y;
        for(x = served.x + 1; x < n && passable[x][y] && (shortest_path[x][y] > c || !visited_horizontally[x][y]); ++x) {
            shortest_path[x][y] = min(shortest_path[x][y], c);
            waiting.push(Point(x, y));
            visited_horizontally[x][y] = true;
        }
        for(x = served.x - 1; x >= 0 && passable[x][y] && (shortest_path[x][y] > c || !visited_horizontally[x][y]); --x) {
            shortest_path[x][y] = min(shortest_path[x][y], c);
            waiting.push(Point(x, y));
            visited_horizontally[x][y] = true;
        }
        x = served.x;
        for(y = served.y + 1; y < n && passable[x][y] && (shortest_path[x][y] > c || !visited_vertically[x][y]); ++y) {
            shortest_path[x][y] = min(shortest_path[x][y], c);
            waiting.push(Point(x, y));
            visited_vertically[x][y] = true;
        }
        for(y = served.y - 1; y >= 0 && passable[x][y] && (shortest_path[x][y] > c || !visited_vertically[x][y]); --y) {
            shortest_path[x][y] = min(shortest_path[x][y], c);
            waiting.push(Point(x, y));
            visited_vertically[x][y] = true;
        }
    }

    I path = shortest_path[baytograd.x][baytograd.y] + 1;

    if(path >= inf) path = -1;

    cout << path << '\n';

    return 0;
}
