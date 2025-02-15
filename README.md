# 🎮 Jeu X

## 📌 Description  
Ce projet, réalisé dans le cadre de ma 1ère année de BUT Informatique**, consiste en l’implémentation d’un **jeu** en **langage C**.

### 🕹️ Règles du jeu  
Le jeu se joue entre deux joueurs, **A** et **B**, sur un plateau de jeu de **L lignes** et **C colonnes**, où **L** et **C** sont des entiers impairs. Chaque joueur dispose de **n jetons** (où **n = (L x C - 1) / 2**), numérotés de 1 à n, avec des couleurs différentes : **bleus** pour le joueur A et **rouges** pour le joueur B.  

Les jetons sont déposés alternativement sur les cases du plateau, avec le joueur A commençant toujours. Le but du jeu est de minimiser la somme des valeurs des jetons entourant la dernière case vide après le placement de tous les jetons.  

Le gagnant est celui qui a la somme la plus faible des jetons autour de la case libre, avec une possibilité de match nul si les sommes sont égales.

### 🧠 Déroulement du jeu  
1. Le joueur A commence et dépose le jeton bleu n°1, puis le joueur B dépose le jeton rouge n°1.
2. Les joueurs continuent à déposer alternativement les jetons numérotés de 2 jusqu'à **n**.
3. Une fois tous les jetons déposés, la case restante est évaluée.
4. On calcule la somme des valeurs des jetons bleus et rouges autour de la dernière case vide.
5. Le joueur ayant la plus petite somme remporte la partie, avec possibilité de match nul si les sommes sont égales.

## 🚀 Fonctionnalités du programme  
- 🎲 Paramétrage du jeu : nombre de lignes et de colonnes (L et C), choix du plateau.
- 🔵 Affichage du plateau de jeu à chaque tour.
- 🧩 Calcul de la somme des jetons bleus et rouges autour de la case libre.
- 🎯 Détermination du gagnant à la fin de la partie, avec possibilité de match nul.

## 📂 Structure du projet
```
/Sae-jeu  
│── jeu.c              # Code source du jeu   
│── jeu                # Executable du jeu
│── Règle du jeu.png   # Règle du jeu
```
