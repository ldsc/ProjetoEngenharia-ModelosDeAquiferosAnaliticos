#include "CSolverInfluxo.h"

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

using namespace std;
 
void CSolverInfluxo::EntradaDados()
{
	
	cout << "__________________________________________________________" << endl;
	cout << "|                                                        |" << endl;
	cout << "|                Carregando Dados                        |" << endl;
	cout << "|________________________________________________________|\n" << endl;
	
	bool errado = true;
	
	string path = "./dados/";

	cout << "\nArquivos Disponiveis\n" << endl;
	
    for (const auto & file : filesystem::directory_iterator(path))
        cout << file.path() << endl;
		
	cout << endl;
	
	cout << "Entre com nome dos arquivos de dados de pressao\n" << endl;
	
	string nomeArquivo;

	getline(cin, nomeArquivo);

	nomeArquivo="dados/"+nomeArquivo;
	  	 	
	ifstream in;
	
	in.open(nomeArquivo, fstream::in);                    
	
	double tmp;
	
	while (!in.eof())
	{
		in >> tmp;
		P.push_back(tmp);
	}	
	
	in.close();
	
	cout << "__________________________________________________________" << endl;
	cout << "|                                                        |" << endl;
	cout << "|             Dados de pressao carregados                |" << endl;
	cout << "|________________________________________________________|\n" << endl;
	
	cout << "Entre com nome dos arquivos de dados de tempo\n" << endl;
		
	getline (cin, nomeArquivo);
    
	nomeArquivo="dados/"+nomeArquivo;
	 	 
	in.open(nomeArquivo, fstream::in);                    
	
		
	while (!in.eof())
	{
		in >> tmp;
		T.push_back(tmp);
	}	
	
	in.close();
	
	cout << "__________________________________________________________" << endl;
	cout << "|                                                        |" << endl;
	cout << "|              Dados de tempo carregados                 |" << endl;
	cout << "|________________________________________________________|\n" << endl;
	
	cout << "Entre com arquivos de dados do reservatorio\n" << endl;
	
	getline (cin, nomeArquivo);
    
	nomeArquivo="dados/"+nomeArquivo;
	
	in.open(nomeArquivo, fstream::in); 
	
	in >> tmp;
	rocha.SetRe(tmp);
	in >> tmp;
	poco.SetRw(tmp);
	in >> tmp;
	rocha.Seth(tmp);
	in >> tmp;
	rocha.SetPhi(tmp);
	in >> tmp;
	rocha.SetK(tmp);
	in >> tmp;
	fluido.SetMi(tmp);
	in >> tmp;
	reservatorio.SetCt(tmp);
	
	cout << endl;
	
}

void CSolverInfluxo::Executa()
{
	
	EntradaDados();
	
	bool rodar = true;
	
	cout << "Qual metodo para resolucao de influxo deseja utilizar? " << endl;
	
	cout << "__________________________________________________________" << endl;
	cout << "|                                                        |" << endl;
	cout << "|    1 -  Carter&Tracy  |  2 -  Fetkovich  | 0 - sair    |" << endl;
	cout << "|________________________________________________________|\n" << endl;
	
	int escolha, j=0;
	cin >> escolha;
	
	bool time = false;
	
	vector <double> TD;
			
			TD = adimensional.CalcTD(rocha.GetK(), rocha.GetPhi(), fluido.GetMi(), reservatorio.GetCt(), poco.GetRw(), T);
		
			double _U;
				
			_U = adimensional.CalcU(rocha.GetPhi(), reservatorio.GetCt(), rocha.Geth(), poco.GetRw());
				
			vector <double> _delp;
				
			_delp = adimensional.CalcdelP(P);
				
			vector <double> _tda;
			
			_tda = adimensional.CalcTDA(poco.GetRw(), rocha.GetRe(), TD);
		
			vector <double> _pd;
				
			_pd = adimensional.CalcPD(_tda, TD, rocha.GetRe(), poco.GetRw());
				
			vector <double> _pdbarra;
				
			_pdbarra = adimensional.CalcPDbarra(_tda, TD, rocha.GetRe(), poco.GetRw());
	
	while (rodar)
	{
				
		if (time)
		{
							
			cout << "\nDeseja rodar o programa novamente ? " << endl;
			
			cout << "__________________________________________________________" << endl;
			cout << "|                                                        |" << endl;
			cout << "|    1 -  Carter&Tracy  |  2 -  Fetkovich  | 0 - sair    |" << endl;
			cout << "|________________________________________________________|\n" << endl;
			
			cin >> escolha;
						
		}
		
		if (escolha == 1)
			{
												
				vector <double> _wecarter;
				
				_wecarter = carter.CarterTracy(TD, _U, _delp, _pdbarra, _pd);
				
				cout << endl;
				
				for (double i=0 ; i<_wecarter.size();i++)
				cout << "We = " << _wecarter[i] << endl;
				
				Gnuplot::Terminal("qt");
				
				plot_carter.Grid();
				plot_carter.showonscreen();
				plot_carter.Title("Carter - Tracy");
				plot_carter.Legend("inside left top nobox");
				plot_carter.set_style();
				plot_carter.set_xlabel("t(Tempo)");
				plot_carter.set_ylabel("We(influxo acumulado)");
				
				plot_carter.plot_xy(T, _wecarter, "Carter-Tracy");
				plot_carter.savetops("CarterTracy");
				cout << "\nAperte ENTER para continuar" << endl;	
				cin.get();
				cin.get();
				
				plot_carter.set_style("lines");
				plot_carter.replot();
				plot_carter.showonscreen();
				plot_carter.plot_xy(T, _wecarter);
				plot_carter.savetops("CarterTracy(linhas)");
				cout << "Aperte ENTER para continuar" << endl;	
				cin.get();
					
				
			}
		else 
		if (escolha == 2)
			{
						 		
		 		cout << "Qual regime de fluxo?   1- Permanente | 2 - Pseudopermanente " << endl;
				
				bool teste = true;
				double escolha2;
				
				cin >> escolha2;
				
				while (teste)
					{
						if (escolha2 == 1)
						{
							fluxo = true;
							teste = false;
						}
						else
						if (escolha2 == 2)
						{
							
							fluxo = false;
							teste = false;
							
						}
						else
						{
							
						cout << "opcao invalida!!!!" << endl;
						cout << "Qual regime de fluxo?   1- Permanente | 2 - Pseudopermanente " << endl;
						
						cin >> escolha2;
						
						}
					}
										
					double _We;
									
					_We = adimensional.CalcWe(rocha.GetRe(), poco.GetRw(), rocha.Geth(), rocha.GetPhi());
										
					double _Wei;
					
					_Wei = adimensional.CalcWei(reservatorio.GetCt(), _We, P[0]);
										
					vector <double> _delpbarra;
					
					_delpbarra = adimensional.DeltaPbarra(P);
										
					double _J;
					
					_J = adimensional.CalcJ(rocha.GetK(), rocha.Geth(), rocha.GetRe(), poco.GetRw(), fluido.GetMi(), fluxo);
							
					vector <double> deltat;
					
					deltat = adimensional.DeltaT(T);
										
					vector <double> Fet;
					
					Fet = fetkovich.CalcFetkovic(_We, _Wei, _delpbarra, _J, deltat, P);
					
					cout << endl;
					
					for (double i=0; i < Fet.size();i++)
					cout << "We = " << Fet[i] << endl;
					
				Gnuplot::Terminal("qt");
				
				plot_fetkovich.Grid();
				plot_fetkovich.showonscreen();
				plot_fetkovich.Title("Fetkovich");
				plot_fetkovich.Legend("inside left top nobox");
				plot_fetkovich.set_style();
				plot_fetkovich.set_xlabel("t(Tempo)");
				plot_fetkovich.set_ylabel("We(influxo acumulado)");
				
				plot_fetkovich.plot_xy(T, Fet, "Fetkovich");
				plot_fetkovich.savetops("Fetkovich");
				cout << "\nAperte ENTER para continuar" << endl;	
				cin.get();
				cin.get();
				
				plot_fetkovich.set_style("lines");
				plot_fetkovich.replot();
				plot_fetkovich.showonscreen();
				plot_fetkovich.plot_xy(T, Fet);
				plot_fetkovich.savetops("Fetkovich(linhas)");
				cout << "Aperte ENTER para continuar" << endl;	
				cin.get();		 		
		 		
		 	}
		else 
		if (escolha == 0)
			rodar = false;
		else
		{
			cout << "Opcao invalida" << endl;
			cout << "\nQual metodo para resolucao de influxo deseja utilizar? " << endl;
	
			cout << "__________________________________________________________" << endl;
			cout << "|                                                        |" << endl;
			cout << "|    1 -  Carter&Tracy  |  2 -  Fetkovichh  | 0 - sair   |" << endl;
			cout << "|________________________________________________________|\n" << endl;
			
			cin >> escolha;
		}
		j++;
		time = true;
		
		if (j==2)
		break;
	
	}
	
}
