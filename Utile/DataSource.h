/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Calcul de Statistiques                     */
/*Labo : Premier labo                                      */
/*Date de la dernière mise à jour : 10/02/2020             */
/***********************************************************/

#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <iostream>
#include <string.h>
#include <fstream>
#include "Ecran.h"

using namespace std;

class DataSource
{	

	protected:
		char*	Nom;
		char*	Sujet;
		int		EffTotal;
		int		Type;
		float	EffMin;
		float	EffMax;
		
	public:
		//constructeurs
		DataSource(void);
		//DataSoucre();
		
		//destructeur
		virtual ~DataSource();
				
		//operators

		//getters
		const char* getNom() const;
		const char* getSujet() const;
		int getEffTotal() const;
		int getType() const;
		float getMin() const;
		float getMax() const;
		
		//setters
		void setNom(const char* NomTmp);
		void setSujet(const char* SujetTmp);
		void setEffTotal(int EffTotalTmp);
		void setType(int TypeTmp);
		void setMin(float MinTmp);
		void setMax(float MaxTmp);		
		
		//methodes
		virtual void InitDonnees(char *nomFichier, int colonne);

};

#endif //DATASOURCE_H
