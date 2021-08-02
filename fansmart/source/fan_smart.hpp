#pragma once

#include <atomic/data_atomic.hpp>
#include <component/icomponent.hpp>
#include <connector/board/gpio.hpp>
#include <module/sensor_temperature_ds18b20.hpp>
#include <module/relay.hpp>
#include <module/led_rgb.hpp>

class FanSmart : public eeIComponent
{
private:
    eeRelay relay;
    eeLedRGB ledRGB;
    eeSensorTemperatureDS18B20 sensorTemperature;
    eeDataAtomic<float> temperatureMax = 25.0f;
    
    /// Permet d'ouvrir le relay, on passe sur NO.
    void openRelay();

    /// Permet de fermer le relay, on passe sur NC.
    void closeRelay();

public:
    DECLARE_COMPONENT(FanSmart)
};
