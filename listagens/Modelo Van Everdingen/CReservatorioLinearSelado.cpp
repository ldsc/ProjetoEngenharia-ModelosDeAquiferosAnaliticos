#define _USE_MATH_DEFINES // define constantes matematicas (exemplo Pi = 3.141516...)
#include <cmath> ////inclui biblioteca matematica padrao com funcoes bessel para c++17 ou superior

#include "CReservatorioLinearSelado.h"

double CReservatorioLinearSelado::LinearSelado(double _u)
{
	
	wd = (1.0- exp(-2.0*sqrt(_u)))/ ((pow(_u, (3.0/2.0)))*(1.0+exp(-2.0*sqrt(_u))));
	
	return wd;
}
