#include <engine/engine.hpp>
#include <connector/network/tcp.hpp>
#include <home_connect.hpp>

int main()
{
    eeEngine engine;
    eeTcp serverTCP;
    HomeConnect homeConnect;

    // Set env
    engine.setEnvironment(true, "/home/pi/logs/");
    LOG(eeTypeLog::INFO, "Starting HomeConnect !", nullptr);


    // Ajout des composants.
    if (engine.addComponent(&homeConnect) == false) return 1;

    // Initialise les connector
    if (engine.initializeClock() == false) return 1;
    if (engine.initializeGpio() == false) return 1;
    if (engine.initializeServerTcp(uint32_t(8001)) == false) return 1;

    // Chargement de l'ensemble des composants.
    if (engine.loadAllComponent() == false) return 1;

    // Chargement de l'ensemble des connecteurs
    if (engine.haveConnector() == false) return 1;

    // Ajout d'evenemt sur le temps
    if (engine.addInClock(&homeConnect, std::chrono::seconds(1)) == false) return 1;

    // Ajout des composants sur le server TCP
    if (engine.addInServerTcp(&homeConnect) == false) return 1;

    // Lancement des taches
    engine.initTaskClock(true);
    engine.initTaskServerTCP(true);

    // Lance l'application
    engine.run();

    return 0;
}
