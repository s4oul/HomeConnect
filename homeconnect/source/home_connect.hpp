#pragma once

#include <vector>

#include <concurrency/protected_data.hpp>
#include <component/icomponent.hpp>
#include <device.hpp>

class HomeConnect : public eeIComponent
{
private:
    eeProtectedData<std::vector<Device>> devices;

public:
    DECLARE_COMPONENT(HomeConnect)
};
