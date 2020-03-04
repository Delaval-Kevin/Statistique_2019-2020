/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Containeurs                                */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 13/11/2019             */
/***********************************************************/

#include "Iterateur.h"

/********************************/
/*                              */
/*         Constructeurs        */			
/*                              */
/********************************/

//Constructeur par défaut
//template <class T> Iterateur<T>::Iterateur(ListeBase<T> &l):lis(l), pCur(l.getTete())
//{
//	#ifdef DEBUG
//	TraceConstructeur("Appel au constructeur par défaut");
//	#endif
//}

		
/********************************/
/*                              */
/*          Destructeurs        */			
/*                              */
/********************************/



/********************************/
/*                              */
/*           Operators          */			
/*                              */
/********************************/

template <class T> void Iterateur<T>::operator++()
{
	if(pCur == NULL)
		throw BaseException("Bout de liste, ++ impossible");
	
	pCur = pCur->suivant;
}

template <class T> void Iterateur<T>::operator++(int)
{
	operator++();
}

//Opérateur de casting qui retourne l'élément pointé par l'itérateur
template <class T> Iterateur<T>::operator T() const
{
	return pCur->valeur;
}

//Opérateur qui retourne la référence de l'élément pointé par l'itérateur
template <class T> T& Iterateur<T>::operator&()
{
	return pCur->valeur;
}

/********************************/
/*                              */
/*            Getters           */			
/*                              */
/********************************/

template <class T> Cellule<T>* Iterateur<T>::getpCur() const
{
	return pCur;
}
		
/********************************/
/*                              */
/*            Setters           */			
/*                              */
/********************************/
			

		
/********************************/
/*                              */
/*            Methodes          */			
/*                              */
/********************************/
		
//Méthode que remet l'itérateur en début de liste
template <class T> void Iterateur<T>::reset()
{
	pCur = lis.getTete();
}

//Méthode qui permet de voir si l'on est en fin de liste
template <class T> bool Iterateur<T>::end() const
{
	if(pCur == NULL)
		return true;
	else
		return false;
}

//Méthode que permet de retirer l'élément pointé par l'itérateur de la liste et de renvoyé sa valeur
template <class T> T  Iterateur<T>::remove()
{
	if(pCur == NULL)
		throw BaseException("Impossible la liste est vide!");
		
	Cellule<T> *tmp = lis.getTete();
	Cellule<T> *tmpPrec = NULL;
	T valRet;
	
	while(tmp != pCur)
	{
		tmpPrec = tmp;
		tmp = tmp->suivant;
	}

	if(tmpPrec == NULL)
	{
		lis.setTete(lis.pTete->suivant);
		reset();
	}
	else
	{
		tmpPrec->suivant = tmp->suivant;
		reset();
	}
	valRet = tmp->valeur;
	delete tmp;

	return valRet;
}



template class Iterateur<int>;
template class Iterateur<float>;
#include "Data1D.h"
template class Iterateur<Data1D>;
#include "Data2D.h"
template class Iterateur<Data2D>;

