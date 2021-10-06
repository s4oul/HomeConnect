#include <util/log.hpp>
#include <smart_relay.hpp>


SmartRelay::SmartRelay() noexcept
{
    setName("SmartRelay");
}

SmartRelay::~SmartRelay() noexcept
{
}

bool SmartRelay::load()
{
    ledRGB.setPin(
        ::ee::connector::gpio::WPI_GPIO_17,
        ::ee::connector::gpio::WPI_GPIO_27,
        ::ee::connector::gpio::WPI_GPIO_22
    );
    ledRGB.setColor(
        ::ee::connector::pin::PIN_LOW,
        ::ee::connector::pin::PIN_LOW,
        ::ee::connector::pin::PIN_HIGH
    );
    sensorTemperature.setPin(::ee::connector::gpio::WPI_GPIO_21);
    relay.setPin(::ee::connector::gpio::WPI_GPIO_20);

    closeRelay();
    return true;
}

void SmartRelay::process()
{
}

void SmartRelay::onTimer()
{
    bool needOpen  {false};
    bool needClose {false};

    if (true == checkTemparature)
    {
        sensorTemperature.execute();

        auto temperatureData {sensorTemperature.getData()};
        auto relayData       {relay.getData()};

        LOG_COMP(eeTypeLog::INFO,
            "Sensor Temp (%f) ~ Temp max (%f)",
            temperatureData.temperature,
            temperatureMax.get());

        if (temperatureData.temperature >= 99.f)
        {
            LOG_COMP(eeTypeLog::WARNING,
                "Skip the temperature (%f) is not possible",
                temperatureData.temperature);
                return;
        }

        bool condition
        {
            (true == checkTemperatureGreater)
            ?
            (temperatureData.temperature >= temperatureMax.get())
            :
            (temperatureData.temperature <= temperatureMax.get())
        };

        if (true == condition)
        {
            if (eeRelay::NORMAL_OUTPUT::CLOSE == relayData.output)
            {
                needOpen = true;
            }
        }
        else
        {
            if (eeRelay::NORMAL_OUTPUT::OPEN == relayData.output)
            {
                needClose = true;
            }
        }
    }

    if (true == needOpen)
    {
        openRelay();
        ledRGB.execute();
    }
    else
    {
        closeRelay();
        ledRGB.execute();
    }
}

void SmartRelay::openRelay()
{
    auto relayData{relay.getData()};

    relayData.output = eeRelay::NORMAL_OUTPUT::OPEN;
    relay.setData(relayData);
    ledRGB.setColor(
        ::ee::connector::pin::PIN_HIGH,
        ::ee::connector::pin::PIN_LOW,
        ::ee::connector::pin::PIN_LOW);
    relay.execute();

    LOG_COMP(eeTypeLog::INFO, "open relay", nullptr);
}

void SmartRelay::closeRelay()
{
    auto relayData{relay.getData()};

    relayData.output = eeRelay::NORMAL_OUTPUT::CLOSE;
    relay.setData(relayData);
    ledRGB.setColor(
        ::ee::connector::pin::PIN_LOW,
        ::ee::connector::pin::PIN_HIGH,
        ::ee::connector::pin::PIN_LOW);
    relay.execute();

    LOG_COMP(eeTypeLog::INFO, "close relay", nullptr);
}

void SmartRelay::onNotifyQueue(
    [[maybe_unused]] uint32_t typeMessageQueue,
    [[maybe_unused]] eeMessageQueue* message)
{
    if (false == checkCommand)
    {
        return;
    }
}

void SmartRelay::onStream(
    [[maybe_unused]]  unsigned int port,
    [[maybe_unused]] const char* message)
{
}

void SmartRelay::activeCheckTemperature()
{
    checkTemparature = true;
}

void SmartRelay::activeCheckCommand()
{
    checkCommand = true;
}

void SmartRelay::activeCheckOnGreater()
{
    checkTemperatureGreater = true;
}

void SmartRelay::activeCheckOnLower()
{
    checkTemperatureGreater = false;
}
