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
				hex[i] = hex[i] + 16;
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

			b = b + (a*(i + 1));
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
		suma = suma + (a*(i + 1));
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
void randomChars(std::string pav)
{
	std::vector<std::string>charai = { "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z" };
	
	std::ofstream fr;
	fr.open(pav);
	std::vector<std::vector<std::string>>pora1, pora2;
	for (int i = 0; i < 1000000; i++)
	{
		std::vector<std::string>a;
		for (int j = 0; j < 5; j++)
		{
			int x = randomNum(0, 25);
			a.push_back(charai[x]);
		}
		pora1.push_back(a);

		std::vector<std::string>b;
		for (int j = 0; j < 5; j++)
		{
			int x = randomNum(0, 25);
			b.push_back(charai[x]);
		}
		pora2.push_back(b);
	}
	for (auto i = 0; i < pora1.size(); i++)
	{
		fr << pora1[i][0] << pora1[i][1] << pora1[i][2] << pora1[i][3] << pora1[i][4] << " " << pora2[i][0] << pora2[i][1] << pora2[i][2] << pora2[i][3] << pora2[i][4] << std::endl;
	}
	fr.close();
}

void randomChars2(std::string pav)
{
	std::vector<std::string>charai = { "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z" };

	std::ofstream fr;
	fr.open(pav);
	std::vector<std::vector<std::string>>pora1, pora2;
	for (int i = 0; i < 10000; i++)
	{
		std::vector<std::string>a;
		std::vector<std::string>b;
		for (int j = 0; j < 4; j++)
		{
			int x = randomNum(0, 25);
			a.push_back(charai[x]);
			b.push_back(charai[x]);
		}
		last_one:
		int paskutinis1 = randomNum(0, 25);
		int paskutinis2 = randomNum(0, 25);
		if (paskutinis1 != paskutinis2)
		{
			a.push_back(charai[paskutinis1]);
			b.push_back(charai[paskutinis2]);
		}
		else
		{
			goto last_one;
		}
		pora1.push_back(a);
		pora2.push_back(b);
	}
	for (auto i = 0; i < pora1.size(); i++)
	{
		fr << pora1[i][0] << pora1[i][1] << pora1[i][2] << pora1[i][3] << pora1[i][4] << " " << pora2[i][0] << pora2[i][1] << pora2[i][2] << pora2[i][3] << pora2[i][4] << std::endl;
	}
	fr.close();
}

int trecia_uzd(std::string pav)
{
	std::vector<unsigned long long int> suma1,suma2;
	std::ifstream fd;
	std::vector<std::string>tex1,tex2;
	fd.open(pav);
	while (!fd.eof())
	{
		std::string tarpinis;
		unsigned long long int a, b = 0;
		for (auto i = 0; i < 5; i++)
		{
			char x;
			
			fd >> x;
			tarpinis.push_back(x);
			int a = int(x);
			if (a < 0)
			{
				a = (a*-1) + 200;
			}
			b = b + (a*(i + 1));
		}
		suma1.push_back(b);
		tex1.push_back(tarpinis);

		 b = 0;
		 std::string tarpinis2;
		for (auto i = 0; i < 5; i++)
		{
			char x;
			
			fd >> x;
			tarpinis2.push_back(x);
			int a = int(x);
			if (a < 0)
			{
				a = (a*-1) + 200;
			}
			b = b + (a*(i + 1));
		}
		suma2.push_back(b);
		tex2.push_back(tarpinis2);
	}
	int kiek_pasikartojo = 0;
	std::vector<int>hex1, hex2; //Konvertuoja i HEX

	for (auto i = 0; i < suma1.size(); i++)
	{
		hex1 = To_Hex(suma1[i]);
		hex2 = To_Hex(suma2[i]);
		if (hex1 == hex2 & suma1[i] != suma2[i])
		{
			kiek_pasikartojo++;
			std::cout << "Text: " << tex1[i] << " , " << "Suma: " << suma1[i] << " , Hash: ";
			for (int i = 0; i < 32; i++)
			{
				std::cout << std::hex << hex1[i];

			}
			std::cout << std::endl;
			std::cout << "Text: " << tex2[i] << " , " << "Suma: " << suma2[i] << " , Hash: ";
			for (int i = 0; i < 32; i++)
			{
				std::cout << std::hex << hex2[i];

			}
			std::cout << std::endl;
			std::cout << std::endl;
		}

	}

	return kiek_pasikartojo;
}

std::vector<double> ketvirta_uzd(std::string pav)
{
	std::vector<unsigned long long int> suma1, suma2;
	std::ifstream fd;

	fd.open(pav);
	while (!fd.eof())
	{
		std::string tarpinis;
		unsigned long long int a, b = 0;
		for (auto i = 0; i < 5; i++)
		{
			char x;

			fd >> x;
			tarpinis.push_back(x);
			int a = int(x);
			if (a < 0)
			{
				a = (a*-1) + 200;
			}
			b = b + (a*(i + 1));
		}
		suma1.push_back(b);

		b = 0;
		std::string tarpinis2;
		for (auto i = 0; i < 5; i++)
		{
			char x;

			fd >> x;
			tarpinis2.push_back(x);
			int a = int(x);
			if (a < 0)
			{
				a = (a*-1) + 200;
			}
			b = b + (a*(i + 1));
		}
		suma2.push_back(b);
	}
	int kiek_pasikartojo = 0;
	std::vector<int>hex1, hex2; //Konvertuoja i HEX

	std::ofstream fr;
	fr.open("4_uzd_rez.txt");
	for (auto i = 0; i < suma1.size(); i++)
	{
		hex1 = To_Hex(suma1[i]);
		hex2 = To_Hex(suma2[i]);

			for (int i = 0; i < 32; i++)
			{
				fr << std::hex << hex1[i];

			}
			fr << " ";
			for (int i = 0; i < 32; i++)
			{
				fr << std::hex << hex2[i];

			}
			fr << std::endl;
		}
	fr.close();

	std::ifstream fd2;
	std::vector<std::string>text1, text2;
	fd2.open("4_uzd_rez.txt");
	while (!fd2.eof())
	{
		std::string a, b;
		fd2 >> a >> b;
		text1.push_back(a);
		text2.push_back(b);

	}
	fd2.close();

	std::vector<double>rezultatai;
	for(auto i=0; i<text1.size();i++)
	{
		double rez;
		rez = sutapimai(text1[i], text2[i]) / (text1.size()*4);
		rezultatai.push_back(rez);
	}
	
	return rezultatai;
}



double max(std::vector<double>rezultatai)
{
	double maxi=0;
	for (auto i = 0; i < rezultatai.size(); i++)
	{
		if (maxi < rezultatai[i])
		{
			maxi = rezultatai[i];
		}
	}
	return maxi;
}
double min(std::vector<double>rezultatai)
{
	double mini = 100;
	for (auto i = 0; i < rezultatai.size(); i++)
	{
		if (mini > rezultatai[i])
		{
			mini = rezultatai[i];
		}
	}
	return mini;
}
double avg(std::vector<double>rezultatai)
{
	double avg = 0;
	for (auto i = 0; i < rezultatai.size(); i++)
	{
		avg = avg + rezultatai[i];
	}
	return avg/rezultatai.size();
}


double sutapimai(std::string test1, std::string test2)
{
	double kiek_sutapimu = 0;
	std::string h1, h2;
		h1 = test1;
		h2 = test2;

		for(auto i=0; i<h1.size();i++)
		{
			double kiek = kiek_sutapo(char(h1[i]), char(h2[i]));
			kiek_sutapimu = kiek_sutapimu + kiek;
		}

	return kiek_sutapimu;
}

int kiek_sutapo(char a, char b)
{
	int kiek=0;
	std::string g1 = "", g2 = "";
	if (a == '0') g1 = "0000";
	if (a == '1') g1 = "0001";
	if (a == '2') g1 = "0010";
	if (a == '3') g1 = "0011";
	if (a == '4') g1 = "0100";
	if (a == '5') g1 = "0101";
	if (a == '6') g1 = "0110";
	if (a == '7') g1 = "0111";
	if (a == '8') g1 = "1000";
	if (a == '9') g1 = "1001";
	if (a == 'a') g1 = "1010";
	if (a == 'b') g1 = "1011";
	if (a == 'c') g1 = "1100";
	if (a == 'd') g1 = "1101";
	if (a == 'e') g1 = "1110";
	if (a == 'f') g1 = "1111";
					   
	if (b == '0') g2 = "0000";
	if (b == '1') g2 = "0001";
	if (b == '2') g2 = "0010";
	if (b == '3') g2 = "0011";
	if (b == '4') g2 = "0100";
	if (b == '5') g2 = "0101";
	if (b == '6') g2 = "0110";
	if (b == '7') g2 = "0111";
	if (b == '8') g2 = "1000";
	if (b == '9') g2 = "1001";
	if (b == 'a') g2 = "1010";
	if (b == 'b') g2 = "1011";
	if (b == 'c') g2 = "1100";
	if (b == 'd') g2 = "1101";
	if (b == 'e') g2 = "1110";
	if (b == 'f') g2 = "1111";

	for (int i = 0; i < 4; i++)
	{
		if (char(g1[i]) == char(g2[i]))
		{
			kiek++;
		}
	}
	return kiek;
}
