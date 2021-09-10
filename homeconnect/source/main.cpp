#include <connector/network/tcp_server.hpp>
#include <engine/engine.hpp>
#include <util/breaker.hpp>

#include <home_connect.hpp>
#include <home_status.hpp>
#include <config_project.hpp>


constexpr char welcome[] = "Starting HomeConnect !";
constexpr char pathLog[] = "/home/pi/logs/";
constexpr char configfile[] = "home_connect.ini";
constexpr uint32_t serverPort = 8001;


int main()
{
    eeEngine engine;
    eeTcpServer server;
    HomeConnect homeConnect;
    HomeStatus homeStatus;

    // Met a jour l'environnement.
    engine.setEnvironment(true, pathLog);
    LOG(eeTypeLog::INFO, welcome, nullptr);

    // Fichier de configuration du projet.
    // ConfigProject config;
    // ifnot(config.load(configfile), true);

    // Ajout des composants.
    returnifnot(engine.addComponent(&homeConnect), true, 1);
    returnifnot(engine.addComponent(&homeStatus), true, 1);

    // Initialise les connector
    returnifnot(engine.initializeClock(), true, 1);
    returnifnot(engine.initializeGpio(), true, 1);

    returnifnot(engine.addServerTcp(uint32_t{8082}), true, 1);

    // Chargement de l'ensemble des composants.
    returnifnot(engine.loadAllComponent(), true, 1);

    // Chargement de l'ensemble des connecteurs
    returnifnot(engine.haveConnector(), true, 1);

    // Ajout d'evenemt sur le temps
    returnifnot(engine.addInClock(&homeConnect, std::chrono::seconds(1)), true, 1);
    returnifnot(engine.addInClock(&homeStatus, std::chrono::seconds(1)), true, 1);

    // Lancement des taches
    engine.initTaskClock(true);

    // Lance l'application
    engine.run();

    return 0;
}
