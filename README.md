# LastShelter : projet de LIFAP4 2019-2020

---


## Table des matières

- [À propos](#à-propos)
- [Dépendances requises](#dépendances-requises)
- [Compilation et exécution](#compilation-et-exécution)
- [Les commandes](#les-commandes)
- [Astuces](#astuces)
- [Les prix](#les-prix)
- [Contenu de l'archive](#contenu-de-l'archive)
- [Étudiants](#étudiants)


## À propos

**LastShelter** est un jeu inspiré de [Fall out shelter](https://fr.wikipedia.org/wiki/Fallout_Shelter) reprenant en partie son fonctionnement. 
C'est un jeu post apocalyptique de **gestion à plusieurs échelles**, centré sur la survie d’un groupe de réfugiés. Pour leur survie, il faut que le bâtisseur (le joueur) **organise leur refuge, gère l’arrivée des nouveaux réfugiés et vieille à garder les differentes jauges remplit (électricité, eau, nourriture, bonheur)**.

Afin de satisfaire les besoins des survivants, le bâtisseur doit **détruire/construire des salles** et **attribuer à ces dernières de la main-d’œuvre** (Exemple : pour nourrir les survivants, il faut construire un réfectoire et y ajouter des joueurs), attention chaque **personnage a des caractéristiques qui concordent plus ou moins avec une salle en particulier** (par exemple si le joueur est intelligent il serait pertinent de le faire travailler dans la salle des réacteurs, à l'inverse si un joueur est très fort il ne serait pas très malin de le faire travailler dans le salon).

De plus, **le nombre de d’habitant est limité au nombre de places dans le dortoir**, il n’y aura donc pas toujours de la place pour tout le monde, pour remédier à ceci, vous pouvez envoyer des personnages en **expédition suicide**, ils reviendront peut-être plus tard dans le jeu avec **aux choix de la ferraille ou bien des stuffs à ajouter dans votre sac à dos (pas disponible pour l'instant car pas d'invasion)**.


## Dépendances requises

- Système d'exploitation: **Linux** (makefile).
- Libraire graphique pour l'**affichage**: [SDL2](https://www.libsdl.org/download-2.0.php)
- Libraire graphique pour l'**audio**: [irrKlang](https://www.ambiera.com/irrklang/)


## Compilation et exécution

Dans le dossier `LastShelter`, il faut ouvrir un terminal est exéctuer la commande `make` (compilation).
Puis il suffit d'executer la commande `bin/progT` pour lancer le jeu (exécution).


## Les commandes

Pour **ajouter** une salle à votre abris:
- verifiez que vous avez de la ferraille ⚙️
- cliquez sur un emplacement où des travaux sont possible 🚧
- choisissez la type de salle que vous souhaitez construire dans le menu à gauche.

Pour **agrandir/détruire** une salle:
- sélectionnez cette dernière
- cliquez sur travaux
- vérifiez que l'action est possible:
    - 🔴 = pas réalisable (la salle est entourée d'autres salles et/ou personnage dans la salle et/ou que vous n'avez pas assez de ferraille ⚙️)
    - 🔵 = OK
- sélectionnez l'action que vous voulez réaliser (agrandir ou détruire).

Pour **ajouter un personnage** à une salle:
- vérifier que il y'ait assez de place dans dans les dortoirs 👥
- vérifier que la salle n'est pas pleine (sinon vous pouvez l'agrandir)
- cliquez sur le personnage une bulle avec ses caratèristiques devrait pop-up
- cliquez sur la salle.

Pour **envoyer des personnages en expédition suicide**:
- Assurez vous qu'il y est une salle milice dans votre abris
- Mettez le personnage que vous souhaitez envoyer en expédition dans la milice
- cliquez sur la milice
- cliquez sur exploration.

## Astuces

Un personnage **agile et fort** sera plus efficace dans **l'atelier**.<br/>
Un personnage **agile et sociable** sera plus efficace dans **le réfectoire**.<br/>
Un personnage **charmant et sociable** sera plus efficace dans **le salon**.<br/>
Un personnage **concentré** sera plus efficace dans **la station d'épuration**.<br/>
Un personnage **fort** sera plus efficace dans **la milice**.<br/>
Un personnage **intelligent** sera plus efficace dans **la salle des réacteurs**.<br/>
**L'ascenceur** permet aux survivants de se **déplacer dans differents étages**.<br/>
**L'atelier** permet aux personnages d'aller resoudre les differents problèmes techniques.<br/>
**L'infirmerie** permet de soigner les personnages blessés.<br/>
**Le nombre de survivants** logeable dans le refuge dépand du nombre de lits dans **les dortoires**.<br/>
**Le réacteur** fournis de l'**énergie** aux salles.<br/>
**Le réfectoire** permet de nourrir les personnages.
**Le salon** est un espace qui **rends heureux** la communauté.<br/>
**Eau potable** est une station dépuration de l'eau qui permet fournir de l'eau potable.<br/>


## Les prix

**Destruction :**

- 0 ⚙️ pour **toutes les salles**.

**Construction :**

- 100 ⚙️ pour **un ascenseur** ou **un atelier** ou **une infirmerie** ou **un salon** ou **une salle d'eau** ou **un réfectoire** ou **un réacteur** ou **un dortoir**.
- 200 ⚙️ pour **une milice**.

**Agrandissment :** 

Du **niveau 1 au 2**: 
- 150 ⚙️ pour **un ascenseur** ou **un atelier** ou **une infirmerie** ou **un salon** ou **une salle d'eau** ou **un réfectoire** ou **un réacteur** ou **un dortoir**.
- 250 ⚙️ pour **une milice**.

Du **niveau 2 au 3**:
- 300 ⚙️ pour **un ascenseur** ou **un atelier** ou **une infirmerie** ou **un salon** ou **une salle d'eau** ou **un réfectoire** ou **un réacteur** ou **un dortoir**.
- 500 ⚙️ pour **une milice**.


## Contenu de l'archive

- Le dossier `bin` qui contient **les éxecutables**.
- Le dossier `data` qui contient **les données audio, image (et anciennes versions)**.
- Le dossier `doxygen` qui contient **la doc**.
- Le dossier `include` qui contient **les includes de la libraire sonore**.
- Le dossier `lib` qui contient la [libraire irrklang](#dépendances-requises).
- Le dossier `save` qui contient **les sauvegardes du jeu**.
- Le dossier `src` qui contient **les sources**.

## Étudiants

- Thibaut PEYRIC  (Code)
- Rose Coroller (Graphisme)

