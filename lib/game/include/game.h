#include "file.h"
#include "field.h"
#include <chrono>
#include <thread>
#include <map>



class Game
{

public:
    Game();
    Game(int argc, char *argv[]);
    void print_field();
    void start_dialogue();
    void start_game();
    void save_field();
private:
    Field field;
    std::string i_file_path;
    std::string o_file_path;
    bool help;
    bool exit;
    bool offline_mode;
    size_t iterations;
};