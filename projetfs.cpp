#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max 50
   typedef struct {
   	int jour;
   	int mois;
   	int ann;
   }DateEcheance;
   typedef struct tache{
   	char titre[100];
   	char description[100];
    int priorite; // plus importante ou moins
    DateEcheance date;
   }Tache; 
   int taille=0;
   Tache T[50]; //Tableau des taches
   int nbretache=0;
   int high;
   int low;
   //Ajout des taches
   void Ajoutertache(){
   printf("Entrer le titre :\n ");
   scanf("%s",T[taille].titre);
   printf("Entrer la discription :\n");
   scanf("%s",T[taille].description);
   printf("Entrer la date d'echeance  :\n");
   scanf("%d %d %d",&T[taille].date.jour,&T[taille].date.mois,&T[taille].date.ann);
   int choix; 
   printf("Entrer la priorite(1:pour high et 2:pour low): \n");
//   	scanf("%d",&T[nbretache].priorite);
   do{
   	   printf("Entrer votre choix: \n");
   	   scanf("%d",&choix);
   		//printf("Priorite: %d\n", (T[nbretache].priorite==  1) ?"high":"low");  //l'operateur ternaire
  			 	if (choix== 1) {
  			 		T[taille].priorite=1;
                      printf("Priorité: high\n");
                } else if(choix== 2) {
                	T[taille].priorite=2;
                           printf("Priorité: low\n");
                     }else printf("priorite inconnue");

//   	   switch(choix){
//   	case 1:strcpy(T[taille].priorite,"high");break; 
//   	case 2:strcpy(T[taille].priorite,"low");break;
//   	default : printf("choix introuvable ");      
//   }
   }while(choix!=1 && choix!=2);
     taille++;
   if(nbretache>=50){
   printf("Erreur: ");// limite de taches atteinte
   }
}
// Affichage des taches 
   void AfficherlisteTaches(){
   	printf("\n______Liste des taches______\n");
   	int i;
   	for(i=0;i<taille;i++){
   		printf("Titre: %s\n ",T[i].titre);
   		printf("Description: %s \n",T[i].description);
   		//printf("Priorite: %d\n",T[nbretache].priorite);
   		//	printf("Priorite: %d\n", T[nbretache].priorite ==1?"high":"low");  //l'operateur ternaire
   			//printf("%d\n",T[nbretache].priorite);
   			if(T[i].priorite==1){
   				printf(" Tache importante\n");
			   }else printf(" Tache normale \n");
   			
   		printf("date d'echeance: %d/ %d/ %d",T[i].date.jour,T[i].date.mois,T[i].date.ann);
	   }
   }
   // Modifier les taches
   void ModifierTache(){
   	int nbreTaches;
   	int choix;
   if(nbreTaches>0){
   	int numeroTache;
   	printf("Donner le numero de tache a modifier\n");
   	scanf("%d",&numeroTache);
   	if(numeroTache>0 && numeroTache<=nbreTaches){
   	Tache* modifierTache=&T[numeroTache - 1];
   	printf("Entrer un nouveau titre\n ");
   	scanf("%s",modifierTache->titre);
   	 
   	 printf("Entrer une nouvelle description \n");
   	 scanf("%s",modifierTache->description);
   	 
   	 printf("Entrer une  nouvelle date d'acheance(sous la forme j/m/ann)\n");
   	 scanf("%d/%d/%d",&modifierTache->date.jour,&modifierTache->date.mois,&modifierTache->date.ann);
   	 
    	printf("Entrer une nouvelle priorite(1:pour high et 2:pour low): \n");
    printf("Entrer une nouvelle priorité (1 pour HIGH, 2 pour LOW):\n");
    do {
        scanf("%d", &choix);
        if (choix == high || choix == low) {
            modifierTache->priorite == choix;
        } else {
            printf("Choix introuvable, veuillez reessayer.\n");
        }
    } while (choix != high && choix != low);
//   	scanf("%d",(int*)&modifierTache->priorite); 
//   	
   	printf("Tache modifier avec succes ^-^");
   }else printf("Aucune Tache a modifier ");
}else printf("Aucune Tache a modifier");
}
void SupprimerTache(){
	AfficherlisteTaches();
	int nbreTaches;
    // Verifiez que le nombre de taches est > 0
	  	int   numeroTache;
	if(nbreTaches>0){
		int i;
		printf("\nEntrer le numero de la tache a supprimer  \n");
		scanf("%d",&numeroTache);
		 // Verifiez que le numero de tache est valide
		if(numeroTache>0 && numeroTache<=nbreTaches){
			// Deplacer les taches suivantes pour combler l'espace
			for(i=numeroTache-1; i<nbreTaches-1; i++){
				T[i]=T[i+1];
			}
			nbreTaches--;  // Reduire le compteur de taches
			printf(" Tache  supprime avec succes^-^");
		}else printf("Numero de Tache invalide.");
	}else printf("Aucune tache a supprimer ");
}
void TriCroissante() {
	AfficherlisteTaches();
	int temp, nbreTaches;
    int i, j;
    if (nbreTaches > 0) {
        for (i = 0; i < nbreTaches ; i++) {
            for (j = i + 1; j < nbreTaches; j++) {
                if (T[i].date.ann > T[j].date.ann ||
                    (T[i].date.ann == T[j].date.ann &&
                     (T[i].date.mois > T[j].date.mois ||
                      (T[i].date.mois == T[j].date.mois &&
                       T[i].date.jour > T[j].date.jour))))
					    {
                    Tache temp = T[i];
                    T[i] = T[j];
                    T[j] = temp; }
            }
        }
        printf("Taches ordonnees par date croissante!\n");
    } else {
        printf("Aucune tache a ordonner!\n"); 
    }
}
      //filtrer les tache par priorite 
     void FiltrerTache(){
     	AfficherlisteTaches();
     	int priorite, nbreTaches;
     	int i;
     	printf("Filtrer  par priorite \n");
     	scanf("%d",&priorite);
     	printf("\n-----liste des tache filtrees-----");
     	for(i=0;i<nbreTaches;i++){
     		Tache T[i];
     		if(T[i].priorite==priorite){
     			printf("Tache %d",i+1);
     			printf("Titre: %s\n",T[i].titre);
     			printf("Description: %s\n",T[i].description);
     			printf("Date d'echeance:%d/%d/%d \n",T[i].date.jour,T[i].date.mois,T[i].date.ann);
     			printf("Priorite: %d\n",(T[nbreTaches].priorite ==high) ?"high":"low");  //l'operateur ternaire
//			 	if (T.priorite== high) {
//                        printf("Priorité: high\n");
//                        } else {
//                                 printf("Priorité: low\n");
//                     }
//switch(T[i].priorite){
//	case 1: 
//	printf("la priorite est importante"); break;
//	case 2: 
//	printf("la priorite est normale"); break;
//default :
//	printf("priorite inconnue");
}
                        printf("\n--------------------------------\n");
						}
			 }
//		 }
//	 }
//   nouvelleTache.id=nbretache+1;
//   printf("Titre :",max_titre-1);
//   scanf("%s",nouvelleTache.titre);
//      printf("Discription :",max_discr-1);
//   scanf("%s",nouvelleTache.discr);
//      printf("Date dateEcheance (jj/mm/ann):",max_-1);
//   scanf("%s",nouvelleTache.dateEcheance);
//   printf("Priorite:(plus ou moins important)");
//   scanf("%s",nouvelletache.priorite);
   
int main(){
	int choix;
	int tache;
	//Menu//
	do{
	printf("\n    Menu    \n");
	printf("1: Ajouter \n");
		printf("2: Afficher \n");
			printf("3: Modifier \n");
				printf("4: Supprimer \n");
					printf("5: Filtrer les taches par prioriter \n");// 
					printf("6: Quitter \n");
						printf("tapez votre choix: \n");
						scanf("%d",&choix);
				switch(choix){
					case 1:Ajoutertache(); break;
					case 2:AfficherlisteTaches(); break;
					case 3:ModifierTache(); 	 break;
				//	printf("Entrer la tache a modifier \n");
					//scanf("%d",&Tache);
				//	ModifierTache();
                     case 4:SupprimerTache(); 	 break;
//					printf("Entrer la tache a supprimer \n");
//					scanf("%d",&tache);
					case 5: FiltrerTache();break;
//					Supprimer(tache); break;
                    case 6:  TriCroissante() ; break;
					case 7:
						printf("Au revoir! \n"); break;
				    default : printf("choix introuvable,veuillez reessayer ^-^");
				}
	}while(choix!=7);
return 0;	
}
