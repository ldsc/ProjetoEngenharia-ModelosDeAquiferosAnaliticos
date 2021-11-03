#ifndef CSTEHFEST_H_
#define CSTEHFEST_H_

#include <vector>

#include "CRadialInfinito.h"
#include "CRadialSelado.h"
#include "CRadialManutencao.h"
#include "ClinearInfinito.h"
#include "CLinearSelado.h"
#include "CLinearManutencao.h" 

class CStehfest
{
	
	protected:
		
		double nn2, nn21, z, ln2_on_t, sum, p, ilt, L, Rd;
		std::vector <double> v;
		CRadialInfinito radialinfinito;
		
	public:
		
		CStehfest(double _RD = 1, double _L = 16) : L(_L), Rd(_RD){};
		
		double StehfestRadialInfinito(double _TD);
		
		//double Stehfest(CRadialInfinito* radialinfinito, double _TD);
		//double StehfestRadialSelado (double _TD, double _RD);
		
		~CStehfest(){};
};

#endif
