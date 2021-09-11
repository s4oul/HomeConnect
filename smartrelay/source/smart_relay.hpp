#pragma once

#include <protected_data/protected_data.hpp>
#include <component/icomponent.hpp>
#include <connector/board/gpio.hpp>
#include <module/sensor_temperature_ds18b20.hpp>
#include <module/relay.hpp>
#include <module/led_rgb.hpp>

class SmartRelay : public eeIComponent
{
private:
    eeRelay relay;
    eeLedRGB ledRGB;
    eeSensorTemperatureDS18B20 sensorTemperature;
    eeProtectedData<float> temperatureMax = 25.0f;
    
    /// Permet d'ouvrir le relay, on passe sur NO.
    void openRelay();

    /// Permet de fermer le relay, on passe sur NC.
    void closeRelay();

public:
    DECLARE_COMPONENT(SmartRelay)
};
