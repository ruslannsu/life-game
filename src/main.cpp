#include <iostream>
#include "field.h"
#include "file.h"
#include <thread>
#include <chrono>
#include <game.h>


int main(int argc, char *argv[])
{
    Game game = Game(argc, argv);
    game.start_game();
}
