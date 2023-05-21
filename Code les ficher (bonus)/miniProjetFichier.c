#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

 // ====================Done by Bilal Ben Aouad ====================

//*****************************************************************
//                 structure de type employe
//*****************************************************************

typedef struct employee
   {
      char  nom[10]    ;
      char  prenom[10] ;
      float salaire    ;
   } employee ;

   int f=0;  // Variable pour vérification si le fichier est déjà Initialiser

  FILE *fichier =NULL ;  // Declaration de notre fichier

  //*****************************************************************
  //           fonction de recherche dans le fichier
  //*****************************************************************

void ajoutAuFile(employee emp)
  {
    fichier =fopen("information.txt","a") ; // stockes dans le fichier txt information
    fprintf(fichier ,"\n\nLes information d'empolyee  - %s - sont :\n",emp.nom) ;
    fprintf(fichier,"\nLe nom  est    : %s\n",emp.nom);
    fprintf(fichier,"\nLe Prenom  est : %s\n",emp.prenom);
    fprintf(fichier,"\nLe salaire  est : %.2f DH\n",emp.salaire);
      fprintf(fichier,"\n\n");

    fclose(fichier);

  }

  //*****************************************************************
  //       fonction d'affichage des elements de fichier
  //*****************************************************************

void aficherFichier()
  {
    fichier=fopen("information.txt","r") ;
    if((fichier ==NULL)||(f!=0)){printf("\nLe fichier est vide !\n");}
    else
    {char c ;
      do{
      c=fgetc(fichier);
      printf("%c",c);}while(c!=EOF);
      fclose(fichier);

    }
  }

  //*****************************************************************
  //      fonction de recherche sur un nom dans le fichier
  //*****************************************************************

  int rechercherUnEmployee(char Name[])
    {
        int p=0 ; // Variable de return
        int langeur ;
            fichier=fopen("information.txt","r") ; //ouvrir notre fichier
            if(fichier ==NULL)
             {printf("\nAucune employes dans le fichier !\n");}

               char motFr[10];

              while (fgets(motFr,10,fichier) != NULL) //Prend 10 caractères du fichier à chaque fois jusqu'a la fin de fichier
              {
                if (strstr(motFr, Name) !=NULL) //verifier c'est le mot entre existe dans les 10 caractères pris grace a la fonction prédéfini strstr
                   p=1; // p devient 1 s'il existe ;
              }
              return p; //return p pour la verification apres

    }

    //*****************************************************************
    //      fonction pour lancer l'operation choisi
    //*****************************************************************

int runOperation(int i)
  {

    switch(i)
      {
       case 1 :
             {
                 //*************** Operation 1 : Ajouter un employe************
               int nbr,c=0 ;
               printf("\n\n------------L'Ajoute d'un employee : ------------\n\n");
               printf("\nEntrer le nombre d'employees : ");
                      scanf("%d",&nbr) ;
                  employee emp[nbr] ; // tableau de type employe ;
                  for(c=0;c<nbr;c++)
                    {
                      printf("\n\nEntrer le nom d'employee num %d     :\t",c+1);
                      scanf("%s",emp[c].nom);

                      printf("\nEntrer le prenom d'employee num %d  :\t",c+1);
                      scanf("%s",emp[c].prenom);

                      printf("\nEntrer le salaire d'employee num %d :\t",c+1);
                      scanf("%f",&emp[c].salaire);
                        ajoutAuFile( emp[c]) ; // ajouter les information stockes dans le tableau dans le fichier ;
                      printf("\n\n");

                    }
                      f=0;
                    printf("\nEffectue avec success \n");
               break ;
             }

       case 2 :
                {
                  //*************** Operation 2 : afficher les employe existant dans le fichier************
                    printf("\n\n");
                    aficherFichier(); //appele de fonction d'affichage
                    break ;
                }

       case 3 :
                {
                  //*************** Operation 3 : rechercher un employe************
                    char nom[10] ;
                    printf("\nEntrer le nom :\t ");
                           scanf("%s",nom); // prend le nom a rechercher
                    if(rechercherUnEmployee(nom)==1) // cas ou p=1
                      {
                        printf("\nL'employe : %s est existe \n\n",nom) ;
                      }
                    else
                       {
                         printf("\nAucune employe sous le nom : %s trouve \n\n",nom) ; //cas au p=0
                       }

                         break ;
                  }

       case 5 :
                {
                  //*************** Operation 5 : Quitter ************
                   system("CLS") ;
                      exit(0);
                      break ;

              }

       case 4 :
                {
                  //*************** Operation 4 : vider le fichier ************
                   f=1; // pour verifier l'etat de fichier
                   fichier=fopen("information.txt","w") ;

                    fclose(fichier);
                  printf("\nL'operation est bien effectue *_*\n");
                           break ;
                }

       default :
               {
                 printf("\nLe choix que vous avez entré est incorrect!!\n");
                 break ;
               }
      }
  }

void interface()
  {
    printf("***********************************\n\n");
    printf(" \tListe des gestions :\n\n");
    printf("***********************************\n\n");
        printf("   1-Ajouter un employee au fichier .\n\n");
        printf("   2-Afficher les empolyes .\n\n");
        printf("   3-Rechercher un empolye.\n\n");
        printf("   4-Initialiser le fichier.\n\n");
        printf("   5-Quitter\n\n");

  }
int main()
 {

   int choix ;
   int d=0 ;
   char rep[5] ;
   while(d!=1){
    interface() ;

    printf("=> Tapez le numero d'operation qui vous voulez :\t");
        scanf("%d",&choix) ;

        runOperation(choix) ;
        printf("\n Retour au menu ?O/N\n");
        scanf("%s",&rep) ;
        if((strcmp(rep,"O")==0)||(strcmp(rep,"o")==0)) d =0;
        else d=1 ;

}
 }
