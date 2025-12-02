#include <iostream>

int main()
{
	//Déclaration de variables
	int damier[8][8] = { {0}, {0} };
	int ligne = 0;
	int colonne = ' ';
	char rep = ' ', c;
	int tour = 0, fou = 0;
	//affichage du tableau vide

	printf("Voici votre damier: \n");
	printf("\t \t \t  ---------------------------------\n");
	for (int x = 7; x >= 0; x--)
	{
		printf("\t\t\t%d | ", x + 1);
		for (int y = 0; y < 8; y++)
			printf("%d | ", damier[x][y]);

		printf("\n \t \t \t  ---------------------------------\n");
	}
	printf("\t \t \t    A  \tB   C   D   E   F   G   H \n");
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
			if (tour == 0)
			{

				//D'abord la colonne

				colonne = 0;
				do
				{
					printf("Quelle colonne ? (A-H) : \n");
					c = toupper(getchar());
					c = toupper(c);
					while (getchar() != '\n');

					if (c < 'A' || c > 'H')
						printf("Colonne invalide, recommencez.\n");

				} while (c < 'A' || c > 'H');

				colonne = c - 'A' + 1;
				//Puis la ligne


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
						printf("Nombre hors limite, recommencez.\n");
						while ((getchar()) != '\n');
					}

				} while (ligne > 8 || ligne < 1);
				while ((getchar()) != '\n');

				printf("Vous avez choisi la ligne %d et la colonne %c\n", ligne, c);
				//--------------------------------------------------------
				//je met la valeur 1 sur toute les colonnes puis les lignes
				//on va additionner si on trouve la valeur 2 dans notre tableau.
				//--------------------------------------------------------  

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
				//---------------------------
				//j'affiche le damier complet
				//---------------------------
				printf("Voici votre damier: \n");
				printf("\t \t \t  ---------------------------------\n");
				for (int x = 7; x >= 0; x--)
				{
					printf("\t\t\t%d | ", x + 1);
					for (int y = 0; y < 8; y++)
						printf("%d | ", damier[x][y]);

					printf("\n \t \t \t  ---------------------------------\n");
				}
				printf("\t \t \t    A  \tB   C   D   E   F   G   H \n");
				tour = 1;
			}
			else
				printf("Vous avez deja pose cette piece\n");

		}




		if (rep == 'F')
		{
			if (fou == 0)
			{
				//D'abord la colonne

				colonne = 0;
				do
				{
					printf("Quelle colonne ? (A-H) : \n");
					c = toupper(getchar());
					c = toupper(c);
					while (getchar() != '\n');

					if (c < 'A' || c > 'H')
						printf("Colonne invalide, recommencez.\n");

				} while (c < 'A' || c > 'H');

				colonne = c - 'A' + 1;

				//Puis la ligne           


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
						printf("Nombre hors limite, recommencez.\n");
						while ((getchar()) != '\n');
					}

				} while (ligne > 8 || ligne < 1);
				while ((getchar()) != '\n');

				printf("Vous avez choisi la ligne %d et la colonne %c\n", ligne, c);
				//-------------------------------------------------------------
				//je met la valeur 2 la ou l'utilisateur à introduit sa position 
				//on va additionner si on trouve la valeur 1 dans notre tableau.
				//-------------------------------------------------------------
				if (damier[ligne - 1][colonne - 1] == 1)
					damier[ligne - 1][colonne - 1] += 2;
				else
					damier[ligne - 1][colonne - 1] = 2;

				// j'ai décrémenté pour correspondre au damier et non a la valeur utilisateur
				//(je dépasserai le tableau ou ce serait trop verbeux de le mettre a chaque fois
				// que j'appelle l'une de ces deux variables - 1)
				ligne -= 1;
				colonne -= 1;

				// on verifie pour les 4 directions diagonales(--,-+,+-,++, comme sur un graphique)
				//j'aurai aimé faire un balayage du tableau comme pour la tour mais je n'ai pas trouvé comment faire
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

				printf("Voici votre damier: \n");
				printf("\t \t \t  ---------------------------------\n");
				for (int x = 7; x >= 0; x--)
				{
					printf("\t\t\t%d | ", x + 1);
					for (int y = 0; y < 8; y++)
						printf("%d | ", damier[x][y]);

					printf("\n \t \t \t  ---------------------------------\n");
				}
				printf("\t \t \t    A  \tB   C   D   E   F   G   H \n");
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

