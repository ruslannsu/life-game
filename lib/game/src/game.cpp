#include "game.h"

#include <complex>

#include "fstream"

void Game::print_field()
{
    std::vector <std::string> t_field = field.get_field();
    for (size_t i = 0; i != field.get_x_size(); ++i)
    {
        for (size_t j  = 0; j != field.get_y_size(); ++j)
        {
            std::cout << t_field[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

Game::Game(int argc, char *argv[]): iterations(1), offline_mode(false), exit(false), help(false)
{
    std::map<std::string, int> command_map = {
        {"dump", 0},
        {"tick", 1},
        {"--i", 2},
        {"--o", 3},
        {"input", 4}
    };
    for (size_t i = 1; i != argc; i+=2)
    {
        //std::cout << command_map[argv[i]];
        switch (command_map[std::string(argv[i])])
        {
            case 0:
            {
                o_file_path = std::string(argv[i + 1]);
                break;
            }
            case 1:
                iterations = stoi(std::string(argv[i + 1]));
                break;

            case 2:
                iterations = stoi(std::string(argv[i + 1]));
                offline_mode = true;
                break;
            case 3:
                o_file_path = std::string(argv[i + 1]);
                offline_mode = true;
                break;
            case 4:
                i_file_path = std::string(argv[i + 1]);
                break;
            default:
                break;
        }
    }
    std::cout << o_file_path << std::endl;
    if (i_file_path.empty())
    {
        field = Field(File("../src/files/examples/pulsar.txt"));
    }
    else
    {
        field = Field(File(i_file_path));
    }
}


void Game::save_field()
{
    std::fstream file(o_file_path);
    std::vector<std::string> t_field = field.get_field();
    if (file.is_open())
    {
        for (size_t i = 0; i != field.get_x_size(); ++i)
        {
            for (size_t j = 0; j != field.get_y_size(); ++j)
            {
                file << t_field[i][j] << " ";
            }
            file << std::endl;
        }
    }
    else
    {
        throw(std::invalid_argument("Incorrect output file path"));
    }
}



void Game::start_game()
{
    if (offline_mode)
    {
        for (size_t i = 0; i != iterations; ++i)
        {
            field.create_next_gen();
        }
        save_field();
        return;
    }
    for (size_t i = 0; i != iterations; ++i)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(700));
        system("cls");
        field.create_next_gen();
        print_field();
    }
    if (!o_file_path.empty())
    {
        save_field();
    }
}
