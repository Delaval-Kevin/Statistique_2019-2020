/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Calcul de Statistiques                     */
/*Labo : Premier labo                                      */
/*Date de la dernière mise à jour : 10/02/2020             */
/***********************************************************/

#ifndef DATA2D_H
#define DATA2D_H

#include <iostream>
#include "Ecran.h"

using namespace std;

class Data2D
{	
	//fonctions amies
	friend ostream& operator<<(ostream& s, const Data2D& d);
		
	private:
		float	Val1;
		float	Val2;
		
	public:
		//constructeurs
		Data2D(void);
		Data2D(float Val1Tmp, float Val2Tmp);
		Data2D(const Data2D& D);
		
		//destructeur
		~Data2D();
		
		//operators
		bool operator<(const Data2D& d);
		bool operator>(const Data2D& d);
				
		//getters
		float getVal1() const;
		float getVal2() const;
		
		//setters
		void setVal1(float Val1Tmp);
		void setVal2(float Val2Tmp);


};

#endif //DATA2D_H
