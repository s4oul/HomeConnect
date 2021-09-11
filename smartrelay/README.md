# Smart Relay
Le principe étant d'activer un relaie en fonction de la température.<br>
Le relaie permet d'alimenter un componsant placé après le relaie si la température est suprérieure
ou inférieure à la demande initiale.<br>

## Matériels
| Materiel               | Description                   |
| :--------------------- | :---------------------------- |
| Raspberry Pico         | Raspberry Pi Pico             |
| Capteur de température | DS18B20 Temperature Sensor v2 |
| 1 Relaie 230v          | TONGLING                      |
| 1 Led RGB              | LED RGB                       |

## Principe
Le projet `SmartRelay` consiste à prendre une mesure de la température toutes les X secondes
et en déterminé si le relaie doit être ouvert ou fermé.<br>
<br>
La donné indiquant la température n'est pas configurable elle est indiqué en dure dans le code source.<br>
La donné indiquant si l'on doit surveiller si la température doit être plus grande ou plus petit n'est pas configurable elle est indiqué en dure dans le code source.<br>
<br>
Aucune transformation du courant doit être fait entre la source 220V et la sortie du relaie.<br>
Le sortie du relaie permet d'alimenter un composant externe.<br>
<br>
Tout le projet sera placé dans un boitier de protection.<br>
Le boiter contient les éléments présent dans **Matériels**.<br>
Le boitier a un cable d'alimentation pouvant être branché sur du 220V.<br>
Le boitier a une sortie permettant d'alimenté un équipement en 220V.<br>

## Remarques
Il est à la charge de l'utilisateur de faire la transformation électrique si nécessaire en sortie du boitier.<br>
Le boitier ne fait qu'ouvrir ou fermer un courrant direct sur le 220V.<br>

## Installation

### Raspberry PI
Déplacer le fichier `script/S99EmbeddedModule` dans `/etc/init.d/S99EmbeddedModule`.<br>
Ajouter les droits d'éxecution au script `S99EmbeddedModule`.<br>
```sh
sudo script/S99EmbeddedModule /etc/init.d/
sudo chmod +x /etc/init.d/S99EmbeddedModule
```

Il faut indiquer à au système que le script `S99EmbeddedModule` est un script d'initialisation :
```sh
cd /etc/init.d/
sudo update-rc.d S99EmbeddedModule
```

La bibliothèque `libEmbeddedEngine.so` doit être installé sur le système !<br>
Si le fichier `/etc/ld.so.conf.d/embedded_engine.conf` n'est pas déjà existant ajouter le.<br>
```
# Library Embedded Engine
/usr/local/lib/embedded_engine
```
