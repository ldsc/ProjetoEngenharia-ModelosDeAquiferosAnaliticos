#ifndef CRADIALINFINITO_H_
#define CRADIALINFINITO_H_

#include "CForma.h"

//Criacao da classe CRadialInfinito.h

class CRadialInfinito : CForma
{
				
		// declaracao metodos publicos
	public:
	
	
	CRadialInfinito(){}; //Construtor default
	
	virtual double RadialInfinito(double _u, double _Rd);
	
	~CRadialInfinito(){}; //Destrutor default
	
};

#endif
