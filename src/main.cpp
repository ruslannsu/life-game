#include <iostream>
#include "field.h"
#include "file.h"
#include <stdlib.h>
#include <thread>
#include <chrono>



int main()
{

    Field f(File("../src/files/input/input.txt"));
    std::cout << f.cells_to_survive.right << std::endl;

}
