#ifndef CROCHA_H_
#define CROCHA_H_

class CRocha{
	
	protected:
	
		double k, phi, Re, h;
		
	public:
		
		CRocha(){};
		
		void SetK(double _k);
		double GetK();
		void SetPhi(double _phi);
		double GetPhi();
		void SetRe(double _Re);
		double GetRe();
		void Seth(double _h);
		double Geth();
		
		~CRocha(){};
		
};

#endif
