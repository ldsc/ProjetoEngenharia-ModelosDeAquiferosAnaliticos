#define _USE_MATH_DEFINES // define constantes matematicas (exemplo Pi = 3.141516...)
#include <cmath> ////inclui biblioteca matematica padrao com funcoes bessel para c++17 ou superior

#include "CStehfest.h"
#include <iostream> //Biblioteca std usada somente pra dar cout e encontrar bugs vai ser apagada na versão final

using namespace std;

double CStehfest::StehfestRadialInfinito(double _TD)
{

nn2 = L/2;
nn21= nn2+1;

for (double n=1 ; n<=L;n++)
{
	z=0.0;
	for (int k = floor( ( n + 1 ) / 2 ); k <= min(n,nn2); k++)
       {
		 z = z + ((pow(k, nn2))*tgamma(2*k))/(tgamma(nn2-k)*tgamma(k)*tgamma(k-1)*tgamma(n-k)*tgamma(2*k - n));
		}
    v.push_back(pow((-1),(n+nn2))*z);

}
sum = 0.0;
ln2_on_t = log(2.0) / _TD;

for (double n = 1; n <= L; n++)
   {
    p = n * ln2_on_t;
    sum = sum + v[n-1]*radialinfinito.RadialInfinito(p, Rd);
   }
	ilt = sum * ln2_on_t;
	return ilt;	
}
