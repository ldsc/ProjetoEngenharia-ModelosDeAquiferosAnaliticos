#ifndef CCARTERTRACY_H_
#define CCARTERTRACY_H_

#include <vector>


class CCarterTracy {
	
	protected:
		
		std::vector <double> Wecarter; 
		double AJ;
			
	public:
	
		CCarterTracy(){};
		
		double CalcAJ(double _U, double _delp, double _we, double _pdbarra, double _TD, double _td, double _PD);
		std::vector <double> CarterTracy(std::vector <double> _TD, double _U, std::vector <double> _delp, std::vector <double> _pdbarra, std::vector <double> _PD);
		
		~CCarterTracy(){};
	
};

#endif
