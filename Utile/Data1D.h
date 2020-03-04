/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Calcul de Statistiques                     */
/*Labo : Premier labo                                      */
/*Date de la dernière mise à jour : 10/02/2020             */
/***********************************************************/

#ifndef DATA1D_H
#define DATA1D_H

#include <iostream>
#include "Ecran.h"

using namespace std;

class Data1D
{	
	//fonctions amies
	friend ostream& operator<<(ostream& s, const Data1D& d);
		
	private:
		float	Val;
		int		Eff;
		
	public:
		//constructeurs
		Data1D(void);
		Data1D(float ValTmp, int EffTmp);
		Data1D(const Data1D& D);

		//destructeur
		~Data1D();
				
		//getters
		float getVal() const;
		int getEff() const;
		
		//setters
		void setVal(float ValTmp);
		void setEff(int EffTmp);
		
		//methodes


};

#endif //DATA1D_H
