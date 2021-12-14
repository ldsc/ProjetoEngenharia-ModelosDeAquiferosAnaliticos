#include "CRocha.h"

void CRocha::SetK(double _k)
{
	k = _k;	
}

void CRocha::SetPhi(double _phi)
{
	phi = _phi;
}

void CRocha::SetRe(double _Re)
{
	Re = _Re;
}

void CRocha::Seth(double _h)
{
	h = _h;
}

double CRocha::GetK()
{
	return k;
}

double CRocha::GetPhi()
{
	return phi;
}

double CRocha::GetRe()
{
	return Re;
}

double CRocha::Geth()
{
	return h;
}
