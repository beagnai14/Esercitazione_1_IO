#include <fstream>  
#include <iostream>  
#include <vector>
#include <iomanip>

int main()
{
	std::ifstream file("./data.txt");
	
	if(file.fail())
	{
		std::cerr << "Errore: non è stato possibile aprire il file" << std::endl;
		return 1;
	}
	 
	
	//function that maps points from [1,5] to [-1,2]
	std::cout << std::fixed << std::setprecision(16); //precisione di 16 decimali
	std::vector<double> y;   //y:vettore dinamico di double
	double x;

	while (file >> x)
	{
		double y_mappato=(3.0/4.0)*x-(7.0/4.0);
		y.push_back(y_mappato);
	}
	
	int N = y.size();   //dimensione vettore dinamico
	std::cout << N << std::endl;
	
	//stampa i valori mappati
	std::cout << "Valori mappati:" << std::endl;
    for (int i = 0; i <= N; ++i) 
	{
        std::cout << "y[" << i << "] = " << y[i] << std::endl;
    }
	
	
	//apertura file output
	std::ofstream outputfile("./result.txt");
	if (outputfile.fail())
	{
		std::cerr << "Errore: non è stato possibile aprire il file result.txt" << std::endl;
		return 1;
	}
	
	// calcolare la media 
	double sum = 0;
	for (int i = 0; i<=N; i++)
	{
		double sum = sum + y[i];
		double media = sum/(i+1);
		outputfile << media << std::endl;
	}
	
	
    return 0;
}
