#ifndef CRESERVATORIORADIALMANUTENCAO_H_
#define CRESERVATORIORADIALMANUTENCAO_H_

#include "CFormaReservatorio.h"

class CReservatorioRadialManutencao : CFormaReservatorio
{

	public:
		
		CReservatorioRadialManutencao(){};
		
		virtual double RadialManutencao(double _u, double _RD);		
		
		~CReservatorioRadialManutencao(){};
			
};

#endif
