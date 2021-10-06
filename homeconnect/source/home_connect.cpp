#include <util/log.hpp>
#include <home_connect.hpp>


HomeConnect::HomeConnect() noexcept
{
    setName("HomeConnect");
}

HomeConnect::~HomeConnect() noexcept
{
}

bool HomeConnect::load()
{
    return true;
}

void HomeConnect::process()
{
}

void HomeConnect::onTimer()
{
    std::vector<Device> copyDevices = devices.get();
    for (Device& device : copyDevices)
    {
        LOG_COMP(eeTypeLog::INFO,
            "Asking send signal KEEP_ALIVE [%u][%s]",
            device.id,
            device.name.c_str()
        );
    }
}

void HomeConnect::onNotifyQueue(
    [[maybe_unused]] uint32_t typeMessageQueue,
    [[maybe_unused]] eeMessageQueue* message)
{
}

void HomeConnect::onStream(
    [[maybe_unused]] unsigned int port,
    [[maybe_unused]] const char* message)
{
}
