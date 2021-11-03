#define _USE_MATH_DEFINES // define constantes matematicas (exemplo Pi = 3.141516...)
#include <cmath> ////inclui biblioteca matematica padrao com funcoes bessel para c++17 ou superior

#include "CLinearInfinito.h"

double CLinearInfinito::LinearInfinito(double _TD)
{
	
	wd = 2*sqrt(_TD/M_PI);
	
	return wd;
}
