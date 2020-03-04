/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Calcul de Statistiques                     */
/*Labo : Premier labo                                      */
/*Date de la dernière mise à jour : 10/02/2020             */
/***********************************************************/

#include "DataSource.h"


/********************************/
/*                              */
/*         Constructeurs        */			
/*                              */
/********************************/
		
//Constructeur par défaut
DataSource::DataSource(void)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur par défaut");
	#endif
	Nom = NULL;
	Sujet = NULL;
}	
		
			
/********************************/
/*                              */
/*          Destructeurs        */			
/*                              */
/********************************/

DataSource::~DataSource()
{
	#ifdef DEBUG
	TraceConstructeur("Appel au destructeur");
	#endif
	
	if(Nom)
	{
		delete Nom;
	}
	
	if(Sujet)
	{
		delete Sujet;
	}

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

const char* DataSource::getNom() const
{
	return Nom;
}

const char* DataSource::getSujet() const
{
	return Sujet;
}

int DataSource::getEffTotal() const
{
	return EffTotal;
}

int DataSource::getType() const
{
	return Type;
}

float DataSource::getMin() const
{
	return EffMin;
}

float DataSource::getMax() const
{
	return EffMax;
}

/********************************/
/*                              */
/*            Setters           */			
/*                              */
/********************************/

void DataSource::setNom(const char* NomTmp)
{
	if(Nom)
		delete Nom;
		
	if(NomTmp != 0)
	{	
		Nom = new char[strlen(NomTmp)+1];
		strcpy(Nom,NomTmp);
	}
	else
		Nom = NULL;
}

void DataSource::setSujet(const char* SujetTmp)
{
	if(Sujet)
		delete Sujet;
		
	if(SujetTmp != 0)
	{	
		Sujet = new char[strlen(SujetTmp)+1];
		strcpy(Sujet,SujetTmp);
	}
	else
		Sujet = NULL;
}

void DataSource::setEffTotal(int EffTotalTmp)
{
	EffTotal = EffTotalTmp;
}

void DataSource::setType(int TypeTmp)
{
	Type = TypeTmp;
}

void DataSource::setMin(float MinTmp)
{
	EffMin = MinTmp;
}

void DataSource::setMax(float MaxTmp)
{
	EffMax = MaxTmp;
}
			
/********************************/
/*                              */
/*            Methodes          */			
/*                              */
/********************************/

void DataSource::InitDonnees(char *nomFichier, int colonne)
{
	int cpt = 1;
	char *pch;
	char Tampon[150];
	
	std::string Tampon1; //variable string pour le getline()
	
	ifstream fichier(nomFichier, ios::in); //ouverture du fichier
		
	std::getline(fichier, Tampon1);	 //avoir la ligne avec le nom
	strcpy(Tampon, Tampon1.c_str()); //Copie de string dans char
	setNom(Tampon);
	
	std::getline(fichier, Tampon1);	//avoir la ligne des sujets
	strcpy(Tampon, Tampon1.c_str()); //Copie de string dans char
	pch = strtok(Tampon, ":");
	while (cpt != colonne)
 	{
    	pch = strtok (NULL, ":");
    	cpt++;
  	}
    setSujet(pch);
	
	std::getline(fichier, Tampon1); //Avoir la ligne des types
	strcpy(Tampon, Tampon1.c_str()); //Copie de string dans char
	
	cpt = 1;
	pch = strtok(Tampon, ":");
	while (cpt != colonne)
 	{
    	pch = strtok (NULL, ":");
    	cpt++;
  	}
  	
  	if(*pch == 'D')
		setType(1);
	else
		setType(2);
		
	fichier.close();
}







