#include "CSolver.h"

using namespace std;

void CSolver::Plot(vector <double> _WD, vector <double> _TD)
{

	plot.set_xlabel("Td");
	plot.set_ylabel("Wd");
//	plot.Title("WdxTD");
	plot.savetops("GraficoTeste");
	plot.set_xlogscale();
	
//	plot.cmd("set term png size 1800,1200");
//	plot.cmd("set output \"save.png\"");

	cin.get();
	plot.plot_xy(_WD, _TD, "WdxTd");	
	
	
}
void CSolver::Solver()
{
	
	vector <double> radialinfinito;
	for (double i=0.01;i<=1000;i+=.01)
		TD.push_back(i);
		
		
	for (double k=0; k < TD.size(); k++)
		radialinfinito.push_back(Stehfest.StehfestRadialInfinito(TD[k]));
		
		cout << TD.size() << endl;
		cout << radialinfinito.size();
		
		Plot(radialinfinito, TD);
	
}
