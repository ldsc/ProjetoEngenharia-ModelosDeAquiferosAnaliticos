#ifndef CFLUIDO_H_
#define CFLUIDO_H_

class CFluido{

	protected:
	
		double mi;
		
	public:	
	
		CFluido(){};
		
		void SetMi(double _mi);
		double GetMi();		
		
		~CFluido(){};
	
};

#endif
