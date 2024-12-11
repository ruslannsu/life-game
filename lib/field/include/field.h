#pragma once
#include <vector>
#include <string>
#include "file.h"

struct Range
{
    size_t left;
    size_t right;
};
class Field
{
public:
    Field();
    Field(File file);
    Field(size_t _x_size, size_t _y_size);
    Field(Field &other);
    size_t get_x_size();
    size_t get_y_size();
    std::vector<std::string> get_field();

    size_t count_neighbors(int x, int y);
    void insert_cell(size_t x, size_t y);
    void create_next_gen();


public:
    size_t x_size;
    size_t y_size;
    std::vector<std::string> field;
    Range cells_to_birth;
    Range cells_to_survive;
};