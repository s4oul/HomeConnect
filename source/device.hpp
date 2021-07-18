#pragma once

#include <cstdint>
#include <string>

#include <util/log.hpp>


struct Device
{
    uint8_t id = 0;
    std::string name;
    uint32_t port = 0;

    Device(uint8_t _id, std::string _name, uint32_t _port):
        id(_id),
        name(_name),
        port(_port)
    {
    }

    Device(const Device& device):
        id(device.id),
        name(device.name),
        port(device.port)
    {
    }

};
