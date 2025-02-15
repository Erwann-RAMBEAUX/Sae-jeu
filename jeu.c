#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Valide_L (3 > *L || *L > 7 || *L % 2 == 0)
#define Valide_C (3 > *C || *C > 7 || *C % 2 == 0 )

/*Création des structure*/
typedef struct 
{
    int L; //nb de ligne
    int C; // nb de colonne
    int ** tab; // tableau
} Plateau;


typedef struct
{
    int num;
    int score [10];
    int total;
    char nom [10];
} Joueur;



/* Choix des lignes et colonnes*/

void taille(int *L, int *C)
{
    printf("\nCombien de lignes voulez-vous?\n");
    while (Valide_L) // Define de verification de la ligne
    {
        scanf("%d", *&L);
        if (Valide_L)
        {
            printf("\nNombre de lignes impossible !!! \nRéessayer \n");
        }
    }

    printf("\nCombien de colonnes voulez-vous?\n");
    while (Valide_C) // Define de verification de la colonne
    {
        scanf("%d", *&C); 
        if (Valide_C)
        {
            printf("\nNombre de colonnes impossible !!! \nRéessayer \n");
        }
    }
}






/*Créatoin du plateau*/

void crea_plateau(Plateau *pl, int L, int C) 
{
    int i, j;
    pl->L = L;
    pl->C = C;

    pl->tab = (int **) malloc(L * (sizeof(int *))); // Permet de créer les lignes du tableau 
    for(i=0; i < L; i++)
    {
        pl->tab[i] = (int*) malloc(C * sizeof(int));  // Permet de créer les colonnes du tableau
    }

    for(i=0; i < L; i++)    //// Boucle pour mettre toutes les cases du tableau à 0
    {
        for(j=0; j < C; j++)
        {
            pl->tab[i][j] = 0;
        }
    }
}






/* Ajoute le pion*/

void ajouterPion(Plateau *pl, Joueur joueur, int val)
{
    int ligne, colonne;
    int dispo = 0;
    printf("\n\t%s a vous de jouer \n",joueur.nom);
    printf("\nDans quelle case voulez-vous placer votre pion?\n");

    while (!dispo)      // Permet de demander et de vérifier si la case choisi par le joueur est disponible (vide ou dans la tableau)
    {
        printf("\nChoississez la ligne\n");
        scanf("%d", &ligne);

        printf("\nChoissisez la colonne\n");
        scanf("%d", &colonne);
        if (ligne >= 0 && ligne < pl->L && colonne >= 0 && colonne < pl->C)
        {
            if (pl->tab[ligne][colonne] == 0)
            {
                dispo = 1;
            }
            else
            {
            printf("Case indisponible\n");
            }
        }
        else
        {
            printf("Case indisponible\n");
        }
    }
    pl->tab[ligne][colonne] = val;  //Change la valeur de la case du tableau pour le nombre de points du coup du joueur
}






/* Afficher le plateau*/

void afficherPl(Plateau pl)
{   
    int ligne, colonne;
    for (ligne = -1; ligne < pl.L; ligne++) //Boucle d'affichage (-1 pour mettre les indices)
    {
        for(colonne = -1; colonne < pl.C; colonne++) //Boucle d'affichage (-1 pour mettre les indices)
        {
            if (ligne == -1)
            {
                if (colonne == -1)
                {
                    printf("\t"); //Permet de mettre une tabulation sur le haut du tableau
                }
                else
                {
                    printf("\t %d", colonne);   //Permet de mettre l'indice de la colonne sur la haut du tableau
                }
            }
            else if (colonne == -1)
            {
                printf("\t %d", ligne); //Permet de mettre l'indice de la ligne sur la droite du tableau
            }
            else 
            {
                if (pl.tab[ligne][colonne] >= 1)
                {
                    printf("\e[0;34m \t|%d| \e[0m", pl.tab[ligne][colonne]); // Affiche en bleu les cases ou le joueur avec les coup positif joue
                }
                else if (pl.tab[ligne][colonne] < 0)
                {
                    printf("\e[0;31m  \t|%d|\e[0m", abs(pl.tab[ligne][colonne])); // Affiche en rouge les cases ou le joueur avec les coup positif joue
                }
                else
                {
                    printf("\t|%d|", pl.tab[ligne][colonne]); // Affiche les cases encore non utilisée
                }
            }
            
        }
        printf("\n\n");
    }
}




/* Vérifie le gagnant de la partie*/
void gagnant(Plateau *pl, Joueur *joueur1, Joueur *joueur2, int tour)
{
    int ligne, colonne;
    int trouver = 0;
    int l, c, max_l, max_c;
    int boucle_l, boucle_c;

    joueur1->score[tour] = 0;               
    joueur2->score[tour] = 0;                   // Initialisation des scores du tour à 0

    for (ligne = 0; ligne < pl->L; ligne++)
    {
        for (colonne = 0; colonne < pl->C; colonne++)
        {   
            if (pl->tab[ligne][colonne] == 0)                   // Vérification des cases afin de trouver la dernière cases vides
            {
                trouver = 1;
                break;
            }
        }
        if (trouver)
        {
            break;
        }
    }

    if (ligne == 0)             // Les 2 if servent à définir les lignes et les colonnes des cases à compter en fonction de la case vide
    {
        l = 0;
        max_l = 1;
    }
    else if (ligne == pl->L - 1)
    {
        l = -1;
        max_l = 0;
    }
    else
    {
        l = -1;
        max_l = 1;
    }

    if (colonne == 0)
    {
        c = 0;
        max_c = 1;
    }
    else if (colonne == pl->C - 1)
    {
        c = -1;
        max_c = 0;
    }
    else
    {
        c = -1;
        max_c = 1;
    }
    for (boucle_l = l; boucle_l <= max_l; boucle_l++)
    {   
        for (boucle_c = c; boucle_c <= max_c; boucle_c++)
        {
            
            if (boucle_l != 0 || boucle_c != 0)
            {
                if(pl->tab[ligne + boucle_l][colonne + boucle_c] < 0)       //Permet d'ajouter le nombre de la case au score du tour du joueur à qui la case appartient
                {
                    joueur2->score[tour]+= abs(pl->tab[ligne + boucle_l][colonne + boucle_c]);
                }
                else
                {
                    joueur1->score[tour] += pl->tab[ligne + boucle_l][colonne + boucle_c];
                }
            }
        }
    }
    printf("\e[0;34mScore de %s : %d\e[0m\n",joueur1->nom,joueur1->score[tour]);    //Donne le score des 2 joueurs
    printf("\e[0;31mScore de %s : %d\e[0m\n",joueur2->nom,joueur2->score[tour]);
    if (joueur1->score[tour] == joueur2->score[tour])
        printf("Cette parti ce fini sur un match nul avec %d points", joueur1->score[tour]);    // Si les 2 joueurs ont le même score sur la partie
    else    
        printf("Le gagnant de cette partie est %s avec un score de : %d \n\n", (joueur1->score[tour] > joueur2->score[tour] ? joueur2->nom : joueur1->nom), 
            (joueur1->score[tour] > joueur2->score[tour] ? joueur2->score[tour] : joueur1->score[tour]));
        //Affiche le gagnat de la partie
}







/*Jouer la partie*/
void jouer_partie(Plateau plateau, int L, int C, Joueur *joueur1, Joueur *joueur2, int tour) 
{
    int n = (L * C - 1)/2;          //Défini le nombre de coup des joueurs 
    int i;
    afficherPl(plateau);
    for(i = 1; i <= n; i++)     //Permet d'augmenter à chaque tour les points de chaque coup
    {
        if (joueur1->num == 1)      // Vérifie quel est le 1er joueur à jouer
        {
            ajouterPion(&plateau, *joueur1, i);
            afficherPl(plateau);
            ajouterPion(&plateau, *joueur2, -i);
            afficherPl(plateau);

        }
        else
        {
            ajouterPion(&plateau, *joueur2, -i);
            afficherPl(plateau);
            ajouterPion(&plateau, *joueur1, i);
            afficherPl(plateau);
        }
    }
    gagnant(&plateau, &*joueur1, &*joueur2, tour);
}


void continuer_partie(int *continuer)
{
    printf("Voulez-vous continuer la partie? (Si oui entrer 1)\n");
    scanf("%d", &*continuer);
}






/////////////////////////////////
/////////////////////////////////
/////////////////////////////////
/////////////////////////////////       Prog Principal
/////////////////////////////////
/////////////////////////////////
/////////////////////////////////

int main()
{   
    Plateau plateau;
    int L, C, continuer;
    int tour = 0;
    int i;
    int change;

    Joueur joueur1;
    joueur1.num = 1;
                                
    Joueur joueur2;
    joueur2.num = 2;

    printf("Entrer nom du joueur 1 (max caractère 20)\n");
    scanf("%s",joueur1.nom);

    printf("\nEntrer nom du joueur 2 (max caractère 20)\n");
    scanf("%s",joueur2.nom);

    taille(&L, &C);
    do
    {
        crea_plateau(&plateau, L, C);
        jouer_partie(plateau, L, C, &joueur1, &joueur2, tour);
        continuer_partie(&continuer);
        tour++;

        change = joueur1.num;
        joueur1.num = joueur2.num;
        joueur2.num = change;

    } while(continuer == 1 && tour < 10); // boucle le temps que les joueurs veulent continier ou alors au bout de 10 parties
    if(tour == 10)
    {
        printf("\n\nVous avez fait le max de partie maximum");
    }
    joueur2.total = 0;
    joueur1.total = 0;
    for(i = 0; i < tour; i++)   // Boucle afin de compter le score total des joueurs 
    {
        joueur1.total += joueur1.score[i];
        joueur2.total += joueur2.score[i];
    }
    printf("\n\n\e[0;34mLe score total de %s est de : %d\e[0m\n",joueur1.nom, joueur1.total);
    printf("\e[0;31mLe score total de %s est de : %d\e[0m\n",joueur2.nom, joueur2.total);
    
    if (joueur1.total == joueur2.total)
        printf("Il n'y a pas de vainqueur ceci est un match nul\n");
    else 
        printf("Le grand gagnant est %s.\n Bravo à toi !!!!!!\n", (joueur1.total > joueur2.total ? joueur2.nom : joueur1.nom));
    return 0;
}