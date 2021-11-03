#define _USE_MATH_DEFINES // define constantes matematicas (exemplo Pi = 3.141516...)
#include <cmath> ////inclui biblioteca matematica padrao com funcoes bessel para c++17 ou superior

#include "CLinearSelado.h"

double CLinearSelado::LinearSelado(double _u)
{
	
	wd = (1- exp(-2*sqrt(_u)))/ ((pow(_u, (3/2)))*(1+exp(-2*sqrt(_u))));
	
	return wd;
}
