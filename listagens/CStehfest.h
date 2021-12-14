#ifndef CSTEHFEST_H_
#define CSTEHFEST_H_

#include <vector>

#include "CReservatorioRadialInfinito.h"
#include "CReservatorioRadialSelado.h"
#include "CReservatorioRadialManutencao.h"
#include "CReservatorioLinearInfinito.h"
#include "CReservatorioLinearSelado.h"
#include "CReservatorioLinearManutencao.h" 

class CStehfest
{
	
	protected:
		
		double nn2, nn21, z, ln2_on_t, sum, p, ilt, L, Rd;
		std::vector <double> v;
		CReservatorioRadialInfinito radialinfinito;
		CReservatorioRadialSelado radialselado;
		CReservatorioRadialManutencao radialmanutencao;
		CReservatorioLinearInfinito linearinfinito;
		CReservatorioLinearSelado linearselado;
		CReservatorioLinearManutencao linearmanutencao;
		
	public:
		
		CStehfest(double _RD = 1, double _L = 12) : L(_L), Rd(_RD){};
		
		double Factorial(int _i);
		double StehfestRadialInfinito(double _TD);
		double StehfestRadialSelado (double _TD, double _RD);
		double StehfestRadialManutencao (double _TD, double _RD);
		double StehfestLinearInfinito (double _TD);
		double StehfestLinearSelado (double _TD);
		double StehfestLinearManutencao (double _TD);
		
		~CStehfest(){};
};

#endif
