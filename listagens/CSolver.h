#ifndef CSOLVER_H_
#define CSOLVER_H_

#include <vector>
#include <iostream>

#include "CStehfest.h"
#include "CGnuplot.h"

class CSolver
{

	protected:
		
		CForma forma;
		CStehfest Stehfest;
    	Gnuplot plot;
		
		std::vector <double> TD;

	public:
		
		CSolver(){};
		
		void Solver();
		void Plot(std::vector <double> _WD, std::vector <double> _TD);
		
		~CSolver(){};
	
};


#endif
