#include "gol.hh"

void golStep(Grid& grid) {
    Grid gridCopy = grid;
    for (uint32_t x = 0; x < gridCopy.getWidth(); x++) {
        for (uint32_t y = 0; y < gridCopy.getWeight(); y++) {
            uint8_t neighbors = 0;
            for (int32_t i = x - 1; i <= (int32_t)(x + 1); i++) {
                for (int32_t j = y - 1; j <= (int32_t)(y + 1); j++) {
                    if (i >= 0 && i < (int32_t)gridCopy.getWidth() && j >= 0 && j < (int32_t)gridCopy.getWeight())
                        if (gridCopy(i, j)) neighbors++;
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