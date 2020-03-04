/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Calcul de Statistiques                     */
/*Labo : Premier labo                                      */
/*Date de la dernière mise à jour : 10/02/2020             */
/***********************************************************/

#ifndef DATASOURCESERIEDISCRETE_H
#define DATASOURCESERIEDISCRETE_H

#include <iostream>
#include <fstream>
#include "Ecran.h"
#include "DataSource.h"
#include "BaseException.h"
#include "Liste.h"
#include "ListeTriee.h"
#include "Iterateur.h"
#include "Data1D.h"

using namespace std;

class DataSourceSerieDiscrete : public DataSource
{	
		
	private:
		Liste<Data1D>* L;
		
	public:
		//constructeurs
		DataSourceSerieDiscrete(char *nomFichier, int colonne);

		//destructeur
		~DataSourceSerieDiscrete();
				
		//getters
		Liste<Data1D>* getL();
		//setters

		//methodes
		void InitDonnees(char *nomFichier, int colonne);
		void Affiche();


};

#endif //DATASOURCESERIEDISCRETE_H
