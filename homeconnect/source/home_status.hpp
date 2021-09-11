#pragma once

#include <vector>

#include <protected_data/protected_data.hpp>
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
    eeProtectedData<STATUS> status{STATUS::UNAVAILABLE};

public:
    DECLARE_COMPONENT(HomeStatus)
};
