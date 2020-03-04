/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Calcul de Statistiques                     */
/*Labo : Premier labo                                      */
/*Date de la dernière mise à jour : 10/02/2020             */
/***********************************************************/

#ifndef DATASOURCESERIECONTINUE_H
#define DATASOURCESERIECONTINUE_H

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

class DataSourceSerieContinue : public DataSource
{	

		
	private:
		Liste<Data1D>*	L;
		float	Debut;
		float	Intervalle;
		
	public:
		//constructeurs
		DataSourceSerieContinue(char * nomFichier, int colonne);

		//destructeur
		~DataSourceSerieContinue();
				
		//getters
		Liste<Data1D>* getL();
		float getDebut() const;
		float getIntervalle() const;
		
		//setters
		void setDebut(float DebutTmp);
		void setIntervalle(float IntervalleTmp);
		
		//methodes
		void InitDonnees(char *nomFichier, int colonne);
		void InitValeurs();
		void Affiche();


};

#endif //DATASOURCESERIECONTINUE_H
