#define _USE_MATH_DEFINES // define constantes matematicas (exemplo Pi = 3.141516...)
#include <cmath> ////inclui biblioteca matematica padrao com funcoes bessel para c++17 ou superior

#include "CReservatorioRadialManutencao.h"

using namespace std;

double CReservatorioRadialManutencao::RadialManutencao(double _u, double _RD)
{
	
	wd =  (((cyl_bessel_i(0, _RD*sqrt(_u))*cyl_bessel_k(1, sqrt(_u)))+(cyl_bessel_i(1, sqrt(_u))*cyl_bessel_k(0, _RD*sqrt(_u))))/((pow(_u, (3.0/2.0)))*((cyl_bessel_i(0, _RD*sqrt(_u))*cyl_bessel_k(0, sqrt(_u)))-(cyl_bessel_i(0, sqrt(_u))*cyl_bessel_k(0, sqrt(_u))))));  
	
	return wd;
	
}
