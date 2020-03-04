/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Calcul de Statistiques                     */
/*Labo : Premier labo                                      */
/*Date de la dernière mise à jour : 10/02/2020             */
/***********************************************************/

#include "DataSourceSerie2D.h"


/********************************/
/*                              */
/*         Constructeurs        */			
/*                              */
/********************************/
		
//Constructeur d'initialisation
DataSourceSerie2D::DataSourceSerie2D(char *nomFichier, int colonne1, int colonne2)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur d'initialisation");
	#endif

	InitDonnees(nomFichier, colonne1, colonne2);
}	
		
			
/********************************/
/*                              */
/*          Destructeurs        */			
/*                              */
/********************************/

DataSourceSerie2D::~DataSourceSerie2D()
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

Liste<Data2D>* DataSourceSerie2D::getL()
{
	return L;
}

const char* DataSourceSerie2D::getSujet2() const
{
	return Sujet2;
}


int DataSourceSerie2D::getType2() const
{
	return Type2;
}

/********************************/
/*                              */
/*            Setters           */			
/*                              */
/********************************/

void DataSourceSerie2D::setL(Liste<Data2D>* LTmp)
{
	L = LTmp;
}

void DataSourceSerie2D::setSujet2(const char* Sujet2Tmp)
{
	if(Sujet2)
		delete Sujet2;
		
	if(Sujet2Tmp != 0)
	{	
		Sujet2 = new char[strlen(Sujet2Tmp)+1];
		strcpy(Sujet2,Sujet2Tmp);
	}
	else
		Sujet2 = NULL;
}


void DataSourceSerie2D::setType2(int Type2Tmp)
{
	Type2 = Type2Tmp;
}
			
/********************************/
/*                              */
/*            Methodes          */			
/*                              */
/********************************/

void DataSourceSerie2D::InitDonnees(char *nomFichier, int colonne1, int colonne2)
{
	int cpt;
	char *pch;
	char Tampon[50];
	Data2D data;
	L = new Liste<Data2D>;
	DataSource::InitDonnees(nomFichier, colonne1);
	
	std::string Tampon1; //variable string pour le getline()
	
	ifstream fichier(nomFichier, ios::in); //ouverture du fichier
	
	std::getline(fichier, Tampon1);	 //avoir la ligne avec le nom
	
	std::getline(fichier, Tampon1);	//avoir la ligne des sujets	
	strcpy(Tampon, Tampon1.c_str()); //Copie de string dans char
	cpt = 1;
	pch = strtok(Tampon, ":");
	while (cpt != colonne2)
 	{
    	pch = strtok (NULL, ":");
    	cpt++;
  	}
    setSujet2(pch);

    std::getline(fichier, Tampon1); //Avoir la ligne des types
	strcpy(Tampon, Tampon1.c_str()); //Copie de string dans char
	cpt = 1;
	pch = strtok(Tampon, ":");
	while (cpt != colonne2)
 	{
    	pch = strtok (NULL, ":");
    	cpt++;
  	}
  	
  	if(*pch == 'D')
		setType2(1);
	else
		setType2(2);
	
	while(std::getline(fichier, Tampon1))  //avoir les ligne de valeur
	{
		cpt = 1;
		strcpy(Tampon, Tampon1.c_str()); //Copie de string dans char
		pch = strtok(Tampon, ":");
		while (cpt != colonne1 && cpt != colonne2) //boucle pour avoir la première valeur
 		{
    		pch = strtok (NULL, ":");
    		cpt++;
  		}
  		
  		if(cpt == colonne1)
			data.setVal1(atof(pch));
		else
			data.setVal2(atof(pch));
		
		pch = strtok (NULL, ":");
		cpt++;
		
		while (cpt != colonne1 && cpt != colonne2) //boucle pour avoir la seconde valeur
 		{
    		pch = strtok (NULL, ":");
    		cpt++;
  		}
  		
  		if(cpt == colonne1)
			data.setVal1(atof(pch));
		else
			data.setVal2(atof(pch));
			
		L->insere(data);
	}

	fichier.close();	
	
	setEffTotal(L->Size());
}

void DataSourceSerie2D::Affiche()
{
	Iterateur<Data2D> it(*L);

	while(!it.end())
	{
		cout << "\t" << it.getpCur()->valeur.getVal1() << " - " << it.getpCur()->valeur.getVal2() << endl;
		it++;
	}
}













