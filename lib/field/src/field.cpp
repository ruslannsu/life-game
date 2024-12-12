#include "field.h"
#include <iostream>



Field::Field():field(1, std::string(1, '0'))
{
}



std::vector<std::string> Field::get_field()
{
    return field;
}




size_t Field::get_x_size()
{
    return x_size;
}

size_t Field::get_y_size()
{
    return y_size;
}

Field::Field(File file)
{
    std::cout << "here";
    x_size = file.get_field_size().x;
    y_size = file.get_field_size().y;

    field = std::vector<std::string>(x_size, std::string(y_size, '0'));
    std::string temp_rules = file.get_rules();
    if (temp_rules.substr(0, 4) != std::string("#R B"))
    {
        throw std::invalid_argument("Incorrect rules");
    }
    bool is_half(false);
    size_t half_index = temp_rules.size() - 1;
    for (size_t i = 4; i != temp_rules.size(); ++i)
    {
        if (temp_rules.substr(i, 2) == "/S")
        {
            try
            {
                stoi(temp_rules.substr(4, i - 3));
                stoi(temp_rules.substr(i + 2, temp_rules.size()));
                cells_to_birth.left = static_cast<size_t>(std::stoi(temp_rules.substr(4, 1)));
                cells_to_birth.right = static_cast<size_t>(std::stoi(temp_rules.substr(i - 1, 1)));
                cells_to_survive.left = static_cast<size_t>(std::stoi(temp_rules.substr(i + 2, 1)));
                cells_to_survive.right = static_cast<size_t>(std::stoi(temp_rules.substr(temp_rules.size() - 1, 1)));
            }
            catch (std::invalid_argument&)
            {
                throw(std::invalid_argument("Not number"));
            }
            break;
        }
    }
    std::vector<Components> t_cells = file.get_cells();

    for (size_t i = 0; i != t_cells.size(); ++i)
    {
        if ((t_cells.at(i).x > get_x_size()) || (t_cells.at(i).y > get_y_size()))
        {
            throw(std::invalid_argument("Cell coordinate out of field size"));
        }
        field[t_cells[i].x][t_cells[i].y] = '#';
    }
}

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

