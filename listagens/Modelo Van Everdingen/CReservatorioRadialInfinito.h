#ifndef CRESERVATORIORADIALINFINITO_H_
#define CRESERVATORIORADIALINFINITO_H_

#include "CFormaReservatorio.h"

//Criacao da classe CReservatorioRadialInfinito.h

class CReservatorioRadialInfinito : CFormaReservatorio
{
				
		// declaracao metodos publicos
	public:
	
	
	CReservatorioRadialInfinito(){}; //Construtor default
	
	virtual double RadialInfinito(double _u, double _Rd);
	
	~CReservatorioRadialInfinito(){}; //Destrutor default
	
};

#endif
