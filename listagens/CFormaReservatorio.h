#ifndef CFORMARESERVATORIO_H_
#define CFORMARESERVATORIO_H_

class CFormaReservatorio
{
	protected:
	
		double wd, RD; //Influxo Adimensional //Raio externo admensional	
	
	public:
		
		CFormaReservatorio(){};

		virtual double Forma(double _u, double _RD); 
			
		~CFormaReservatorio(){};
		
};

#endif
