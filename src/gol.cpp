#include "gol.hh"

void gol_step(Grid& grid) {
    Grid grid_copy = grid;
    for (uint16_t x = 0; x < grid_copy.get_width(); x++) {
        for (uint16_t y = 0; y < grid_copy.get_height(); y++) {
            uint8_t neighbors = 0;
            for (int8_t i = x - 1; i <= x + 1; i++) {
                for (int8_t j = y - 1; j <= y + 1; j++) {
                    if (i >= 0 && i < grid_copy.get_width() && j >= 0 && j < grid_copy.get_height())
                        if (grid_copy(i, j)) neighbors++;
                }
            }
            if (grid(x, y)) neighbors--;
            if (grid(x, y)) {
                if (neighbors == 2 || neighbors == 3) grid(x, y, true);
                else grid(x, y, false);
            } else {
                if (neighbors == 3) grid(x, y, true);
                else grid(x, y, false);
            }
        }
    }
}