#ifndef CFORMA_H_
#define CFORMA_H_

class CForma
{
	protected:
	
		double wd, RD; //Influxo Adimensional //Raio externo admensional	
	
	public:
		
		CForma(){};

		virtual double Forma(double _u, double _RD); 
			
		~CForma(){};
		
};

#endif
