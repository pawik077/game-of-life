#ifndef GRID_HH
#define GRID_HH

#include <vector>
#include <cstdint>
#include <iostream>

class Grid {
    uint32_t width;
    uint32_t height;
    std::vector<bool> cells;
public:
    Grid(uint32_t width, uint32_t height);
    const bool operator() (uint32_t x, uint32_t y) const { return cells[x + y * width]; }
    void operator() (uint32_t x, uint32_t y, bool value) { cells[x + y * width] = value; }
    const uint32_t& get_width() const { return width; }
    const uint32_t& get_height() const { return height; }
    void resize(uint32_t width, uint32_t height);
};

std::ostream& operator<< (std::ostream& out, const Grid& grid);

struct point {
    uint32_t x;
    uint32_t y;
};

#endif