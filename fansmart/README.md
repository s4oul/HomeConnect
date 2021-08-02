# FanSmart
Le principe étant d'activer un relaie en fonction de la température.<br>
Le relaie permet d'alimenter un componsant placé après le relaie si la température est suprérieure
ou inférieure à la demande initiale.<br>

## Matériels
* Circuit imprimé
* Carte                  : ***Raspberry Pi Pico***
* Capteur de température : ***DS18B20 Temperature Sensor v2***
* 1 Relaie               : ***TONGLING***
* 1 Led rgb              : ***LED RGB***

## Principe
Le projet `FanSmart` consiste à prendre une mesure de la température toutes les X secondes
et en déterminé si le relaie doit être ouvert ou fermé.<br>
Aucune transformation du courant doit être fait entre la source 200V et la sortie du relaie.<br>
Le sortie du relaie permet d'alimenter un composant externe.<br>
<br>
Tout le projet sera placé dans un boitier de protection.
Le boiter contient les éléments présent dans **Matériels**.
Le boitier a un cable d'alimentation pouvant être branché sur du 220V.
Le boitier a une sortie permettant de l'alimenté un équipement en 220V.

## Remarques
Il est à la charge de l'utilisateur de faire la transformation électrique si nécessaire en sortie du boitier.<br>
Le boitier ne fait qu'ouvrir ou fermer un courrant direct sur le 220V.<br>

## Architecture Développement
Le projet n'a aucune contraite de Temps réel.<br>
Aucune connexion, ni synchronisation avec d'autres appareils.<br>
Environnement fermé.<br>
Aucune remonté de logs.<br>
Les mise à jours se sont via un nouveau frirmware.<br>

## Installation

### Raspberry PI
Déplace le fichier `script/S99EmbeddedModule` dans `/etc/init.d/S99EmbeddedModule`.<br>

Mettre à jour :
```sh
cd /etc/init.d/
sudo update-rc.d S99EmbeddedModule
```

Ajouter dans `/etc/ld.so.conf.d/embedded_engine.conf` :
```
# Library Embedded Engine
/usr/local/lib/embedded_engine
```
