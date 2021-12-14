#ifndef CFETKOVICH_H_
#define CFETKOVICH_H_

#include "CAdimensional.h"

#include <vector>

class CFetkovich : CAdimensional{
	
	protected:
		
		std::vector <double>  WeFet;
		double Pan, deltaWen;
		
	public:
		
		CFetkovich(){};
		
		double CalcPan(double _Pi, double _We, double _Wei);
		double CalcdeltaWen(double _Wei, double _Pi, double _Pan, double _Pbarra, double _J, double _DeltaT);
		std::vector <double> CalcFetkovic(double _We, double _Wei, std::vector <double> _Pbarra, double _J, std::vector <double> _DeltaT, std::vector <double> _P);
		
		~CFetkovich(){};
		
};

#endif
