#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


 //-----------------------------------------------------------------//
 //----------------Done By oussama el maimouni d([*_*])b----------------//
 //-----------------------------------------------------------------//


//              ++++++++     beginning of fonctions     ++++++++

//*****************************************************************************
typedef struct employe
  {
      char nom[10];
      char prenom[10] ; // c'est un type sous forme d'une structure contient les information des empoloyees ;
      float salaire ;

  } employe ;
//*****************************************************************************
                 // c'est notre liste ;
//*****************************************************************************
typedef struct Boite
  {
     employe data ;
     struct  Boite * suivant ;
  } Boite ;
//*****************************************************************************
             // c'est la fonction d'ajoute un employee ;

//*****************************************************************************

Boite * ajouterALaFin (Boite * start,employe elm) //start c'est le start de la liste ;
 {
      Boite *cellule ,*temp ;    // deux pointure pour parcourir le traitment dans le tableau ...;
      cellule=(Boite*)malloc(sizeof(Boite));
      cellule->data=elm ;
      cellule->suivant =NULL;
      if(start==NULL)
       start=cellule;
      else
    {
         temp=start ;
       while(temp->suivant!=NULL)
         temp=temp->suivant;
         temp->suivant=cellule ;
    }
       return start;
  }
  //*****************************************************************************
               // c'est la fonction d'ajoute un employee au fichier ;

  //*****************************************************************************

   void ajouterAuFichier(employe elm)
    {

      FILE *fichier =NULL ;
      fichier = fopen("Employes.txt","w") ; // les informations sera stockés dans le fichier Employes.txt


      if(fichier==NULL){printf("ce fichier n'existe pas\n") ;}
     else {

           fprintf(fichier,"\n\nLes information d'empolyee  - %s - sont :\n",elm.nom) ;
           fprintf(fichier,"\nLe nom  est    : %s\n",elm.nom);
           fprintf(fichier,"\nLe Prenom  est : %s\n",elm.prenom);
           fprintf(fichier,"\nLe salaire  est : %.2f DH\n",elm.salaire);
           printf(fichier,"\n\n");

           fclose(fichier);

          }

    }

//*****************************************************************************
   // la fonction qui permet de retourner au menu
//*****************************************************************************


int reponseRtr()
 {
      char  r[7];
    printf("\nRetour au menu? (oui/non) :\t") ;
      scanf("%s",&r );
    if(strcmp(r, "oui") ==0 || strcmp(r, "OUI") ==0)//c'est une fonction prédéfini de Comparaison de deux mots
       return 1;
    else
       return 0;
 }
 //*****************************************************************************
    // la fonction qui permet d'affiche les elements de liste
 //*****************************************************************************

void afficherListe(Boite * start )
 {
     Boite * temp ;
     temp =start ;
     int i=0 ;
   if(start==NULL)
 printf("la liste est vide!\n") ;
  else
    {
                 // c'est la fonction d'affichage des information des employees ;
       while(temp!=NULL) // Tant que le pointeur n'a pas atteint la fin de la liste  alors fairee
         {


            //afficher les informations des employés enregistré dans la liste
        printf("\nle Nom  d'empolyee Num %d est : %s   \n ",i+1,temp->data.nom    );
        printf("\nle prenom d'empolyee Num %d est : %s \n ",i+1,temp->data.prenom );
        printf("\nle salaire d'empolyee Num %d est : %.2f DH\n ",i+1,temp->data.salaire);

        temp=temp->suivant; // incrémentation de pointure ;


         printf("\n\n\n") ;
            i++ ;
         }

  }
}

//*****************************************************************************
                //c'est la fonction qui effectuer le choix

//*****************************************************************************
void faire(int choix,Boite * li)
  {
       switch(choix) // c'est le choix ;
    {

     case 1 :
         {
                //operation 1 : Ajoute d'un employe ;
            int i ,nbr;

            printf("\n============= Ajoute d'un employe =============\n\n") ;
            printf("Donner le nombre des elements :\t");
                     scanf("%d",&nbr);
                 employe personne[nbr] ;

          for(i=0;i<nbr;i++)
        {
           printf("\nEntrer le Nom d'employee num %d       :\t",i+1) ;
                 scanf("%s",(personne[i].nom)) ;
           printf("\nEntrer le prenom d'employee num %d    :\t",i+1) ;
                 scanf("%s",(personne[i].prenom)) ;
           printf("\nEntrer le salaire d'employee num %d   :\t",i+1) ;
                 scanf("%f",&(personne[i].salaire)) ;

               ajouterAuFichier(personne[i]);   // ajouter au fichier

                 li = ajouterALaFin(li,personne[i]) ;

       }
                   printf("\nDone!\n");
          if(reponseRtr()==1){interfaceChoix(li);}
                       break ;

         }

     case 2 :
       {
                //operation 2 : affiche des employees ;
          printf("\n============= affiche d'un employe =============\n\n") ;
                    afficherListe(li); //fonction d'affichage ;
                    printf("\nDone!\n");

              if(reponseRtr()==1){interfaceChoix(li);} //pour Quitter ou retour au menu;
                        break;

       }
     case 3 :
       {
          //operation 3 : rechercher un employees par le nom et affiche les caracteristiques ;
             char cherche[10];
            printf("\nEntrer le nom a rechercher : \t") ;
                      scanf("%s",cherche);

              if(rechercher(li,cherche)==0 )
               {
                  printf("\nAucune information trouve sur le nom que vous entre !\n");
               }
             else
                 {printf("\n\n");}

                  printf("\nDone!\n");
              if(reponseRtr()==1){interfaceChoix(li);}
                           break ;

        }
     case 5 :
       {
         //operation 5 : Quitter le console ;
           system("CLS");
              exit(0);
               break ;
       }
     case 4 :
       {
         //operation 4 : initialiser la liste e à la liste vide ;
            char rp[7] ;
          if(li==NULL)
            {
              printf("\nLa liste est deja vide !! \n\n");
                 if(reponseRtr()==1){interfaceChoix(li);}
            }
           else {
                     printf("\nEtes-vous sur de vouloir vider la liste ? (oui/non) :\t ") ;
                                 scanf("%s",rp) ;
                     if(strcmp(rp, "oui") ==0 || strcmp(rp, "OUI") ==0)
                                li =NULL ;
                     else printf("\nOK !\n" );
                                  printf("\nDone!\n");
                     if(reponseRtr()==1){interfaceChoix(li);}
                                  break ;
                 }

         }
     default :
       {
         // le message sera affiché au cas de le choix choisi n'existe pas ;
           printf("\nChoix incorrecte d(*_*)b\n");
         if(reponseRtr()==1)
           {interfaceChoix(li);}
       }
    }
  }

  //*****************************************************************************
      // c'est la fonction qui prend le choix est afficter a la fonction "faire()"

  //*****************************************************************************

void valeur(Boite *li )
  {
     int choix          ;       //c'est le choix ;
     scanf("%d",&choix) ;   //saisie au clavier
     faire(choix,li)     ;  //affictation de choix a la fonction qui lance l'operation demandé ;
  }

  //*****************************************************************************
      // c'est la fonction qui contient les operations disponibles ;

  //*****************************************************************************

void interfaceChoix(Boite * li)
   {
       printf("\n\n");
              printf("***************************************\n\n");
            printf("   ++ Gestion De Liste ++\n\n");
printf("***************************************\n");
       printf("\n");



       printf("   1)- Ajouter un employe    \n\n");
       printf("   2)- Afficher la liste     \n\n");  // interface de menu ;
       printf("   3)- Rechercher un employe \n\n");
       printf("   4)- initialiser la liste  \n\n");
       printf("   5)- Quitter             \n\n\n");
       printf("--> Veuillez choisir une operation a fairee :\t") ;
    valeur(li);  // affecter la liste sur lequel on travaille a la fonction "valeur()";

   }

//*****************************************************************************
    // c'est la fonction qui cherche un employe dans la liste par le nom ;

//*****************************************************************************


int rechercher(Boite *t, char nomModule[10]){
   Boite *ptr = t;

   while(ptr != NULL)
    {

      if(strcmp(ptr->data.nom, nomModule)==0)
        {
          printf("\nLes caracteristiques de  * %s * sont : Nom : %s | Prenom : %s | salaire : %.2f DH\n",nomModule,ptr->data.nom,ptr->data.prenom,ptr->data.salaire) ;
                              return 1  ;
                              ptr =NULL ;
        }
     else
                        ptr = ptr->suivant ;
   }
                              return 0 ;
}


//              ++++++++     end of fonctions     ++++++++


int main()
 {
             system("color 02"); // pour changer le couleur de CMD en verte ;

     Boite * li=NULL ;  //declaration d'un fonction et l'intialiser par "NULL" ;

    interfaceChoix(li); // affichage de menu (toutes les opérations viendront via cette fonction ) ;

    /*
      Remarque >>> j'ai travailler par une methode d'inserer une fonction dans une autre ;
                      pour ca j'ai declaré une seul fonction dans la main
   */


 }
