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

void HomeStatus::execute()
{

}

void HomeStatus::onNotifyQueue(
    std::size_t typeMessageQueue,
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
    unsigned int /*port*/,
    const char* /*message*/)
{
}
