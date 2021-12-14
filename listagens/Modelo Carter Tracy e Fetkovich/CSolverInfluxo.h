#ifndef CEXECUTA_H_
#define CEXECUTA_H_

#include <vector>

#include "CRocha.h"
#include "CPoco.h"
#include "CFluido.h"
#include "CFetkovich.h"
#include "CCarterTracy.h"
#include "CAdimensional.h"
#include "CGnuplot.h"
#include "CReservatorio.h"
#include "CCarterTracy.h"

class CSolverInfluxo{
	
	protected:
		
		std::vector <double> P, T;
		
		int fluxo;
		
		CGnuplot plot_carter, plot_fetkovich;
		CFluido fluido;
		CPoco poco;
		CRocha rocha;
		CReservatorio reservatorio;
		CCarterTracy carter;
		CFetkovich fetkovich;
		CAdimensional adimensional;
		
		
	public:
	
		CSolverInfluxo(){};
		
		void EntradaDados();
		void Executa();
		
		~CSolverInfluxo(){};
	
};

#endif
