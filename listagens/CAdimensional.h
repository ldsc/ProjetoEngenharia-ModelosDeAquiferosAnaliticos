#ifndef CADIMENSIONAL_H_
#define CADIMENSIONAL_H_

#include <vector>

class CAdimensional{

	protected:
	
		std::vector <double> delT, deltPbarra, TD, delP, TDA, PD, PDbarra, WE; 
		double U, J, We, Wei;
	
	public:

		CAdimensional(){};
		
		std::vector <double> DeltaT(std::vector <double> _t);
		std::vector <double> DeltaPbarra(std::vector <double> _Pbarra);
		std::vector <double> CalcTD(double _k, double _phi, double _mi, double  _ct, double _Ro, std::vector <double> _t);
		std::vector <double> CalcdelP(std::vector <double> _P);
		std::vector <double> CalcTDA(double _Ro, double _Re,std::vector <double> _TD);
		std::vector <double> CalcPD(std::vector <double> _TDA, std::vector <double> _TD, double _Re, double _Ro);
		std::vector <double> CalcPDbarra(std::vector <double> _TDA, std::vector <double> _TD, double _Re, double _Ro);
		double CalcU(double _phi, double _ct, double _h, double _Ro);
		double CalcJ(double _k, double _h, double _Re, double _Ro, double _mi, bool _regime);
		double CalcWe(double _Re, double _Ro, double _h, double _phi);
		double CalcWei(double _ct, double _WI, double _Pi);
		
		~CAdimensional(){};
	
};

#endif
