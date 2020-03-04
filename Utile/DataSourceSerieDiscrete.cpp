/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Calcul de Statistiques                     */
/*Labo : Premier labo                                      */
/*Date de la dernière mise à jour : 10/02/2020             */
/***********************************************************/

#include "DataSourceSerieDiscrete.h"


/********************************/
/*                              */
/*         Constructeurs        */			
/*                              */
/********************************/
		
//Constructeur d'initialisation
DataSourceSerieDiscrete::DataSourceSerieDiscrete(char * nomFichier, int colonne)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur d'initialisation");
	#endif
	
	InitDonnees(nomFichier, colonne);
	
	
}	
		
			
/********************************/
/*                              */
/*          Destructeurs        */			
/*                              */
/********************************/

DataSourceSerieDiscrete::~DataSourceSerieDiscrete()
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

Liste<Data1D>* DataSourceSerieDiscrete::getL()
{
	return L;
}
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

void DataSourceSerieDiscrete::InitDonnees(char *nomFichier, int colonne)
{	
	int cpt;
	char *pch;
	char Tampon[50];
	ListeTriee<float> listeT;
	Iterateur<float> it(listeT);
	
	DataSource::InitDonnees(nomFichier, colonne);
	
	std::string Tampon1; //variable string pour le getline()
	
	ifstream fichier(nomFichier, ios::in); //ouverture du fichier
		
	std::getline(fichier, Tampon1);	 //avoir la ligne avec le nom
	
	std::getline(fichier, Tampon1);	//avoir la ligne des sujets

	std::getline(fichier, Tampon1); //avoir la ligne des types

  	
	while(std::getline(fichier, Tampon1))  //avoir les ligne de valeur
	{
		cpt = 1;
		strcpy(Tampon, Tampon1.c_str()); //copie de string dans char
		pch = strtok(Tampon, ":");
		while (cpt != colonne)
 		{
    		pch = strtok (NULL, ":");
    		cpt++;
  		}
		listeT.insere(atof(pch));
	}
	
	fichier.close();
	
	setEffTotal(listeT.Size());
	
	L = new Liste<Data1D>;
	it.reset();
	setMin((float)it);
	
	for(int i = 0; i < (getEffTotal()-1) ; i++) //aller en fin de liste
	{
		it++;
	}
	setMax((float)it);
	
	it.reset();
	while(!it.end())
	{
		int i = 1;
		Data1D data;
		data.setVal((float)it);
		data.setEff(i);
		it++;

		while(!it.end()  && (float)it == data.getVal())
		{
			i++;
			data.setEff(i);
			it++;
		}
		L->insere(data);			
	}

}	

void DataSourceSerieDiscrete::Affiche()
{
	Iterateur<Data1D> it(*L);

	cout << "Valeur\t\tEffectif" << endl;
	
	while(!it.end())
	{
		cout << it.getpCur()->valeur.getVal() << "\t\t" << it.getpCur()->valeur.getEff() << endl;
		it++;
	}
}





