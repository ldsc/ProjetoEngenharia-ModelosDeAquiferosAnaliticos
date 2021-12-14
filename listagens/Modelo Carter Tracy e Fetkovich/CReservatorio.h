#ifndef CRESERVATORIO_H_
#define CRESERVATORIO_H_

class CReservatorio{
	
	protected:
		
		double ct;
		
	public:
		
		CReservatorio(){};		
		
		void SetCt(double _ct);
		double GetCt();
		
		~CReservatorio(){};
		
};

#endif
