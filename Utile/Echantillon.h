/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Calcul de Statistiques                     */
/*Labo : Premier labo                                      */
/*Date de la dernière mise à jour : 10/02/2020             */
/***********************************************************/

#ifndef ECHANTILLON_H
#define ECHANTILLON_H

#include <iostream>
#include <fstream>
#include "Ecran.h"
#include "DataSource.h"
#include "BaseException.h"
#include "DataSourceSerieDiscrete.h"
#include "DataSourceSerieContinue.h"
#include "DataSourceSerie2D.h"

using namespace std;

class Echantillon
{	
		
	private:
		DataSource* Source;
		
	public:
		//constructeurs
		Echantillon(char *nomFichier, int colonne);
		Echantillon(char *nomFichier, int colonne1, int colonne2);

		//destructeur
		~Echantillon();
				
		//getters
		DataSource* getSource() const;
		
		//setters
		void setSource(DataSource *SourceTmp);
		
		//methodes
		char LectureType(const char *nomFichier, int colonne);
		void VerifColonnes2D(const char *nomFichier, int colonne1, int colonne2);

};

#endif //ECHANTILLON_H
