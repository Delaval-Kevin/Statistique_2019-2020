/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Calcul de Statistiques                     */
/*Labo : Premier labo                                      */
/*Date de la dernière mise à jour : 10/02/2020             */
/***********************************************************/

#include "Data1D.h"


/********************************/
/*                              */
/*         Constructeurs        */			
/*                              */
/********************************/
		
//Constructeur par défaut
Data1D::Data1D(void)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur par défaut");
	#endif
	
	setEff(0);
	setVal(0);
}

//Constructeur d'initialisation
Data1D::Data1D(float ValTmp, int EffTmp)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur d'initialisation");
	#endif
	
	setEff(EffTmp);
	setVal(ValTmp);
}

//Constructeur de copie
Data1D::Data1D(const Data1D& D)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur de copie");
	#endif

	setEff(D.getEff());
	setVal(D.getVal());	
}
		
			
/********************************/
/*                              */
/*          Destructeurs        */			
/*                              */
/********************************/

Data1D::~Data1D()
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

ostream& operator<<(ostream& s, const Data1D& d)
{

	s<< "Valeur : " << d.getVal() << " Effectif : " << d.getEff();
	return s;
}

/********************************/
/*                              */
/*            Getters           */			
/*                              */
/********************************/

float Data1D::getVal() const
{
	return Val;
}
		
int Data1D::getEff() const
{
	return Eff;
}

/********************************/
/*                              */
/*            Setters           */			
/*                              */
/********************************/
		
void Data1D::setVal(float ValTmp)
{
	Val = ValTmp;
}

void Data1D::setEff(int EffTmp)
{
	Eff = EffTmp;
}
			
/********************************/
/*                              */
/*            Methodes          */			
/*                              */
/********************************/












