# Smart Relay
Le principe étant d'activer un relai en fonction de différent paramètres.<br>
Le relaie permet d'alimenter un componsant placé après le relaie si les conditions sont réunis.<br>

## Matériels
| Materiel               | Description                   |
| :--------------------- | :---------------------------- |
| Raspberry Pico         | Raspberry Pi Pico             |
| Capteur de température | DS18B20 Temperature Sensor v2 |
| 1 Relaie 230v          | TONGLING                      |
| 1 Led RGB              | LED RGB                       |
| 1 antenne Wifi         | XXX                           |

## Principe
Le projet `SmartRelay` consiste à prendre des mesures a intervalle régulier puis en déterminé si le relai doit être ouvert ou fermé.<br>
Le relai peut s'ouvrir ou se fermer celons les critrères suivants :
* La température
* Commande interne

Les données :
* La donné indiquant la température n'est pas configurable elle est indiqué en dure dans le code source.
* La donné indiquant si l'on doit surveiller si la température doit être plus grande ou plus petit n'est pas configurable elle est indiqué en dure dans le code source.
* La commande n'est pas configurable elle est indiqué en dure dans le code source.

La led RGB indique l'état des conditions :
* Vert aucune conditions n'est réuni, le relaie reste ouvert.
* Route toutes les conditions sont réunis, le relai est fermé.

<br>
Aucune transformation du courant doit être fait entre la source 220V et la sortie du relaie.<br>
Le sortie du relaie permet d'alimenter un composant externe.<br>
<br>

Tout le projet sera placé dans un boitier de protection :
* Le boiter contient les éléments présent dans **Matériels**.
* Le boitier a un cable d'alimentation pouvant être branché sur du 220V.
* Le boitier a une sortie permettant d'alimenté un équipement en 220V.
* La carte Raspberry PICO est branché sur l'entré 220V et a son propre transformater

## Remarques
Il est à la charge de l'utilisateur de faire la transformation électrique si nécessaire en sortie du boitier.<br>
Le boitier ne fait qu'ouvrir ou fermer un courrant direct sur le 220V.<br>

## Installation

### Raspberry PI
Déplacer le fichier `script/S99EmbeddedModule_Smartrelay` dans `/etc/init.d/S99EmbeddedModule_Smartrelay`.<br>
Ajouter les droits d'éxecution au script `S99EmbeddedModule_Smartrelay`.<br>
```sh
sudo script/S99EmbeddedModule /etc/init.d/
sudo chmod +x /etc/init.d/S99EmbeddedModule
```

Il faut indiquer à au système que le script `S99EmbeddedModule_Smartrelay` est un script d'initialisation :
```sh
cd /etc/init.d/
sudo update-rc.d -f "S99EmbeddedModule_Smartrelay" defaults
```

La bibliothèque `libEmbeddedEngine.so` doit être installé sur le système !<br>
Si le fichier `/etc/ld.so.conf.d/embedded_engine.conf` n'est pas déjà existant ajouter le.<br>
```
# Library Embedded Engine
/usr/local/lib/embedded_engine
```

### Raspberry PICO
