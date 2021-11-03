#ifndef CLINEARMANUTENCAO_H_
#define CLINEARMANUTENCAO_H_

#include "CForma.h"

class CLinearManutencao : CForma
{
	
	public:
	
		CLinearManutencao(){};
		
		double virtual LinearManutencao(double _u);
		
		~CLinearManutencao(){};
		
};

#endif
