#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class C8_6 {
    static void PaintFill(vector<vector<int>> screen, int x, int y, int color) {
        PaintFill(screen, x, y, screen[y][x], color);
    }

    static void PaintFill(vector<vector<int>> screen, int x, int y, int old_color, int new_color) {
        if(x < 0 || x >= screen[y].size() || y < 0 || y >= screen.size()) return;

        if(screen[y][x] == old_color) {
            screen[y][x] = new_color;
            PaintFill(screen, x-1, y, old_color, new_color);
            PaintFill(screen, x+1, y, old_color, new_color);
            PaintFill(screen, x, y-1, old_color, new_color);
            PaintFill(screen, x, y+1, old_color, new_color);
        }
    }
};