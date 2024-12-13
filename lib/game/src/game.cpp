#include "game.h"

#include <complex>

#include "fstream"

void Game::print_field()
{
    std::vector <std::string>& temp_field = field.get_field();
    for (size_t i = 0; i != field.get_x_size(); ++i)
    {
        for (size_t j  = 0; j != field.get_y_size(); ++j)
        {
            std::cout << temp_field[i][j] << " ";
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
    for (size_t i = 1; i != argc; i += 2)
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
    std::vector<std::string>& temp_field = field.get_field();
    if (file.is_open())
    {
        for (size_t i = 0; i != field.get_x_size(); ++i)
        {
            for (size_t j = 0; j != field.get_y_size(); ++j)
            {
                file << temp_field[i][j] << " ";
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
    std::map<std::string, int> command_map =
    {
        {"exit", 0},
        {"help", 1},
        {"start", 2}
    };
    std::string input;
    while (input != "start")
    {
        std::cout << "Enter 'start to start the game, enter 'help' to get information about commands or enter 'exit' to stop the game" << std::endl;
        std::cin >> input;
        switch (command_map[input])
        {
            case 0:
                return;
            case 1:
                std::cout << "Use dump<path> to save game in the file" << std::endl;
                std::cout << "Use tick<n> to set iterations";
                std::cout << "Use --i<n> to set iterations in offline mode and use --o to set output path in offline mode" << std::endl;
                std::cout << "Use input<path> to create game from the file" << std::endl;
            break;


        }
    }
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
