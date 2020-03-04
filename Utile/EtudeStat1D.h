/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Calcul de Statistiques                     */
/*Labo : Premier labo                                      */
/*Date de la dernière mise à jour : 10/02/2020             */
/***********************************************************/

#ifndef ETUDESTAT1D_H
#define ETUDESTAT1D_H

#include <math.h>
#include <iostream>
#include <QApplication>
#include "Ecran.h"
#include "Liste.h"
#include "Iterateur.h"
#include "Echantillon.h"
#include "Data1D.h"
#include "BaseException.h"
#include "DataSource.h"
#include "DataSourceSerieDiscrete.h"
#include "DataSourceSerieContinue.h"
#include "graphstat1ddiscrete.h"
#include "graphstat1dcontinue.h"

using namespace std;

extern QApplication* a;

class EtudeStat1D
{		
	private:
		//variables membres
		Echantillon	*E;
		float		Moyenne;
		float		EcartType;
		float		Mediane;
		float		Mode[3];
		float		Etendue;
		float		CV;
		
		//setters
		void setMoyenne(float MoyenneTmp);
		void setEcartType(float EcartTypeTmp);
		void setMediane(float MedianeTmp);
		void setMode(float *ModeTmp);
		void setEtendue(float EtendueTmp);
		void setCV(float CVTmp);
		
	public:
		//constructeurs
		EtudeStat1D(char * nomFichier, int colonne);

		//destructeur
		~EtudeStat1D();
				
		//getters
		const Echantillon* getE() const;
		float getMoyenne() const;
		const float* getMode() const;
		float getMediane() const;
		float getEcartType() const;
		float getEtendue() const;
		float getCV() const;
		
		//methodes
		void AfficheRapport();
		void CalculMoyenne();
		void CalculMode();
		void CalculMediane();
		void CalculEcartType();
		void CalculEtendue();
		void CalculCV();
		

};

#endif //ETUDESTAT1D_H






