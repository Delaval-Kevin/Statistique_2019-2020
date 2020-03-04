/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Calcul de Statistiques                     */
/*Labo : Premier labo                                      */
/*Date de la dernière mise à jour : 10/02/2020             */
/***********************************************************/

#ifndef ETUDESTAT2D_H
#define ETUDESTAT2D_H

#include <iostream>
#include <math.h>
#include <QApplication>
#include "Ecran.h"
#include "Liste.h"
#include "ListeTriee.h"
#include "Iterateur.h"
#include "BaseException.h"
#include "DataSource.h"
#include "Echantillon.h"
#include "DataSourceSerie2D.h"
#include "Data2D.h"
#include "graphstat2d.h"

using namespace std;

extern QApplication* a;

class EtudeStat2D
{			
	private:
		//variables membres
		Echantillon	*E;
		float		MoyenneVal1;
		float		MoyenneVal2;
		float		CoeffA;
		float		CoeffB;
		float		CoeffCorrelation;
		
		//setters
		void setMoyenneVal1(float MoyenneVal1Tmp);
		void setMoyenneVal2(float MoyenneVal2Tmp);
		void setCoeffA(float CoeffATmp);
		void setCoeffB(float CoeffBTmp);
		void setCoeffCorrelation(float CoeffCorrelationTmp);
				
	public:
		//constructeurs
		EtudeStat2D(char *nomFichier, int colonne1, int colonne2);

		//destructeur
		~EtudeStat2D();
				
		//getters
		Echantillon* getE() const;
		float getMoyenneVal1() const;
		float getMoyenneVal2() const;
		float getCoeffA() const;
		float getCoeffB() const;
		float getCoeffCorrelation() const;
				
		//methodes
		void AfficheRapport();
		void ChoixPrediction();
		void PrevSujet(int choix);
		void CalculMoyenneVal1();
		void CalculMoyenneVal2();
		void CalculCoeffA();
		void CalculCoeffB();
		void CalculCoeffCorrelation();
		void CalculAll();
		float EqDroiteY(float valeur);
		float EqDroiteX(float valeur);
};

#endif //ETUDESTAT2D_H
