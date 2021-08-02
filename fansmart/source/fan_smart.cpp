#include <util/log.hpp>
#include <fan_smart.hpp>


FanSmart::FanSmart()
{
    setName("FanSmart");
}

FanSmart::~FanSmart()
{
}

bool FanSmart::load()
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

void FanSmart::execute()
{
    sensorTemperature.execute();

    eeSensorTemperatureDS18B20::Data temperatureData = sensorTemperature.getData();
    eeRelay::Data relayData = relay.getData();

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

    if (temperatureData.temperature >= temperatureMax.get())
    {
        if (relayData.output == eeRelay::NORMAL_OUTPUT::CLOSE)
        {
            openRelay();
        }
    }
    else
    {
        if (relayData.output == eeRelay::NORMAL_OUTPUT::OPEN)
        {
            closeRelay();
        }
    }
    ledRGB.execute();
}

void FanSmart::openRelay()
{
    eeRelay::Data relayData = relay.getData();

    relayData.output = eeRelay::NORMAL_OUTPUT::OPEN;
    relay.setData(relayData);
    ledRGB.setColor(
        ::ee::connector::pin::PIN_HIGH,
        ::ee::connector::pin::PIN_LOW,
        ::ee::connector::pin::PIN_LOW);
    relay.execute();
    LOG_COMP(eeTypeLog::INFO, "open relay", nullptr);
}

void FanSmart::closeRelay()
{
    eeRelay::Data relayData = relay.getData();

    relayData.output = eeRelay::NORMAL_OUTPUT::CLOSE;
    relay.setData(relayData);
    ledRGB.setColor(
        ::ee::connector::pin::PIN_LOW,
        ::ee::connector::pin::PIN_HIGH,
        ::ee::connector::pin::PIN_LOW);
    relay.execute();
    LOG_COMP(eeTypeLog::INFO, "close relay", nullptr);
}

void FanSmart::onNotifyQueue(
    std::size_t /*typeMessageQueue*/,
    eeMessageQueue* /*message*/)
{
}

void FanSmart::onStream(
    unsigned int /*port*/,
    const char* /*message*/)
{
}
