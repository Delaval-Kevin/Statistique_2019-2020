/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Containeurs                                */
/*Labo : Mini Photoshop                                    */
/*Date de la dernière mise à jour : 13/11/2019             */
/***********************************************************/

#include "ListeBase.h"

/********************************/
/*                              */
/*         Constructeurs        */			
/*                              */
/********************************/

//Constructeur par défaut
template <class T> ListeBase<T>::ListeBase(void)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur par défaut");
	#endif
	setTete(NULL);
}

//Constructeur de copie
template <class T> ListeBase<T>::ListeBase(const ListeBase& LB)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur de copie");
	#endif
	if(LB.pTete != NULL)
	{
		struct Cellule<T> *suivCellule = NULL;
		struct Cellule<T> *tmpCellule = LB.pTete;
		pTete = new struct Cellule<T>;
		pTete->valeur = tmpCellule->valeur;
		suivCellule = pTete;
		tmpCellule = tmpCellule->suivant;
		while(tmpCellule != NULL)
		{
			suivCellule->suivant = new struct Cellule<T>;
			suivCellule = suivCellule->suivant;
			suivCellule->valeur = tmpCellule->valeur;
			tmpCellule = tmpCellule->suivant;
		}
		suivCellule->suivant = NULL;
	}
	else
		setTete(NULL);
}
		
/********************************/
/*                              */
/*          Destructeurs        */			
/*                              */
/********************************/

template <class T> ListeBase<T>::~ListeBase()
{
	#ifdef DEBUG
	TraceConstructeur("Appel au destructeur");
	#endif
	if(!estVide())
	{
		struct Cellule<T> *tmpCellule = pTete->suivant;
		
		while(tmpCellule != NULL)
		{
			delete pTete;
			pTete = tmpCellule;
			tmpCellule = pTete->suivant;
		}
		setTete(NULL);
	}
}

/********************************/
/*                              */
/*           Operators          */			
/*                              */
/********************************/

template <class T>  const ListeBase<T>& ListeBase<T>::operator=(const ListeBase& LB)
{
	/*Pour vider la liste déjà existante s'il y a lieu*/
	if(!estVide())
	{
		struct Cellule<T> *tmpCellule = pTete->suivant;
		
		while(tmpCellule != NULL)
		{
			delete pTete;
			pTete = tmpCellule;
			tmpCellule = pTete->suivant;
		}
		setTete(NULL);
	}
	/*Copier la liste*/
	if(LB.pTete != NULL)
	{
		struct Cellule<T> *suivCellule = NULL;
		struct Cellule<T> *tmpCellule = LB.pTete;
		pTete = new struct Cellule<T>;
		pTete->valeur = tmpCellule->valeur;
		suivCellule = pTete;
		tmpCellule = tmpCellule->suivant;
		while(tmpCellule != NULL)
		{
			suivCellule->suivant = new struct Cellule<T>;
			suivCellule = suivCellule->suivant;
			suivCellule->valeur = tmpCellule->valeur;
			tmpCellule = tmpCellule->suivant;
		}
		suivCellule->suivant = NULL;
	}
	 
	return *this;
}

/********************************/
/*                              */
/*            Getters           */			
/*                              */
/********************************/

template <class T> struct Cellule<T>* ListeBase<T>::getTete() const
{
	return pTete;
}

template <class T> T ListeBase<T>::getElement(int place) const
{
	struct Cellule<T> *pCur;
	pCur = getTete();
	
	for(int i = 0 ; i < place ; i++)
	{
		pCur = pCur->suivant;
	}	
	
	return pCur->valeur;
}
		
/********************************/
/*                              */
/*            Setters           */			
/*                              */
/********************************/
			
template <class T> void ListeBase<T>::setTete(struct Cellule<T> *Tete)
{
	pTete = Tete;
}
		
/********************************/
/*                              */
/*            Methodes          */			
/*                              */
/********************************/
		
template <class T> int ListeBase<T>::Size() const
{
	int nbr=0;
		
	if(!estVide())
	{
		struct Cellule<T> *tmpCellule = getTete();
		nbr++;
		while(tmpCellule->suivant != NULL)
		{
			nbr++;
			tmpCellule = tmpCellule->suivant;
		}
	}
	return nbr;
}

template <class T> bool ListeBase<T>::estVide() const
{
	if(pTete == NULL)
		return true;
	else
		return false;
}

template <class T> void ListeBase<T>::Affiche() const
{
	if(estVide())
		cout << "La liste est vide" << endl;
	else
	{
		struct Cellule<T> *tmpCellule = pTete;
		cout << "[" << tmpCellule->valeur << "]" << endl;
		while(tmpCellule->suivant != NULL)
		{
			tmpCellule = tmpCellule->suivant;
			cout << "[" << tmpCellule->valeur << "]" << endl;
		}
	}
}

template <class T> T ListeBase<T>::retireElement(int place)
{
	struct Cellule<T> *pCur;
	struct Cellule<T> *pPreg = NULL;
	struct Cellule<T> Tmp;
	pCur = getTete();
	
	if(pCur != NULL)
	{
		for(int i = 0 ; i < place ; i++)
		{
			pPreg = pCur;
			pCur = pCur->suivant;
		}	
		
		if(pPreg == NULL)
		{
			setTete(pCur->suivant);		
		}
		else
		{
			pPreg->suivant = pCur->suivant;
		}
	
		Tmp = *pCur;
	
		delete pCur;
	
		return Tmp.valeur;
	}
}

template class ListeBase<int>;
template class ListeBase<float>;
#include "Data1D.h"
template class ListeBase<Data1D>;
#include "Data2D.h"
template class ListeBase<Data2D>;
		
