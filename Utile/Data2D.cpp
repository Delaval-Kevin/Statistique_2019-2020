/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Calcul de Statistiques                     */
/*Labo : Premier labo                                      */
/*Date de la dernière mise à jour : 10/02/2020             */
/***********************************************************/

#include "Data2D.h"


/********************************/
/*                              */
/*         Constructeurs        */			
/*                              */
/********************************/
		
//Constructeur par défaut
Data2D::Data2D(void)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur par défaut");
	#endif
	
	setVal1(0);
	setVal2(0);
}

//Constructeur d'initialisation
Data2D::Data2D(float Val1Tmp, float Val2Tmp)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur d'initialisation");
	#endif
	
	setVal1(Val1Tmp);
	setVal2(Val2Tmp);
}

//Constructeur de copie
Data2D::Data2D(const Data2D& D)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur de copie");
	#endif

	setVal1(D.getVal1());
	setVal2(D.getVal2());	
}
			
/********************************/
/*                              */
/*          Destructeurs        */			
/*                              */
/********************************/

Data2D::~Data2D()
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

ostream& operator<<(ostream& s, const Data2D& d)
{

	s<< "Valeur 1 : " << d.getVal1() << " Valeur 2 : " << d.getVal2();
	return s;
}

bool Data2D::operator<(const Data2D& d)
{

	if(getVal1() < d.getVal1() && getVal2() < d.getVal2())
		return true;
	else
		return false;	
}

bool Data2D::operator>(const Data2D& d)
{

	if(getVal1() > d.getVal1() && getVal2() > d.getVal2())
		return true;
	else
		return false;	

}

/********************************/
/*                              */
/*            Getters           */			
/*                              */
/********************************/

float Data2D::getVal1() const
{
	return Val1;
}

float Data2D::getVal2() const
{
	return Val2;
}

/********************************/
/*                              */
/*            Setters           */			
/*                              */
/********************************/
			
void Data2D::setVal1(float Val1Tmp)
{
	Val1 = Val1Tmp;
}

void Data2D::setVal2(float Val2Tmp)
{
	Val2 = Val2Tmp;
}
			
/********************************/
/*                              */
/*            Methodes          */			
/*                              */
/********************************/













