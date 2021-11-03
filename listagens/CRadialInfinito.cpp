#define _USE_MATH_DEFINES // define constantes matematicas (exemplo Pi = 3.141516...)
#include <cmath> ////inclui biblioteca matematica padrao com funcoes bessel para c++17 ou superior

#include "CRadialInfinito.h"

using namespace std;

//Forma da equação solucao do modelo de van everdinger para reservaatorio infinito e radial

double CRadialInfinito::RadialInfinito(double _u, double _Rd)
{

	wd = cyl_bessel_k(1, sqrt(_u))/((pow(_u,(3/2)))*cyl_bessel_k(0, sqrt(_u)));
	
	return wd;

}
