#pragma once

#include <string>

#include <util/log.hpp>

class ConfigProject
{
public:
    ConfigProject();
    ~ConfigProject();

    bool load(const std::string& filename);
    bool load(const char* filename);
};
