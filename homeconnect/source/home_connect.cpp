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

void HomeConnect::execute()
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
    std::size_t /*typeMessageQueue*/,
    eeMessageQueue* /*message*/)
{
}

void HomeConnect::onStream(
    unsigned int /*port*/,
    const char* /*message*/)
{
}
