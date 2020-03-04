/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Calcul de Statistiques                     */
/*Labo : Premier labo                                      */
/*Date de la dernière mise à jour : 10/02/2020             */
/***********************************************************/

#include "EtudeStatDescriptive.h"


/********************************/
/*                              */
/*         Constructeurs        */			
/*                              */
/********************************/
		
//Constructeur d'initialisation
EtudeStatDescriptive::EtudeStatDescriptive(int argc, char*argv[])
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur d'initialisation");
	#endif
	
	if (argc == 2)
		EtudeStat1D E(argv[1],1);	//reçois en paramètre le nom du fichier 
	else if (argc == 3)				//et la colonne par défaut (la première)
		EtudeStat1D E(argv[1],atoi(argv[2]));	//reçois en paramètre le nom du fichier 
	else if (argc == 4)							//et la colonne choisie par l'utilisateur
		EtudeStat2D E(argv[1],atoi(argv[2]),atoi(argv[3]));	//reçois en paramètre le nom du fichier 
	else													//et les colonnes choisies par l'utilisateur
		throw BaseException("mauvais parametres");
}		
			
/********************************/
/*                              */
/*          Destructeurs        */			
/*                              */
/********************************/

EtudeStatDescriptive::~EtudeStatDescriptive()
{
	#ifdef DEBUG
	TraceConstructeur("Appel au destructeur");
	#endif

}

/********************************/
/*                              */
/*           Operators          */			
/*                              */
/********************************/

/********************************/
/*                              */
/*            Getters           */			
/*                              */
/********************************/

/********************************/
/*                              */
/*            Setters           */			
/*                              */
/********************************/
			
/********************************/
/*                              */
/*            Methodes          */			
/*                              */
/********************************/
