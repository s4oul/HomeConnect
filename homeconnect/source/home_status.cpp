#include <util/log.hpp>
#include <home_status.hpp>


HomeStatus::HomeStatus() noexcept
{
    setName("HomeStatus");
}

HomeStatus::~HomeStatus() noexcept
{
}

bool HomeStatus::load()
{
    status.set(STATUS::AVAILABLE);
    return true;
}

void HomeStatus::process()
{
}

void HomeStatus::onTimer()
{
}

void HomeStatus::onNotifyQueue(
    uint32_t typeMessageQueue,
    eeMessageQueue* message)
{
    if (message == nullptr)
    {
        LOG(eeTypeLog::ERROR,
            "Receive a message null with type [%u]!",
            typeMessageQueue);
        return;
    }

    switch (typeMessageQueue)
    {
    default:
        LOG(eeTypeLog::WARNING,
            "Receive type message unknow [%u]",
            typeMessageQueue);
        break;
    }
}

void HomeStatus::onStream(
    [[maybe_unused]] unsigned int port,
    [[maybe_unused]] const char* message)
{
}
