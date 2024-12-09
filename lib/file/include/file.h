#pragma once
#include <iostream>
#include <vector>

struct Components
{
    size_t x;
    size_t y;
};


class File
{
public:
    File();
    File(std::string path);
    void scan_field_file();
    void parse_cells(std::string buffer);
    void parse_size(std::string buffer);
    void scan_rules(std::string buffer);
    void scan_version(std::string buffer);
    void scan_field_size(std::string buffer);
    void write_field_to_file();

public:
    std::vector<Components> cells;
    std::string rules;
    std::string version;
    Components field_size;

};


