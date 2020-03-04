/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Calcul de Statistiques                     */
/*Labo : Premier labo                                      */
/*Date de la dernière mise à jour : 10/02/2020             */
/***********************************************************/

#ifndef DATASOURCESERIE2D_H
#define DATASOURCESERIE2D_H

#include <iostream>
#include "Ecran.h"
#include "DataSource.h"
#include "Liste.h"
#include "ListeTriee.h"
#include "Data2D.h"
#include "Iterateur.h"

using namespace std;

class DataSourceSerie2D : public DataSource
{	

		
	private:
		Liste<Data2D>	*L;
		char			*Sujet2;
		int				Type2;
		
	public:
		//constructeurs
		DataSourceSerie2D(char *nomFichier, int colonne1, int colonne2);

		//destructeur
		~DataSourceSerie2D();
				
		//getters
		Liste<Data2D>* getL();
		const char* getSujet2() const;
		int getType2() const;
		
		//setters
		void setL(Liste<Data2D>* LTmp);
		void setSujet2(const char* Sujet2Tmp);
		void setType2(int Type2Tmp);
		
		//methodes
		void InitDonnees(char *nomFichier, int colonne1, int colonne2);
		void Affiche();


};

#endif //DATASOURCESERIE2D_H
