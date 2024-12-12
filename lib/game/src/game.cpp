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
        //std::cout << t_field.at(i) << std::endl;
    }
}

Game::Game(int argc, char *argv[]): iterations(1), offline_mode(false), exit(false), help(false)
{
    std::map<std::string, int> command_map = {
        {"dump", 0},
        {"tick", 1},
        {"exit", 2},
        {"help", 3},
        {"--iterations=", 4},
        {"--output=", 5},
        {"input", 6}

    };
    for (size_t i = 1; i != argc - 1; ++i)
    {
        std::cout << command_map[argv[i]];
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
                exit = true;
                break;
            case 3:
                help = true;
                break;
            case 4:
                iterations = stoi(std::string(argv[i + 1]));
                offline_mode = true;
                break;
            case 5:
                o_file_path = std::string(argv[i + 1]);
                offline_mode = true;
                break;
            case 6:
                i_file_path = std::string(argv[i + 1]);
                break;
            default:
                break;
        }
    }
    /*
    for (size_t i = 1; i != argc; ++i)
    {
        std::string arg = std::string(argv[i]);
        if ((std::string("dump") == std::string(arg)))
        {
            o_file_path = std::string(argv[i + 1]);
        }
        if (std::string("tick") == std::string(arg))
        {
            iterations = stoi(std::string(argv[i + 1]));
        }
        if (std::string("exit") == std::string(arg))
        {
            exit = true;
        }
        if (std::string("help") == std::string(arg))
        {
            help = true;
        }
        if (std::string("-i") == arg)
        {
            iterations = stoi(std::string(argv[i + 1]));
            offline_mode = true;
        }
        if (std::string("-o") == arg)
        {
            o_file_path = std::string(argv[i + 1]);
            offline_mode = true;
        }
        if (std::string("input") == arg)
        {
            i_file_path = std::string(argv[i + 1]);
        }
    }
    */
    if (i_file_path.empty())
    {
        //
    }
    field = Field(File(i_file_path));

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
}



void Game::start_game()
{

    if (offline_mode)
    {
        File output(o_file_path);

    }
    for (size_t i = 0; i != iterations; ++i)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(700));
        system("cls");
        field.create_next_gen();
        print_field();
        //std::this_thread::sleep_for(std::chrono::milliseconds(400));
    }
    if (!o_file_path.empty())
    {
        save_field();
    }

}
