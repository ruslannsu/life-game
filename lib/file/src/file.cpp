#include "file.h"
#include "fstream"


std::vector<Components> File::get_cells(){return cells;}

std::string File::get_rules(){return rules;}

Components File::get_field_size(){return field_size;}

static Components parse_components(std::string buffer)
{
    if (buffer.empty())
    {
        throw std::invalid_argument("No coordinates");
    }
    for (size_t i = 0; i != buffer.size(); ++i)
    {
        if (buffer.at(i) == ' ')
        {
            return {static_cast<size_t>(std::stoi(buffer.substr(0, i))),static_cast<size_t>(std::stoi(buffer.substr(i, buffer.size())))};
        }
    }
    throw std::invalid_argument("Incorrect cells coordinates");
}

File::File(std::string path)
{
    std::string buffer;
    std::ifstream file(path);
    size_t string_counter = 0;

    if (file.is_open())
    {
        std::cout << "file has opened" << std::endl;
        while(getline(file, buffer))
        {
            if (string_counter == 0)
            {
                version = buffer;
                ++string_counter;
                continue;
            }
            if (string_counter == 1)
            {

                field_size = parse_components(buffer);
                ++string_counter;
                continue;
            }
            if (string_counter == 2)
            {
                rules = buffer;
                ++string_counter;
                continue;
            }
            if (string_counter > 2)
            {
                cells.push_back(parse_components(buffer));
                ++string_counter;
            }
        }
    }
    else
    {
        throw std::invalid_argument("Incorrect path!");
    }


}





