#ifndef CRESERVATORIOLINEARINFINITO_H_
#define CRESERVATORIOLINEARINFINITO_H_

#include "CFormaReservatorio.h"

class CReservatorioLinearInfinito : CFormaReservatorio
{
	
	public:
		
		CReservatorioLinearInfinito(){};
		
		virtual double LinearInfinito(double _TD);
		
		~CReservatorioLinearInfinito(){};
	
};

#endif
