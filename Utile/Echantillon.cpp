/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Calcul de Statistiques                     */
/*Labo : Premier labo                                      */
/*Date de la dernière mise à jour : 10/02/2020             */
/***********************************************************/

#include "Echantillon.h"


/********************************/
/*                              */
/*         Constructeurs        */			
/*                              */
/********************************/
		
//Constructeur d'initialisation à 2 parametres
Echantillon::Echantillon(char *nomFichier, int colonne)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur d'initialisation à 2 parametres");
	#endif
	
	char Type;
	
	Type = LectureType(nomFichier, colonne);
	
	if(Type == 'C')
	{
		setSource(new DataSourceSerieContinue(nomFichier, colonne));	
	}
	else if(Type == 'D')
	{
		setSource(new DataSourceSerieDiscrete(nomFichier, colonne));	
	}
	else
	{
		throw BaseException("Type incorrecte !");
	}	
}	

//Constructeur d'initialisation à 3 parametres
Echantillon::Echantillon(char *nomFichier, int colonne1, int colonne2)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur d'initialisation à 3 parametres");
	#endif
	
	VerifColonnes2D(nomFichier, colonne1, colonne2);
	
	setSource(new DataSourceSerie2D(nomFichier, colonne1, colonne2));
}		
			
/********************************/
/*                              */
/*          Destructeurs        */			
/*                              */
/********************************/

Echantillon::~Echantillon()
{
	#ifdef DEBUG
	TraceConstructeur("Appel au destructeur");
	#endif
	
	if(Source)
		delete Source;
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

DataSource* Echantillon::getSource() const
{
	return Source;
}

/********************************/
/*                              */
/*            Setters           */			
/*                              */
/********************************/

void Echantillon::setSource(DataSource *SourceTmp)
{
	Source = SourceTmp;
}
			
/********************************/
/*                              */
/*            Methodes          */			
/*                              */
/********************************/

char Echantillon::LectureType(const char *nomFichier, int colonne)
{
	if(colonne == 0)
		throw BaseException("Colonne incorrecte !");

	int taille;
	int indice;
	char Tampon[150];
	std::string Tampon1; //variable string pour le getline()
	ifstream fichier(nomFichier, ios::in);
	
	if(fichier == NULL)
		throw BaseException("Le fichier n'existe pas !");
		
	std::getline(fichier, Tampon1);	//Pour passer les 2
	std::getline(fichier, Tampon1); //premières lignes
	std::getline(fichier, Tampon1); //Avoir la ligne des types
	
	strcpy(Tampon, Tampon1.c_str()); //Copie de string dans char
	
	fichier.close();
		
	taille = strlen(Tampon);
	
	if(colonne > ((taille+1)/2))
		throw BaseException("Colonne incorrecte !");
		
	indice = (colonne*2)-2; //Permet d'obtenir l'indice du type de la colonne voulue
	
	return Tampon[indice];
}	

void Echantillon::VerifColonnes2D(const char *nomFichier, int colonne1 , int colonne2)
{
	char TypeTmp;	
	
	//test de la colonne 1
	TypeTmp = LectureType(nomFichier, colonne1);
	
	if(TypeTmp != 'C' && TypeTmp != 'D')
		throw BaseException("Type incorrecte !");
		
	//test de la colonne 2
	TypeTmp = LectureType(nomFichier, colonne2);
	
	if(TypeTmp != 'C' && TypeTmp != 'D')
		throw BaseException("Type incorrecte !");	
	
}



