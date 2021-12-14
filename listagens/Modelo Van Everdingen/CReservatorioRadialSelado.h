#ifndef CRESERVATORIORADIALSELADO_H_
#define CRESERVATORIORADIALSELADO_H_

#include "CFormaReservatorio.h"

class CReservatorioRadialSelado : CFormaReservatorio
{

	public:
		
		CReservatorioRadialSelado(){};
		
		virtual double RadialSelado(double _u, double _RD);
		
		~CReservatorioRadialSelado(){};
		
	
};


#endif
