#include <engine/engine.hpp>
#include <fan_smart.hpp>

int main()
{
    eeEngine engine;
    FanSmart fanSmart;

    // Set l'environnement d'execution.
    engine.setEnvironment(false, "/home/pi/logs/");
    LOG(eeTypeLog::INFO, "Starting FanSmart !", nullptr);

    // Ajout des composants.
    if (engine.addComponent(&fanSmart) == false) return 1;

    // Initialise les connector
    if (engine.initializeClock() == false) return 1;
    if (engine.initializeGpio() == false) return 1;

    // Chargement de l'ensemble des composants.
    if (engine.loadAllComponent() == false) return 1;

    if (engine.haveConnector() == false) return 1;

    if (engine.addInClock(&fanSmart, std::chrono::seconds(1)) == false) return 1;

    // Lancement des taches
    engine.initTaskClock(true);

    // Run l'application
    engine.run();

    return 0;
}