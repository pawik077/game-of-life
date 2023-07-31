#include "Grid.hh"

Grid::Grid(uint32_t width, uint32_t height) : width(width), height(height), cells(width * height, false) { }

void Grid::resize(uint32_t width, uint32_t height) {
    this->width = width;
    this->height = height;
    cells.resize(width * height);
}

std::ostream& operator<< (std::ostream& out, const Grid& grid) {
    for (uint32_t i = 0; i < grid.get_width(); i++) {
        for (uint32_t j = 0; j < grid.get_height(); j++)
            out << grid(i,j ) << " ";
        out << "\n";
    }
    return out;
}