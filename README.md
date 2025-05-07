# PIE ENSTA 2024/2025
## Conception d'un drone de cartographie sous-marine


### I - Présentation
Dans le cadre de notre deuxième année à l'ENSTA, nous avons la charge d'un **Projet d'ingénieur en équipe (PIE)** dont le sujet est la conception d'un drone de cartographie sous-marine, avec pour objectif la cartographie du lac de l'école Polytechnique attenant à l'école. 

Ce dépôt contient les programmes informatiques utilisés lors du projet :

- **Arduino :** Programmes de comportement du sous-marin, déplacement, acquisition et stockage des données

- **Matlab :** Programmes permettant de générer automatiquement le chemin à suivre par le sous-marin à partir d'un ensemble de points définis par l'utilisateur ; programmes de traitement des données à partir des données brutes extraites du sous-marin (affichage de la cartographie des zones déjà effectuées).


### II - Contenu des programmes
- **Arduino :** Deux programmes ont été écrits : le premier s'appelle `test_moteur.ino` et se trouve dans le dossier du même nom. Ce programme est fonctionnel mais mal écrit/optimisé. Un deuxième programme appelé `depl_sous_marin.ino` déclare des fonctions dans un fichier `fonctions.h` et les implémente dans le fichier `fonctions.c`. Elles sont ensuite appelées dans le programme pour le calibrage et le contrôle des moteurs. Pour une raison inconnue qui sera certainement résolue l'année prochaine, ce code ne fonctionne pas. 

- **Matlab :** Le programme se lance depuis le fichier `main.m`, en choisissant les paramètres voulus (points délimitant le domaine, direction de balayage...). La fonction `genere_chemin.m` calcule les coordonnées des points à suivre par le sous-marin pour effectuer le balayage en zig-zag du domaine, en utilisant les deux fonctions `genere_chemin_hb.m` et `genere_chemin_gd.m`. Les coordonnées sont ensuite enregistrées grâce à la fonction `sauve_points.m` dans un fichier `.txt` qu'on pourra directement mettre avec les codes Arduino quand ceux-ci seront adaptés. 