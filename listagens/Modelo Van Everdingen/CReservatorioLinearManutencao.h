#ifndef CRESERVATORIOLINEARMANUTENCAO_H_
#define CRESERVATORIOLINEARMANUTENCAO_H_

#include "CFormaReservatorio.h"

class CReservatorioLinearManutencao : CFormaReservatorio
{
	
	public:
	
		CReservatorioLinearManutencao(){};
		
		double virtual LinearManutencao(double _u);
		
		~CReservatorioLinearManutencao(){};
		
};

#endif
