#include <iostream>
#include "field.h"
#include "file.h"
#include <stdlib.h>
#include <thread>
#include <chrono>



int main()
{
    /*
    File f("../src/files/input/input.txt");
    std::cout << f.version << std::endl;
    std::cout << f.field_size.x << "---" <<f.field_size.y << std::endl;
    std::cout << f.rules<< std::endl;


    for (size_t i = 0; i != f.cells.size(); ++i)
    {
        std::cout << f.cells.at(i).x << "---" << f.cells.at(i).y << std::endl;
    }
    int f1 = 1;
    int f2 = 2;
    std::cout << (-1) % 3;
    */
    Field f(10, 10);









    int j=0;
    while(true)
    {
        system("cls");
        for (size_t i = 0; i != f.x_size; ++i)
        {
            std::cout << f.field[i] << std::endl;
        }
        f.create_next_gen();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}
