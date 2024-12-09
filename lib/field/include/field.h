#pragma once
#include <vector>
#include <string>
#include "file.h"



class Field
{
public:
    Field();
    Field(File file);
    Field(size_t _x_size, size_t _y_size);
    Field(Field &other);
    size_t get_x_size();
    size_t get_y_size();
    size_t count_neighbors(int x, int y);
    void create_next_gen();




public:
    size_t x_size;
    size_t y_size;
    std::vector<std::string> field;
    size_t cell_to_birth;
    size_t cells_to_survive;
};