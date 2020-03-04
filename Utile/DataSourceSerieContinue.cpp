/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Calcul de Statistiques                     */
/*Labo : Premier labo                                      */
/*Date de la dernière mise à jour : 10/02/2020             */
/***********************************************************/

#include "DataSourceSerieContinue.h"


/********************************/
/*                              */
/*         Constructeurs        */			
/*                              */
/********************************/
		
//Constructeur d'initialisation
DataSourceSerieContinue::DataSourceSerieContinue(char * nomFichier, int colonne)
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

DataSourceSerieContinue::~DataSourceSerieContinue()
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

Liste<Data1D>* DataSourceSerieContinue::getL()
{
	return L;
}

float DataSourceSerieContinue::getDebut() const
{
	return Debut;
}

float DataSourceSerieContinue::getIntervalle() const
{
	return Intervalle;
}

/********************************/
/*                              */
/*            Setters           */			
/*                              */
/********************************/

void DataSourceSerieContinue::setDebut(float DebutTmp)
{
	Debut = DebutTmp;
}

void DataSourceSerieContinue::setIntervalle(float IntervalleTmp)
{
	Intervalle = IntervalleTmp;
}
			
/********************************/
/*                              */
/*            Methodes          */			
/*                              */
/********************************/

void DataSourceSerieContinue::InitDonnees(char *nomFichier, int colonne)
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
		strcpy(Tampon, Tampon1.c_str()); //Copie de string dans char
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

	InitValeurs();
	
	it.reset();
	
	float valeur = getDebut();
	
	while(!it.end() && (float)it < valeur) // boucle pour retirer les valeurs trop petites
	{
		it++;
	}
	
	while(!it.end())
	{
		int i = 0;
		Data1D data;
		data.setVal(valeur);
		data.setEff(i);


		while(!it.end()  && (float)it < (valeur + getIntervalle()))
		{
			i++;
			data.setEff(i);
			it++;
		}
		L->insere(data);
		valeur = valeur + getIntervalle();		
	}
}	

void DataSourceSerieContinue::InitValeurs()
{
	float tmp;
	
	cout << "Voici le minimum : " << getMin() << " et le maximum : " << getMax() << endl;
	cout << "Entrez une valeur pour le début : ";
	cin >> tmp;
	setDebut(tmp);
	cout << "Entrez une valeur pour l'intervalle : ";
	cin >> tmp;
	setIntervalle(tmp);
}

void DataSourceSerieContinue::Affiche()
{
	Iterateur<Data1D> it(*L);

	cout << "Valeur\t\tEffectif" << endl;
	
	while(!it.end())
	{
		cout << (it.getpCur()->valeur.getVal() + (getIntervalle()/2)) << "\t\t" << it.getpCur()->valeur.getEff() << endl;
		it++;
	}
}





