#include "stdafx.h"
#include "funkcijos.h"


std::vector<int> To_Hex(unsigned long long int suma)
{
	std::vector<int>hex = { 43,57,47,81,93,18,9,6,1,26,96,7,44,96,64,67,68,35,64,88,23,24,76,8,54,64,60,62,86,94,52,34 };

	for (int i = 0; i < 32; i++)
		{
			hex[i] = (hex[i] + suma) % 256;
			if (hex[i] < 16)
			{
				hex[i] = hex[i] + 50;
			}
		}
	
	return hex;

}

std::vector<unsigned long long int> Nuskaitymas_failas_2(std::string pav)
{
	std::vector<unsigned long long int> suma;
	std::ifstream fd;
	fd.open(pav);
	std::string x;
	while (!fd.eof())
	{
		getline(fd, x);
		unsigned long long int a, b = 0;
		for (auto i = 0; i < x.size(); i++)
		{
			int a = int(x[i]);
			if (a < 0)
			{
				a = (a*-1) + 200;
			}

			b = b + sqrt(a)*(i + 1);
		}
		suma.push_back(b);
	}
	return suma;
}
unsigned long long int Nuskaitymas_failas(std::string pav)
{
	unsigned long long int suma=0;
	int i = 0;
	std::ifstream fd;
	fd.open(pav);
	while (!fd.eof())
	{
		
		char x;
		fd >> x;
		int a = int(x);
		if (a < 0)
		{
			a = (a*-1) + 200;
		}

		i++;
		suma = suma + +sqrt(a)*(i + 1);
	}
	return suma;
}

void spausdinimas(std::vector<std::vector<int>>hex2)
{
	std::ofstream fr;
	fr.open("rez.txt");
	for (auto j = 0; j < hex2.size(); j++)
	{
		for (int i = 0; i < 32; i++)
		{
			fr << std::hex << hex2[j][i];
			//std::cout  << hex[i];
		}
		fr << std::endl;
	}
	std::cout << std::endl;
	fr.close();
}


std::mt19937 randomly_seeded_engine() {

	// create a seed sequence of several reasonably random values
	std::seed_seq seed_seq{ (unsigned int)std::random_device{}(),
						   (unsigned int)std::chrono::system_clock::now().time_since_epoch().count(),
						   (unsigned int)std::random_device{}(),
						   (unsigned int)std::chrono::steady_clock::now().time_since_epoch().count(),
						   (unsigned int)std::random_device{}() };

	return std::mt19937(seed_seq); // note: the seed sequence provides a warm up sequence for the rng
}

int randomNum(int a, int b) {

	static auto rng = randomly_seeded_engine();
	static std::uniform_int_distribution<int> distribution;

	distribution.param(std::uniform_int_distribution<int>::param_type{ a, b });
	return distribution(rng);
}
