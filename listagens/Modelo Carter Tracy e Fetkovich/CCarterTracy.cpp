#include "CCarterTracy.h"

using namespace std;

double CCarterTracy::CalcAJ(double _U, double _delp, double _we, double _pdbarra, double _TD, double _td, double _PD)
{
	double A,B,C;
	
	A = (_U*_delp) - (_we*_pdbarra);
	B = _PD - (_td*_pdbarra);
	C = _TD-_td;
	AJ = (A/B)*C;	
	
	return AJ;
	
}

vector <double> CCarterTracy::CarterTracy(vector <double> _TD, double _U, vector <double> _delp, vector  <double> _pdbarra, vector <double> _PD)
{
	double we;
	for (int i=0; i < _TD.size(); i++)
	{
		if (i==0)
			we = 0.0;
		else
			we = Wecarter[i-1] + CalcAJ(_U, _delp[i], Wecarter[i-1], _pdbarra[i], _TD[i], _TD[i-1], _PD[i]);
			
	Wecarter.push_back(we);
		 
	}	
		
	return Wecarter;
	
}
