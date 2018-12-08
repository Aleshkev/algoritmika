#include <iostream>
#include <cstdlib>
#include <vector>
#include <cassert>

using namespace std;

typedef long long unsigned row_t;


const char BLOCK_REPR[] = "\xdb\xdb";
const char SPACE_REPR[] = "  ";

class Board {
public:
    int inner_width, inner_height;
    int width, height;

    row_t full_line;
    row_t empty_line;

    vector<row_t> content;

    vector<int> column_heights;

    int aggregate_height = 0;
    int completed_lines = 0;
    int num_blocks = 0;
    int holes = 0;
    int bumpiness = 0;

    Board(int inner_width_ = 10, int inner_height_ = 20) {
        inner_width = inner_width_; inner_height = inner_height_;
        width = inner_width_ + 2; height = inner_height_ + 2;

        full_line = (1 << (width + 1)) - 1;
        empty_line = (1 << (width - 1)) + 1;

        content.resize(height, empty_line);
        content[0] = content[height - 1] = full_line;

        column_heights.resize(width);
    }

    bool get_block(int x, int y) {
        return content[y] & (1 << x);
    }
    void bit_set_block(int x, int y) {
        content[y] |= (1 << x);
    }
    void bit_erase_block(int x, int y) {
        content[y] &= ~(1 << x);
    }

    void drop_block(int x, int y, int h = 1) {
        for(int i = y; i < y + h; ++i) {
            assert(!get_block(x, i));
            bit_set_block(x, i);
            if(content[i] == full_line) {
                ++completed_lines;
            }
        }
        num_blocks += h;

        int new_height = y + h - 1;
        int old_height = column_heights[x];
        column_heights[x] = new_height;
        aggregate_height += (new_height - old_height);

        holes = aggregate_height - num_blocks;
    }

    void undrop_block(int x, int y, int h = 1)


    void print() {
        for(int i = 0; i < height; ++i) {
            for(int j = 0; j < width; ++j) {
                cout << (get_block(j, height-i-1) ? BLOCK_REPR : SPACE_REPR);
            }
            cout << "  ";

            if(i == 0) {
                cout << "Blocks: " << num_blocks;
            } else if(i == 1) {
                cout << "Total height: " << aggregate_height;
            } else if(i == 2) {
                cout << "Holes: " << holes;
            } else if(i == 3) {
                cout << "Completed lines: " << completed_lines;
            }

            cout << '\n';
        }
        cout.flush();
    }
};


int main()
{
    cout.sync_with_stdio(false);

    Board b;
    b.drop_block(1, 1);
    b.drop_block(4, 2);
    b.print();


    return 0;
}
