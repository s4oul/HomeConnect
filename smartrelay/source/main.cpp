#include <engine/engine.hpp>
#include <smart_relay.hpp>

int main()
{
    eeEngine engine;
    SmartRelay smartrelay;

    // Set l'environnement d'execution.
    engine.setEnvironment(false, "/home/pi/logs/");
    LOG(eeTypeLog::INFO, "Starting SmartRelay !", nullptr);

    // Ajout des composants.
    if (engine.addComponent(&smartrelay) == false) return 1;

    // Initialise les connector
    if (engine.initializeClock() == false) return 1;
    if (engine.initializeGpio() == false) return 1;

    // Chargement de l'ensemble des composants.
    if (engine.loadAllComponent() == false) return 1;

    if (engine.haveConnector() == false) return 1;

    if (engine.addInClock(&smartrelay, std::chrono::seconds(1)) == false) return 1;

    // Lancement des taches
    engine.initTaskClock(true);

    // Run l'application
    engine.run();

    return 0;
}