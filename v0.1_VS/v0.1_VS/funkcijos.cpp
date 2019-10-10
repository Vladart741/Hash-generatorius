#include "stdafx.h"
#include "funkcijos.h"


std::vector<long int> To_Hex(std::vector<long int> rezultatas)
{
	std::vector<long int>hex;
	for (int i = 0; i < 65; i++)
	{
		hex.push_back(0);
	}
	for (auto j = 0; j < rezultatas.size(); j++)
	{
		for (int i = 0; i < 65; i++)
		{
			int x;
			x = (rezultatas[j] * (i+1)) + hex[i];
			hex[i] = hex[i] + x;
			if (hex[i] < 0)
			{
				hex[i] = hex[i] * -1;
			}
		}
	}
	for (int i = 0; i < 65; i++)
	{
		hex[i] = hex[i] % 32;
		//hex[i] = hex[i] % 16;
	}
	return hex;

}

std::vector<long int> To_Dec(std::vector<char> failas)
{
	std::vector<long int> rezultatas;
	for (auto i = 0; i < failas.size(); i++)
	{
		rezultatas.push_back(long int(failas[i]));
	}
	return rezultatas;
}


std::vector<data> Nuskaitymas_data()
{
	std::vector<data>enigma;
	std::ifstream fd;
	fd.open("data.txt");
	
	while (!fd.eof())
	{
		data Data;
		fd >> Data.x >> Data.value;

		enigma.push_back(Data);
	}
	fd.close();
	return enigma;
}
std::vector<char> Nuskaitymas_failas(std::string pav)
{
	std::vector<char> failas;
	std::ifstream fd;
	fd.open(pav);
	while (!fd.eof())
	{
		char x;
		fd >> x;
		failas.push_back(x);
	}
	return failas;
}