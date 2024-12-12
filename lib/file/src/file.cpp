#include "file.h"
#include "fstream"




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

                parse_size(buffer);
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
                parse_cells(buffer);
                ++string_counter;
            }
        }
    }
    else
    {
        throw std::invalid_argument("Incorrect path!");
    }


}
std::vector<Components> File::get_cells(){return cells;}
std::string File::get_rules(){return rules;}
Components File::get_field_size(){return field_size;}


void File::parse_cells(std::string buffer)
{
    for (size_t i = 0; i != buffer.size(); ++i)
    {
        if (buffer.at(i) == ' ')
        {
            this->cells.push_back({static_cast<size_t>(std::stoi(buffer.substr(0, i))),static_cast<size_t>(std::stoi(buffer.substr(i, buffer.size())))});
            break;
        }
    }
}
void File::parse_size(std::string buffer)
{
    for (size_t i = 0; i != buffer.size(); ++i)
    {
        if (buffer.at(i) == ' ')
        {
            this->field_size = {static_cast<size_t>(std::stoi(buffer.substr(0, i))),static_cast<size_t>(std::stoi(buffer.substr(i, buffer.size())))};
            break;
        }
    }
}


