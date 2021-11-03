#ifndef CRADIALMANUTENCAO_H_
#define CRADIALMANUTENCAO_H_

#include "CForma.h"

class CRadialManutencao : CForma
{

	public:
		
		CRadialManutencao(){};
		
		virtual double RadialManutencao(double _u, double _RD);		
		
		~CRadialManutencao(){};
			
};

#endif
