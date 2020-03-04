/***********************************************************/
/*Auteur : DELAVAL Kevin                                   */
/*Groupe : 2203                                            */
/*Application : Calcul de Statistiques                     */
/*Labo : Premier labo                                      */
/*Date de la dernière mise à jour : 10/02/2020             */
/***********************************************************/

#include "EtudeStat2D.h"


/********************************/
/*                              */
/*         Constructeurs        */			
/*                              */
/********************************/
		
//Constructeur d'initialisation avec 3 parametres		
EtudeStat2D::EtudeStat2D(char *nomFichier, int colonne1, int colonne2)
{
	#ifdef DEBUG
	TraceConstructeur("Appel au constructeur d'initialisation avec 3 parametres");
	#endif
	
	E = new Echantillon(nomFichier, colonne1, colonne2);
	
	CalculAll();	
	
	AfficheRapport();
}	
			
/********************************/
/*                              */
/*          Destructeurs        */			
/*                              */
/********************************/

EtudeStat2D::~EtudeStat2D()
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

/********************************/
/*                              */
/*            Getters           */			
/*                              */
/********************************/

Echantillon* EtudeStat2D::getE() const
{
	return E;
}

float EtudeStat2D::getMoyenneVal1() const
{
	return MoyenneVal1;
}

float EtudeStat2D::getMoyenneVal2() const
{
	return MoyenneVal2;
}

float EtudeStat2D::getCoeffA() const
{
	return CoeffA;
}

float EtudeStat2D::getCoeffB() const
{
	return CoeffB;
}

float EtudeStat2D::getCoeffCorrelation() const
{
	return CoeffCorrelation;
}

/********************************/
/*                              */
/*            Setters           */			
/*                              */
/********************************/

void EtudeStat2D::setMoyenneVal1(float MoyenneVal1Tmp)
{
	MoyenneVal1 = MoyenneVal1Tmp;
}

void EtudeStat2D::setMoyenneVal2(float MoyenneVal2Tmp)
{
	MoyenneVal2 = MoyenneVal2Tmp;
}

void EtudeStat2D::setCoeffA(float CoeffATmp)
{
	CoeffA = CoeffATmp;
}

void EtudeStat2D::setCoeffB(float CoeffBTmp)
{
	CoeffB = CoeffBTmp;
}

void EtudeStat2D::setCoeffCorrelation(float CoeffCorrelationTmp)
{
	CoeffCorrelation = CoeffCorrelationTmp;
}
		
/********************************/
/*                              */
/*            Methodes          */			
/*                              */
/********************************/

void EtudeStat2D::AfficheRapport()
{
	DataSource *Data = E->getSource();

    DataSourceSerie2D* p2D = dynamic_cast<DataSourceSerie2D*>(Data);
    if (p2D != NULL)
    {
    	GraphStat2D w(this);
		w.show();
		a->exec();
    
    	CalculAll();
    
		cout << endl << "Nom : " << p2D->getNom() << endl;
		cout << "Sujet de l'etude : " << p2D->getSujet() << " -- " << p2D->getSujet2() << endl;
		if(p2D->getType() == 1)
			cout << "Type : Discrete";
		else
			cout << "Type : Continue";
		
		if(p2D->getType2() == 1)
			cout << " -- Discrete" << endl;
		else
			cout << " -- Continue " << endl;
			
		cout << "Effectif total : " << p2D->getEffTotal() << endl << endl;
	
		cout << "Valeurs :" << endl;
		cout << "---------" << endl;
		
		p2D->Affiche();
		
		cout << endl << endl;
		cout << "   Moyenne Val1 : " << getMoyenneVal1() << endl;
		cout << "   Moyenne Val2 : " << getMoyenneVal2() << endl << endl;
		
		cout << "Correlation : " << getCoeffCorrelation() << endl << endl;
		
		cout << "   Coefficient A : " << getCoeffA() << endl;
		cout << "   Coefficient B : " << getCoeffB() << endl;
		
		ChoixPrediction();		
	}
}

void EtudeStat2D::ChoixPrediction()
{
	int choix;

	DataSource *Data = E->getSource();

    DataSourceSerie2D* p2D = dynamic_cast<DataSourceSerie2D*>(Data);
    if (p2D != NULL)
    {	
		do
		{
			cout << "\t1 : Prévision pour : " << p2D->getSujet() << endl;
			cout << "\t2 : Prévision pour : " << p2D->getSujet2() << endl;
			cout << "\t3 : Sortie         : " << endl;
			cout << "Choix : ";
			cin >> choix;
		
			if(choix == 1)
				PrevSujet(choix);
			else if(choix == 2)
				PrevSujet(choix);
		}while(choix != 3);
	
		cout << "fin" << endl;
	}
}

void EtudeStat2D::PrevSujet(int choix)
{
	DataSource *Data = E->getSource();
	float valeur;

    DataSourceSerie2D* p2D = dynamic_cast<DataSourceSerie2D*>(Data);
    if (p2D != NULL)
    {	
		if(choix == 1)
		{
			cout << "\tEntrer la valeur pour" << p2D->getSujet() << " : ";
			cin >> valeur;
			cout << "La valeur prevue : " << EqDroiteY(valeur) << endl;
		}
		else
		{
			cout << "\tEntrer la valeur pour" << p2D->getSujet2() << " : ";
			cin >> valeur;
			cout << "La valeur prevue : " << EqDroiteX(valeur) << endl;
		}
	}	
}

void EtudeStat2D::CalculMoyenneVal1()
{
	DataSource *Data = E->getSource();	
	float moyenneTmp = 0;
	
    DataSourceSerie2D* p2D = dynamic_cast<DataSourceSerie2D*>(Data);
    if (p2D != NULL)
    {    	
    	Iterateur<Data2D> it(*(p2D->getL()));
    	it.reset();
    	
		while(!it.end())
		{
			moyenneTmp = moyenneTmp + ((Data2D)it).getVal1();
			it++;
		}
		
		p2D->setEffTotal(p2D->getL()->Size());
		
		moyenneTmp = moyenneTmp / p2D->getEffTotal();
		
		setMoyenneVal1(moyenneTmp);
    }
}

void EtudeStat2D::CalculMoyenneVal2()
{
	DataSource *Data = E->getSource();	
	float moyenneTmp = 0;
	
    DataSourceSerie2D* p2D = dynamic_cast<DataSourceSerie2D*>(Data);
    if (p2D != NULL)
    {    	
    	Iterateur<Data2D> it(*(p2D->getL()));
    	it.reset();
    	
		while(!it.end())
		{
			moyenneTmp = moyenneTmp + ((Data2D)it).getVal2();
			it++;
		}
		
		p2D->setEffTotal(p2D->getL()->Size());
		
		moyenneTmp = moyenneTmp / p2D->getEffTotal();
		
		setMoyenneVal2(moyenneTmp);
    }
}

void EtudeStat2D::CalculCoeffA()
{
	DataSource *Data = E->getSource();
	float CoeffATmp;
	float SomX1 = 0;
	float SomY2 = 0;
	float SomX1Y2 = 0;
	float SomX1Car = 0;

    DataSourceSerie2D* p2D = dynamic_cast<DataSourceSerie2D*>(Data);
    if (p2D != NULL)
    {    	
    	Iterateur<Data2D> it(*(p2D->getL()));
    	it.reset();
    	
		while(!it.end())
		{
			SomX1 = SomX1 + ((Data2D)it).getVal1();
			SomY2 = SomY2 + ((Data2D)it).getVal2();
			SomX1Y2 = SomX1Y2 + ( ((Data2D)it).getVal1() * ((Data2D)it).getVal2() );
			SomX1Car = SomX1Car + ( ((Data2D)it).getVal1() * ((Data2D)it).getVal1() );
			it++;
		}
		
		p2D->setEffTotal(p2D->getL()->Size());
		
		CoeffATmp = SomX1Y2 - ( (SomX1 * SomY2) / p2D->getEffTotal() );
		
		CoeffATmp = CoeffATmp / ( SomX1Car - ( ( SomX1 *SomX1 ) / p2D->getEffTotal() ) );
		
		setCoeffA(CoeffATmp);
    }
}

void EtudeStat2D::CalculCoeffB()
{
	float CoeffBTmp;
	CalculMoyenneVal1();
	CalculMoyenneVal2();
	
	CoeffBTmp = getMoyenneVal2() - ( getCoeffA() * getMoyenneVal1() );
	
	setCoeffB(CoeffBTmp);
}

void EtudeStat2D::CalculCoeffCorrelation()
{
	DataSource *Data = E->getSource();
	float CoeffCorrTmp;
	float SomX1 = 0;
	float SomY2 = 0;
	float SomX1Y2 = 0;
	float SomX1Car = 0;
	float SomY2Car = 0;

    DataSourceSerie2D* p2D = dynamic_cast<DataSourceSerie2D*>(Data);
    if (p2D != NULL)
    {    	
    	Iterateur<Data2D> it(*(p2D->getL()));
    	it.reset();
    	
		while(!it.end())
		{
			SomX1 = SomX1 + ((Data2D)it).getVal1();
			SomY2 = SomY2 + ((Data2D)it).getVal2();
			SomX1Y2 = SomX1Y2 + ( ((Data2D)it).getVal1() * ((Data2D)it).getVal2() );
			SomX1Car = SomX1Car + ( ((Data2D)it).getVal1() * ((Data2D)it).getVal1() );
			SomY2Car = SomY2Car + ( ((Data2D)it).getVal2() * ((Data2D)it).getVal2() );
			it++;
		}
		
		CoeffCorrTmp = SomX1Y2 - ( (SomX1 * SomY2) / p2D->getEffTotal() );
		
		CoeffCorrTmp = CoeffCorrTmp / sqrt( ( SomX1Car - ( ( SomX1 *SomX1 ) / p2D->getEffTotal() ) ) * ( SomY2Car - ( ( SomY2 *SomY2 ) / p2D->getEffTotal() ) ) );
		
		setCoeffCorrelation(CoeffCorrTmp);
    }	
}

void EtudeStat2D::CalculAll()
{
	E->getSource()->setEffTotal(((DataSourceSerie2D*)(E->getSource()))->getL()->Size());
	CalculMoyenneVal1();
	CalculMoyenneVal2();
	CalculCoeffA();
	CalculCoeffB();
	CalculCoeffCorrelation();
}

float EtudeStat2D::EqDroiteY(float valeur)
{
	float Y;
	
	Y = ( getCoeffA() * valeur ) + getCoeffB();
	
	return Y;
}

float EtudeStat2D::EqDroiteX(float valeur)
{
	float X;
	
	X = ( valeur - getCoeffB() ) / getCoeffA();
	
	return X;
}



