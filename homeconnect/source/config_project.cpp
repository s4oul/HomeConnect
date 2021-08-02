#include <config_project.hpp>


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

    return true;
}
