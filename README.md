# WorldCup
## Introduction
Ce repository est l'hébergement d'un projet effectué par Alexia Prevot et Bastien Guillemare.

## Objectifs
Le but de ce projet est de créer un programme en C++ suivant le thème suivant : la coupe du monde. Il doit aussi répondre à certaines contraintes comme par exemple doit contenir au moins 8 classes.

## Organisation des dossiers

Le dossier assets contient les resssources : images, questions et la police d'écriture pour la fenêtre

## Installation et lancement

L'application utilise les librairie SMFL et GNU, disponibles ici :
https://www.sfml-dev.org/
https://www.gnu.org/


Dans un terminal Linux :  
```
git clone .....
```
### compiler et lancer le projet
```
make 

./projet
```
### compiler et lancer les tests unitaires
```
make testcase

./testcase
```
ou 

```
make checkout
```

## Dépendances

La bibliothèque suivante est nécessaire au fonctionnement du programme :
* gtkmm (pour créer des interfaces graphiques en programmant en C++ avec la programmation orientée objet). Son installation se fait sur linux avec la commande : 
```
sudo apt-get install libgtkmm-4.0-dev
```


