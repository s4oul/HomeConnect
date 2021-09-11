#pragma once

#include <vector>

#include <protected_data/protected_data.hpp>
#include <component/icomponent.hpp>
#include <device.hpp>

class HomeConnect : public eeIComponent
{
private:
    eeProtectedData<std::vector<Device>> devices;

public:
    DECLARE_COMPONENT(HomeConnect)
};
