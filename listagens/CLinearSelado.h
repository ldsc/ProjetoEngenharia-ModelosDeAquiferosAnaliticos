#ifndef CLINEARSELADO_H_
#define CLINEARSELADO_H_

#include "CForma.h"

class CLinearSelado :CForma
{
	
	public:
		
		CLinearSelado(){};
	
		virtual double LinearSelado(double _u);
	
		~CLinearSelado(){};
};

#endif
