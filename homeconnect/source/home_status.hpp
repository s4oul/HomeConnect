#pragma once

#include <vector>

#include <atomic/data_atomic.hpp>
#include <component/icomponent.hpp>
#include <device.hpp>

class HomeStatus : public eeIComponent
{
public:
    enum STATUS : uint8_t
    {
        AVAILABLE,
        UNAVAILABLE,
        UNSTABLE
    };

private:
    eeDataAtomic<STATUS> status{STATUS::UNAVAILABLE};

public:
    DECLARE_COMPONENT(HomeStatus)
};
