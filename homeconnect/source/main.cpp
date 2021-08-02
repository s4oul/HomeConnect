#include <engine/engine.hpp>
#include <connector/network/tcp.hpp>
#include <util/breaker.hpp>

#include <home_connect.hpp>
#include <config_project.hpp>


constexpr char welcome[] = "Starting HomeConnect !";
constexpr char pathLog[] = "/home/pi/logs/";
constexpr char configfile[] = "home_connect.ini";
constexpr uint32_t serverPort = 8001;


int main()
{
    eeEngine engine;
    eeTcp serverTCP;
    HomeConnect homeConnect;

    // Set env
    engine.setEnvironment(true, pathLog);
    LOG(eeTypeLog::INFO, welcome, nullptr);

    // Fichier de configuration du projet.
    ConfigProject config;
    config.load(configfile);

    // Ajout des composants.
    ifnot(engine.addComponent(&homeConnect), true);

    // Initialise les connector
    ifnot(engine.initializeClock(), true);
    ifnot(engine.initializeGpio(), true);
    ifnot(engine.initializeServerTcp(serverPort), true);

    // Chargement de l'ensemble des composants.
    ifnot(engine.loadAllComponent(), true);

    // Chargement de l'ensemble des connecteurs
    ifnot(engine.haveConnector(), true);

    // Ajout d'evenemt sur le temps
    ifnot(engine.addInClock(&homeConnect, std::chrono::seconds(1)), true);

    // Ajout des composants sur le server TCP
    ifnot(engine.addInServerTcp(&homeConnect), true);

    // Lancement des taches
    engine.initTaskClock(true);
    engine.initTaskServerTCP(true);

    // Lance l'application
    engine.run();

    return 0;
}
