#include "CAdimensional.h"

#define _USE_MATH_DEFINES

#include <cmath>

using namespace std;

vector <double> CAdimensional::DeltaT(vector <double> _t)
{
	
	double delt;
	
	for (int i = 0; i < _t.size(); i++)
	{
		if (i==0)
			delt = 0;
		else
			delt = _t[i] - _t[i-1];
			
		delT.push_back(delt);
	}
	
	return delT;
	
}

std::vector <double> CAdimensional::DeltaPbarra(std::vector <double> _Pbarra)
{
	double pbarra;
	
	for (int i = 0; i < _Pbarra.size(); i++)
{
	
	if (i==0)
        pbarra = 0;
    else
        pbarra = (_Pbarra[i-1] + _Pbarra[i])/2.0;
        
    deltPbarra.push_back(pbarra);
}

return deltPbarra;
	
}

vector <double> CAdimensional::CalcTD(double _k, double _phi, double _mi, double  _ct, double _Ro, vector <double> _t)
{
	
	double td;
	
	for (int i=0; i <_t.size(); i++)
		{
			td = (_k*_t[i])/(_phi*_mi*_ct*(_Ro*_Ro));
			TD.push_back(0.008362*td);
		}
		
	return TD;
	
}

vector <double> CAdimensional::CalcdelP(vector <double> _P)
{
	
	double prsI = _P[0], A;
		
	for (int i = 0; i < _P.size(); i++)
		{
			A = prsI - _P[i];
			delP.push_back(A);
		}
		
	return delP;
	
}

vector <double> CAdimensional::CalcTDA(double _Ro, double _Re,vector <double> _TD)
{

	double tda;
	
	for (int i = 0; i < _TD.size();i++)
	{	
		tda = (_TD[i])/(M_PI*(((_Re/_Ro)*(_Re/_Ro)) - 1));	
		TDA.push_back(tda);
	}
	
	return TDA;
	
}

vector <double> CAdimensional::CalcPD(vector <double> _TDA, vector <double> _TD, double _Re, double _Ro)
{
	double pd;
	
	for (int i = 0; i<_TD.size();i++)
	{
		
		if (_TDA[i]<.1)
			pd = (1.0/2.0)*(log(_TD[i])+.80907);
		else 
			pd = ((2.0*_TD[i])/((_Re/_Ro)*(_Re/_Ro))) + log(_Re/_Ro) -(3.0/4.0);
			
		PD.push_back(pd);
	}
	
	return PD;	
	
}

vector <double> CAdimensional::CalcPDbarra(vector <double> _TDA, vector <double> _TD, double _Re, double _Ro)
{
	double pdbarra;
	
	for (int i = 0; i<_TD.size();i++)
	{
		
		if (_TDA[i]<.1)
			pdbarra = (1.0/(2.0*_TD[i]));
		else 
			pdbarra = 2.0/((_Re/_Ro)*(_Re/_Ro));
			
		PDbarra.push_back(pdbarra);
	}
	
	return PDbarra;
	
}

double CAdimensional::CalcU(double _phi, double _ct, double _h, double _Ro)
{
	
	U=2.0*M_PI*_phi*_ct*_h*_Ro*_Ro;
	
	return U;
	
}

double CAdimensional::CalcJ(double _k, double _h, double _Re, double _Ro, double _mi, bool _regime)
{
	double A, B;
	
	if (_regime)
	{
		A = 0.05255*_k*_h;
		B = _mi*(log(_Re/_Ro));
		J = A/B;
	}
	else
	{
		A = 0.05255*_k*_h;
		B = _mi*(log(_Re/_Ro) -(3.0/4.0));
		J = A/B;
	}
	
	return J;
	
}

double CAdimensional::CalcWe(double _Re, double _Ro, double _h, double _phi)
{
	
	We = M_PI*_h*_phi*((_Re*_Re) - (_Ro*_Ro));
	
	return We;
	
}

double CAdimensional::CalcWei(double _ct, double _We, double _Pi)
{
	
	Wei = _ct*_We*_Pi;
	return Wei;
}

