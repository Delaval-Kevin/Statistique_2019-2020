/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Calcul de Statistiques                     */
/*Labo : Premier labo                                      */
/*Date de la dernière mise à jour : 10/02/2020             */
/***********************************************************/

#include "EtudeStat1D.h"


/********************************/
/*                              */
/*         Constructeurs        */			
/*                              */
/********************************/
		
//Constructeur d'initialisation
EtudeStat1D::EtudeStat1D(char * nomFichier, int colonne)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur d'initialisation");
	#endif
	
	E = new Echantillon(nomFichier, colonne);
	
	CalculMoyenne();
	CalculMode();
	CalculMediane();
	CalculEcartType();
	CalculEtendue();
	CalculCV();
	
	AfficheRapport();
}
			
/********************************/
/*                              */
/*          Destructeurs        */			
/*                              */
/********************************/

EtudeStat1D::~EtudeStat1D()
{
	#ifdef DEBUG
	TraceConstructeur("Appel au destructeur");
	#endif
	
	if(E)
		delete E;

}

/********************************/
/*                              */
/*           Operators          */			
/*                              */
/********************************/

/********************************/
/*                              */
/*            Getters           */			
/*                              */
/********************************/

const Echantillon* EtudeStat1D::getE() const
{
	return E;
}

float EtudeStat1D::getMoyenne() const
{
	return Moyenne;
}

const float* EtudeStat1D::getMode() const
{
	return Mode;
}

float EtudeStat1D::getMediane() const
{
	return Mediane;
}

float EtudeStat1D::getEcartType() const
{
	return EcartType;
}

float EtudeStat1D::getEtendue() const
{
	return Etendue;
}

float EtudeStat1D::getCV() const
{
	return CV;
}

/********************************/
/*                              */
/*            Setters           */			
/*                              */
/********************************/
		
void EtudeStat1D::setMoyenne(float MoyenneTmp)
{
	Moyenne = MoyenneTmp;
}

void EtudeStat1D::setEcartType(float EcartTypeTmp)
{
	EcartType = EcartTypeTmp;
}

void EtudeStat1D::setMediane(float MedianeTmp)
{
	Mediane = MedianeTmp;
}

void EtudeStat1D::setMode(float *ModeTmp)
{
	Mode[0] = ModeTmp[0];
	Mode[1] = ModeTmp[1];
	Mode[2] = ModeTmp[2];
}

void EtudeStat1D::setEtendue(float EtendueTmp)
{
	Etendue = EtendueTmp;
}

void EtudeStat1D::setCV(float CVTmp)
{
	CV = CVTmp;
}
	
/********************************/
/*                              */
/*            Methodes          */			
/*                              */
/********************************/

void EtudeStat1D::AfficheRapport()
{
	DataSource *Data = E->getSource();

	cout << endl << "Nom : " << Data->getNom() << endl;
	cout << "Sujet de l'etude : " << Data->getSujet() << endl;
	if(Data->getType() == 1)
		cout << "Type : Discrete" << endl << endl;
	else
		cout << "Type : Continue " << endl << endl;
	
	cout << "Donnees :" << endl;
	cout << "---------" << endl;
	
	
	
    DataSourceSerieDiscrete* pD = dynamic_cast<DataSourceSerieDiscrete*>(Data);
    if (pD != NULL)
    {
		pD->Affiche();
    }
    
    DataSourceSerieContinue* pC = dynamic_cast<DataSourceSerieContinue*>(Data);
    if (pC != NULL) 
    {
		pC->Affiche();
    }
	
	cout << "Effectif total : " << Data->getEffTotal() << endl << endl;
	
	cout << "\tMoyenne : " << getMoyenne() << endl;
	cout << "\tMediane : " << getMediane() << endl;
	cout << "\tMode : " << (getMode()[0]) << " : " << (getMode()[1]) << " : " << (getMode()[2])  << endl;
	cout << "\tEcart type : " << getEcartType() << endl;
	cout << "\tCoefficient de variation : " << getCV() << "%" << endl << endl;
	
	cout << "Controle de qualité :" << endl << endl;
	
	cout << "\tValeur minimum : " << Data->getMin() << endl;
	cout << "\tValeur maximum : " << Data->getMax() << endl << endl;
	
	cout << "Etendue : " << getEtendue() << endl << endl;	
	
	if (pD != NULL)
    {
		GraphStat1DDiscrete w(*this);
		w.show();
		a->exec();
    }
    if (pC != NULL) 
    {
		GraphStat1DContinue w(*this);
		w.show();
		a->exec();
    }
}

void EtudeStat1D::CalculMoyenne()
{
	DataSource *Data = E->getSource();
	
	float moyenneTmp = 0;
	
    DataSourceSerieDiscrete* pD = dynamic_cast<DataSourceSerieDiscrete*>(Data);
    if (pD != NULL)
    {    	
    	Iterateur<Data1D> it(*(pD->getL()));
    	it.reset();
    	
		while(!it.end())
		{
			moyenneTmp = moyenneTmp + ( ((Data1D)it).getVal() * ((Data1D)it).getEff() );
			it++;
		}
		
		moyenneTmp = moyenneTmp / (E->getSource()->getEffTotal());
		
		setMoyenne(moyenneTmp);
    }
    
    DataSourceSerieContinue* pC = dynamic_cast<DataSourceSerieContinue*>(Data);
    if (pC != NULL) 
    {
    	Iterateur<Data1D> it(*(pC->getL()));
    	it.reset();
    	
		while(!it.end())
		{
			moyenneTmp = moyenneTmp + ( ( ((Data1D)it).getVal() + (pC->getIntervalle()/2) ) * ((Data1D)it).getEff() );
			it++;
		}
		
		moyenneTmp = moyenneTmp / (E->getSource()->getEffTotal());   	
    	
		setMoyenne(moyenneTmp);
    }
	
}

void EtudeStat1D::CalculMode()
{
	DataSource *Data = E->getSource();
	
	Liste<Data1D> LTmp;
	
	float modeTmp[3] = {0,0,0};
	int effTmp = 0;
	
    DataSourceSerieDiscrete* pD = dynamic_cast<DataSourceSerieDiscrete*>(Data);
    if (pD != NULL)
    {    	
		LTmp = (*(pD->getL()));
    }
    
    DataSourceSerieContinue* pC = dynamic_cast<DataSourceSerieContinue*>(Data);
    if (pC != NULL) 
    {
 		LTmp = (*(pC->getL()));
    }
    	Iterateur<Data1D> it(LTmp);
    	it.reset();

		while(!it.end())
		{
			if(((Data1D)it).getEff() > effTmp)
			{
				effTmp = ((Data1D)it).getEff();
				
				if (pC != NULL) 
    			{
					modeTmp[0] = ((Data1D)it).getVal() + (pC->getIntervalle() / 2);	
    			}
    			else
    			{
    				modeTmp[0] = ((Data1D)it).getVal();
    			}
    			
    			modeTmp[1] = 0;
    			modeTmp[2] = 0;
						
			}
			else
			{
				if(((Data1D)it).getEff() == effTmp) // si une autre valeur a le meme effectif
				{
					if(modeTmp[1] == 0)
					{
						if (pC != NULL) 
						{
							modeTmp[1] = ((Data1D)it).getVal() + (pC->getIntervalle() / 2);	
						}
						else
						{
							modeTmp[1] = ((Data1D)it).getVal();
						}					
					}
					else if (modeTmp[2] == 0)
					{
						if (pC != NULL) 
						{
							modeTmp[2] = ((Data1D)it).getVal() + (pC->getIntervalle() / 2);	
						}
						else
						{
							modeTmp[2] = ((Data1D)it).getVal();
						}						
					}
				}
				

			}
			it++;
		}
		setMode(modeTmp);   
    
}

void EtudeStat1D::CalculMediane()
{
	DataSource *Data = E->getSource();
	int position;
    int positionTmp = 0;
	
    DataSourceSerieDiscrete* pD = dynamic_cast<DataSourceSerieDiscrete*>(Data);
    if (pD != NULL)
    {    	
    	Iterateur<Data1D> it(*(pD->getL()));
    	it.reset();
    	
		if(E->getSource()->getEffTotal()%2 == 0) // si effectif pair
		{
			position = (E->getSource()->getEffTotal()/2);
			
			positionTmp = ((Data1D)it).getEff();
			
			while(positionTmp < position)
			{
				it++;
				positionTmp += ((Data1D)it).getEff();
			}
			
			if(positionTmp > position) // on est en plein dans l'effectif de la valeur
			{
				setMediane(((Data1D)it).getVal());
			}
			else // on est la derniere position de la valeur, alors faire la moyenne avec celle du dessus
			{
				float valTmp;
				valTmp = ((Data1D)it).getVal();
				it++;
				valTmp += ((Data1D)it).getVal();
				setMediane(valTmp/2);
			}
		}
		else // si effectif impair
		{
			position = (E->getSource()->getEffTotal()/2)+1;
			
			positionTmp = ((Data1D)it).getEff();
			
			while(positionTmp < position)
			{
				it++;
				positionTmp += ((Data1D)it).getEff();
			}
			
			setMediane(((Data1D)it).getVal());
		}		
    }
    
    DataSourceSerieContinue* pC = dynamic_cast<DataSourceSerieContinue*>(Data);
    if (pC != NULL) 
    {
    	Iterateur<Data1D> it(*(pC->getL()));
    	it.reset();

		if(E->getSource()->getEffTotal()%2 == 0) // si effectif pair
		{
			position = (E->getSource()->getEffTotal()/2);
			positionTmp += ((Data1D)it).getEff();
			
			while(positionTmp <= position)
			{
				it++;
				positionTmp += ((Data1D)it).getEff();
			}	

			positionTmp -= position; //pour avoir la position dans l'effectif de l'intervalle

			positionTmp = ((Data1D)it).getEff() - positionTmp;
	
			float medianeTmp;
			medianeTmp = ((Data1D)it).getVal() + (( pC->getIntervalle() / ((Data1D)it).getEff() ) * positionTmp);
			
			medianeTmp = (medianeTmp + ( (Data1D)it).getVal() + (( pC->getIntervalle() / ((Data1D)it).getEff() ) * (positionTmp+1) ) )/2;
		
			setMediane(medianeTmp);
    	}
		else // si effectif impair
		{
			position = (E->getSource()->getEffTotal()/2)+1;
			positionTmp += ((Data1D)it).getEff();
			
			while(positionTmp <= position)
			{
				it++;
				positionTmp += ((Data1D)it).getEff();
			}	

			positionTmp -= position; //pour avoir la position dans l'effectif de l'intervalle

			positionTmp = ((Data1D)it).getEff() - positionTmp;
	
			float medianeTmp;
			medianeTmp = ((Data1D)it).getVal() + (( pC->getIntervalle() / ((Data1D)it).getEff() ) * (positionTmp-1)) + ( (pC->getIntervalle() / ((Data1D)it).getEff()) / 2 );
		
			setMediane(medianeTmp);
		}	    	
    }
}

void EtudeStat1D::CalculEcartType()
{
	DataSource *Data = E->getSource();
	float EcartTypeTmp1 = 0;
	float EcartTypeTmp2 = 0;
	
    DataSourceSerieDiscrete* pD = dynamic_cast<DataSourceSerieDiscrete*>(Data);
    if (pD != NULL)
    {    	
    	Iterateur<Data1D> it(*(pD->getL()));
    	it.reset();
		
		while(!it.end())
		{
			EcartTypeTmp1 = EcartTypeTmp1 + ( ((Data1D)it).getVal() * ((Data1D)it).getVal() * ((Data1D)it).getEff() );
			EcartTypeTmp2 = EcartTypeTmp2 + ( ((Data1D)it).getVal() * ((Data1D)it).getEff() );
			it++;
		}
		
		EcartTypeTmp2 = (EcartTypeTmp2 * EcartTypeTmp2) / (E->getSource()->getEffTotal());
		
		EcartTypeTmp1 = EcartTypeTmp1 - EcartTypeTmp2;
		
		EcartTypeTmp1 = EcartTypeTmp1 / (E->getSource()->getEffTotal());
		
		EcartTypeTmp1 = sqrt(EcartTypeTmp1);
		
		setEcartType(EcartTypeTmp1);
    }
    
    DataSourceSerieContinue* pC = dynamic_cast<DataSourceSerieContinue*>(Data);
    if (pC != NULL) 
    {
    	Iterateur<Data1D> it(*(pC->getL()));
    	it.reset();

		while(!it.end())
		{
			EcartTypeTmp1 = EcartTypeTmp1 + ( ( ((Data1D)it).getVal() + (pC->getIntervalle()/2) ) * ( ((Data1D)it).getVal() + (pC->getIntervalle()/2) ) * ((Data1D)it).getEff() );
			EcartTypeTmp2 = EcartTypeTmp2 + ( ( ((Data1D)it).getVal() + (pC->getIntervalle()/2) ) * ((Data1D)it).getEff() );
			it++;
		}
		
		EcartTypeTmp2 = (EcartTypeTmp2 * EcartTypeTmp2) / (E->getSource()->getEffTotal());
		
		EcartTypeTmp1 = EcartTypeTmp1 - EcartTypeTmp2;
		
		EcartTypeTmp1 = EcartTypeTmp1 / (E->getSource()->getEffTotal());
		
		EcartTypeTmp1 = sqrt(EcartTypeTmp1);
		
		setEcartType(EcartTypeTmp1);
    }
}

void EtudeStat1D::CalculEtendue()
{
	setEtendue((E->getSource()->getMax())-(E->getSource()->getMin()));
}

void EtudeStat1D::CalculCV()
{
	setCV((getEcartType() / getMoyenne()) * 100);
}





