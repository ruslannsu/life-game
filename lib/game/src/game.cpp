#include "game.h"

void Game::print_field()
{
    std::vector <std::string> t_field = field.get_field();
    for (size_t i = 0; i != field.x_size; ++i)
    {
        std::cout << t_field.at(i) << std::endl;
    }
}

Game::Game(int argc, char *argv[]): iterations(1), offline_mode(false), exit(false), help(false)
{
    std::map<std::string, int> command_map = {
        {"dump ", 0},
        {"tick ", 1},
        {"exit", 2},
        {"help", 3},
        {"--iterations=", 4},
        {"--output=", 5},
        {"--input=", 6}

    };

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
    if (i_file_path.empty())
    {
        //
    }
    field = Field(File(i_file_path));
}

void Game::start_game()
{

    if (offline_mode)
    {
        File output(o_file_path);


    }
    for (size_t i = 0; i != iterations; ++i)
    {
        system("cls");
        field.create_next_gen();
        print_field();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

}
