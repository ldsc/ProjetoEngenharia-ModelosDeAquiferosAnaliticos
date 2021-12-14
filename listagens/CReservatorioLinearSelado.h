#ifndef CRESERVATORIOLINEARSELADO_H_
#define CRESERVATORIOLINEARSELADO_H_

#include "CFormaReservatorio.h"

class CReservatorioLinearSelado : CFormaReservatorio
{
	
	public:
		
		CReservatorioLinearSelado(){};
	
		virtual double LinearSelado(double _u);
	
		~CReservatorioLinearSelado(){};
};

#endif
