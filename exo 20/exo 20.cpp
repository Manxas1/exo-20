#include <iostream>

int main()
{
    //Déclaration de variables
    int damier[8][8] = {{0}, {0}};
    int ligne = 0;
    int colonne = 0;
    char rep = ' ';
    int tour = 0, fou = 0;
    //affichage du tableau vide

    printf("Voici votre Damier:\n\v");

    for (int x = 0 ; x < 8; x++)
    {
        printf("\t \t \t|");
        for (int y = 0; y < 8; y++)
            printf("%d|", damier[x][y]);     

        printf("\n");
    }
    // on demande a l'utilisateur par quelle pièce commencer.
    while (tour == 0 || fou == 0)
    {
        do {
            printf("Voulez-vous commencer par la tour ou le fou ? (T/F) : \n");
            rep = toupper(getchar());  
            while ((getchar()) != '\n'); 
            if (rep != 'T' && rep != 'F')
            {
                printf("Vous n'avez pas choisi Tour ou Fou, recommencez \n");
                
            }
        } while (rep != 'T' && rep != 'F');
        



        if (rep == 'T')
        {
            //Je demande a l'utilisateur ou veut-il placer sa tour
            //D'abord la ligne
            if (tour == 0)
            {
                printf("Ou souhaitez-vous placer votre tour? (1-8 pour la ligne, 1-8 pour la colonne)\n");

                ligne = 0;
                do {
                    printf("Quelle ligne?\n");

                    if (scanf_s("%d", &ligne) != 1)
                    {
                        printf("ce nombre est ou incorrect veuillez choisir un nombre entre 1 et 8\n");
                        while ((getchar()) != '\n');
                        continue;
                    }

                    if (ligne > 8 || ligne < 1)
                    {
                        printf("Nombre trop grand ou trop petit, recommencez.\n");
                        while ((getchar()) != '\n');
                    }

                } while (ligne > 8 || ligne < 1);
                while ((getchar()) != '\n');

                //Puis la colonne

                colonne = 0;
                do {
                    printf("Quelle colonne?\n");

                    if (scanf_s("%d", &colonne) != 1)
                    {
                        printf("ce nombre est ou incorrect veuillez choisir un nombre entre 1 et 8\n");
                        while ((getchar()) != '\n');
                        continue;
                    }

                    if (colonne > 8)
                    {
                        printf("Nombre trop grand, recommencez.\n");
                        while ((getchar()) != '\n');
                    }
                } while (colonne > 8 || colonne < 1);
                while ((getchar()) != '\n');

                //je met la valeur 1 la ou l'utilisateur à introduit sa position + l'allonge


                for (int x = 0; x < 8; x++)
                {
                    if (damier[x][colonne - 1] == 2)
                        damier[x][colonne - 1] += 1;

                    else if (damier[x][colonne - 1] == 0)
                        damier[x][colonne - 1] = 1;
                }

                for (int y = 0; y < 8; y++)
                {
                    if (damier[ligne - 1][y] == 2)
                        damier[ligne - 1][y] += 1;
                    else if (damier[ligne - 1][y] == 0)
                        damier[ligne - 1][y] = 1;
                }

                //j'affiche le damier complet

                printf("Voici votre Damier:\n\v");

                for (int x = 0; x < 8; x++)
                {
                    printf("\t \t \t|");
                    for (int y = 0; y < 8; y++)
                        printf("%d|", damier[x][y]);

                    printf("\n");
                }
                tour = 1;
            }
            else
                printf("Vous avez deja pose cette piece\n");
            
        }
        

        

        if (rep == 'F')
        {

            //Maintenant je fais de même pour le fou
            //en commençant par la ligne
            if (fou == 0)
            {
                ligne = 0;
                printf("Ou souhaitez-vous placer votre fou? (1-8 pour la ligne, 1-8 pour la colonne)\n");

                do {
                    printf("Quelle ligne?\n");

                    if (scanf_s("%d", &ligne) != 1)
                    {
                        printf("ce nombre est ou incorrect veuillez choisir un nombre entre 1 et 8\n");
                        while ((getchar()) != '\n');
                        continue;
                    }

                    if (ligne > 8 || ligne < 1)
                    {
                        printf("Nombre trop grand ou trop petit, recommencez.\n");
                        while ((getchar()) != '\n');
                    }

                } while (ligne > 8 || ligne < 1);
                while ((getchar()) != '\n');

                //Puis la colonne

                colonne = 0;
                do {
                    printf("Quelle colonne?\n");

                    if (scanf_s("%d", &colonne) != 1)
                    {
                        printf("ce nombre est ou incorrect veuillez choisir un nombre entre 1 et 8\n");
                        while ((getchar()) != '\n');
                        continue;
                    }

                    if (colonne > 8)
                    {
                        printf("Nombre trop grand, recommencez.\n");
                        while ((getchar()) != '\n');
                    }
                } while (colonne > 8 || colonne < 1);
                while ((getchar()) != '\n');


                //je met la valeur 2 la ou l'utilisateur à introduit sa position + l'allonge en diagonale cette fois
                //on va additionner si on trouve la valeur 1 dans notre tableau.

                if (damier[ligne - 1][colonne - 1] == 1)
                    damier[ligne - 1][colonne - 1] += 2;
                else
                    damier[ligne - 1][colonne - 1] = 2;

                // j'ai décrémenté pour correspondre au damier et non a la valeur utilisateur
                //(je dépasserai le tableau sinon)
                ligne -= 1;
                colonne -= 1;

                // on verifie pour les 4 directions diagonales(--,-+,+-,++, comme sur un graphique)

                for (int i = 1; i < 8; i++)
                {
                    if (ligne - i >= 0 && colonne - i >= 0)
                    {
                        if (damier[ligne - i][colonne - i] == 1)
                            damier[ligne - i][colonne - i] += 2;
                        else
                            damier[ligne - i][colonne - i] = 2;
                    }

                    if (ligne - i >= 0 && colonne + i < 8)
                    {
                        if (damier[ligne - i][colonne + i] == 1)
                            damier[ligne - i][colonne + i] += 2;
                        else
                            damier[ligne - i][colonne + i] = 2;
                    }

                    if (ligne + i < 8 && colonne - i >= 0)
                    {
                        if (damier[ligne + i][colonne - i] == 1)
                            damier[ligne + i][colonne - i] += 2;
                        else
                            damier[ligne + i][colonne - i] = 2;
                    }

                    if (ligne + i < 8 && colonne + i < 8)
                    {
                        if (damier[ligne + i][colonne + i] == 1)
                            damier[ligne + i][colonne + i] += 2;
                        else
                            damier[ligne + i][colonne + i] = 2;
                    }
                }

                //j'affiche le tableau

                printf("Voici votre damier \n");
                for (int x = 0; x < 8; x++)
                {
                    printf("\t \t \t|");
                    for (int y = 0; y < 8; y++)
                        printf("%d|", damier[x][y]);

                    printf("\n");
                }

                fou = 1;
            }
            else
                printf("Vous avez deja pose cette piece\n");

        }
        

            
    }
    printf("Appuyez Enter pour quitter..");
    getchar();
    return 0;
}

