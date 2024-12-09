#include "field.h"
#include <iostream>
#include <setjmp.h>

#define N 10

Field::Field(): field(N, std::string(N, '0')), x_size(N), y_size(N){}

Field::Field(size_t _x_size, size_t _y_size): field(x_size, std::string(y_size, '0')), x_size(_x_size), y_size(_y_size){}
size_t Field::count_neighbors(int x, int y)
{
    size_t neighbors = 0;
    for (int i = -1; i != 2; ++i)
    {
        for (int j = -1; j != 2; ++j)
        {
            if ((i != 0) || (j != 0))
            {
                int neighbor_x = (x + j) % static_cast<int>(x_size);
                int neighbor_y = (y + i) % static_cast<int>(y_size);
                if (neighbor_x == -1)
                {
                    neighbor_x = x_size - 1;
                }
                if ((neighbor_y) == -1)
                {
                    neighbor_y = y_size - 1;
                }

                if (field[neighbor_x][neighbor_y] == '#')
                {
                    ++neighbors;
                }
            }
        }
    }
    return neighbors;
}


void Field::create_next_gen()
{
    std::vector<std::string> next_field(x_size, std::string(y_size, '0'));
    for (size_t i = 0; i != x_size; ++i)
    {
        for (size_t j = 0; j != y_size; j++)
        {
            size_t count = count_neighbors(i ,j);
            if (((count == 2) || (count == 3)) && field[i][j] == '#')
            {
                next_field[i][j] = '#';
                continue;
            }
            if (count == 3)
            {
                next_field[i][j] = '#';
                continue;
            }
            if (((count != 2) && (count != 3)))
            {
                next_field[i][j] = '0';
            }
        }
    }
    field = next_field;
}
