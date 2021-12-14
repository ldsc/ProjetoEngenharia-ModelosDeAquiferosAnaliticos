#ifndef CSOLVERVANEVERDINGEN_H_
#define CSOLVERVENEVERDINGER_H_

#include <vector>
#include <iostream>
#include <string>

#include "CStehfest.h"
#include "CGnuplot.h"

class CSolverVanEverdingen
{

	protected:
		
		CFormaReservatorio forma;
		CStehfest Stehfest;
    	Gnuplot plot, plot2, plot3;
		
		std::vector <double> TD, ReD;

	public:
		
		CSolverVanEverdingen(){};
		
		void Solver();
		void Plot(std::vector <double> _WD, std::vector <double> _TD, std::string name, bool _setY);
		void Plot2(std::vector <double> _WD, std::vector <double> _TD, std::string name, bool _setY);
		void Plot3(std::vector <double> _WD, std::vector <double> _TD, std::string name);		
		
		~CSolverVanEverdingen(){};
	
};


#endif
