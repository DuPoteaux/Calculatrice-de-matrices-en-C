#include <stdio.h>
#include <stdlib.h>


int Menu ( void );
int Sous_Menu ( int );
float** Allocate_Mat_Memory ( int, int );
void Free_Mat_Memory ( float**, int );
void Affiche_Vecteur ( float*, int );
void Affiche_Mat ( float**, int, int );
void Saisi_Mat ( float**, int, int );
void Add_Soust_Mat ( char, float**, float** , int, int );
void Multi_Mat_Nbr ( float**, int, int, int );
float** Produit_Matriciel ( float**, float**, int, int, int );
float** Sous_Mat_Det ( float**, int, int , int );
float Determinant ( float**, int);
void Comatrice ( float** , float** , int );
float** Inverse_Matrice ( float**, int );
float** Division_Matriciel( float**, float**, int, int );


void Transpose_Mat ( float**, float**, int, int );
float** Compactage ( float**, int, int );
void Trie_Mat_Croissant ( float**, int, int );
void Trie_Mat_Decroissant ( float**, int, int );
void Max_Ligne ( float**, int, int );
void Max_Colonne ( float**, int, int );
void Extraction_Sous_Mat ( float**, int, int, int, int );


/***************** Fonction Praincipale: main() *****************/
int main(void)
{
    int choixMenu, continuer = 1;
    float **matrice1, **matrice2;
    int N,M;

    do
    {
        choixMenu = Menu();

        switch ( choixMenu )
        {
            case 0:
                continuer = 0; /* On quitte la boucle  do{ ... }while */
            break;

            case 11:  /* La somme de deux matrices (Addition) */
            {
                printf("\n Donnez les dimensions de matrices:\n");
                printf("Nombre de lignes:  ");     scanf("%d", &N );
                printf("Nombre de colonnes:  ");   scanf("%d", &M);

                matrice1 = Allocate_Mat_Memory( N, M );
                matrice2 = Allocate_Mat_Memory( N, M );

                printf("\n Saisisez les valeurs de La 1ere matrice:\n");
                Saisi_Mat( matrice1, N, M );
                printf("La 1ere Matrice est:\n\n");
                Affiche_Mat( matrice1, N, M );

                printf("\n Saisisez les valeurs de La 2eme matrice:\n");
                Saisi_Mat( matrice2, N, M );
                printf("La 2eme Matrice est:\n\n");
                Affiche_Mat( matrice2, N, M );

                Add_Soust_Mat( '+', matrice1, matrice2, N, M ); // l'additon
                Affiche_Mat( matrice1, N, M );

                Free_Mat_Memory( matrice1, N );  // Liberer la memoire
                Free_Mat_Memory( matrice2, N );
            }
            break;

            case 12:   /* La difference de matrices (Soustraction) */
            {
                printf("\n Donnez les dimmantions de matrices:\n");
                printf("Nombre de lignes:  ");     scanf("%d", &N);
                printf("Nombre de colonnes:  ");   scanf("%d", &M);

                matrice1 = Allocate_Mat_Memory( N, M );
                matrice2 = Allocate_Mat_Memory( N, M );

                printf("\n Saisisez les valeurs de La 1ere matrice:\n");
                Saisi_Mat( matrice1, N, M );
                printf("La 1ere Matrice est:\n\n");
                Affiche_Mat( matrice1, N, M );

                printf("\n Saisisez les valeurs de La 2eme matrice:\n");
                Saisi_Mat( matrice2, N, M );
                printf("La 2eme Matrice est:\n\n");
                Affiche_Mat( matrice2, N, M );

                Add_Soust_Mat( '-', matrice1, matrice2, N, M ); // soustraction
                Affiche_Mat( matrice1, N, M );

                Free_Mat_Memory( matrice1, N );
                Free_Mat_Memory( matrice2, N );
            }
            break;

            case 13:  /* Mutimplier une matrice par un nombre */
            {
                float nombre;

                printf("\n Donnez les dimmantions de la matrice:\n");
                printf("Nombre de lignes:  ");       scanf("%d", &N);
                printf("Nombre de colonnes:  ");     scanf("%d", &M);

                matrice1 = Allocate_Mat_Memory( N, M );

                printf("\n Saisisez les valeurs de La matrice:\n");
                Saisi_Mat(matrice1, N, M);
                printf("Voici votre Matrice initiale:\n\n");
                Affiche_Mat(matrice1, N, M);

                printf("\n Donnez un nombre:   ");
                scanf("%f", &nombre);

                printf("\nLa Matrice multiplier par %f est:\n\n", nombre);
                Multi_Mat_Nbr( matrice1, nombre, N, M );
                Affiche_Mat( matrice1, N, M );

                Free_Mat_Memory(matrice1, N);
            }
            break;

            case 14:   /* Produit matriciel */
            {
                int P; // => nombre de colonnes de la 2eme matrice
                float **matProduit;

                printf("\n Les dimmantions de la 1ere matrice:\n");
                printf("Nombre de lignes:  ");     scanf("%d", &N);
                printf("Nombre de colonnes:  ");   scanf("%d", &M);

                matrice1 = Allocate_Mat_Memory( N, M );

                printf("\n Saisisez les valeurs de La 1ere matrice:\n");
                Saisi_Mat( matrice1, N, M );
                printf("La 1ere Matrice est:\n\n");
                Affiche_Mat( matrice1, N, M );

                printf("\n Les dimmantions de la 2eme matrice:\n");
                printf("Nbr de lignes = %d (obligatoirement)\n", M);
                printf("Nombre de colonnes:  ");    scanf("%d", &P);

                matrice2 = Allocate_Mat_Memory( N, M );

                printf("\n Saisisez les valeurs de La 2eme matrice:\n");
                Saisi_Mat( matrice2, M, P );
                printf("La 2eme Matrice est:\n\n");
                Affiche_Mat( matrice2, M, P );

                matProduit = Produit_Matriciel( matrice1, matrice2, N, M, P );

                printf("\nLe Produit matriciel est:\n\n");
                Affiche_Mat( matProduit, N, P );

                Free_Mat_Memory( matrice1, N );
                Free_Mat_Memory( matrice2, M );
                Free_Mat_Memory( matProduit, N );
            }
            break;

            case 15:   /* Inverse d'une matrice */
            {
                printf("\n Donnez les dimmantions de la matrice (carrée):\n");
                printf("Nombre de lignes == Nombre de colonnes : ");
                scanf("%d", &N);

                matrice1 = Allocate_Mat_Memory(N, N);

                printf("\n Saisisez les valeurs de La matrice:\n");
                Saisi_Mat( matrice1, N, N );
                printf("Voici votre Matrice initiale:\n\n");
                Affiche_Mat( matrice1, N, N );


                matrice1 = Inverse_Matrice( matrice1, N );
                /* si la fonction n'a pas retourné NULL, alors notre matrice1
                   à été inversé, on affiche: */
                if( matrice1 != NULL )
                {
                    Affiche_Mat( matrice1, N, N );
                    Free_Mat_Memory( matrice1, N );
                }

            }
            break;

            case 16:   /* Division de deux matrices */
            {
                float **matDivision;

                /* (N,M) : la dimantion de la matrice 1 */
                /* (M,M) : la dimansion de la matrice 2 */

                printf("\n Les dimmantions de la 1ere matrice:\n");
                printf("Nombre de lignes:  ");     scanf("%d", &N);
                printf("Nombre de colonnes:  ");   scanf("%d", &M);

                matrice1 = Allocate_Mat_Memory( N, M );

                printf("\n Saisisez les valeurs de La 1ere matrice:\n");
                Saisi_Mat( matrice1, N, M );
                printf("La 1ere Matrice est:\n\n");
                Affiche_Mat( matrice1, N, M );

                /* la dimmantion de la 2eme matrice (carré) doit être égal
                   au nombre de colonnes de la 1ere matrice */
                printf("\n Les dimmantions de la 2eme matrice sont :\n");
                printf("Nbr lignes = Nbr colonnes = %d (matrice carré)\n", M);

                matrice2 = Allocate_Mat_Memory( M, M );

                printf("\n Saisisez les valeurs de La 2eme matrice:\n");
                Saisi_Mat( matrice2, M, M );
                printf("La 2eme Matrice est:\n\n");
                Affiche_Mat( matrice2, M, M );

                matDivision = Division_Matriciel( matrice1, matrice2, N, M );

                if( matDivision != NULL )
                {
                    printf("\nLa Divistion des deux matrice donne :\n\n");
                    Affiche_Mat( matDivision, N, M ); // De taille (N,M)

                    Free_Mat_Memory( matDivision, N );
                    Free_Mat_Memory( matrice2, M );
                }
                else
                    printf("\nImpossible de faire la division...\n");

                Free_Mat_Memory( matrice1, N );
            }
            break;

            case 21:  /* Transposer d'une matrice */
            {
                printf("\n Donnez les dimmantions de la matrice:\n");
                printf("Nombre de lignes:  ");       scanf("%d", &N);
                printf("Nombre de colonnes:  ");     scanf("%d", &M);

                /* Attention au dimmentions de la matrice2 (la transposée),
                  le nbr de colonnes devien le nbr de ligne, et vice verça:  */
                matrice2 = Allocate_Mat_Memory( M, N );
                matrice1 = Allocate_Mat_Memory( N, M );

                printf("\n Saisisez les valeurs de La matrice:\n");
                Saisi_Mat(matrice1, N, M);
                printf("Voici votre Matrice initiale:\n\n");
                Affiche_Mat(matrice1, N, M);

                Transpose_Mat( matrice1, matrice2, N, M);
                printf("\nLa matrice transposee est:\n\n");
                Affiche_Mat( matrice2, M, N );

                Free_Mat_Memory(matrice1, N);
                Free_Mat_Memory(matrice2, M);
            }
            break;

            case 22:   /* Compactage d'une matrice */
            {
                printf("\n Donnez la dimmantion de votre matrice:\n");
                printf("Nombre de lignes:  ");        scanf("%d", &N);
                printf("Nombre de colonnes:  ");      scanf("%d", &M);

                matrice1 = Allocate_Mat_Memory( N, M );

                printf("\n Saisisez les valeurs de La matrice:\n");
                Saisi_Mat( matrice1, N, M );
                printf("Voici votre Matrice initiale:\n\n");
                Affiche_Mat(matrice1, N, M);

                matrice1 = Compactage( matrice1, N, M);
                Affiche_Mat( matrice1, N, M );

                Free_Mat_Memory( matrice1, N );
            }
            break;

            case 23:   /* Trier une matrice */
            {
                char choixOrdre;

                do
                {
                    printf("Entrer:\n D pour le trie Decroissant, Ou\n"
                           " C pour l'ordre Croissant (en majuscule):\n");
                    scanf("%c", &choixOrdre);
                /*getchar() pour prendre le \n que lesse scanf() dans le stdin*/
                    getchar();
                }
                while( choixOrdre!='D' && choixOrdre!='C' );

                printf("\n Donnez la dimmantion de votre matrice:\n");
                printf("Nombre de lignes:  ");        scanf("%d", &N);
                printf("Nombre de colonnes:  ");      scanf("%d", &M);

                matrice1 = Allocate_Mat_Memory( N, M );

                printf("\n Saisisez les valeurs de La matrice:\n");
                Saisi_Mat( matrice1, N, M );
                printf("Voici votre Matrice non trier:\n\n");
                Affiche_Mat( matrice1, N, M );

                if(choixOrdre == 'D')
                    Trie_Mat_Decroissant( matrice1, N, M );
                else
                    Trie_Mat_Croissant( matrice1, N, M );

                Affiche_Mat( matrice1, N, M );
                Free_Mat_Memory( matrice1, N );
            }
            break;

            case 24:   /* Les élements maximum des lignes */
            {
                printf("\n Donnez la dimmantion de votre matrice:\n");
                printf("Nombre de lignes:  ");        scanf("%d", &N);
                printf("Nombre de colonnes:  ");      scanf("%d", &M);

                matrice1 = Allocate_Mat_Memory( N, M );

                printf("\n Saisisez les valeurs de La matrice:\n");
                Saisi_Mat( matrice1, N, M );
                printf("Voici votre Matrice:\n\n");
                Affiche_Mat( matrice1, N, M );

                Max_Ligne( matrice1, N, M );

                Free_Mat_Memory( matrice1, N );
            }
            break;

            case 25:   /* Les élements maximum des colonnes */
            {
                printf("\n Donnez la dimmantion de votre matrice:\n");
                printf("Nombre de lignes:  ");        scanf("%d", &N);
                printf("Nombre de colonnes:  ");      scanf("%d", &M);

                matrice1 = Allocate_Mat_Memory( N, M );

                printf("\n Saisisez les valeurs de La matrice:\n");
                Saisi_Mat( matrice1, N, M );
                printf("Voici votre Matrice:\n\n");
                Affiche_Mat( matrice1, N, M );

                Max_Colonne( matrice1, N, M );

                Free_Mat_Memory( matrice1, N );
            }
            break;

            case 26:   /* Extraction de sous matrices */
            {
                int sMat_N, sMat_M;

                printf("\n Donnez la dimmantion de votre matrice:\n");
                printf("Nombre de lignes:  ");        scanf("%d", &N);
                printf("Nombre de colonnes:  ");      scanf("%d", &M);

                matrice1 = Allocate_Mat_Memory( N, M );

                printf("\n Saisisez les valeurs de La matrice:\n");
                Saisi_Mat( matrice1, N, M );

                printf("\n Donnez la dimmantion des sous matrices a extraire:\n");
                printf("Nombre de lignes:  ");
                scanf("%d", &sMat_N);
                printf("Nombre de colonnes:  ");
                scanf("%d", &sMat_M);

                printf("Voici votre Matrice initial:\n\n");
                Affiche_Mat( matrice1, N, M );

                printf("Voici touts les sous matrices possible:\n\n");
                Extraction_Sous_Mat( matrice1, N, M, sMat_N, sMat_M );

                Free_Mat_Memory( matrice1, N );
            }
            break;
        }
    }
    while( continuer );

    return 0;
}



/*********************** Les Fonctions : ***********************/

/* Cette fonction propose un menu tout simple */
int Menu(void)
{
    int choix;

    printf("\n*** MENU: ***\n 1.  Operations arithmetiques\n"
           " 2.  Autres operations\n 3.  Quitter\n");

    do
    {
        printf("Choisissez 1 ou 2 ou 3 :  ");
        scanf("%d", &choix);
    }
    while( (choix!=1) && (choix!=2) && (choix!=3) );

    /* si le choix est 3 on quitte la fonction en retournant 0 */
    if ( choix == 3 )
        return 0;
    else
        return ( Sous_Menu(choix) );

}



/* Propose un sous menu correspendant au choix du menu principale */
int Sous_Menu(int choix)
{
    int sousChoix;

    /* si le choix est 1, on affiche le 1er sous menu */
    if( choix == 1 )
    {
        printf("\n 1. Somme de deux matrices\n 2. Difference de deux matrices\n"
               " 3. Multiplication d'une matrice par un nombre\n"
               " 4. Produit de deux matrices\n 5. Inverse d'une matrice\n"
               " 6. Division de deux matrices\n");

        /* on fait un petit controle de saisie */
        do
        {
            printf("Choisissez un numero entre 1 et 6 du menu :  ");
            scanf("%d", &sousChoix);
        }
        while( (sousChoix!=1) && (sousChoix!=2) && (sousChoix!=3)
                && (sousChoix!=4) && (sousChoix!=5) && (sousChoix!=6) );

        switch (sousChoix)
        {
            case 1:  return 11;  break;   /* Menu 1.1 */
            case 2:  return 12;  break;   /* Menu 1.2 */
            case 3:  return 13;  break;   /* Menu 1.3 */
            case 4:  return 14;  break;   /* Menu 1.4 */
            case 5:  return 15;  break;   /* Menu 1.5 */
            case 6:  return 16;  break;   /* Menu 1.6 */
        }
    }

    /* sinon, le choix est forcément 2, car on a obligé l'utilisateur a ne
       saisir que 1 ou 2 ou 3 dans la fonction Menu */
    else
    {
        printf("\n 1. Transposee d'une matrice\n 2. Compactage d'une matrices\n"
               " 3. Tri d'une matrice\n 4. Calcul du vecteur Maxligne\n"
               " 5. Calcule du vecteur Maxcolonne\n"
               " 6. Extraction de Sous-Matrice\n");

        do
        {
            printf("Choisissez un numero entre 1 et 6 du menu :  ");
            scanf("%d", &sousChoix);
        }
        while( (sousChoix!=1) && (sousChoix!=2) && (sousChoix!=3)
                && (sousChoix!=4) && (sousChoix!=5) && (sousChoix!=6) );

        switch (sousChoix)
        {
            case 1:  return 21;  break;   /* Menu 2.1 */
            case 2:  return 22;  break;   /* Menu 2.2 */
            case 3:  return 23;  break;   /* Menu 2.3 */
            case 4:  return 24;  break;   /* Menu 2.4 */
            case 5:  return 25;  break;   /* Menu 2.5 */
            case 6:  return 26;  break;   /* Menu 2.6 */
        }
    }

    return 0; /*  pas obligatoire de retourne ici */
}



/* Cette fonction permet d'allouer de la memoire pour une matrice qulquonque */
float** Allocate_Mat_Memory(int N, int M)
{
    int i;
    float **A = NULL;

    /* On fait l'allocation de memoire pour un vecteur de N cases,
      C'est un vecteur de pointeurs */
    A = (float**) malloc( sizeof(float*) * N );

    /* Si l'allocation à réussi, On fait une allocation de M cases
       pour chaque ligne */
    if( A != NULL )
        for( i=0; i<N; i++ )
            A[i] = (float*) malloc( sizeof(float) * M );

    return A;

}



/* cette fonction fait la désallocation d'une matrice (liberer la memoire)*/
void Free_Mat_Memory( float **A, int N )
{
    int i;
    /* librer chaque ligne: */
    for( i=0; i<N; i++ )
        free( A[i] );

    free( A );
}



/* Affichage des eélements d'un simple vecteur d'entiers */
void Affiche_Vecteur( float *vector, int taille )
{
    int i;

    for( i=0; i<taille; i++ )
        printf("%f\t", vector[i]);
}


/* Affichage des élement de la matrice */
void Affiche_Mat( float **A, int N, int M )
{
    int i, j;

    for(i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
            printf("%f\t", A[i][j]);

        printf("\n");
    }
}



/* Saisir les élément de la matrice */
void Saisi_Mat( float **A, int N, int M )
{
    int i, j;

    for( i=0; i<N; i++ )
        for( j=0; j<M; j++ )
        {
            printf("matrice(%d,%d) :  ", i, j);
            scanf("%f", &A[i][j]);
        }
}



/* Fonction Addition/Soustraction , de deux matrice */
void Add_Soust_Mat( char operateur, float **mat1, float **mat2, int N, int M )
{
    int i, j;

    /* Pour ne pas perdre du temps, je ne vais pas crée une troisième matrice
       mat3 pour contenire le résultat de l'addition ou de la soustraction.
       Je vais dirrectement affecter le resultat à mat1 */

    if( operateur == '+' )
    {
        printf("\nLa Somme des deux Matrice est:\n\n");

        for( i=0; i<N; i++ )
            for( j=0; j<M; j++ )
                mat1[i][j] += mat2[i][j];
    }

    /* Si on veut faire une soustraction alore c'est meme chose avec un - */
    else if( operateur == '-' )
    {
        printf("\nLa Differance entre les deux Matrice est:\n\n");

        for( i=0; i<N; i++ )
            for( j=0; j<M; j++ )
                mat1[i][j] -= mat2[i][j];
    }
}



/* Multiplication d'une matrice par un nombre */
void Multi_Mat_Nbr( float **mat, int nbr, int N, int M )
{
    int i, j;

    for( i=0; i<N; i++ )
            for( j=0; j<M; j++ )
                mat[i][j] *= nbr;
}



/* Multiplication de deux matrices */
float** Produit_Matriciel( float **mat1, float **mat2, int N, int M, int P )
{
    int i, k, j;
    float **mat3 = NULL;

    mat3 = Allocate_Mat_Memory(N, P);

    /* produit matriciele : */
    for( i=0; i<N; i++ )
        for( j=0; j<P; j++ )
        {
            mat3[i][j] = 0; /* initialisation à 0 */
            for(k=0; k<M; k++)
                mat3[i][j] += mat1[i][k] * mat2[k][j];
        }

    return mat3;
}



/* Fonction qui enléve une ligne et une colonne pressise à une matrcie,
   Pour l'utiliser dans le calcule du déterminant :) */
float** Sous_Mat_Det( float** mat, int dim, int lign_a_sup, int col_a_sup )
{
    int i, j, l = 0, c = 0;
    float **sousMat;

    sousMat = Allocate_Mat_Memory( dim-1, dim-1 );

    /* parcourire chaque ligne */
    for( i=0; i<dim; i++ )
        if( i != lign_a_sup ) /* si cet ligne n'est pas cel à supprimer: */
        {
            for( j=0; j<dim; j++ )
                if( j != col_a_sup ) /*si ce n'est pas la colonne à supprimer */
                {
                    sousMat[l][c] = mat[i][j];
                    c++;
                    if( c > dim-2 )
                    {
                        c = 0;
                        l++;
                    }
                }
        }

    return sousMat;

}



float Determinant( float **mat, int N )
{
    int c, signe = 1;
    float det = 0.0;

    if( N == 1 )
        return mat[0][0];

    for( c=0; c<N; c++ )
    {
        det += signe * mat[0][c] * Determinant(Sous_Mat_Det(mat,N,0,c), N-1);
        signe *= (-1);
    }

    return det;
}



/* Fonction qui calcule la CoMatrice d'une matrice donné,
   pour l'utiliser dans le calcule de l'inverce */
void Comatrice( float** mat, float** comat, int dim )
{
    int i, j;

    for( i=0; i<dim; i++ )
        for( j=0; j<dim; j++ )
            comat[i][j] = Determinant( Sous_Mat_Det( mat, dim, i, j ), dim-1 );
}




/* Fonction qui calcule l'inverce d'une matrice donné, et retourne NULL si la
   matrice est non inversible ( det == 0 ) */
float** Inverse_Matrice( float **matrice, int dim )
{
    float det = Determinant( matrice, dim );
    float **comatrice, **comatTransposed;

    if( det == 0 )
    {
        printf("\nLe determinant est null, cet matrice est non inversible\n\n");
        return NULL;
    }

    comatrice = Allocate_Mat_Memory( dim, dim );
    comatTransposed = Allocate_Mat_Memory( dim, dim );

    /* calculer la comatrice de la matrice */
    Comatrice( matrice, comatrice, dim );

    /* calculer la comatrice transposer */
    Transpose_Mat( comatrice, comatTransposed ,dim, dim );

    /* calculer la matrice inverse selon la relation suivante:
       l'inverce d'un matrice = (1 / det) * comatriceTranspoed */
    Multi_Mat_Nbr( comatTransposed, (1.0/det), dim, dim );

    return comatTransposed;

}



/* Division de deux matrices */
float** Division_Matriciel( float **mat1, float **mat2, int N, int M )
{
    /* On inverse la mat2, et on fait une simple multiplication matriciel,
       donc:     ( mat1 * inverce_de_mat2 )  */

    float **matDivision = Allocate_Mat_Memory( N, M );

    mat2 = Inverse_Matrice( mat2, M );

    if( mat2 == NULL )  // Si l'inverse n'a pas reussi alors
    {
        Free_Mat_Memory( matDivision, N );
        /* On quite en retournant NULL, car mat2 n'est pas inversible */
        return NULL;
    }

    /* on fait le produit matriciel */
    matDivision = Produit_Matriciel( mat1, mat2, N, M, M );

    return matDivision;
}



/* Le transposé d'une matrice */
void Transpose_Mat( float **mat1, float **mat2 ,int N, int M )
{
    int i,j;

    for( i=0; i<N; i++ )
        for( j=0; j<M; j++ )
            mat2[j][i] = mat1[i][j];
}



/* Fonction qui met tout les element null d'une matrice à la
   fin de la matrice */
float** Compactage( float **mat, int N, int M )
{
    int i, j, L=0, C=0, cptNull = 0;
    float **t;

    t = Allocate_Mat_Memory( N,  M);

    printf("\nCompactage :\n\n");

    for( i=0; i<N; i++ )
        for( j=0; j<M; j++ )
        {
            if( mat[i][j] != 0 )
            {
                t[L][C] = mat[i][j];
                C++;
                if( C == M )
                {
                    C = 0;
                    L++;
                }
            }
            else
            {
                cptNull++; // on compte.
            }
        }

    /* On met les cptNull derniers element de la matrice à 0 */
    for( i=N-1; i>=0; i-- )
        for( j=M-1; j>=0; j-- )
           if( cptNull!=0 )
           {
                t[i][j]=0;
                cptNull--;
           }

    return t;
}


/* Trier la matrice selon l'ordre Decroissant (Trie par selection) */
void Trie_Mat_Decroissant( float **mat, int N, int M )
{
  int i, j, L, C, posColonMin, posLignMin;
  float tmp;

    printf("\nLa matrice Trie selon l'ordre decroissant est:\n\n");

    for ( i=0; i<N; i++ )
        for ( j=0; j<N; j++ )
        {
            /* Recherche du maximum aprés A[i][j] */
            posLignMin = i;
            posColonMin = j;

			C = j;

            for ( L=i; L<N; L++ )
            {
               if( L != i )
                  C=0;
	    	   for ( ; C<M; C++ )
       			if ( mat[L][C] > mat[posLignMin][posColonMin] )
                    {
                        posLignMin = L;
                        posColonMin = C;
                    }

			}

			/* Echange de A[I] avec le maximum */
            tmp = mat[i][j];
            mat[i][j] = mat[posLignMin][posColonMin];
            mat[posLignMin][posColonMin] = tmp;
        }
}



/* Trier la matrice selon l'ordre Croissant (Trie par selection) */
void Trie_Mat_Croissant( float **mat, int N, int M )
{
    int i, j, L, C, posColonMin, posLignMin;
    float tmp;

    printf("\nLa matrice Trie selon l'ordre croissant est:\n\n");

    for ( i=0; i<N; i++ )
        for ( j=0; j<N; j++ )
        {
            /* Recherche du maximum aprés A[i][j] */
            posLignMin = i;
            posColonMin = j;
			C = j;

            for ( L=i; L<N; L++ )
            {
               if( L != i )
                  C = 0;
	    	   for (; C<M; C++)
       			if ( mat[L][C] < mat[posLignMin][posColonMin] )
                    {
                        posLignMin = L;
                        posColonMin = C;
                    }

			}

			/* Echange de A[I] avec le maximum */
            tmp = mat[i][j];
            mat[i][j] = mat[posLignMin][posColonMin];
            mat[posLignMin][posColonMin] = tmp;
        }
}



/* Les elements maximume des lignes */
void Max_Ligne( float **mat, int N, int M )
{
    int i, j;
    float *maxLigne, Max;
    printf("\nLe vecteur des elements maximum des lignes est:\n\n");

    maxLigne = (float*) malloc( N * sizeof(float) );

	for(i=0; i<N; i++)
    {
        /* initialiser avec le 1er element de la ligne */
        Max = mat[i][0];

		for(j=0; j<M; j++)
            if( Max < mat[i][j] )
                Max = mat[i][j];

        maxLigne[i] = Max;
    }

    Affiche_Vecteur( maxLigne, N );
}




/* Les élements maximume des colonnes */
void Max_Colonne( float **mat, int N, int M )
{
    int i, j;
    float *maxColonne, Max;
    printf("\nLe vecteur des elements maximum des colonne est:\n\n");

    maxColonne = (float*) malloc( M * sizeof(float) );

    for(j=0; j<M; j++)
    {
        /* initialiser avec le 1er element de la colonne */
        Max = mat[0][j];

		for( i=0; i<N; i++ )
            if( Max < mat[i][j] )
                Max = mat[i][j];

		maxColonne[j] = Max;
    }

    Affiche_Vecteur( maxColonne, M );
}



/* Extarcation des sous matrice s_mat de taille s_N et s_M à partir de la
   matrice mat de dimentions N et M */
void Extraction_Sous_Mat( float **mat, int N, int M, int s_N, int s_M )
{
    int i, j, L=0, C=0;
    float **s_mat;

    /* L est l'indice de debut de lignes d'une suite de sous matrice
         On appel une etage une suite de s_N lignes commençant à la ligne L.
       C est l'indice de debut de colones de chaque sous matrice */

    /* tantqu'on à pas encor tréter les sous matrices
       de la derniere etage de la matrice */
    while( L <= N-s_N )
    {
        /* allocation de la sous matrice */
        s_mat = Allocate_Mat_Memory( s_N,  s_M);

        /* remplissage de la sous matrice */
        for( i=0; i<s_N; i++ )
            for( j=0; j<s_M; j++ )
                s_mat[i][j] = mat[i+L][j+C];

        /* si on à pas encor tréter la derniere sous matrices de cette etage */
        if( C < M-s_M )
            C++;
        else
        {
            C = 0;
            L++;
        }

        /* affichage de la sous matrice */
        Affiche_Mat(s_mat, s_N, s_M);

        Free_Mat_Memory(s_mat, s_N);
    }

}

