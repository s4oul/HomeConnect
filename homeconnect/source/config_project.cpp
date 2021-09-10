#include <filesystem>
#include <fstream>

#include <config_project.hpp>
#include <util/log.hpp>
#include <string/string_util.hpp>


ConfigProject::ConfigProject()
{

}

ConfigProject::~ConfigProject()
{
}


bool ConfigProject::load(const std::string& filename)
{
    if (filename.empty())
    {
        LOG(eeTypeLog::ERROR, "Can not load an empty file", nullptr);
        return false;
    }

    return load(filename.c_str());
}

bool ConfigProject::load(const char* filename)
{
    if (filename == nullptr)
    {
        LOG(eeTypeLog::ERROR, "filename is nullptr", nullptr);
        return false;
    }

    if (std::filesystem::exists(filename) == false)
    {
        LOG(eeTypeLog::ERROR, "The file [%s] does not exists", filename);
        return false;
    }

    std::ifstream in;
    in.open(filename, std::ifstream::in);
    if (in.is_open() == false)
    {
        LOG(eeTypeLog::ERROR, "Can not open file [%s]", filename);
        return false;
    }

    std::string line;
    while (std::getline(in, line))
    {
        std::vector<std::string> args = ee::string::string_split(line, "=");
        if (args.size() != 2)
        {
            LOG(eeTypeLog::WARNING, "Line invalid [%s]", line.c_str());
            continue;
        }

        LOG(eeTypeLog::INFO, "line [%s] = [%s]",
            args.at(0).c_str(), args.at(1).c_str());
    }

    in.close();

    return true;
}
