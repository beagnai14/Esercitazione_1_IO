#include <fstream>  
#include <iostream>  
#include <vector>
#include <iomanip>


int main()
{
	//apertura file input e output
	std::ifstream file("./data.txt");
	
	if(file.fail())
	{
		std::cerr << "Errore: non è stato possibile aprire il file" << std::endl;
		return 1;
	}
	 
	
	std::ofstream outputfile("./result.txt");
	if (outputfile.fail())
	{
		std::cerr << "Errore: non è stato possibile aprire il file result.txt" << std::endl;
		return 1;
	}
	
	
	//funzione lineare da [1,5] a [-1,2]
	std::cout << std::fixed << std::setprecision(16); //precisione di 16 decimali
	std::vector<double> y;   //y:vettore dinamico di double
	double x;				 //x: numero del file

	while (file >> x)
	{
		double y_mappato=(3.0/4.0)*x-(7.0/4.0);
		y.push_back(y_mappato);    //aggiungo il numero al vettore y
	}
	
	file.close();
	

	
	// calcolo della media progressiva
	double sum = 0;
	size_t i = 0;    //dichiaro i come size_t per fare il confronto con la dimensione di y
	while (i < y.size())
	{
		sum = sum + y[i];
		double media = sum/(i+1);
		outputfile << media << std::endl;
		i++;
	};

	outputfile.close();
	return 0;
	
};
