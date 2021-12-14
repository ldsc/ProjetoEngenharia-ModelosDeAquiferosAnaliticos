#include "CFetkovich.h"

#include <cmath>

double CFetkovich::CalcPan(double _Pi, double _We, double _Wei)
{
	
	Pan = _Pi*(1.0 - (_We/_Wei));
		
	return Pan;	
	
}

double CFetkovich::CalcdeltaWen(double _Wei, double _Pi, double _Pan, double _Pbarra, double _J, double _DeltaT)
{
	double A, B, C;
	
	A = (_Wei/_Pi)*(_Pan - _Pbarra);
	B = -1*((_J*_Pi)/_Wei)*_DeltaT;
	C = exp(B);
	deltaWen = A*(1 - C);
	
	return deltaWen;		
}

std::vector <double> CFetkovich::CalcFetkovic(double _We, double _Wei, std::vector <double> _Pbarra, double _J, std::vector <double> _DeltaT, std::vector <double> _P)
{
	double prsI = _P[0];
	double _paN, DelWen, wef;
	
	for (int i=0; i< _P.size();i++)
	{
		if (i==0)
			{
			_paN = prsI;
			wef = 0.0;
			}
		else 
		{
			
			DelWen = CalcdeltaWen( _Wei, prsI, _paN, _Pbarra[i], _J, _DeltaT[i]);
			wef = WeFet[i-1] + DelWen;
			_paN = CalcPan(prsI, wef, _Wei);
		}

		WeFet.push_back(wef);
	}
	
	return WeFet;
	
}
