#pragma once

#include <vector>

#include <atomic/data_atomic.hpp>
#include <component/icomponent.hpp>
#include <device.hpp>

class HomeConnect : public eeIComponent
{
private:
    eeDataAtomic<std::vector<Device>> devices;

public:
    DECLARE_COMPONENT(HomeConnect)
};
